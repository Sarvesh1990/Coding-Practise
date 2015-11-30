//This program does level order traversal in a BST using Queue
#include <iostream>
#include <string>
#include <queue>
#include <cmath>
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

int FindDepth(Node * root){
    if(root == NULL)
        return 1;
    else{
        return(max(FindDepth(root->left), FindDepth(root->right))+1);
    }
}

void AlternateOrder(Node * root, int level, bool alternateOrder){
    if(root == NULL) 
        return;
    if(level>1){
        if(alternateOrder){
            AlternateOrder(root->right, level-1, alternateOrder);
            AlternateOrder(root->left, level -1, alternateOrder);
        }
        else{
            AlternateOrder(root->left, level-1, alternateOrder);
            AlternateOrder(root->right, level -1, alternateOrder);
        }
    }
    else{
        cout<<"Value is "<<root->value<<endl;
    }
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
    int maxDepth = FindDepth(root);
    int i;
    cout<<"Max depth is "<<maxDepth<<endl;
    for (i = 1; i <= maxDepth; i++) {
        if(i%2==0)
            AlternateOrder(root, i, true);
        else
            AlternateOrder(root, i, false);
    }
}
