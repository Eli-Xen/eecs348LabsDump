// Author: Eliza Malyshev 
// KUID: 3122318
// Date: 10/4/2024 
// Lab: #4.2
// Purpose: display different weather warnings based on temperature 

#include <stdio.h>

//all of these are functions to convert between different temperature types 
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

int typeTemp() //this will ge tthe kind of temperature the user will input, it will trap them in a loop until they give valid input 
{
    int tempType;
    do 
    {
        printf("1 celcius \n2 kelvin \n3 farenheight\ninput an integer for coresponding tempterature: ");
        scanf("%d", &tempType);
        if(tempType<1 || tempType>3)
        {
            printf("bad input enter integers 1-3 for corresponding temperature types\n");
        }
    } while(tempType<1 || tempType>3);
    return tempType;
}

float getTemp(int tempType) //this will get the temperature the user will input, it will trap them in a loop until they give valid input 
{
    float temp;
    do 
    {
        printf("give temperature: ");
        scanf("%f", &temp);
        if(tempType==2 && temp<0) 
        {
            printf("kelvin cant be negative\n");
        }
    } while(tempType==2 && temp<0);
    return temp;
}

int convertType() //this will get the kind of temperature the user wants to convert to, it will trap them in a loop until they give valid input 
{
    int tempConvert;
    do 
    {
        printf("1 celcius \n2 kelvin \n3 farenheight\ninput an integer for what you want to convert to: ");
        scanf("%d", &tempConvert);
        if(tempConvert<1 || tempConvert>3)
        {
            printf("bad input enter integers 1-3 for corresponding temperature types\n");
        }
    } while(tempConvert<1 || tempConvert>3);
    return tempConvert;
}

void categorize(float temp) //this will categorize the temparture and give a weather suggestion based on the temperature 
{
    if(temp<0)
    {
        printf("freezing: wear a thick jacket if you go out \n");
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
}

int main() 
{
    float temp; //tempearture 
    int tempType; //the type of temperature user will give 
    int tempConvert; //what the user wants to convert to 
    //calls supporting functions to get user input and force to give valid input 
    tempType=typeTemp(); 
    temp=getTemp(tempType);
    tempConvert=convertType();
    
    switch(tempType) //this converts whatevery they gave us (C/K/F) into celcius so we can put it into function
    { 
        case 1: 
            categorize(temp); //this will categorize the temperature and give weather aadvisory 
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

    if ((tempType==1 && tempConvert==1) || (tempType==2 && tempConvert==2) || (tempType==3 && tempConvert==3)) //if the user wants to convert to temp they are already in... 
    {
        printf("you are trying to convert to the temparture type you are already in"); //..tell them that they are already in that type 
    }
    else if (tempType==1 && tempConvert==2) //if in C converting to K 
    {
        printf("converted temperature %f", c2k(temp)); //call appropriate function 
    }
    else if (tempType==1 && tempConvert==3) //if in C converting to F 
    {
        printf("converted temperature %f", c2f(temp)); 
    }
    else if (tempType==2 && tempConvert==1) //if in K convering to C 
    {
        printf("converted temperature %f", k2c(temp)); 
    }
    else if (tempType==2 && tempConvert==3) //if in K convering to F 
    {
        float a=k2c(temp); //call functions to convert twice 
        a=c2f(a); 
        printf("converted temperature %f", a); 
    }
    else if (tempType==3 && tempConvert==1) //if in F convering to C 
    {
        printf("converted temperature %f", f2c(temp)); 
    }
    else if (tempType==3 && tempConvert==2) //if in F convereing to K 
    {
        float b=f2c(temp); 
        b=c2k(b); 
        printf("converted temperature %f", b); 
    }

    return 0; 
}