#include <iostream>
#include <map>
#include <string>
#define MAX 1000010
using namespace std;

int main() 
{
    int nTest;
    cin>>nTest;
    string sNumber[nTest];
    //char sNumber[MAX];
    string temp[MAX];
    /*for(int m=0; m<nTest; m++)
    {
        cin>>sNumber[m];
    }*/
    for(int k=0; k<nTest; k++)
    {
        cin>>sNumber[k];
        temp[k]=sNumber[k];
        for(int i=0; i<sNumber[k].length()/2; i++)
        {
            if(sNumber[k][i]!=sNumber[k][sNumber[k].length()-i-1])
            {
                temp[k][sNumber[k].length()-i-1]=sNumber[k][i];
            }
        }

        if(temp[k]>sNumber[k])
        {
            cout<<temp[k]<<endl; 
            //return 0;
        }

        else
        {
            int i=sNumber[k].length()/2;
            i=sNumber[k].length()-i-1;
            bool bFlag=true;

            while(bFlag)
            {
                if(int(sNumber[k][i])!=57)
                {
                    sNumber[k][i]++;
                    bFlag=false; 
                }
                else
                {
                    sNumber[k][i]=sNumber[k][i]-9;
                    i=i-1;
                    if(!sNumber[k][i])
                    {
                        for(int j=0; j<=sNumber[k].length();j++)
                        {
                            sNumber[k][j]='0';
                        }
                        sNumber[k]+='0';
                        sNumber[k][0]='1';
                    }
                }
            }
            
            temp[k]=sNumber[k];
            
            for(int i=0; i<sNumber[k].length()/2; i++)
            {
                if(sNumber[k][i]!=sNumber[k][sNumber[k].length()-i-1])
                {
                    temp[k][sNumber[k].length()-i-1]=sNumber[k][i];
                }
            }
            
            cout<<temp[k]<<endl;    
        }
    }
    return 0;
}
