<img width="3188" height="1202" alt="frame (3)" src="https://github.com/user-attachments/assets/517ad8e9-ad22-457d-9538-a9e62d137cd7" />


# Chumma Counter: The World's Most Pointless Bookmark 📖🤖


## Basic Details
### Team Name: GP

### Team Members
- Team Lead: Gokul P - Adishankara Institute of Engineering and Technology 
- Member 2: Pavithra Deepu E - Adishankara Institute of Engineering and Technology

### Project Description
Why write down your page number like a 15th-century monk when you can summon the power of React, Firebase and an ESP32? This marvel of modern overengineering exists solely to show you the page number of a book where you could easily just use a piece of paper or fold the corner as a bookmark.

### The Problem (that doesn't exist)
Remembering your page number is too basic. Bookmarks are boring, and folding pages is a crime. Clearly, what we need is a smart, Firebase-connected, ESP 32-powered solution.

### The Solution (that nobody asked for)
Slap an ESP32 into a breadboard, connect it to Firebase, build a Web app, and voilà 🎉 your page number is now in the cloud. Totally unnecessary, wildly overengineered, and somehow... beautiful.

## Technical Details
### Technologies/Components Used
For Software:
- HTML
- CSS
- JavaScript
- Firebase DB
- Firebase Hosting

For Hardware:
- ESP 32
- I2C OLED
- [List specifications]
- Wirecutter
- Wirestripper

### Implementation
For Software: 
# Installation
git clone https://github.com/pavithradeepue/Chumma_Counter
cd Chumma_Counter
firebase use --add

# Cloud Deployement
firebase init hosting
firebase deploy

# Run
firebase emulators:start
Use our website: https://chumma-counter.web.app/
# Hardware
Connect the circuit following the schematic.
Program ESP 32 using microcode.cpp

### Project Documentation
For Software:

# Screenshots (Add at least 3)
<img width="1908" height="932" alt="Screenshot 2025-08-02 033414" src="https://github.com/user-attachments/assets/fb6f84a3-b0a5-4f86-b5f3-fff9241ae3cf" />
Our website Hosted on firebase

![HardWare_Demo_1](https://github.com/user-attachments/assets/a4636304-9fc8-40b8-8ef2-83f81c7f0f25)
![HardWare_Demo_3](https://github.com/user-attachments/assets/8205322e-f313-4dee-b802-0b71c24e5873)

Our Hardware

https://github.com/user-attachments/assets/8b93487f-c3c7-4b65-9932-696206be8f62


# Diagrams
<img width="626" height="348" alt="image" src="https://github.com/user-attachments/assets/6bfc22bc-fcb9-4ed8-850c-3d92e5f609e4" />
Our system Uses a ESP 32 take input from the user (It is a  counter with 3 inputs Increment,Decrement and Upload). When the upload is Pushed the value is send to the Firebase DB . Then Our front end displays it (In the front end there is no way to modify the value only to view it). The Front end is hosted on Firebase. 

For Hardware:

# Schematic & Circuit
<img width="680" height="420" alt="circuit" src="https://github.com/user-attachments/assets/5997430a-d354-4c48-9063-1e827dc03e47" />
<img width="1076" height="750" alt="Schematic" src="https://github.com/user-attachments/assets/1daa2f7f-f925-4c03-b5a0-db365196a52d" />

We use a ESP-32 with a I2C oled display and 3 push buttons (Increment,Decrement,Upload), The esp keeps a counter which gets initilialized with a value from DB and When pressed upload it uploads it to the DB


# Build Photos

Early Hardware:
![WhatsApp Image 2025-08-02 at 04 53 01_7b422a61](https://github.com/user-attachments/assets/1eff00e6-b033-48a2-becd-4ece27b0094d)
![WhatsApp Image 2025-08-02 at 04 53 00_018faba6](https://github.com/user-attachments/assets/9605fd75-c145-4be0-a2ec-94972a29302b)
Early Software:
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/1aba49c0-18d7-4b48-9882-357bc7703c72" />
We started building our hardware first then Our Database. after getting both to be running perfectly we built the front end website 

Final Build:
![HardWare_Demo_3](https://github.com/user-attachments/assets/1184edbc-5d28-4d20-9823-69b06cd5d140)
<img width="1908" height="932" alt="Screenshot 2025-08-02 033414" src="https://github.com/user-attachments/assets/b1ffff49-b2c2-4f54-85e6-92ae1ce3364c" />


### Project Demo
# Video

https://github.com/user-attachments/assets/237230d2-3fd6-4d26-861a-8fc400181682


# Additional Demos
https://github.com/pavithradeepue/Chumma_Counter/tree/main/Gallery

## Team Contributions
- Gokul P: Hardware I+ntegration, Frontend 
- Pavithra Deepu E: Frontend, Decoration

---
Made with ❤️ at TinkerHub Useless Projects 

![Static Badge](https://img.shields.io/badge/TinkerHub-24?color=%23000000&link=https%3A%2F%2Fwww.tinkerhub.org%2F)
![Static Badge](https://img.shields.io/badge/UselessProjects--25-25?link=https%3A%2F%2Fwww.tinkerhub.org%2Fevents%2FQ2Q1TQKX6Q%2FUseless%2520Projects)


