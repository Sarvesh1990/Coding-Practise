#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int value;
    int distance;
};

queue <Node *> bfsQueue;
bool visited[8];

Node * CreateNode(int value, int distance){
    Node * myNode = new Node();
    myNode->value = value;
    myNode->distance = distance;
    return myNode;
}
void FindVertexAtDistanceK(bool adjacency[][8], int root, int k){
    while(!bfsQueue.empty()){
        if(bfsQueue.front()->distance>k){
            break;
        }
        if(bfsQueue.front()->distance==k){
            int value = bfsQueue.front()->value;
            if(visited[value]!=true){
                cout<<"One vertex is "<<value<<endl;
                visited[value]=true;
            }
        }
        int value = bfsQueue.front()->value;
        int distance = bfsQueue.front()->distance;
        bfsQueue.pop();
        for(int i=0; i<8; i++){
            if(adjacency[value][i]==true){
                    bfsQueue.push(CreateNode(i, distance+1));
            }
        }
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
    Node * source = CreateNode(0, 0);
    bfsQueue.push(source);
    FindVertexAtDistanceK(adjacency, 0, k);
}
