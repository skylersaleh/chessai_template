# Chess AI tournament template
This repo contains a template project for use in developing chess engines for the Chess AI Competition.
It implements the UCI protocol and basic board management boilerplate allowing for the users chess engine 
to be used in any chess program that supports UCI engines. Such as Xboard or Winboard.

For example purposes this AI implements the following simple algorithm:
- If there is any valid move to attack the opponents piece, perform the move that takes the most valuable piece. 
- If a valid move can't attack an opponents, do a random valid move. 

To build: 
```
mkdir build && cd build
cmake ..
cmake --build . 
```

To test configure Xboard (or another chess program) to utilize this as an engine. 

# Credits

Much of the boilerplate from this template was adapted from: https://github.com/fogleman/MisterQueen
Which is licensed under an MIT license. 
