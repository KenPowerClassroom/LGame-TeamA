# The L-Game Research report 
## Introduction

### Who are we
- Joshua Dunne (Joshua-Dunne)
- Allexis Alvarico (AllexisAlvarico)
- Jack Malone (JackMalone1)
- Michał Krzyzanowski (MichalKrzyzanowski)

### What is the purpose of this document
The purpose of this document is to research the [L-Game](https://en.wikipedia.org/wiki/L_game) and try to re-create it.

### Why are we doing this project
It is part of our assessment in our [Software Engineering](http://itcarlow.akarisoftware.com/index.cfm/page/module/moduleCode/COMP%20H2218) module which is part of our [Course](https://www.itcarlow.ie/courses/type/undergraduate-cao-courses/computing-networking-courses/cw208.htm).

## Game description
The L game is a two-player game played on a board of 4×4 squares. Each player has a 3×2 L-shaped piece, and there are two 1×1 neutral pieces (normally represented by coins). These neutral pieces are placed at both the top left and bottom right corners of the game board. Both L pieces begin in the centre of the board.

![alt text](https://upload.wikimedia.org/wikipedia/commons/thumb/8/82/L_Game_start_position.svg/250px-L_Game_start_position.svg.png "Picture of Starting Board")

## Game rules
On each turn, a player must move their L-shape to an empty square and must not overlap with the opponent’s L-shape or the neutral pieces. The L-shape can be rotated or flipped over but the L-shape must end in a different position from it started from, hence covering at least one empty square to make it a valid move. After moving the L-shape, the player has an option to move one of the neutral pieces to an empty square, if not the opponent turn begins. The objective of the game is to leave your opponent without a legal move for their L-shape.

## Playing strategies
### Strategy 1
Blocking off a 3x3 grid in any corner of the board with your L-shape and your neutral piece. You can then manipulate the other neutral piece to decrease your opponent’s possible moves.

### Strategy 2
Dividing the grid in half. Control one of the halves and lock your opponent within the other half.

### Strategic Principles
- Always try to have your L-shape occupy a corner.
- Try to make sure a neutral piece is adjacent to your L-shape.

### Defensive Strategy
If your L-shape occupies three of the four squares in the centre of the grid, you can play almost forever. You can then wait until your opponent makes a mistake and capitalize on it.

Or your L-shape can occupy 2 of the four squares in the centre of the grid and no neutral pieces occupy any of the X's marked below:

![alt text](https://cdn.discordapp.com/attachments/650345344890175488/651180874120822806/Screenshot_3.png "Picture of wanted positions for the neutral pieces")
