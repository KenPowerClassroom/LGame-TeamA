# Minimal Viable Product (MVP) 

## Outline MVP functionality

The simplest version of the game lets the player play a command line version of the game. The
player is able to input 4 positions in the grid and the game will check if this move is legal 
depending on if they moved into a space occupied by the other player or if their piece now occupies
a position not in the grid. The player has to move their piece to include at least one new position
to not lose the game. The player will then be given the option to move one of the neutral pieces.
They can press either 1 or 2 to select the piece they want to move or any other number to not move
either piece. Once their turn is over the computer will take its turn automatically.
The game will check if the game is over or not and if it is the game will allow the player 
to play the game again and will tell the player if they or the computer won the game.
For the minimum viable project, the ai will not move neutral pieces. To move its piece it will search the grid for any available spaces. If it finds an empty spacce it will check if
it is able to move into that space, it will only be able to move into it if it is adjacent to one of its current pieces and wont intersect any other pieces or go outside the bounds
of the grid.
To display the grid to the player with the ASCII art, ----- and ¦¦¦¦¦ will be used to represent the borders of the board. These will be drawn around the board so that the player
will be able to easily recognise individual spaces in the grid. A 1 will be used to represnt a single square of the players piece. 2's will
 be used to represent a single square of the AI's piece.
N1 will be used to represent neutral piece 1
and N2 will be used to represent neutral piece 2.

## List the features of the MVP
- feature1
- feature2
- ...

## Out Of Scope

Explicity describe what is not part of MVP


## List of stories needed to complete the MVP `aim for 8 stories`

1. `Example story` Display board

As a player I need to be able to see the current board configuration so that I can understand my position and figure out my next move.

2. Story-name

As a user `usually player, but can be developer` I need to be able to `do something` so that I can `complete and objective`.


