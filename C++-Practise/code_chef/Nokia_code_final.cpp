#include <iostream>
#include<map>
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
        if(length<*minLength && *minLength !=0)*minLength=length;
        if(length>*maxLength && *maxLength !=0)*maxLength=length;
        if(*minLength==0)*minLength=length;
        if(*maxLength==0)*maxLength=length;
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
            swap (v, i, j);
        }
    }
}

int main() 
{
    int nSoldiers = 0, nWire=0, count=0, minLength=0, maxLength=0;
    cout<<"Insert number of soldiers within 1 to 10"<<endl;
    cin>>nSoldiers;
    cout<<"Enter the length of wire to be used"<<endl;
    cin>>nWire; 
    int v[nSoldiers], i;
    for (i=0; i<nSoldiers; i++) v[i] = i+1;
    perm (v, nSoldiers, 0, &count, &nWire, &minLength, &maxLength);
    if(count==1)cout<<"Length of wire left is 0"<<endl;
    else if(minLength>nWire)cout<<"Not possible, minimum wire length required is "<<minLength<<endl;
    else if(maxLength<nWire)cout<<"Wire left will be "<<nWire-maxLength<<endl;
    return 0;
}
