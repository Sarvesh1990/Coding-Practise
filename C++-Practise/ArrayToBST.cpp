#include <iostream>
using namespace std;

struct Node{
    int value;
    Node * left;
    Node * right;
};

Node * GenerateNode(int value){
    Node * newNode = new Node ();
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node * GenerateBST(int * array, int low, int high){
    Node * tempNode;
    if(low == high){
        tempNode = GenerateNode(array[low]);
        return tempNode;
    }
    int mid = (low+high)/2;
    tempNode=GenerateNode(array[mid]);
    if(mid>low)
        tempNode->left=GenerateBST(array, low, mid-1);
    tempNode->right=GenerateBST(array, mid+1, high);
    return tempNode;
}

int main(){
    cout<<"Enter number of elements in the array"<<endl;
    int length;
    cin>>length;
    int arrayToBST[length];
    int i;
    for (i = 0; i < length; i++) {
        cin>>arrayToBST[i];
    }
    Node * root = GenerateBST(arrayToBST, 0, length-1);
    cout<<"Root value is "<<root->value<<endl;
    cout<<"Node left to left value is "<<root->left->left->value<<endl;
    cout<<"Node right value is "<<root->right->value<<endl;
}

    
