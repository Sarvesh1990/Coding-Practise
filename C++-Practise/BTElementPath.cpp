//This program does level order traversal in a BST using Queue
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct Node
{
    int value;
    Node * left;
    Node * right;
};

Node * newNode(int number)
{
    Node * myNode = new Node();
    myNode->value = number;
    myNode->left=myNode->right=NULL;
    return myNode;
};

bool FindPath(Node * root, vector<int> &path, int value){
    if(root==NULL)
        return false;
    path.push_back(root->value);
    if(root->value == value)
        return true;
    if(FindPath(root->left, path, value) || FindPath(root->right, path, value))
        return true;
    path.pop_back();
    return false;    
}

int main()
{
    //Create BST
    Node * root = newNode(1);
    root->left=newNode(2);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right=newNode(3);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    vector<int> path;
    FindPath(root, path, 5);
    cout<<"Size of path is "<<path.size()<<endl;
    for(int i=0; i<path.size(); i++){
        cout<<"Value is "<<path[i]<<endl;
    }
}
