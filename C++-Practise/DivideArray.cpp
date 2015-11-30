//This program takes an array and an integer as an input and checks if the array can be divided into subsets of 2 numbers all of which are divisible by given integer

#include <iostream>
using namespace std;

bool IfDivisible(int * array, int length, int k){
    int tempArray[k];
    bool flag=true;
    for(int j=0; j<k; j++){
        tempArray[j]=0;
    }
    for(int i=0; i<length; i++){
        tempArray[array[i]%k]=tempArray[array[i]%k]+1;
    }
    for(int i=0; i<length; i++){
        if(array[i]%k==0){
            if(tempArray[0]>0)
                tempArray[0]=tempArray[0]-1;
            else{
                flag=false;
                break;
            }
        }
        else{
            if(tempArray[k-array[i]%k]>0)
                tempArray[k-array[i]%k]=tempArray[k-array[i]%k]-1;
            else{
                flag=false;
                break;
            }
        }
    }
    if(flag)
        return true;
    else
        return false;
}

int main()
{
    int length =0;
    int k;
    cout<<"Give number of elements in array in even numbers"<<endl;
    cin>>length;
    int array[length];
    for(int i=0; i<length; i++)
    {
        cin>>array[i];
    }
    cout<<"Give number with whom we need to divide sum of 2"<<endl;
    cin>>k;
    bool divisible = IfDivisible(array, length, k);
    if(divisible)
        cout<<"Array can be broke into subsets of 2, all of which are divisble by "<< k <<endl;
    else
        cout<<"Array can't be broke into subsets of 2, all of which are divisble by "<< k <<endl;

}
