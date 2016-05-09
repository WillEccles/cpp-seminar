# Hangman

This project is a hangman game using colors, like the 2048 game, that reads words from a list in a text file and picks a random one for the user to guess at. You have to press a letter and then press enter, and from there the program will tell you if you are right, if you have already guessed that letter, or if you're wrong. It also prints a nice picture of a man hanging, which serves as the countdown for how many wrong guesses you've taken and have left.

## Files in this project:

*(Click on a file name to view its code, or scroll below for more information.)*

| File | Description |
| --- | --- |
| [`main.cpp`](code/main.cpp) | This file handles all of the game's logic. |
| [`IOManager.h`](code/IOManager.h) | Declares the IOManager class and all its members. |
| [`IOManager.cpp`](code/IOManager.cpp) | Handles file/console IO. |

# How does it work?

First, it picks a random word from a text file. It then shows that as blanks, whereupon the user guesses random words. This works just like the old paper version, so I shouldn't have to explain how hangman works.

# `main.cpp`

This handles all of the logic for the game, meaning parsing guesses, turning words into blanks, showing all the text, and so on.

**The Logic:**

It starts off by storing the word. Then, it shows it as a bunch of blanks and waits for user input. It stores each guess in a vector, without duplicates. If the user already guessed the letter, there is no penalty, it simply shows the user that they have already guessed it. If they haven't and it *is* in the word, the blanks corresponding to that letter are replaced with that letter and the blanks are displayed again. If they haven't guessed it and it's *not* in the word, it will tell them that and add another piece to the hangman. Once the hangman is fully made, they will lose. If they guess the whole word before then, then they win!

# `IOManager.h` and `IOManager.cpp`

The `IOManager` class handles all file and console IO. It is adapted from my standard library's `iofuncs` namespace, which can be found [here](https://github.com/WillEccles/wrestd/blob/master/Code/wrestd.h).

**`IOManager.h`**

This is the header file for the `IOManager` class. This declares all methods and variables defined in the class, and also defines all the color codes for printing in colors.

**`IOManager.cpp`**

This class defines all of the methods and variables in the `IOManager` class. This handles everything from getting a random word to printing to the console in colors. This is equivalent to the [`iofuncs.cpp`](https://github.com/WillEccles/wrestd/blob/master/Code/iofuncs.cpp) file in my library.
