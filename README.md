# Remote-Controlled-Arduino-Arm
It sounds like your typical arduino project, and it is. However, after seeing how those arms are typically built, I decided to use a stepper motor and more servos than what I've seen. 
I made the arm to have $${\color{yellow}4 degrees of freedom(DOF)}$$ to give it more freedom of movement, and although contructing took a few weeks of effort in between my final exams, seeing it come to life made me swell with relief and pride, even if the wires and hot glue and tape were a bit of a mess.

<img width="413" height="413" alt="image" src="https://github.com/user-attachments/assets/955e391d-15c2-4b4b-ab5b-bf5e189fe6c5" />

## The process 
Both the code and build for this project took a lot of trial and effort to get it to work. From calibrating the servos to move at the push of a button on an infrared remote, to ensuring that the other buttons did not interfere with each other's signals, I learned a lot about controllers, signals and logic in this. All of which led to the final product of the arm. 

## Early motor tests
At first, it was a challenge to code the motors so that they would move at the 'push' of a button, not a 'hold'. Moreover, the motors kept stopping every time I held a button down for too long. That is, until I did a bit of research and found this piece of code that moved this project forward: 

<img width="413" height="140" alt="Screenshot 2025-10-24 180147" src="https://github.com/user-attachments/assets/f06f15e8-43b3-4468-a1d3-8509d3dbbd02" />

I commented on the code to make it more understandable, but what this essentially does is save the value of the signal as an unsigned long value called lastValue. Then, if the ensuing signal, 0x0, the signal that's sent when the button is held, is received, it makes the value equal to the lastValue stored, so button holds no longer stopped the motor. That is how the motors began to move like this controlled with the remote: 




