#include <iostream>
#include <map>
#include <string>
#define MAX 1000010
using namespace std;
#define x getchar_unlocked()
#define y putchar_unlocked
int main() 
{
    long long nTest;
    cin>>nTest;
    x;
    /*for(int m=0; m<nTest; m++)
    {
        cin>>sNumber[m];
    }*/
    while(nTest--)
    {
        int j;
        char ch;
        char sNumber[MAX];
        char temp[MAX];
        ch=x;//cout<<ch<<endl<<"yo\n";
        for(j=0;ch!='\n';j++){
             sNumber[j]=ch,ch=x;//cout<<ch;
             temp[j]=sNumber[j];
        }
        sNumber[j]='\0';
        temp[j]='\0';
        for(int i=0; i<j/2; i++)
        {
            if(sNumber[i]!=sNumber[j-i-1])
            {
                temp[j-i-1]=sNumber[i];
            }
        }
        bool flag=true;
        for(int a=0;a<j; a++)
        {
            if(sNumber[a]>temp[a])
            {         
                flag=false;
                break;
            }
        }
        bool rflag=true;
        for(int a=0;a<j; a++)
        {
            if(sNumber[a]!=temp[a])
            {
                rflag=false;
            }
        }
        if(rflag)flag=false;
        if(flag)
        {
            for(int a=0; a<j; a++)
            {
                y(temp[a]);
            }
            y('\n');
        }

        else
        {
            int i=j/2;
            i=j-i-1;
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
                    if(i==-1)
                    {   
                        int k;
                        for(k=0; k<=j;k++)
                        {
                            sNumber[k]='0';
                        }
                        sNumber[0]='1';
                        j=k;
                    }
                }
            }
            for(int m=0; m<j; m++)
            {
                temp[m]=sNumber[m];
            }
            
            for(int i=0; i<j/2; i++)
            {
                if(sNumber[i]!=sNumber[j-i-1])
                {
                    temp[j-i-1]=sNumber[i];
                }
            }
            
            for(int a=0; a<j; a++)
            {
                y(temp[a]);
            }
            y('\n');
            
        }
    }
    return 0;
}
