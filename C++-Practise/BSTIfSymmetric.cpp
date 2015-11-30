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

bool IsSymmetricHelper(Node * left, Node * right){
    if(left == NULL && right == NULL)
        return true;
    if(left == NULL || right == NULL)
        return false;
    if(left->value != right->value)
        return false;
    return (IsSymmetricHelper(left->left, right->right) && IsSymmetricHelper(left->right, right->left));
}

bool IsSymmetric(Node * root){
    if(root==NULL)
        return true;
    return IsSymmetricHelper(root->left, root->right);
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
    root->right=newNode(14);
    root->right->left=newNode(18);
    root->right->right=newNode(10);
    root->right->left->right=newNode(17);
    root->right->left->left=newNode(20);
    bool isSymmetric = IsSymmetric(root);
    if(isSymmetric)
        cout<<"Given binary tree is symmetric"<<endl;
    else
        cout<<"Given binary tree is not symmetric"<<endl;
}
