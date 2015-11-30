#include <iostream>
//nclude <array> 
using namespace std;
#define size (high-low)+1
int main()
{
    void Sort(int* aSort, int low, int high);
    void Merge(int* aMerge, int low,int high);
    int nSize;
    cout<< "Please enter the size of the array" <<endl;
    cin>>nSize;
    int a[nSize];
    cout<<"Please enter "<<nSize<<" elements to the array"<<endl;
    for(int i=0; i<nSize; i++)
    {
        cin>>a[i];
    }
    Sort(a,0,(nSize)-1);
    cout<<"Sorted array is ";
    for(int k=0; k<nSize; k++)
    {
        cout<<a[k];
    }
    cout<<endl;
    return 0;
}

void Sort(int* aSort, int low, int high)
{
    void Merge(int* aMerge, int low, int high);  
    if(size>1)
    {
        Sort(aSort, low, (low+high)/2);
        Sort(aSort, ((low+high)/2)+1, high);
    }
    else return ;
    Merge(aSort,low,high);
}

void Merge(int* aMerge, int low, int high)
{
    int aTemp[size];
    for(int i=low; i<=high; i++)
    {
        aTemp[i]=aMerge[i];
    }
    int low1=low;
    int high1=(low+high)/2;
    int low2=((low+high)/2)+1;
    int high2=high;
    while(low1<=high1 &&  low2<=high2)
    {
        if(aTemp[low1]<=aTemp[low2])
        {
            aMerge[low]=aTemp[low1];
            low++;
            low1++;
        }
        else
        {
            aMerge[low]=aTemp[low2];
            low++;
            low2++;
        }
    }
    if(low1>high1)
    {
        while(low2<=high2)
        {
            aMerge[low]=aTemp[low2];
            low2++;
            low++;
        }
    }
    else
    {
         while(low1<=high1)
        {
            aMerge[low]=aTemp[low1];
            low1++;
            low++;
        }
    }
}
