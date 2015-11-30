#include <iostream>
#include <map>
#include <string>

using namespace std;

void swap (int v[], int i, int j) 
{
    int t;
    t = v[i];
    v[i] = v[j];
    v[j] = t;
}

void perm (int v[], int n, int i, int *count, int *reqLength, int *minLength, int *maxLength) 
{
    //cout<<"Inside perm"<<endl;
    int j;
    if (i == n) 
    {
        map<int, int>testing;
        int length=0;
        int temp=0;
        for(int j=0; j<n; j++)
        {
            for(int k=j; k>0; k--)
            {
                if(testing[k]==1)
                {
                    temp=1;
                    length=length+(v[j]-k);
                    break;
                }               
            }
            if(temp==0)
            {
                length=length+(v[j]-0);
            }
            temp=0;
            for(int k=j+1; k<=n; k++)
            {         
                if(testing[k]==1)
                {
                    temp=1;
                    length=length+(k-v[j]);
                    testing[v[j]]=1;
                    break;
                }
            }
            if(temp==0)
            {
               length=length+n+1-v[j];
               testing[v[j]]=1;
            }
        }
        if(length == *reqLength)
        {
            *count=1;
        }
        cout<<"Length is "<<length<<endl;
        for(int m=0; m<n; m++)
        {
            cout<<v[m];
        }
        cout<<endl;
        if(length<*minLength && *minLength !=0)*minLength=length;
        if(length>*maxLength && *maxLength !=0)*maxLength=length;
        if(*minLength==0)*minLength=length;
        if(*maxLength==0)*maxLength=length;
        if(*reqLength>*maxLength)*count=2;
    } 
    else
    {
        for (j=i; j<n; j++) 
        {
            swap (v, i, j);
            if(*count == 0)
            {
                perm (v, n, i+1, count, reqLength, minLength, maxLength);
            }
            //else break;
            swap (v, i, j);
        }
    }
}

int main() 
{
    int nCases=0;
    cin>>nCases;
    string temp;
    string input;
    getline(cin,temp);
    for(int m=0; m<nCases; m++)
    {
        int nSoldiers = 0, nWire=0, count=0, minLength=0, maxLength=0;
        getline(cin, input);
        char inputTok[256]="";
        strcpy(inputTok, input.c_str());
        char *tok=strtok(inputTok, " ");
        int nItems=0;
        while(tok)
        {
            if(nItems==0)
                nSoldiers=atoi(tok);
            else if(nItems==1)
                nWire=atoi(tok);
            nItems++;
            tok=strtok(NULL, " ");
        }
        int v[nSoldiers], i;
        for (i=0; i<nSoldiers; i++) v[i] = i+1;
        perm (v, nSoldiers, 0, &count, &nWire, &minLength, &maxLength);
        if(count==1)cout<<"0"<<endl;
        else if(minLength>nWire)cout<<"-1"<<endl;
        else if(maxLength<nWire)cout<<nWire-maxLength<<endl;
    }
}
