# UNO_Robot
Goal: Create a robot capable of playing UNO with real people.</br>

__Progress:__</br>
*Done*
> Robot arm functional</br>
> Image recognition model trained<br>
*TO-DO*
> Image recognition model fails (likely need more/better images)</br>
> Discover how to move the arm in coordinate-like manner rather than relative movement to last position</br>
> Discover how to send images from the ArduCAM to a server to run the card recognition model</br>
> Discover how to interpret the results from the card recognition and send coordinates for the robot arm to move the appropriate card</br>

__*Specifications:*__<br></br>
__Robot:__</br>
> Two Arduino Uno microprocessors</br>
> One breadboard</br>
> Two "step motor 28byj-48" motors for the arm</br>
> One ArduCAM mini 5 MP-plus ov5642 camera</br>
> Many male-male & male-female wires</br>

__Image Recognition:__</br>
-Refer to card_recognition.ipynb-</br>
> Using Keras with Tensorflow libraries with my own card dataset to train a model</br>
