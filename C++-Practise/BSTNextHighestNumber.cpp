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

int NextHighest(Node * root, int k)
{
    int nextHigh;
    if(root->value == k)
    {
        if(root->right)
        {
            Node * temp = root->right;
            while(temp->left!=NULL)
                temp=temp->left;
            return temp->value;
        }
        else
            return root->value;
    }
    else if (k<root->value)
    {
        if(root->left)
            nextHigh=NextHighest(root->left, k);
        else
            return root->value;
    }
    else
    {
        if(root->right)
            nextHigh = NextHighest(root->right, k);
        else
            return root->value;
    }

    if(nextHigh!=k)
        return nextHigh;
    
    else if(nextHigh==k)
    {
        if(root->value>k)
            return root->value;
        else
            return k;
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
    int k = 47;
    int nextHigh = NextHighest(root,k);
    if(nextHigh!=k)
        cout<<"Next highest value is "<<nextHigh<<endl;
    else
        cout<<"Given value is highest"<<endl;
}
