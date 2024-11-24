#include <iostream>
#include <iomanip> //for formatting a double percision number 
#include <string> 
#include <sstream>

using namespace std; 

double extractNum(string str) 
{
    double finalNum=0; //iniitlize to avoid undefined behavior 

    //get rid of whitespace below: 
    string cleanstr;
	for (int i=0; i<str.length(); i++) 
    {
		if (str[i]!=' ')
			cleanstr+=str[i];
	}

    //validate input below: 
    for (int i=0; i<cleanstr.length(); i++) 
    {
        char next=(i+1<cleanstr.length()) ? cleanstr[i+1] : '\0'; //gets next character or null if at end/out of bound 
		if (!(isdigit(cleanstr[i]) || cleanstr[i]=='.' || cleanstr[i]=='-' || cleanstr[i]=='+')) //if not digit, period, dash or plus then invalid and return -999999.99 
            {return -999999.99; }
        else if ((isdigit(cleanstr[i]) && (next=='+'|| next=='-') || (cleanstr[i]=='-' && next=='+') || (cleanstr[i]=='+' && next=='-'))) //check for possible invalid combinations of operators 
            {return -999999.99; }
	}
    try  //incase there is other invalid input like 12.2.3 or something??
    {finalNum=stod(cleanstr); }
    catch (const invalid_argument& e) //possible given error that stod() can throw 
        {return -999999.99; }
    catch (const out_of_range& e) //possible given error that stod() can throw 
        {return -999999.99; }
        
	return finalNum; //yay return!! 
}

int main() 
{
    string input; 
    while(true)
    {
        cout << "enter a string or END to quit: "; 
        cin >> input; 
        if (input=="END")
            {break; }
        double num=extractNum(input); 
        if(num!=-999999.99)
            {cout << "input is: " << fixed << setprecision(4) << num <<endl; }
        else
            {cout << "the input is invalid." << endl; }
    }
}