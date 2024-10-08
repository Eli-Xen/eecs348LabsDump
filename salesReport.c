// Author: Eliza Malyshev 
// KUID: 3122318
// Date: 10/8/2024 
// Lab: #5.1
// Purpose: process file IO and print data using arrays 
#include <stdio.h>
int monthlySales(float sales[]) 
{
    printf("\nMONTHLY SALES REPORT:\n");
    printf("january: \t %f\n", sales[0]); 
    printf("february: \t %f\n", sales[1]); 
    printf("march: \t\t %f\n", sales[2]); 
    printf("april: \t\t %f\n", sales[3]); 
    printf("may: \t\t %f\n", sales[4]); 
    printf("june: \t\t %f\n", sales[5]); 
    printf("july: \t\t %f\n", sales[6]); 
    printf("august: \t %f\n", sales[7]); 
    printf("september: \t %f\n", sales[8]); 
    printf("october: \t %f\n", sales[9]); 
    printf("novemeber: \t %f\n", sales[10]); 
    printf("december: \t %f\n", sales[11]); 
    return 0; 

}

int summary(float sales[])
{
    float min=sales[0], max=sales[0], avg=0; 
    int minMonth=1, maxMonth=1; 
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
    printf("\nSALES SUMMARY REPORT:\n");
    printf("minimum sale in month %d: %f\n", minMonth, min); 
    printf("maximum sale in month %d: %f\n", maxMonth, max); 
    printf("average sale: %f\n", avg/12); //divdies by 12 to get average
    return 0; 
}

float sixAvg(int start, int stop, float sales[]) //supporting function that gets average between two specified indecies 
{
    float avg=0; 
    for (int i=start; i<=stop; i++)
    {
        avg+=sales[i%12]; //use mod for when i gets greater than 12 
    }
    return avg/6; //returns total/6 to give average 
}
int sixMonth(float sales[]) //this function calcualtes and prints the 6-month average over a given time period 
{
    printf("\nSIX-MONTH MOVING AVERAGE REPORT:\n"); 
    for (int i=0; i<7; i++) //calls supporting function with parameters being the low and high range of 6 month period 
    {  
        int j=i+5;  //end of 6 month period 
        printf("average for months %d-%d: %f\n", i+1, j+1, sixAvg(i, j, sales));  //loop start at 0,6 1,7 2,8
    }
    return 0; 
}

int high2low(float sales[]) //prints values in array from high to low 
{
    printf("\nSALES REPORT HIGHEST TO LOWEST:\n");
    for (int i=0; i<12-1; i++) //bubble sort that organizes array high to low 
    {
        for (int j=0; j<12-i-1; j++) 
        {
            if (sales[j]<sales[j+1]) //sorts decsending order 
            {
                float temp = sales[j];
                sales[j] = sales[j + 1];
                sales[j + 1] = temp;
            }
        }
    }
    for (int i=0; i<12; i++)
    {
        printf("%f\n", sales[i]); 
    }
}


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

    monthlySales(sales); //function call that will print all the sales for each month 
    summary(sales); //function that will show the minimum, maximum, and average sales
    sixMonth(sales); //shows what average is for each 6-month period 
    high2low(sales); //shows sales highest to lowest 
    fclose(file); 
    return 0; 

}
