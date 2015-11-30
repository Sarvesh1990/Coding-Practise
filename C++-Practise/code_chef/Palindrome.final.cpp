#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() 
{
    int nTest;
    string sNumber;
    string temp;
    cin>>nTest;
    for(int k=0; k<nTest; k++)
    {
        cin>>sNumber;
        temp=sNumber;

        for(int i=0; i<sNumber.length()/2; i++)
        {
            if(sNumber[i]!=sNumber[sNumber.length()-i-1])
            {
                temp[sNumber.length()-i-1]=sNumber[i];
            }
        }

        if(temp>sNumber)
        {
            cout<<temp<<endl; 
            return true;
        }

        else
        {
            int i=sNumber.length()/2;
            i=sNumber.length()-i-1;
            bool bFlag=true;

            while(bFlag)
            {
                if(int(sNumber[i])!=57)
                {
                    sNumber[i]++;
                    bFlag=false; 
                }
                else
                {
                    sNumber[i]=sNumber[i]-9;
                    i=i-1;
                    if(!sNumber[i])
                    {
                        for(int j=0; j<=sNumber.length();j++)
                        {
                            sNumber[j]='0';
                        }
                        sNumber+='0';
                        sNumber[0]='1';
                    }
                }
            }
            temp=sNumber;
            for(int i=0; i<sNumber.length()/2; i++)
            {
                if(sNumber[i]!=sNumber[sNumber.length()-i-1])
                {
                    temp[sNumber.length()-i-1]=sNumber[i];
                }
            }
            cout<<temp<<endl;    
        }
    }
}
