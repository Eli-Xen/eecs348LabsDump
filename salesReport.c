// Author: Eliza Malyshev 
// KUID: 3122318
// Date: 10/8/2024 
// Lab: #5.1
// Purpose: process file IO and print data using arrays 
#include <stdio.h>
int monthlySales(float sales[]) 
{
    printf("january: \t %f", sales[0]); 
    printf("february: \t %f", sales[1]); 
    printf("march: \t %f", sales[2]); 
    printf("april: \t %f", sales[3]); 
    printf("may: \t %f", sales[4]); 
    printf("june: \t %f", sales[5]); 
    printf("july: \t %f", sales[6]); 
    printf("august: \t %f", sales[7]); 
    printf("september: \t %f", sales[8]); 
    printf("october: \t %f", sales[9]); 
    printf("novemeber: \t %f", sales[10]); 
    printf("december: \t %f", sales[11]); 
    return 0; 

}

int summary(float sales[])
{
    float min=0, max=0, avg=0; 
    int minMonth, maxMonth; 
    for (int i=0; i<12; i++)
    {
        if (sales[i]<min) //goes through array and if it finds new min/max it save sit to variable 
        {
            min=sales[i]; //saves new min 
            minMonth=i+1; //saves month of min 
        }
        else if (sales[i]>max)
        {
            max=sales[i]; 
            maxMonth=i+1; //saves month of max 
        }
    }
    for (int i=0; i<12; i++) //adds all the sales together 
    {
        avg+=sales[i]; 
    }
    // avg=avg/12; //divides by 12 to get average 

    printf("minimum sale in month %d: %f", minMonth, min); 
    printf("maximum sale in mont %d: %f", maxMonth, max); 
    printf("average sale: %f", avg/12); //divdies by 12 to get average
}

// int sixMonth(float sales[])
// {

        // sixAvg(start,stop,sales[]); 
// }
// int sixAvg(int start, int stop, float sales[]) //supporting function that gets average between two specified indecies 
// {
//     for (int i=0; i<6; i++)
//     {

//     }
// }

int main()
{
    float sales[12]; //this array will hold all the values for sales 
    FILE *file; //pointer to file 
    char fileName[100]; //string for name of file, assumed to be less than 100 chars 
    printf("name of your file: "); 
    scanf("%s", fileName); 
    file=fopen(fileName, "r"); //open the file in read mode 
    
    for (int i = 0; i < 12; i++) //read each line of file into array 
    {
        fscanf(file, "%f", &sales[i]); 
    }

    monthySales(sales); //function call that will print all the sales for each month 
    summary(sales); //function that will show the minimum, maximum, and average sales
    // sixMonth(sales); //shows what average is for each 6-month period 
    // high2low(sales); //shows sales highest to lowest 
    fclose(file); 
    return 0; 

}
