#include <Wire.h>
#include <ArduCAM.h>
#include <SPI.h>
#if !(defined (OV5642_MINI_5MP_PLUS))
#error Please select the hardware platform and camera module in the ../libraries/ArduCAM/memorysaver.h file
#endif
const int CS = 7;
static uint8_t resolution = 0;
const int ledPin = 2; // for button
const int buttonPin = 3; // for button
int buttonState = 0; // for button
#if defined (OV5642_MINI_5MP_PLUS)
  ArduCAM myCAM(OV5642, CS);
#endif
void setup() {
  pinMode(ledPin, OUTPUT); // button
  pinMode(buttonPin, INPUT); // button
  uint8_t vid, pid;
  uint8_t temp;
  Wire.begin();
  Serial.begin(921600);
  Serial.println(F("ACK CMD ArduCAM Start!"));
  pinMode(CS, OUTPUT);
  digitalWrite(CS, HIGH);
  // intializa SPI:
  SPI.begin();
  myCAM.write_reg(0x07, 0x80);
  delay(100);
  myCAM.write_reg(0x07, 0x00); // 0x07 = address, 0x00 == data
  delay(100);
  while(1) {   // testing the SPI is working
    myCAM.write_reg(ARDUCHIP_TEST1, 0x55);
    delay(100);
    temp = myCAM.read_reg(ARDUCHIP_TEST1);
    if (temp != 0x55) {
      Serial.println(F("ACK CMD SPI interface Error!"));
      delay(1000); continue;
    } else {
      Serial.println(F("ACK CMD SPI interface OK.")); break;
    }
  }
  while (1) {
    myCAM.rdSensorReg16_8(OV5642_CHIPID_HIGH, &vid);
    myCAM.rdSensorReg16_8(OV5642_CHIPID_LOW, &pid);
    if ((vid != 0x56) || (pid != 0x42)) {
      Serial.println(F("ACK CMD Can't find OV5642 module!"));
      delay(1000); continue;
    } else {
      Serial.println(F("ACK CMD OV5642 detected.")); break;
    }
  }
  myCAM.set_format(JPEG);
  myCAM.OV5642_set_JPEG_size(OV5642_640x480);
  myCAM.InitCAM();
  myCAM.write_reg(ARDUCHIP_TIM, VSYNC_LEVEL_MASK);
  myCAM.clear_fifo_flag();
  myCAM.write_reg(ARDUCHIP_FRAMES, 0x00);
  myCAM.set_bit(ARDUCHIP_GPIO,GPIO_PWDN_MASK);
  delay(800);
  Serial.println(F("ACK CMD Ready to Take Pictures."));
}
void loop() {
  uint8_t temp = 0xff, temp_last = 0;
  uint8_t start_capture = 0;
  temp = Serial.read();
  buttonState = digitalRead(buttonPin);
  if (buttonState != 0) {
    digitalWrite(ledPin, HIGH);
    temp = 0x10;
  } else {
    digitalWrite(ledPin, LOW);
    temp = 0x00;
  }
  if (temp == 0x10) {
      temp = 0xff;
      start_capture = 1;
      Serial.println(F("ACK CMD CAM start single shot."));
      myCAM.clear_bit(ARDUCHIP_GPIO,GPIO_PWDN_MASK);
      delay(800);
  }
  if (start_capture == 1) {
    myCAM.flush_fifo();
    myCAM.clear_fifo_flag();
    myCAM.start_capture();
    start_capture = 0;
  }
  if (myCAM.get_bit(ARDUCHIP_TRIG, CAP_DONE_MASK)) {
    Serial.println(F("ACK CMD CAM Capture Done."));
    temp = 0;
    Serial.println(F("ACK IMG"));
    while ((temp != 0xD9) | (temp_last != 0xFF)) {
      temp_last = temp;
      temp = myCAM.read_fifo();
      Serial.write(temp);
      delayMicroseconds(15);
    }
    myCAM.clear_fifo_flag();
  }
}
