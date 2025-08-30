/* Task description:
Convert to upper case

Write a program that converts all lower case latin letters in a text file to uppercase. Write the result to an other file called "output.txt". Display an error message in case opening the files was not successful.

To test the program, use lorem.txt, execute the program. Then, open "output.txt" with nano, and check whether its content is correct.

Hint
Detecting and handling the end of file properly is often a critical issue in a file processing program. There are two options to choose from:

    >Based on the return value of fscanf: Remember that fscanf returns the number of data successfully obtained from the file - if it is less than expected, than probably the end of file has been reached.
    >Based on feof: The feof function can also be used to detect the end of a file. But there is a catch. feof returns false even after reading the last data from the file. It becomes true only after the next read attempt, that failed due to the end of file. Thus, its value has to be checked after every read attempt and the data processing needs to be stopped when it returns false.



*/


#include <stdio.h>

int main(){


  return 0;
}
