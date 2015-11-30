//This programs generates permutation of a given string recursively starting from single character and keep adding characters
#include <iostream>
#include <string>

using namespace std;

void Permute(string * myStr, char myChar, int curChar)
{
    int myCount=0;
    while(myStr[myCount]!="\0")
        myCount++;
    string tempStr[200];
    int count=0;
    for(int j=0; j<myCount; j++)
    {
        cout<<"String in function is "<<myStr[0]<<" and char is "<<myChar<<endl;
        myStr[j]=myStr[j]+myChar;
        cout<<"String in function is "<<myStr[0]<<endl;
        for(int i=0; i<=curChar; i++)
        {
            string myString = myStr[j];
            myString[curChar]=myString[i];
            myString[i]=myChar;
            tempStr[count]=myString;
            cout<<"My string is "<<myString<<endl;
            count++;            
        }
    }
    for(int m=0; m<count; m++)
    myStr[m]=tempStr[m];
}

int main()
{
    char myString[5];
    cout<<"Give me the string less than 5 characters you want to permute"<<endl;
    cin>>myString;
    string myStr[200];
    myStr[0]=myString[0];
    for(int i=1; i<strlen(myString); i++)
    {
       Permute(myStr, myString[i], i);
    }
    for(int j=0; j<24; j++)
    {
        cout<<"String is "<<myStr[j]<<endl;
    }
}
