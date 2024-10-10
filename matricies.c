// Author: Eliza Malyshev 
// KUID: 3122318
// Date: 10/10/2024 
// Lab: #5.2
// Purpose: make and manipulate 2D arrays 
#include <stdio.h> 
#define SIZE 5 

int addMx(int m1[], int m2[])
{
    
    return 0;    
}

int multMx(int m1[], int m2[])
{

    return 0;    
}

int transMx(int m1[], int m2[])
{

    return 0;    
}

int printMx(int m1[], int m2[])
{

    return 0;    
}

int main()
{
    int m1[SIZE][SIZE]; 
    int m2[SIZE][SIZE]; 
    for (int i=0; i<SIZE; i++)
    {
        int temp[SIZE]; 
        printf("give row %d of matrix, with each integer seperated by spaces: ", i+1); 
        for (int j=0; j<SIZE; j++) //will read each int seperatley becuase white space seperates them 
        {
            scanf("%d", &temp[j]); 
        }
    }
    
    

//     printf("array: ");
//     for (int i=0; i<SIZE; i++) 
//     {
//         printf("%d ", temp[i]);
//     }
//     return 0;    
}