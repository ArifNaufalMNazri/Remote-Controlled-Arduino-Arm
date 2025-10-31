# **Remote Controlled Arduino Arm**
This is a 4-jointed robotic arm powered by an Arduino. Nothing is attached to the robotic wrist, as this project was intended as an experiment to learn about structuring robotic arms and programming motors to move independently using a remote control. 

This project required me to look at how the motors received and responded to signals from a new angle, and it seeing it come to life was rewarding and satisfying

<p align="center">
<img width="413" height="413" alt="image" src="https://github.com/user-attachments/assets/955e391d-15c2-4b4b-ab5b-bf5e189fe6c5" />
</p>

## **The process** 
I gained a deeper understanding of **controllers, signals and logic** throughout the build. Here are some important points from that process

### **Early motor tests**
After struggling to program the motors, I discovered a piece of code that allowed the motors to move smoothly without jamming shortly after. 

<p align="center">
<img width="413" height="140" alt="Screenshot 2025-10-24 180147" src="https://github.com/user-attachments/assets/f06f15e8-43b3-4468-a1d3-8509d3dbbd02" />
</p>

It saves the previous value of the signal sent in `lastRead` if the signal wasn't `0x0`. The motors only respond to predetermined signals, and storing them in `lastRead` and rewriting it into `read`, the motors moved ragardless of whether I held or pressed the button. As a result, the motors could move like this: 

<p align="center">
![Remote-Controlled-Arduino-Arm](https://raw.githubusercontent.com/ArifNaufalMNazri/Remote-Controlled-Arduino-Arm/main/ServoVideo-ezgif.com-optimize.gif)
</p>




