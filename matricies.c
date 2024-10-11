// Author: Eliza Malyshev 
// KUID: 3122318
// Date: 10/10/2024 
// Lab: #5.2
// Purpose: make and manipulate 2D arrays 
#include <stdio.h> 
#define SIZE 5 

int (*addMx(int m1[SIZE][SIZE], int m2[SIZE][SIZE]))[SIZE] //this declaration will return a pointer of SIZE; add corresponding entries of two matricies and return matrix of added matricies 
{
    static int added[SIZE][SIZE]; 
    printf("matrix 1 looks like:\n"); //prints 2D array in pretty format 
    for (int i=0; i<SIZE; i++) 
    {
        for (int j=0; j<SIZE; j++) 
        {
            added[i][j]=m1[i][j]+m2[i][j]; //add corresponding entries and put them into added array 
        }
        printf("|\n");
    }  
    return added; //returns pointer to added matrix 
}

int multMx(int m1[SIZE][SIZE], int m2[SIZE][SIZE])
{

    return 0;    
}

int transMx(int m1[SIZE][SIZE], int m2[SIZE][SIZE])
{

    return 0;    
}

int printMx(int m1[SIZE][SIZE], int m2[SIZE][SIZE])
{
    printf("matrix 1 looks like:\n"); //prints 2D array in pretty format 
    for (int i=0; i<SIZE; i++) 
    {
        printf("|");
        for (int j=0; j<SIZE; j++) 
        {
            printf("%d ", m1[i][j]);
        }
        printf("|\n");
    }  
    printf("matrix 2 looks like:\n"); //prints 2D array in pretty format 
    for (int i=0; i<SIZE; i++) 
    {
        printf("|");
        for (int j=0; j<SIZE; j++) 
        {
            printf("%d ", m2[i][j]);
        }
        printf("|\n");
    }  
    return 0;    
}

int main()
{
    int m1[SIZE][SIZE]; 
    int m2[SIZE][SIZE]; 
    for (int i=0; i<SIZE; i++) //goes through each row of matrix 1... 
    {
        printf("give row %d of matrix 1, with each integer seperated by spaces: ", i+1); 
        for (int j=0; j<SIZE; j++) //...and for every column...
        {
            scanf("%d", &m1[i][j]); //...read each int seperatley becuase white space seperates them 
        }

    }

    int (*added)[SIZE]=addMx(m1, m2); //uses function pointer to call function and take return of pointer 
    printf("added matrix:\n");
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            printf("%d ", added[i][j]);
        }
        printf("\n");
    }

}