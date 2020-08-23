//
//  main.c
//  NortonCodingChallenge
//
//  Created by Nirpeksh Tomar on 18/08/20.
//  Copyright © 2020 Nirpeksh Tomar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1000

// Please edit the path according to your needs
#define PATH_OF_FILE "/Users/nirpekshtomar/Workspace/git_workspace/norton_coding_challenge/NortonCodingChallenge/data_collected_by_standard_input_stream.txt"

/*
* Function: writeToFile
* ----------------------------
*   Writes the data from input stream to file.
*   Returns 0 if successfull.
*/
int writeToFile()
{
    // Buffer variable to read data from standard input stream
    char data[BUFFER_SIZE];
    
    // File pointer to hold reference to our file
    FILE * fptr;
    
    // Open file in w (write) mode.
    fptr = fopen( PATH_OF_FILE, "a");
    
    // fopen() return NULL if last operation was unsuccessful
    if(fptr == NULL)
    {
        // File not created hence exit
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Enter contents to store in file : \n");
    fgets(data, BUFFER_SIZE, stdin);
    // Write data to file
    fputs(data, fptr);
    
    // Close file to save file data
    fclose(fptr);
    
    // Success message
    printf("File created and saved successfully. :) \n");
    return 0;
}


/*
* Function: readFromFile
* ----------------------------
*   Reads the data from file and print it on console.
*   Returns 0 if successfull.
*/
int readFromFile()
{
    FILE * fptr;
    char ch;
    fptr = fopen(PATH_OF_FILE, "r");
    // fopen() return NULL if last operation was unsuccessful
    if(fptr == NULL)
    {
        // Unable to open file hence exit
        printf("Unable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        exit(EXIT_FAILURE);
    }
    // File open success message
    printf("File opened successfully. Reading file contents character by character. \n\n");

    do
    {
        // Read single character from file
        ch = fgetc(fptr);

        // Print character read on console
        putchar(ch);

    } while(ch != EOF);
    // Done with this file, close file to release resource
    fclose(fptr);
    return 0;
}


/*
* Function: removeFile
* ----------------------------
*   Delete the file.
*/
int removeFile()
{
    int del = remove(PATH_OF_FILE);
    if (!del)
       printf("The file is Deleted successfully");
    else
       printf("the file is not Deleted");
    return 0;
}

int main(int argc, const char * argv[]) {
    
    int flag = 1;
    do
    {
        int choice;
        printf("\nPlease make a choice :\n");
        printf("1 . Press 1 for write data into the file.\n");
        printf("2 . Press 2 for read data from the file.\n");
        printf("3 . Press 3 to remove file.\n");
        printf("4 . Press 4 for Exit.\n");
        scanf("%d", &choice);
        fflush (stdin);
        switch(choice)
        {
            case 1 :
                writeToFile();
                break;
            case 2 :
                readFromFile();
                break;
            case 3 :
                removeFile();
                break;
            case 4 :
                flag = 0;
                break;
            default:
                printf("Please select a valid choice\n");
        }
    }while(flag);
    
    return 0;
}
