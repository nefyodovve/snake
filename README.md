# Snake game implementation in C
## Usage

Make sure you have installed ncurses library!

`$ make all`

`$ ./snake`

Default size of field is 15x10, can be redefined in 'snake.h' file. 
You can pass 2 integers as arguments to program, they will be used as new width/height (min is 5x5).

Use arrows or wasd to move, space or 'p' for pause, and 'q' for quit.

## How it works

Field is a 2-dim array of enum e_cell. Its elements can be: EMPTY, EDGE, BODY, HEAD, FOOD. They used to determine what symbol will be used to represent the field. I used ' ', '#', 'o', '0' and '@'.

Snake is a linked list (data is x and y). Each time we want to move, we push_front a new element with updated coordinates. Then we delete last element of list, and don't do it, if new coordinates point to FOOD.

Game is over when snake's head encounters its BODY part or field's border (EDGE). When food is eaten, speed of game increases.

Main loop content:
1. Get user's input.
2. If it's quit key, then quit, if it's pause, swap pause flag.
3. If game is not over and not paused:
   1. Check if user wants to move.
   2. If he does, check if he wants to move opposite direction. Don't move if he does.
   3. Pass move direction to snake. It can be no-move.
   4. Snake handles movement command, and returns result, if it's eaten FOOD, or smashed into EDGE or itself, or move was ok.
   5. Perform auto-move command. Same function as user-move, but using direction from previous moving command. Auto-move proceeds every specific time interval. Default - decreases from 1 sec to 300 ms whenever FOOD is eaten.
   6. Check if we got some FOOD. Increase length counter, update snake's move result. Place new food to field (get random value from 0 to EMPTY count, and place it there). Game over (win) if we have no space to place FOOD.
   7. Check if game over (smashed), change flag. Update previous input.
   8. Display field and snake on the screen.
	  1. Clear field from snake, keep food. We need this to remove tail.
	  2. Update field with snake's coordinates (loop over whole body).
	  3. Show field's array on the screen, by char. May be I can add some colors here.
	  4. Show additional info.
	  
Feel free to email me if you have some questions. This project had been done for educational purposes, I don't mind if you want to use any part of this code.
