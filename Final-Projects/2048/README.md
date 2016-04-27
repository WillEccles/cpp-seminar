# 2048

This is a working, colored version of 2048 in the console, made in C++ (obviously). It's **NOT** cross-platform, since it requires Windows headers to use the arrow keys. My Hangman program is cross-platform, however, since it requires nothing of the sort.

It can save your game, load your game, etc.

You use the arrow keys to control the game.

*(work in progress)*

### Files in this project:

*(Click on a file name to view its code, or scroll below for more information.)*

| File | Description |
| --- | --- |
| [`main.cpp`](code/main.cpp) | This is the main gameplay code, handling all of the game logic. |
| [`IOManager.h`](code/IOManager.h) | Declares IOManager class. IOManager handles all IO operations. |
| [`IOManager.cpp`](code/IOManager.cpp) | Defines IOManager class. Handles all IO operations. |

## How does the game work?

First, it picks two random boxes and puts either a 2 or a 4 there, with a higher chance of a 2. Each time you press an arrow key, all boxes shift that way if possible. Then can only group with others of their kind, so a 2 with a 2, etc. The objective is to get to the 2048 tile, where the game will end and you win. You lose if you do not get there but cannot make any more moves. When you close the game, it will save where you are and load it next time.

## `main.cpp`

This class handles all the logic for the game. It will load the game when you start, handles all key presses, and so on.

## `IOManager.h` & `IOManager.cpp`

This class handles all IO operations, including file IO. The reason this class was invented was so that I could use it in other projects and have access to the same methods everywhere. I am currently making a library for myself that contains all of my custom classes, and you can find that [here](https://github.com/WillEccles/wrestd).

This will allow me to print in colors, clear the console, and other things like that easily. It's not Windows-only, but with a catch: you will not be able to print in color on other platforms. This does use Windows headers, but since I made this code nice, it will just ignore that and print in normal colors on other platforms.
