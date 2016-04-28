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

**The logic:**

There is an array of arrays (actually, I used vectors, but close enough - see [here](code/main.cpp#L39)) that is 4x4, which makes up the grid of numbers. Each number from 2<sup>1</sup> (2) to 2<sup>11</sup> (2048) has a defined color in a different list (see [here](code/main.cpp#L41)). First, it loads an old game from the file, or, if none was there, it makes a new one. It will then put a 2 or a 4 (3:1 odds for 2, 1:3 for 4 - code for that is [here](code/main.cpp#L443)) in two random tiles, and from there you just use the arrow keys to move the numbers around. This works just like the phone app, so you just play it like that. Each time you move the tiles, it will check to see which can move and which can't. If none can, you lose. If you can, it will move those that can and will combine those that can. The score (the total of all the tiles) is also counted, and then printed at the top of the screen in the color of the hightest tile on the screen. If you get to 2048, you win!

## `IOManager.h` & `IOManager.cpp`

This class handles all IO operations, including file IO. The reason this class was invented was so that I could use it in other projects and have access to the same methods everywhere. I am currently making a library for myself that contains all of my custom classes, and you can find that [here](https://github.com/WillEccles/wrestd).

This will allow me to print in colors, clear the console, and other things like that easily. It's not Windows-only, but with a catch: you will not be able to print in color on other platforms. This does use Windows headers, but since I made this code nice, it will just ignore that and print in normal colors on other platforms.
