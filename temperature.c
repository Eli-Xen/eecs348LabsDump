// Author: Eliza Malyshev 
// KUID: 3122318
// Date: 10/3/2024 
// Lab: #5.2
// Purpose: display different weather warnings based on temperature 

#include <stdio.h>
float c2f(float celsius) 
{
    return (celsius*9.0/5.0)+32;
}
float f2c(float fahrenheit) 
{
    return (fahrenheit-32)*5.0/9.0;
}
float c2k(float celsius) 
{
    return celsius+273.15;
}
float k2c(float kelvin) 
{
    return kelvin-273.15;
}

void categorize(float temp) 
{
    if(temp<0)
    {
        printf("freezing:wear a thick jacket if you go out \n");
    }
    else if(temp>=0 && temp<10) //has to be seperate statments or else it just reads that num>=10000 is 0 or 1 and compares that to 26000 (if dont 10000<=num<26000)
    {  
        printf("cold: wear a sweater or long sleeves \n");
    }
    else if(temp>=10 && temp<25)
    {  
        printf("comfortable: its good weather out \n");
    }
    else if(temp>=25 && temp<35)
    {  
        printf("hot: wear short sleeves and sunscreen \n");
    }
    else if(temp>=35)
    {  
        printf("extreme heat: avoid going outdoors \n");
    }
    else
    {
        printf("invalid input");
    }
}

int main()
{
    float temp; 
    int tempType; 
    int tempConvert; 
    printf("1 celcius \n2 kelvin \n3 farenheight\ninput an integer for coresponding tempterature: ");
    scanf("%d", &tempType);
    printf("give temp: "); 
    scanf("%f", &temp); //saves to address of temparture variable 
    if (tempType==2 && temp<0) 
    {
        printf("kelvin cannot be negative, try again"); 
        //something to make them enter input again 
    }
    printf("1 celcius \n2 kelvin \n3 farenheight\ninput an integer for what you want to convert to: "); 
    scanf("%d", &tempConvert);
    
    switch(tempType) //this converts whatevery they gave us (C/K/F) into celcius so we can put it into function
    { 
        case 1: 
            categorize(temp); 
            break; //we do nothing since we are aledy in Kelvin
        case 2:
            temp=k2c(temp);  
            categorize(temp); 
            temp=c2k(temp); //converts back so we dont mess up values 
            break; 
        case 3: 
            temp=f2c(temp); 
            categorize(temp); 
            temp=c2f(temp); 
            break; 
        default: //if nothing else mathces to the variable given (like the last else statement)
            printf("you gave bad input when we asked Celcius, kelvin or farenheight\n");
    }

    if ((tempType==1 && tempConvert==1) || (tempType==2 && tempConvert==2) || (tempType==3 && tempConvert==3)) 
    {
        printf("you are trying to convert to the temparture type you are already in"); 
    }
    else if (tempType==1 && tempConvert==2)
    {
        printf("converted temperature %f", c2k(temp)); 
    }
    else if (tempType==1 && tempConvert==3)
    {
        printf("converted temperature %f", c2f(temp)); 
    }
    else if (tempType==2 && tempConvert==1)
    {
        printf("converted temperature %f", k2c(temp)); 
    }
    else if (tempType==2 && tempConvert==3)
    {
        float a=k2c(temp); 
        a=c2f(a); 
        printf("converted temperature %f", a); 
    }
    else if (tempType==3 && tempConvert==1)
    {
        printf("converted temperature %f", f2c(temp)); 
    }
    else if (tempType==3 && tempConvert==2)
    {
        float b=f2c(temp); 
        b=c2k(b); 
        printf("converted temperature %f", b); 
    }

    return 0; 
}