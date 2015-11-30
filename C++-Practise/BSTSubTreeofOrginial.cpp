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

bool isIdentical (Node * root1, Node * root2)
{
    if(root1 == NULL && root2== NULL)
        return true;
    else if ((root1 == NULL && root2 != NULL) || ( root1 != NULL && root2 == NULL))
        return false;
    else
    {
        if(root1->value != root2->value)
            return false;
        else
        {
            if(isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right))
                return true;
            else return false;
        }
    }
}

bool isSubTree(Node * root1, Node * root2)
{
    if(isIdentical(root1, root2))
        return true;
    if(root1->left)
    {
        if(isSubTree(root1->left, root2))
            return true;
    }
    if(root1->right)
    {
        if(isSubTree(root1->right, root2))
            return true;
    }
    return false;
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
    Node * rootNew = newNode(40);
    rootNew->right=newNode(43);
    rootNew->right->left=newNode(42);
    rootNew->right->right=newNode(44);
   //rootNew->right->left=newNode(17);
    //rootNew->right->right=newNode(20);
    bool myVal = 0;
    myVal = isSubTree(root, rootNew);
    cout<<"Trees are identical? "<<myVal<<endl;
}
