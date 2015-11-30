#include <iostream>
using namespace std;

int MinCost(int * sizeMatrix, int number){
    int cost[number+1][number+1];
    for(int i=0; i<=number; i++)
        cost[i][i]=0;
        int i, j, k;
    for(int gap=2; gap<=number; gap++){
        for(i=1; i<=number-gap+1; i++){
            j=gap+i-1;
            int min=0;
            cost[i][j]=0;
            for(k=i; k<j; k++){
                min=cost[i][k]+cost[k+1][j]+sizeMatrix[i-1]*sizeMatrix[k]*sizeMatrix[j];
                if(cost[i][j]<min)
                    cost[i][j]=min;
            }
        }
    }    
    return cost[1][number];
}

int main(){
    cout<<"Enter number of matrix to be multiplied"<<endl;
    int length;
    cin>>length;
    cout<<"Enter sizes of matrix"<<endl;
    int sizeMatrix[length+1];
    for(int i=0; i<=length; i++)
        cin>>sizeMatrix[i];
    cout<<"Minimum cost for multiplying these matrix is "<<MinCost(sizeMatrix, length)<<endl;
}
