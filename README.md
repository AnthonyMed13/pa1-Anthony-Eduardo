# PA1: Openframeworks Audiovisualizer
The objective for this first project is to complete this audiovisualizer with the help of OpenFrameworks!

# What it can do out of the box
After compiling and running the project for the first time, you should be able to do a couple of things:

- Using the "A" key, you should be able to play and pause music from "beat.wav" 
- Using different number keys, you can visualize the music in different ways:
    - 1: Rectangle Height Visualizer
    - 2: Circle Radius Visualizer
    - 3: Rectangle Width Visualizer (to be implemented)
    - 4: Custom Visualizer (to be implemented)
    
- Using different keys, you can change the music in different ways:
    - 1: By pressing the ’D’ key, the music will be changed to ’beat.wav’
    - 2: By pressing the ’O’ key, the music will be changed to ’geesebeat.wav’
    - 3: By pressing the ’L’ key, the music will be changed to ’pigeon-coo.wav’
    - 4: By pressing the ’K’ key, the music will be changed to ’rock-song.wav’

- Using different symbol keys, you can change the volume of the music in different ways:
    - 1: Use ’=’ for raising volume
    - 2: Use ’-’ for lowering volume

- Pressing the ‘R’ key will start recording all the keys pressed afterwards in order until it is pressed again as indicated by the sudden appearance of "RECORDING".

- Pressing the ‘T’ key will replay all the recorded keys and their
associated actions at fixed intervals as indicated by the sudden appearance of "REPLAYING".

- Pressing the ‘C’ key cancels a playing replay.

# Classes
This project contains two classes that should be of your concern: ofApp and AudioVisualizer.

## ofApp
This is the class that brings most things together. Here, you will find the code that causes the audio to play and pause. It is also to where the visualization happens. Here, you can observe how the code to change between modes works, and how the song is actually played. 

## AudioVisualizer
The AudioVisualizer class provides us with the data needed to do the visualization. Using some of the tools OpenFrameworks provides us and math, we can obtain information such as the amplitude of the sound. 