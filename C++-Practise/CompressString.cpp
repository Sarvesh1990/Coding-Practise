//Inplace compression of string (abbccda -> a1b2c2d1a1)
//Use recursion, starts from 0, keep increasing count, divides count/10 to decide number of digits after alphabet, then call compress again with starting as new character and act pointer set at alphabet+number of digit, put character at act pointer and use n to put number of digits after character
#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;
void compress(char *str,int len, int act);
char str[100];
int length;

int main()
{
scanf("%s",str);
length=strlen(str);
//cout<<"length is "<<length<<endl;
//compression
//we need a recursive sol so that 
//cases like abbbccc or abcccc are also taken care of
compress(str,0,0);
printf("%s",str);
scanf("%d",&length);

}

//recursive code - prefered
void compress(char *str,int len, int act) {

if(len<length) {
    int k=len;
    int count=0;
    int c, n;
    while(str[k]==str[len]){
        len++; count++;
    }
    n = 0;
    c=count;
    do {
        c /= 10;
        n++;
    } while (c != 0);
  //  cout<<"n is "<<n<<endl;
    compress(str,len,act+n+1);
    
    str[act]=str[k];
    if(k+count==length)
    {
       str[act+n+1]='\0';
    }
    for(c=0;c<n;c++) 
    {
        str[act+n-c]=(count%10)+48;
        count=count/10;
    }

}
return;
}

