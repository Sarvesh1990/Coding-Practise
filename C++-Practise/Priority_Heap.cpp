#include <iostream>
using namespace std;

int main()
{
    int nElements;
    void Insert(int *heap, int a, int b);
    int Remove(int *heap, int nElements);
    cout<<"Give number of elements in the array"<<endl;
    cin>>nElements;
    int a[nElements], heap[nElements];
    cout<<"Enter "<<nElements<<" number to be sorted"<<endl;
    for(int i=0; i<nElements; i++)
    {
        cin>>a[i];
    }
    for(int j=0; j<nElements; j++)
    {
        Insert(heap, a[j], j);
    }
   // cout<<"Biggest element is "<<heap[0]<<endl;
    cout<<"Sorted array is ";
    for(int k=0; k<nElements; k++)
    {
        cout<<Remove(heap, nElements-k);
        cout<<" ";
        //cout<<heap[k]<<endl;
    }
    cout<<endl;
    return 0;
}

void Insert(int *heap, int a, int b)
{
    if((b+1)/2 ==0)heap[b]=a;
    while((b+1)/2>0)
    {
        if(a>heap[((b+1)/2)-1])
        {
            int temp=heap[((b+1)/2)-1];
            heap[((b+1)/2)-1]=a;
            heap[b]=temp;
            b=((b+1)/2)-1;
        }   
        else 
        {
            heap[b]=a;
            break;
        }
    }
}

int Remove(int *heap, int nElements)
{
    int max = heap[0];
//    cout<<"Max is "<<max<<endl;   
    int bigB=0;
    heap[0]=heap[nElements-1];
    //cout<<"heap0 is "<<heap[0]<<endl;
    heap[nElements-1]=0;
    int b=0;
    while((2*(b+1)+1)<=nElements)
    {
        if(heap[2*(b+1)]>=heap[2*(b+1)-1]) bigB = 2*(b+1);
        else bigB = 2*(b+1)-1;
    //    cout<<"Bigger is "<<heap[b]<<endl;
        if(heap[b]>=heap[bigB]) break;
        else
        {   
            int temp=heap[b];
            heap[b]=heap[bigB];
            heap[bigB]=temp;
            b=bigB;
         //   cout<<"B is "<<heap[b]<<endl;
        }
    }
    return max;
}
