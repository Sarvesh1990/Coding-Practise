#include <iostream>
using namespace std;

int TotalSubSeqZeroSum(int * array, int length, int sum){
    if(length==0)
        return 0;
    if(sum==array[length-1])
        return 1+TotalSubSeqZeroSum(array, length-1, sum-array[length-1])+TotalSubSeqZeroSum(array, length-1, sum);
    else
        return TotalSubSeqZeroSum(array, length-1, sum-array[length-1])+TotalSubSeqZeroSum(array, length-1, sum);
}

int main(){
    cout<<"Enter number of elements in the array"<<endl;
    int length;
    cin>>length;
    int array[length];
    for(int i=0; i<length; i++)
        cin>>array[i];
    cout<<"Total number of possible subsequence with sum 0 is "<<TotalSubSeqZeroSum(array, length, 0)<<endl;
}
