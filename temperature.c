#include <stdio.h>
int main()
{
    int temp; 
    printf("give temp in Celcius, give an integer: "); 
    scanf("%d", &temp); //saves to address of temparture variable 
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
}