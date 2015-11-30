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

int getWidth(Node * root, int level)
{
    if(root == NULL)
        return 0;
    else if(level ==1)
        return 1;
    else
    {
        return (getWidth(root->left, level-1)+getWidth(root->right, level-1));
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
    for(int i=0; i<max; i++)
    {
        int myWidth=getWidth(root, i);
        if(myWidth>=maxWidth)
        {
            maxWidth=myWidth;
            level = i;
        }
    }
    cout<<"Max width is "<<maxWidth<<" for level "<<level<<endl;
}
