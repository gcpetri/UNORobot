# UNO_Robot
Goal: Create a robot capable of playing UNO with real people.

# Progress: #
Robot arm functional
Image recognition model trained
> Image recognition model fails (likely need more/better images)
> Discover how to move the arm in coordinate-like manner rather than relative movement to last position
> Discover how to send images from the ArduCAM to a server to run the card recognition model
> Discover how to interpret the results from the card recognition and send coordinates for the robot arm to move the appropriate card

Specifications:
# Robot: #
Two Arduino Uno microprocessors
One breadboard
Two "step motor 28byj-48" motors for the arm
One ArduCAM mini 5 MP-plus ov5642 camera
Many male-male & male-female wires

# Image Recognition: #
-Refer to card_recognition.ipynb-
Using Keras with Tensorflow libraries with my own card dataset to train a model
