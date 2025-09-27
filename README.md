# Multipurpose-Modular-Robotic-Vehicle-MMPRV-
A proof of concept demonstrator for a more advanced modular robot powered by Arduino. The concept is to have a base robot build with plug-and-play attachments that can be used to have the vehicle carry out different tasks to minimize cost and complexity of production and make robotic helpers more common/easy to use.

When the MMPRV starts the servos at the head and the frontal wheels of the vehicle into their origin spot.
After approximately 10 seconds the rear motors start recieving power
At this time the distance to closest object should be more than 30cm
The moment the MMPRV comes within 30 cm of the nearest object, power to the motors is cut
The ultrasonic sensor rotates about 10 degrees every few seconds recording the distance at each angle
Once the ultrasonic sensor completes the cycle of 18 rotations, coming back to its origin, the motors go into reverse mode
The motors remain in reverse mode for about 5 second before coming to a stop
The front wheel servos are slowly shifted to the angle with the most distance while the motors accelerate
if another object is sensed then the cycle can rinse and repeat
