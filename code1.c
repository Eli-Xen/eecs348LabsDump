// Author: Eliza Malyshev 
// KUID: 3122318
// Date: 10/3/2024 
// Lab: #5.2
// Purpose: display different weather warnings based on temperature 

#include <stdio.h>
int main()
{
    int temp; 
    int tempType; 
    printf("1 celcius \n2 kelvin \n3 farenheight\ninput an integer for coresponding tempterature: ");
    scanf("%d", &tempType);
    printf("give temp as integer: "); 
    scanf("%d", &temp); //saves to address of temparture variable 
    switch(tempType) //like if-else statment except it just finds what the variable given is equal to 
    { //this converts whatevery they gave us (C/K/F) into celcius 
        case 1: 
            temp=temp; 
            break; //we do nothing since we are aledy in Kelvin
        case 2:
            temp=temp-273.15; 
            break; 
        case 3: 
            temp=(temp-32)*(5.0/9.0); //(°F - 32) × 5/9 formula to convert farenheight to celcius 
            break; 
        default: //if nothing else mathces to the variable given (like the last else statement)
            printf("you gave bad input when we asked Celcius, kelvin or farenheight\n");
    }

    if(temp<0)
    {
        printf("freezing:wear a thick jacket if you go out");
    }
    else if(temp>=0 && temp<10) //has to be seperate statments or else it just reads that num>=10000 is 0 or 1 and compares that to 26000 (if dont 10000<=num<26000)
    {  
        printf("cold: wear a sweater or long sleeves ");
    }
    else if(temp>=10 && temp<25)
    {  
        printf("comfortable: its good weather out ");
    }
    else if(temp>=25 && temp<35)
    {  
        printf("hot: wear short sleeves and sunscreen");
    }
    else if(temp>=35)
    {  
        printf("extreme heat: avoid going outdoors ");
    }
    else
    {
        printf("invalid input");
    }

    return 0; 
}