#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    int nTest;
    cin>>nTest;
    for(int i=0; i<nTest; i++)
    {
        int nList;
        cin>>nList;
        int aList[nList];
        //char szList[nList];
        char szLetter;

        for(int i=0; i<nList; i++)
        {
            cin>>aList[i];
        }

        int A, B, C;

        cin>>A;
        cin>>B;
        cin>>C;

        string str;
        for(int i=0; i<nList; i++)
        {
            cin>>szLetter;
            if(szLetter=='A')
            {
                //cout<<"Letter is "<<i<<endl;
                for(int j=i; j<nList; j++)
                {
                    aList[j]=aList[j]+A;
                }
            }
            else if(szLetter=='R')
            {
                int n=nList-1;
                int temp;
                for(int j=i-1; j<nList; j++)
                {
                    temp=aList[j];
                    aList[j]=aList[n];
                    aList[n]=temp;
                    n--;
                }
            }
            else
            {
                for(int j=i; j<nList; j++)
                {
                    aList[j]=aList[j]*B;
                }
            }
        }
        for(int i=0; i<nList; i++)
        {
            ostringstream oss;
            oss<<aList[i]%C;
            str+=oss.str();
            str+=" ";
        }
        cout<<str<<endl;
    }
}

