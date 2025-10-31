# **Remote Controlled Arduino Arm**
This is a 4-jointed robotic arm powered by an Arduino. Nothing is attached to the robotic wrist, as this project was intended as an experiment to learn about structuring robotic arms and programming motors to move independently using a remote control. 

This project required me to look at how the motors received and responded to signals from a new angle, and it seeing it come to life was rewarding and satisfying.😆

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

![ServoVideo-ezgif com-optimize](https://github.com/user-attachments/assets/5d9939b2-9342-4f1b-bb66-66406d8f03c8)

### **Signals trouble shooting**
It was a challenge to configure the remote controller signals to different motors.

I settled on a few signals to control each individual motors clockwise and anticlockwise movements, the names of which beginning with *right* or *left*. 
<p align="center">
<img width="453" height="246" alt="image" src="https://github.com/user-attachments/assets/04f8f266-2780-4837-959b-110b5a3c3f4b" />
</p>

### **Controlling motor movement**
I created a function which would increment or decrement the angle of the *180-degreee rotational servo motor* based on their signals. In this way, I could reuse the same function for each of my servos. 

<p align="center">
<img width="620" height="329" alt="image" src="https://github.com/user-attachments/assets/cb593699-51a5-4038-82ce-7828b26d5668" />
</p>

For the *continuous rotation servo* at the wrist of the arm, the code was: 

<p align="center">
<img width="528" height="365" alt="image" src="https://github.com/user-attachments/assets/a344f177-31a7-401b-bd34-5af7334e0d6a" />
</p>

The code for the *stepper motor* was: 

<p align="center">
<img width="240" height="173" alt="image" src="https://github.com/user-attachments/assets/b5e988c4-de2a-4241-8c34-8f091c919c87" />
</p>

However, when I held the button down, the Arduino would continue to send that signal to the function, making the servo continue moving. To solve this, I added a limit to how many increments could happen before setting the the `lastRead` and `read` value to 0. I used an `int` named `plus` to limit the increments to **5**. 

With this, I could finally control all the motors independently, of which I do not have a video of. Now, it was time for the structure of the build. 

### **Arm Structure**
The first design had been built on an unstable, hot-glued popsicle stick base that also made me realize that I was over-straining the servo motors with all the weight they were carrying. Because of this, the first design fell apart. 

<p align="center">
<img width="433" height="397" alt="image" src="https://github.com/user-attachments/assets/0b5b9153-5d64-4d24-825f-928a1ec9a4d9" />
</p>

After doing some research on Arduino arms around the internet, I realized I needed to place arm on a sturdier base, and also attach the servo motors directly on top of the stepper motor so tilting wouldn't become a problem, which became the final build whose screenshot began this README. 

<p align="center">
<img width="413" height="413" alt="image" src="https://github.com/user-attachments/assets/955e391d-15c2-4b4b-ab5b-bf5e189fe6c5" />
</p>

### **Full code**
Here's a link to the full code of the arm movement: [💻Code Link](https://github.com/ArifNaufalMNazri/Remote-Controlled-Arduino-Arm/blob/main/arm.ino)

You can also see the code in a file in the repo too!


## **Final Product**
I was proud of how well the final product turned out. Every motor did it's job. With that, I was happy to conclude this project and experiment with a video recording it. 

GIF: 

![Untitledvideo-MadewithClipchamp6-ezgif com-optimize (1)](https://github.com/user-attachments/assets/e719cd90-7a6a-4cab-b5c9-94f81c67dfd4)

## **Final Thoughts**
This experience has made me learn to think more *critically* and built my *problem-solving skills* and *grit* when it comes to solving issues. This project took me a few weeks of building in between my exams. Seeing it move around made me feel like a real engineer, having to troubleshoot and fix problems constantly until it finally moved the way I wanted it to. It's an experience I won't forget, and something I'll be doing again soon.👍

If you found this interesting, don't forget to star it as your favourites⭐













