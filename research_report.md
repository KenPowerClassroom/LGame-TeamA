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
Each player takes a turn moving their L piece. After making their move, they then have the option to move any of the two neutral pieces to an unoccupied space. The game is won if either player cannot move their L piece to a new position.

During the player's turn their L-shape cannot be in the same space as the other player's L-shape or any space a neutral piece occupies. The player can move its coloured L-piece on an empty space and it can be rotated or flipped over. The gimmick of this game is that the L-shape must be in a different space from where it started. A legal move can contain previously occupied spaces of that player, as long as one new space is empty. You cannot move your piece somewhere outside of the board. To move the neutral piece, simply pick up the neutral piece then move it to an empty space anywhere on the board.

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
