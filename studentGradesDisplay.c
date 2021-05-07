#include <stdio.h>
/* 
 * Global structures to store student name, final results (Pass/Fail)
 * total marks scored 
 */
struct grades
{
    char name[101];
    // Value of 1 indicates PASS and 0 FAIL
    unsigned final;
    unsigned total;
};

// Function to display the passed students and class average
void printPassedAverage(struct grades myClass[25], int size);

int main()
{
    // List or array of structures to store class results
    struct grades myClass[25];

    // Used to read a character to clear the input buffer
    char temp;
    unsigned flag, i;

    flag = 1; // Loop termination flag 

    // Total number of students in class
    int numStudents;
    
    // Read the student name, final result and total mark for the class
    // of students
    printf ("Enter the details of students in the class\n");
    while(flag == 1)
    {
            printf ("Enter the number of students: ");
            scanf ("%d", &numStudents);
            //printf ("%d", numStudents);
            if (numStudents > 25)
            {
                    printf ("Total number of students in the class cannot exceed 25!!");
                    continue;
            }
            flag = 0;
    }

    printf ("Enter student details of the class\n");
    for (i=0; i < numStudents; i++)
    {
            printf ("\nEnter details of student %d:\n",i+1);
            // Clear the buffer to read the string with spaces for the student name
            scanf("%c",&temp);
            printf ("Enter the name: "); 
            scanf ("%[^\n]", myClass[i].name);
            //fgets(myClass[i].name, 101, stdin);

            flag = 1;
            while (flag)
            {    
                printf ("Enter the final result (1 - PASS, 0 - FAIL): ");
                scanf ("%u", &myClass[i].final);
                if ((myClass[i].final != 0) && (myClass[i].final !=1))
                        continue;
                flag = 0;
            }
            printf ("Enter the total marks: ");
            scanf ("%u", &myClass[i].total);
    }

    printf ("\n\nDetails of students:");
    for (i=0; i < numStudents; i++)
    {
        printf ("Student %d\n", i+1);
        printf ("Name: %s\n",myClass[i].name);
        printf ("Final Result: %u\n",myClass[i].final);
        printf ("Total Marks: %u\n",myClass[i].total);
    }

    // Display the list of students who have passed the course in the class
    printPassedAverage(myClass, numStudents);


    return 0;
}

// Function to display the passed students and class average
// Input - Student details of the class and size of class
// The function checks final result of each student and prints the 
// details of passed students (name and total marks) and class average
// at the end.
void printPassedAverage(struct grades myClass[25], int size)
{

    unsigned i;
    unsigned totalPassed = 0;
    unsigned totalMarks = 0;
    printf ("\nStudents Passed:\n");
    printf ("------------------\n");
    for (i=0; i < size; i++)
    {
        if (myClass[i].final == 1)
        {
                printf ("%s  %u\n", myClass[i].name, myClass[i].total);
                totalMarks = totalMarks + myClass[i].total;
                totalPassed = totalPassed + 1;
        }

    }
    printf ("Class Average: %u\n", totalMarks/totalPassed);
                    
}
 
