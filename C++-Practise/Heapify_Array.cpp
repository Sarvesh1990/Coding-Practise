#include <iostream>
#include <string>
using namespace std;

void Sink(int * a, int b, int size);
int main()
{
    int N;
    cout<<"Enter number of elements in array"<<endl;
    cin>>N;
    int a[N];
    for(int i=0; i<N;i++)
        cin>>a[i];
    int j=N-1;
    while(j>0)
    {
        if(j%2!=0)
        {
            if(a[j+1])
                j=j+1;
            else
            {
                if(a[j/2]<a[j])
                {
                    Sink(a, j/2,j+1);
                    j=j-1;
                }

            }

        }
        else
        {
            int max = a[j];
            if(a[j-1]>max)max=a[j-1];
            if(a[(j/2-1)]<max)
            {
                Sink(a,(j/2-1),j+1);
                j=j-2;
            }
        }
    }
    cout<<"1st element of heap is "<<a[1]<<" " <<a[2]<<" "<<a[3]<<" "<<endl;
}
void Sink(int * a, int b, int size)
{
    int max=0, temp=0, i=0;
    //cout<<"Integers are "<<a[2*b+2]<<" " <<a[2*b+1]<<endl;
    if(2*b+2<=size)
    {
        i=a[2*b+2]>a[2*b+1] ? (2*b+2):(2*b+1);
        //cout<<"i is "<<i<<endl;
        max=a[i];
        if(a[b]<max)
        {
            temp=a[b];
            a[b]=max;
            a[i]=temp;
          //  cout<<"Temp is "<<temp<<endl;
            Sink(a, i,size);
        }
    }
    else if(2*b+1<=size)
    {
        max=a[2*b+1];
        if(a[b]<max)
        {
            temp=a[b];
            a[b]=max;
            a[2*b+1]=temp;
            Sink(a, 2*b+1,size);
        }
    }
    else
    {
        return;
    }
}
