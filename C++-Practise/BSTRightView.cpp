//This program prints the right view of a given binary tree, leftmost element at every level
#include <iostream>
#include <string>

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

bool printWidth(Node * root, int level)
{
    bool flag = false;
    if(root == NULL)
        return flag;
    else if(level ==1)
    {
        cout<<"Key is "<<root->value<<endl;
        return true;
    }
    else
    {
        flag = printWidth(root->right, level-1);
        if(flag == false)
            flag = printWidth(root->left, level-1);
        return flag;
    }
}

int MaxDepth (Node * node)
{
    int dl=0;
    int dr=0;
    if(node==NULL)
    {
        return 0;
    }
    dl = MaxDepth(node->left);
    dr = MaxDepth(node->right);
    if(dl>=dr)
        return ++dl;
    else
        return ++dr;
};

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
    int max = MaxDepth(root);
    int maxWidth=0;
    int level=0;
    for(int i=0; i<=max; i++)
    {
        bool flag = printWidth(root, i);
    }
}
