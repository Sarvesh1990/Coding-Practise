#include <iostream>
using namespace std;

int GetMaxValue(int * value, int * weight, int knapWeight, int length){
    int maxValue[length+1][knapWeight+1];
    for(int i=0; i<=length; i++){
        for(int j=0; j<=knapWeight; j++){
            if(i==0 || j==0)
                maxValue[i][j]=0;
            else if(weight[i]<=knapWeight){
                maxValue[i][j]=value[i]+maxValue[i-1][knapWeight-weight[i]];
            }
            else
                maxValue[i][j]=0;
        }
    }
    return maxValue[length][knapWeight];
}

int main(){
    cout<<"Enter length of value array"<<endl;
    int length;
    cin>>length;
    int value[length];
    int weight[length];
    cout<<"Create value array"<<endl;
    for(int i=0; i<length; i++){
        cin>>value[i];
    }
    cout<<"Create weight array"<<endl;
    for(int i=0; i<length; i++){
        cin>>weight[i];
    }
    cout<<"Give knapsack weight"<<endl;
    int knapWeight;
    cin>>knapWeight;
    cout<<"Maximum value that can be obtained with sum of weights lt or eq knapSackWeight is "<<GetMaxValue(value, weight, knapWeight, length)<<endl;
}
