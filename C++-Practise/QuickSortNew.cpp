#include <iostream>
using namespace std;

//Pivot = low;
//i = low+1;
//j=high;
//while i<=j, while(a[i]<pivot i++) same for j, swap a[i] and j, i++, j--, call while loop
//Swap j and pivot, call for half half

void Swap(int * array, int index1, int index2){
    int tempValue = array[index1];
    array[index1]=array[index2];
    array[index2]=tempValue;
}

void QuickSort(int * array, int low, int high){
    int pivotValue = array[low];
    int tempLow = low+1;
    int tempHigh = high;
    if(low==high)
        return;
    while(tempLow <= tempHigh){
        if(array[tempLow]<=pivotValue)
            tempLow++;
        else{
            if(array[tempHigh]>=pivotValue)
                tempHigh--;
            else{
                Swap(array, tempLow, tempHigh);
                tempLow++;
                tempHigh--;
            }
        }
    }
    if(tempHigh>low){
        Swap(array, low, tempHigh);
        QuickSort(array, low, tempHigh-1);
        if(tempHigh<high)
            QuickSort(array, tempHigh+1, high);
    }
}

int main(){
    cout<<"Enter number of elements in the array"<<endl;
    int length;
    cin>>length;
    int array[length];
    for(int i=0; i<length; i++)
        cin>>array[i];
    QuickSort(array, 0, length-1); 
    for(int i=0; i<length; i++)
        cout<<array[i]<<endl;
}
