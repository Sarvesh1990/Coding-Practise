#include <iostream>
#include <string>

using namespace std;

class Node
{
    public:
        int value;
        Node * left;
        Node * right;
        Node(int Value)
        {   
            value = Value;
            left = NULL;
            right = NULL;
        }
};

void ConvertToDLL(Node * root)
{
    if(root->left)
    {
        ConvertToDLL(root->left);
        Node * temp = root->left;
        for(;temp->right!=NULL; temp=temp->right);
        temp->right=root;
        root->left=temp;
    }
    if(root->right)
    {
        ConvertToDLL(root->right);
        Node * temp = root->right;
        for(;temp->left!=NULL; temp=temp->left);
        root->right=temp;
        temp->left=root;
    }
    return;
}
int main()
{
    Node * Node1 = new Node(10);
    Node * Node2 = new Node(12);
    Node * Node3 = new Node(15);
    Node * Node4 = new Node(25);
    Node * Node5 = new Node(30);
    Node * Node6 = new Node(36);
    Node1->left=Node2;
    Node1->right=Node3;
    Node2->left=Node4;
    Node2->right=Node5;
    Node3->left=Node6;
    ConvertToDLL(Node1);
    Node * root = Node1;
    while(root->left!=NULL)
    {
        root = root->left;
    }
    while(root !=NULL)
    {   
        cout<<"Key is "<<root->value<<endl;
        root=root->right;
    }
}
