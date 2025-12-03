Assignment 2 – Part 1: Game Analysis
#Overview
This repository is a fork of the original game given by the teacher.  
My task in Part 1 was to study how the game works, understand the code structure, and explain the logic before making changes.


#Original Game Summary
The game is a small console-based C program.

- The player moves using number input.
- Obstacles appear and move toward the player.
- If the player touches an obstacle, the game ends instantly.
- Everything is shown using printf inside loops.


#Game Flow, Logic & Implementation

1. Game Flow
- The game starts, variables are set, and the screen is prepared.
- A loop runs repeatedly to update the game.
- Each loop:
  - reads the player's movement,
  - moves obstacles,
  - checks for collision,
  - and redraws the screen.
- If a collision happens → the loop stops → game over.

2. Logic
- Positions are stored as simple variables and updated every cycle.
- Obstacles move automatically across the screen.
- Collision is checked by comparing the player's position with obstacle positions.
- The game uses basic conditions and loops to control everything.

3. Implementation Details
- Written in pure C with no external libraries.
- Uses while() loops for constant game updates.
- Uses if() statements for decisions (like movement and collision).
- Uses printf() to show the game board frame by frame.
- All code is inside one file and mostly inside main.

#C Concepts Demonstrated
- Arrays and pointers to store game state.  
- Loops for continuous game updates.
- Conditions for collision and game rules.  
- Functions to organize the code.  
- Basic terminal input/output.
