Chess Test: We have the following method used in a chess game: boolean canMoveTo(int x,
int y). This method is part of the Piece class and returns whether or not the piece can move to
position (x, y). Explain how you would test this method.


Ans:

Testing Type #1: Extreme Case ValidationWe need to ensure that the program handles bad or unusual input gracefully. This means checking the following conditions

Test with negative numbers  r x and y Test with x larger than the widthTest with y larger than the heightTest with a completely full boardTest with an empty or nearly empty boardTest with far more white pieces than black
