#include <iostream>
#include <string.h>

using namespace std;

void ReverseString(char * begin, char * end)
{
    while(begin<end)
    {
        char temp = *begin;
        *begin = *end;
        *end=temp;
        begin++;
        end--;
    }
}

void Reverse(char * begin)
{
    char * temp = begin;
    while(*temp != ' ' && *temp != '\0')
    {
        temp++;
    }
    ReverseString(begin, temp-1);
    if(*temp == ' ')
    {
        Reverse(temp+1);
    }
}
int main()
{
    char myString[] = "  Let us reverse this string word by word";
    Reverse(myString);
 // cout<<"Size is "<<sizeof(myString)<<endl;
  //char * begin = myString;
   //char * end = begin + size; 
   // cout<<"Begin is "<<*begin <<" and end is "<<*end<<endl;
    ReverseString(myString, myString+sizeof(myString)-2);
    cout<<"String is "<<myString<<" Ending"<<endl;
}
