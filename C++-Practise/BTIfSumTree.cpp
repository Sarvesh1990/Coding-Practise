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

bool CheckIfLeaf(Node * root){
    if(root==NULL)
        return true;
    if(root->left==NULL && root->right==NULL)
        return true;
    return false;
}

bool CheckIfSumTree(Node * root){
    if(root==NULL)
        return true;
    if(CheckIfLeaf(root))
        return true;
    if(!CheckIfSumTree(root->left)||!CheckIfSumTree(root->right))
        return false;
    int leftSum=0;
    int rightSum=0;
    if(root->left){
        if(CheckIfLeaf(root->left))
            leftSum=root->left->value;
        else
            leftSum=2*root->left->value;
    }
    if(root->right){
        if(CheckIfLeaf(root->right))
            rightSum=root->right->value;
        else
            rightSum=2*root->right->value;
    }
    if(root->value == leftSum+rightSum)
        return true;
    else 
        return false;
}
int main()
{
    //Create BST
    Node * root = newNode(194);
    root->left=newNode(45);
    root->left->left=newNode(7);
    root->left->right=newNode(19);
    root->left->right->left=newNode(11);
    root->left->right->right=newNode(8);
    root->right=newNode(52);
    root->right->left=newNode(10);
    root->right->right=newNode(21);
    root->right->right->right=newNode(9);
    root->right->right->left=newNode(3);
//    root->right->right->left->left=newNode(3);
    root->right->right->right->left=newNode(4);
    root->right->right->right->right=newNode(5);
    cout<<"Check for given tree as sum tree came out as "<<CheckIfSumTree(root)<<endl;
}
