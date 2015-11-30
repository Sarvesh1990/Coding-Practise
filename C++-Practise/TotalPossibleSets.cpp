#include <iostream>
using namespace std;

int TotalCoinSets(int * array, int length, int sum){
    if(sum==0)
        return 1;
    if(sum < 0)
        return 0;
    if(length <=0 && sum>=1)
        return 0;
    int sumInclude = TotalCoinSets(array, length, sum-array[length-1]);
    int sumExclude = TotalCoinSets(array, length -1, sum);
    return (sumInclude + sumExclude);
}

int main(){
    int array[2]={1,5};
    int sum = TotalCoinSets(array, 2, 15);
    cout<<"Sum is "<<sum<<endl;
}
