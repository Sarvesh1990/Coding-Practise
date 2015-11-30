#include <iostream>
//nclude <array> 
using namespace std;
#define size (high-low)+1
struct points
{
    int x;
    int y;
};
int main()
{
    void Sort(points* aSort, int low, int high);
    void Merge(points* aMerge, int low,int high);
    int nSize;
    cout<< "Please enter the size of the array of points" <<endl;
    cin>>nSize;
    points a[nSize];
    cout<<"Please enter x and y value consecutively for "<<nSize<<" elements to the array"<<endl;
    for(int i=0; i<nSize; i++)
    {
        cin>>a[i].x;
        cin>>a[i].y;
    }
    Sort(a,0,(nSize)-1);
    cout<<"Sorted array is : "<<endl;
    for(int k=0; k<nSize; k++)
    {
        cout<<a[k].x<<","<<a[k].y<<endl;
    }
    cout<<endl;
    return 0;
}

void Sort(points* aSort, int low, int high)
{
    void Merge(points* aMerge, int low, int high);  
    if(size>1)
    {
        Sort(aSort, low, (low+high)/2);
        Sort(aSort, ((low+high)/2)+1, high);
    }
    else return ;
    Merge(aSort,low,high);
}

void Merge(points* aMerge, int low, int high)
{
    points aTemp[size];
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
        if(aTemp[low1].x<aTemp[low2].x)
        {
            aMerge[low].x=aTemp[low1].x;
            aMerge[low].y=aTemp[low1].y;
            low++;
            low1++;
        }
        else if(aTemp[low1].x==aTemp[low2].x)
        {
            if(aTemp[low1].y<=aTemp[low2].y)
            {
                aMerge[low].x=aTemp[low1].x;
                aMerge[low].y=aTemp[low1].y;
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
