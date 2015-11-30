#include <iostream>
#include <string>
#include <map>

using namespace std;

map <int, int> myMap;

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

void VerticalSum(Node * root, int verticalLine){
    if(root == NULL)
        return;
    if(myMap[verticalLine])
        myMap[verticalLine]=myMap[verticalLine]+root->value;
    else
        myMap[verticalLine]=root->value;
    VerticalSum(root->left, verticalLine-1);
    VerticalSum(root->right, verticalLine+1);
}

int main()
{
    //Create BST
    Node * root = newNode(25);
    root->left=newNode(14);
    root->left->left=newNode(10);
    root->left->right=newNode(18);
    root->left->right->left=newNode(17);
    root->left->right->right=newNode(20);
    root->right=newNode(35);
    root->right->left=newNode(30);
    root->right->right=newNode(45);
    root->right->right->right=newNode(55);
    root->right->right->right->left=newNode(50);
    root->right->right->right->right=newNode(60);
    root->right->right->right->left->right=newNode(53);
    root->right->right->right->left->left=newNode(48);
    root->right->right->left=newNode(40);
    root->right->right->left->right=newNode(43);
    root->right->right->left->right->left=newNode(42);
    root->right->right->left->right->right=newNode(44);
    VerticalSum(root, 0);
    map<int, int> :: iterator myIter;
    for(myIter= myMap.begin(); myIter != myMap.end(); myIter++){
        cout<<"Sum at vertical line "<<myIter->first<<" is "<<myIter->second<<endl;
    }    
}
