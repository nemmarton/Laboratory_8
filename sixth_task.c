/*
Task:
Write a C program tho manage job assignments. Each job assignment has

    a unique identifier (an integer number),
    the name of the employee who has to do the job (max. length: 100 characters),
    the description of the job (max. length: 200 characters),
    and a status, which is a 1/0 value indicating that the job is done or not done yet.

The file containing job assignments starts with an integer number, representing the total number of jobs in the file, then the members of the structure follow each other in separate lines.

The C code below creates a structure to represent job assignments, and loads job assignments from file "jobs.txt" into a dynamic array.

Note that we used fgets to read the name and the description, to allow spaces. Since fgets keeps the newline character and the end of the line, we had to remove it manually.

The tasks are as follows.

    ->Write a function to print all jobs assigned to "Joe"
    ->Set the status of all jobs assigned to "Joe" to 1.
    ->Save the modified data to "jobs2.txt".


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[101];
    char descr[201];
    int status;
} job;

int main () {
    FILE* infile;   // file handle
    job* a;         // start address of the dynamic array    
    int N;          // number of elements in the dynamic array
    int i;          // auxiliary variable for loops
    
    // open file
    infile = fopen("jobs.txt","r");
    if (infile==NULL) {
        printf("Cannot open jobs.txt\n");
        return 1;
    }
    
    // load the content of the file into a dynamic array
    fscanf(infile, "%d", &N);   // first integer is the number of items
    a = (job*)malloc(sizeof(job)*N);
    for (i = 0; i < N; i++) {
        fscanf(infile, "%d\n", &a[i].id);
        fgets(a[i].name, 101, infile);       // we use fgets to allow space characters in the name
        a[i].name[strlen(a[i].name)-1] = '\0'; // last newline character is deleted
        fgets(a[i].descr, 201, infile);        
        a[i].descr[strlen(a[i].descr)-1] = '\0';
        fscanf(infile, "%d\n", &a[i].status);
    }
    fclose(infile);
 
    free(a);
    return 0;
}
