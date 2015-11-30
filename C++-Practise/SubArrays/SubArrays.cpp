#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int MaxMid(int* a, int low, int high)
{
    int lowMax=a[(low+high)/2]+a[(low+high)/2-1];
    int highMax=a[(low+high)/2]+a[(low+high)/2+1];
    int value=a[(low+high)/2];
    for(int i=(low+high)/2-1; i>=low; i--)
    {
        value=value+a[i];
        if(value>lowMax)lowMax=value;
    }
    value=a[(low+high)/2];
    for(int i=(low+high)/2+1;i<=high;i++)
    {
        value=value+a[i];
        if(value>highMax)highMax=value;
    }
    int midMax=0;
    if(lowMax>a[(low+high)/2])midMax=midMax+lowMax-a[(low+high)/2];
    if(highMax>a[(low+high)/2])midMax=midMax+highMax-a[(low+high)/2];
    midMax=midMax+a[(low+high)/2];
    if(lowMax>=highMax && lowMax>=midMax)
    {
        return lowMax;
    }
    else if(highMax>=lowMax && highMax>=midMax)
    {
        return highMax;
    }
    else
    {
        return midMax;
    }
}

int MaxSubArray(int* a, int low, int high)
{
    if(low==high) return a[low];
    int lowMax, highMax, midMax;
    if(high-low>1)
    {
        lowMax=MaxSubArray(a, low, ((low+high)/2)-1);
        highMax=MaxSubArray(a, ((low+high))/2+1, high);
        midMax=MaxMid(a, low, high);
    }
    else
    {
        lowMax=a[low];
        highMax=a[high];
        midMax=a[low]+a[high];

    }

        if(lowMax>=highMax && lowMax>=midMax)return lowMax;
    else if(highMax>=lowMax && highMax>=midMax)return highMax;
    else return midMax;
}

int main()
{
    int a[100];
    ifstream file;
    file.open("file.txt");
    if(!file) 
    {
        cout<<"File not found"<<endl;
        exit(EXIT_FAILURE);
    }

    int current;
    int i=0;
    while(file >> current) 
    {
        a[i]=current;
        i++;
        //file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    cout<<i<<endl;
    int max=MaxSubArray(a, 0, i-1);
    cout<<"Maximum subarray value is "<<max<<endl;
}
