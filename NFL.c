#include <stdio.h>
// int* comb(int score)
// {
//     int* arr=(int*)malloc(6*sizeof(int)); //according to example we only need 6 numbers for output so alocate enough space for 6 ints
//     printf(score); //do stuff to fill array, maybe do 2d array for all combinations 
//     return arr; //return pointer to array 
// }

int comb(int score) 
{
    int td2, td1, td, fg, sfty; //initializes varibles for touchdown+2/+1+0, feild goal and saftey 
    printf("combinations of scoring %d\n", score); 
    for (td2=0; td2*8<=score; td2++) 
    {
        
    }
}

int main()
{
    int score; 
    int loop=1; 
    while(1)
    {
        printf("enter 1 or 0 to stop");
        printf("enter NFL score integer less than 100 (realistically feasable): ");
        scanf("%d", &score); 
        if(score<=1)
        {
            break; 
        }
        else
        {
            comb(score); //function call to find all cmbinations 
        }
        
        // int* array; //pointer to array that will hold values for score combos 
        // array=comb(score); //passes score so that comb can find all combinations 
        // free(array); //frees space that array was allocating so that we dont cause memory leak 
    }
}