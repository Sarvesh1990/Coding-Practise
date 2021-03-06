//This program does level order traversal in a BST using Queue
#include <iostream>
#include <string>
#include <queue>
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

void LevelOrder(Node * root)
{
    queue <Node *> myQueue;
    myQueue.push(root);
    while(!myQueue.empty())
    {
        Node * temp = new Node();
        temp = myQueue.front();
        myQueue.pop();
        cout<<"Key is "<<temp->value<<endl;
        if(temp->left)
            myQueue.push(temp->left);
        if(temp->right)
            myQueue.push(temp->right);
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
    LevelOrder(root);
}
