#include <iostream>
using namespace std;

int FindLength(int origNumber){
    int length =0;
    while(origNumber>0){
        origNumber = origNumber/10;
        length++;
    }
    cout<<"Length is "<<length<<endl;
    return length;
}  

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
        if(array[tempLow]>=pivotValue)
            tempLow++;
        else{
            if(array[tempHigh]<=pivotValue)
                tempHigh--;
            else{
                Swap(array, tempLow, tempHigh);
                tempLow++;
                tempHigh--;
            }
        }
    }
    Swap(array, low, tempHigh);
    if(tempHigh>low)
        QuickSort(array, low, tempHigh-1);
    if(tempHigh<high)
        QuickSort(array, tempHigh+1, high);
}

int FindGreater(int origNumber, int length){
    int array[length];
    int i=0;
    int tempNumber=origNumber;
    while(tempNumber > 0){
        array[i]=tempNumber%10;
        tempNumber = tempNumber/10;
        i++;
    }
    bool flag = true;
    for(i=0; i<length-1; i++){
        if(array[i]>array[i+1]){
            flag=false;
            break;
        }
    }
    if(flag){
        cout<<"Number is in its largest state with given digits"<<endl;
        return origNumber;
    }
    QuickSort(array, 0, i);
    int j;
    for(j=i; j>=0; j--){
        if(array[j]>array[i+1])
            break;
    }
  
    Swap(array, j, i+1);
    origNumber=0;
    for(i=length-1; i>=0; i--){
        origNumber = origNumber*10+array[i];
    }
    return origNumber;
}

int main(){
    int origNumber;
    cout<<"Give number"<<endl;
    cin>>origNumber;
    int length = FindLength(origNumber);
    int greaterNumber = FindGreater(origNumber, length);
    cout<<"Greater number is "<<greaterNumber<<endl;
}
