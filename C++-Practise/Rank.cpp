#include <iostream>
#include <map>
using namespace std;

struct Node
{
    int value;
    Node * left;
    Node * right;
};

Node *  newNode(int Value)
{
    Node * myNode = new Node();
    myNode->value = Value;
    myNode->left = myNode->right = NULL;

    return myNode;
};

void Insert(int value, Node * root, map<int, int> * myMap)
{
    if(value<root->value)
    {
        cout<<value<<" is less than "<<root->value<<endl;
        if(root->left)
        {
           Insert(value, root->left, myMap);
           (*myMap)[root->value]=(*myMap)[root->value]+1;
        }
        else
        {
            Node * myNode = newNode(value);
            root->left=myNode;
            (*myMap)[value]=1;
            (*myMap)[root->value]=(*myMap)[root->value]+1;
        }
    }
    else
    {
        if(root->right)
            Insert(value, root->right, myMap);
        else
        {
            Node * myNode = newNode(value);
            root->right=myNode;
            (*myMap)[value]=1;
        }
    }
}

int main()
{
    map<int, int> myMap;
    Node * root = newNode(25);
    myMap[25]=1;
    Insert(25, root, &myMap);
    Insert(14, root, &myMap);
    Insert(10, root, &myMap);
    Insert(35, root, &myMap);
    Insert(45, root, &myMap);
    Insert(30, root, &myMap);
    Insert(40, root, &myMap);
    Insert(38, root, &myMap);
    cout<<"Value for 25 is "<<myMap[25]<<" and for 45 is "<<myMap[45]<<endl;
}
