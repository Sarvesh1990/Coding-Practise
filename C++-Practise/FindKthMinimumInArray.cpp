#include <iostream>
using namespace std;


void Swap(int * array, int index1, int index2){
    int tempValue = array[index1];
    array[index1]=array[index2];
    array[index2]=tempValue;
}

int QuickSort(int * array, int low, int high, int k){
    int pivotValue = array[low];
    int tempLow = low+1;
    int tempHigh = high;
    int kMin;
    if(low==high)
        return array[low];
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
    Swap(array, low, tempHigh);
    if(tempHigh==k-1)
        return array[tempHigh];
    if(tempHigh>low && tempHigh>k-1)
        kMin = QuickSort(array, low, tempHigh-1, k);
    else{
        if(tempHigh<high)
            kMin = QuickSort(array, tempHigh+1, high, k-tempHigh+1);
    }
    return kMin;
}

int main(){
    cout<<"Enter number of elements in the array"<<endl;
    int length;
    cin>>length;
    int array[length];
    for(int i=0; i<length; i++)
        cin>>array[i];
    int k;
    cout<<"Give which number smallest you want"<<endl;
    cin>>k;
    int kMin = QuickSort(array, 0, length-1, k);
    cout<<k<<"th smallest number is "<<kMin<<endl;
}
