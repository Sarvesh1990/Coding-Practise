#include <iostream>
using namespace std;

int FindMaximumSum(int * array, int length){
    int inclCurr=0;
    int exclCurr=0;
    int inclPrev=0;
    int exclPrev=0;
    for(int i=0; i<length; i++){
        inclCurr=exclPrev+array[i];
        exclCurr=max(inclPrev, exclPrev);
        inclPrev=inclCurr;
        exclPrev=exclCurr;
    }
    return max(inclPrev, exclPrev);
}

int main(){
    cout<<"Enter number of elements in the array"<<endl;
    int length;
    cin>>length;
    int array[length];
    for(int i=0; i<length; i++){
        cin>>array[i];
    }
    int maxSum = FindMaximumSum(array, length);
    cout<<"Maximum sum is "<<maxSum<<endl;
}
