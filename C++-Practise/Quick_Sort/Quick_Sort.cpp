#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void Sort(int * a, int low, int high);

int main(){
string line, file;
int current;

file=getenv("FLEXAPP");
file.erase(file.end()-7, file.end());
file+="Practise/Quick_Sort/";
file+="file.txt";
std::ifstream myfile;
myfile.open(file.c_str());

if(!myfile) {
    cout<<"Can't find file"<<endl;
    exit(EXIT_FAILURE);
}

myfile>>current;
int size = current;
int a[size];
int i=0;
while(myfile >> current) 
{
    a[i]=current;
    i++;
}

Sort(a, 0, size-1);
cout<<"Sorted array is ";
for(int j=0; j<size; j++)
{
   cout<< a[j]<<" ";
}
cout<<endl;
}

void Sort(int * a, int low, int high)
{
    int currHigh = high;
    int currLow=low;
    int temp;
    while(currHigh > currLow)
    {
        if(a[currHigh]<a[currLow])
        { 
            temp = a[currHigh];
            a[currHigh]=a[currHigh-1];
            a[currHigh-1]=temp;
            if((currHigh-currLow)>1)
            {
                temp=a[currHigh];
                a[currHigh]=a[currLow];
                a[currLow]=temp;
            }
            currHigh--;
        }
        else if(a[currHigh]>=a[currLow])
        {
            currLow++;
        }
    }
    if((high-currHigh)>1)
    {
        Sort(a, (currHigh+1), high);
    }
    if((currHigh-low)>1)
    {
        Sort(a, low, (currHigh-1));
    }

}

