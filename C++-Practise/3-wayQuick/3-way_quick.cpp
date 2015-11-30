#include <iostream>
#include <string>
using namespace std;

void QuickSort(int * a, int b, int c);

int main()
{
    int N;
    cout<<"Enter no of integers in array"<<endl;
    cin>>N;
    int a[N];
    for(int i=0; i<N; i++)
        cin>>a[i];
    //t a[13]={5,4,3,5,2,5,4,1,4,8,3,7,6};
    int lt=0;
    int gt=N-1;
    QuickSort(a, lt, gt);  
    for(int i=0; i<N; i++)
        cout<<a[i];
    cout<<endl;
}

void QuickSort(int * a, int lt, int gt)
{
    int temp=0;
    int start=lt;
    int end = gt;
    int i=lt+1;
    while(i<=gt)
    {
        if(a[i]==a[lt])i++;
        else if(a[i]<a[lt])
        {
            temp=a[i];
            a[i]=a[lt];
            a[lt]=temp;
            lt++;
            i++;
        }
        else
        {
            while(a[gt]>a[lt])gt--;
            if(i>gt) break;
            temp=a[gt];
            a[gt]=a[i];
            a[i]=temp;
            gt--;                
        }
    }
    if(start<lt-1)
        QuickSort(a, start, lt-1);
    if(i<end)
        QuickSort(a, i, end);
}

