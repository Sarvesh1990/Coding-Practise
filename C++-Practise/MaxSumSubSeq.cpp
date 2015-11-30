#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int FindMaximumSum(int * array, int length){
    int maximumSum=0;
    int maximumSumHere=0;
    int lowerIndex = 0;
    int tempLowerIndex = 0;
    int higherIndex = 0;
    for(int i=0; i<length; i++){
        maximumSumHere = maximumSumHere+array[i];
        if(maximumSumHere < 0){
            tempLowerIndex = i+1;
            maximumSumHere = 0;
        }

        if(maximumSum < maximumSumHere){
            if(lowerIndex != tempLowerIndex)
                lowerIndex = tempLowerIndex;
            maximumSum = maximumSumHere;
            higherIndex = i;
        }
    }
    for(int i=lowerIndex; i<=higherIndex; i++)
        cout<<"Value is "<<array[i]<<endl;
    return maximumSum;
}

int main(){
    cout<<"Please enter length of array"<<endl;
    int length;
    cin>>length;
    int array[length];
    for(int i=0; i<length; i++){
        cin>>array[i];
    }
    int maximumSum = FindMaximumSum(array, length);
    cout<<"Maximum sum is "<<maximumSum<<endl;
}
