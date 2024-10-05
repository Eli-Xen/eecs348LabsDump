// Author: Eliza Malyshev 
// KUID: 3122318
// Date: 10/3/2024 
// Lab: #4.1
// Purpose: find NFL scoring combinations using C

#include <stdio.h>
// int* comb(int score)
// {
//     int* arr=(int*)malloc(6*sizeof(int)); //according to example we only need 6 numbers for output so alocate enough space for 6 ints
//     printf(score); //do stuff to fill array, maybe do 2d array for all combinations 
//     return arr; //return pointer to array 
// }

int comb(int score) //this function will try all combinations and will print the combinations that equal the score 
{
    int td2, td1, td, fg, sfty; //initializes varibles for touchdown+2/+1+0, feild goal and saftey 
    printf("combinations of scoring %d\n", score); 
    for (td2=0; td2*8<=score; td2++) //this will add 8*i every time it loops until it surpasses the score 
    {
        for (td1=0; (td2*8+td1*7)<=score; td1++) //not it does 8*i+7*j so that every time it loops it tries adding different incriments 
        {
            for (td=0; (td2*8+td1*7+td*6)<=score; td++) //we keep adding other types of goals with thier point amounts...
            {
                for (fg=0; (td2*8+td1*7+td*6+fg*3)<=score; fg++) //...so that each is incrimented by the loop they are at...
                {
                    for (sfty=0; (td2*8+td1*7+td*6+fg*3+sfty*2)<=score; sfty++) //...until the addition of all the incriments surpasses or equals the score 
                    {
                        if ((td2*8+td1*7+td*6+fg*3+sfty*2)==score) //if this combination equals the score then print it 
                        {
                            printf("%d TD+2pt, %d TD+FG, %d TD, %d FG 3pt, %d Saftey 2pt\n", td2, td1, td, fg, sfty); 
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int score; 
    while(1)
    {
        printf("enter 1 or 0 to stop\n"); 
        printf("enter NFL score integer: ");
        scanf("%d", &score); //saves score to address of variable 
        if(score<=1)
        {
            break; 
        }
        else
        {
            comb(score); //function call to find all combinations 
        }
        
        // int* array; //pointer to array that will hold values for score combos 
        // array=comb(score); //passes score so that comb can find all combinations 
        // free(array); //frees space that array was allocating so that we dont cause memory leak 
    }

    return 0; 
}