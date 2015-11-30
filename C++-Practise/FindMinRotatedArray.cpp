#include <iostream>
using namespace std;

//Look for left if increasing
//If yes, check just right, if smaller, pass right, otherwise pass whole right array
//If decreasing check for just before, if greater, pass current
//Else pass whole left
//
int FindMin(int * rotatedArray, int low, int high)
{
    if(low==high)
        return -1;
    int mid = (low+high)/2;
    if(rotatedArray[low]<=rotatedArray[mid]){
        if(rotatedArray[mid+1]<rotatedArray[mid]){
            return rotatedArray[mid+1];
        }
        else
            return FindMin(rotatedArray, mid+1, high);
    }
    else{
        if(rotatedArray[mid-1]>rotatedArray[mid])
            return rotatedArray[mid];
        else
            return FindMin(rotatedArray, low, mid);
    }
}

int main()
{
    int length;
    cout<<"Give length of rotated array"<<endl;
    cin>>length;
    int rotatedArray[length];
    for(int i=0; i<length; i++){
        cin>>rotatedArray[i];
    }
    int min = FindMin(rotatedArray, 0, length-1);
    cout<<"Minimum element is "<<min<<endl;
}
