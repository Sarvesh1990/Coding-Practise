#include <iostream>
using namespace std;

bool IfSumPossible(int * array, int low, int high, int sum){
    if(sum==0)
        return true;
    if(sum<0)
        return false;
    if(low>high)
        return false;
    bool inclLow = IfSumPossible(array, low+1, high, sum-array[low]);
    bool exclLow = IfSumPossible(array, low+1, high, sum);
    if(inclLow == 1 || exclLow == 1)
        return true;
    else
        return false;
}

int main(){
    cout<<"Enter number of elements in the array"<<endl;
    int length;
    cin>>length;
    int array[length];
    for(int i=0; i<length; i++){
        cin>>array[i];
    }
    cout<<"Give the sum you want"<<endl;
    int sum;
    cin>>sum;
    cout<<"Possibility of getting the sum in given array is "<<IfSumPossible(array,0, length-1,sum)<<endl;
}
