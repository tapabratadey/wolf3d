# Wolf3d

![DEMO](https://user-images.githubusercontent.com/12387917/43370278-fe02556a-9330-11e8-9207-9ad744830d5e.gif)

An implementation of the famous John Carmack’s and John Romero’s video game Wolfenstein 3D which was the first FPS ever. The goal of the projects was to write the game in C using the ray casting technique, a 3D representation of a maze in which a player can find his/her way. Ray casting is a rendering process to create 3D world from a 2D map. Wolfenstein 3D was the first video game ever implemented in the fast ray casting rendering because in this procedure calculation has to be done for every vertical line of the screen. For this project, I used the “Digital Differential Analysis” algorithm which is usually implemented on squares to find which square a line hits, for example, to draw a line on a screen, which is a grid of square pixels. The concept is to generate rays and to figure out which squares of the map the rays hit and mark that square as a wall.</br>

Steps to run the Wolf3d-</br>
Copy and paste the following two lines in your terminal</br>

git clone https://github.com/tapabratadey/Wolf3d.git</br>
cd wolf3d2.0 && sh run.sh</br>

Movements:</br>
Up: W</br>
Down: S</br>
Right: D</br>
Left: A</br>
Esc: To quit the game</br>
