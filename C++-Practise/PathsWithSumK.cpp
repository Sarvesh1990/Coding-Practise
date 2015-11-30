#include <iostream>
#include <stack>
using namespace std;

struct Node{
    int value;
    int distance;
};

stack <int> bfsStack;

void PrintPathWithSumK(bool adjacency[][8], int root, int k){
    if(k<0){
        return;
    }
    if(k==0){
        cout<<"Path is ";
        cout<<root<<" ";
        stack <int> tempBfsStack = bfsStack;
        while(!tempBfsStack.empty()){
            int value = tempBfsStack.top();
            cout<<value<<" ";
            tempBfsStack.pop();
        }
        cout<<endl;
        return;
    }
    for(int i=0; i<8; i++){
        bfsStack.push(root);
        if(adjacency[root][i]==true){
            PrintPathWithSumK(adjacency, i, k-i);
        }
        bfsStack.pop();
    }
}

int main(){
    bool adjacency[8][8];
    for(int i=0; i< 8; i++){
        for(int j=0; j<8; j++){
            adjacency[i][j]=0;
        }
    }
    adjacency[0][1]=1;
    adjacency[0][2]=1;
    adjacency[0][5]=1;
    adjacency[1][3]=1;
    adjacency[1][7]=1;
    adjacency[2][7]=1;
    adjacency[2][4]=1;
    adjacency[3][4]=1;
    adjacency[4][6]=1;
    adjacency[5][3]=1;
    adjacency[7][4]=1;
    cout<<"Enter distance"<<endl;
    int k;
    cin>>k;
    PrintPathWithSumK(adjacency, 0, k);
}
