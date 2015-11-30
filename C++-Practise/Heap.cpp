#include <iostream>
#include <algorithm>

using namespace std;

void Heapify(int * heap, int i)
{
    while(i/2 > 0)
    {
        if(heap[i/2]<heap[i])
        {
            int temp = heap[i];
            heap[i]=heap[i/2];
            heap[i/2]=temp;
            Heapify(heap, i/2);
        }
        else return;
    }
};

void Sink(int * heap, int k)
{
    heap[1]=heap[k];
    heap[k]=0;
    int i = 1;
    while(i<=k/2)
    {
        int maxm = max(heap[2*i], heap[2*i+1]);
        cout<<"Maximum is "<<maxm<<endl;
        if(maxm>heap[i])
        {
           if(heap[2*i]>heap[2*i+1])
            {
                heap[2*i]=heap[i];
                heap[i]=maxm;
                i=2*i;
            }
           else
            {
                heap[2*i+1]=heap[i];
                heap[i]=maxm;
                i=2*i+1;
            }
        }
        else break;
    }
}
int main()
{
    int myArray[]={2,3,17,11,34,12,5};//,8,9,4,6,18};
    int k=5;
    int Heap[k+1];
    for(int i=1; i<=(sizeof(myArray))/sizeof(*myArray); i++)
    {
        if(i<=k)
        {
            Heap[i]=myArray[i-1];
            Heapify(Heap, i);
        }
        else
        {
            int max = Heap[1];
            Sink(Heap, k);
            cout<<"Removing max "<<max<<endl;
            Heap[k]=myArray[i-1];
            cout<<"Heap is "<<Heap[k]<<endl;
            Heapify(Heap, k);
        }
    }
    cout<<"Largest element is "<<Heap[1]<<endl;
}
