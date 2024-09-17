# TODO
# Finish the field constructor
# Add simple AI to bot
# difficulty level and bot behaviour settings
# Normalize README



This is a simple console game of "Sea Battle".
Rules are easy:
You and your enemy (bot) have 10 ships, on a field of 10 by 10 squares.
There are 4 types of ships:
4 - deckers (they take 4 squares of space, each player has only 1 of this type)
3 - deckers (they take 3 squares of space, each player has 2 of this type)
2 - deckers (they take 2 squares of space, each player has 3 of this type)
1 - deckers (they take 1 square of space, each player has 4 of this type).

Ships have to be placed 1 square away from other ships (including diagonally).

Each player shoots on his turn. If they miss, the turn goes to second player, but if the strike - they shoot again.

Player always know if he hit or missed his shot.

The ship is considered sunken if every single one of its' decks are hit.

The game continues unless all ships of one of the players are sunken.

You can set your own board up/generate random/load the board from file.


