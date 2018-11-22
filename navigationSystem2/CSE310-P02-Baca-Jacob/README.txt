This program was written in C++. It is an implementation of a Priority Queue. 

Written by: Jacob Baca
Email: jbaca6@asu.edu


How To Use the Program:

On reading S, the program stops.

On reading C n, the program creates an empty heap with capacity equal to n, and waits for the next command.

On reading R f, the program reads in the array A from file HEAPinput.txt, calls the linear time build heap algorithm to build the max-heap based on A, with flag set to f, and waits for the next command.

On reading W, the program writes the current heap information to the screen, and waits for the next command. The output should be in the same format as in the file HEAPinput.txt, proceeded by the heap capacity.

On reading I k f, the program inserts an element with key equal to k into the current heap with the corresponding flag set to f, and waits for the next command.

On reading D f, the program deletes the maximum element from the heap with the corresponding
flag set to f, and prints the key field of the deleted element on the screen, it waits for the next command.

On reading K i v f, the program increases the key of element with index i to v with the corresponding flag set to f.

