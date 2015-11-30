#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int value;
    Node * left;
    Node * right;
    Node * next;
};

Node * newNode(int number)
{
    Node * myNode = new Node();
    myNode->value = number;
    myNode->left=myNode->right=myNode->next=NULL;
    return myNode;
};  

Node * GetNextRoot (Node * root){
    if(root==NULL)
        return NULL;
    if(root->left)
        return root->left;
    else if (root->right)
        return root->right;
    else
        return GetNextRoot(root->next);
}

void PointNext(Node * root){
    if(root==NULL)
        return;
    Node * nextLevelNode = NULL;
    Node * tempRoot = root;
    //Find out leftmost node of next level to be passed at the end to continue recursion
    while(root->next != NULL){//Keep looking for a node in the whole level
        if(root->left){
            nextLevelNode = root->left;
            break;
        }
        else if (root->right){
            nextLevelNode = root->right;
            break;
        }
        else
            root=root->next;
    }
    if(nextLevelNode==NULL){//It means we are currently at the rightmost node of the level
        if(root->left)
            nextLevelNode = root->left;
        else if (root->right)
            nextLevelNode = root->right;
        else
            return;
    }

    while(tempRoot->next != NULL){//Once the leftmost node is found, assign next pointer to every node of next level
        if(tempRoot->left){
            if(tempRoot->right){
                tempRoot->left->next=tempRoot->right;//If right node is there for left, assign right
            }
            else{
                tempRoot->left->next = GetNextRoot(tempRoot->next);//Search for nearest node 
            }
        }
        if(tempRoot->right){
            tempRoot->right->next = GetNextRoot(tempRoot->next);
        }
        tempRoot=tempRoot->next;
    }

    if(tempRoot->left){
        tempRoot->left->next = tempRoot->right;
    }
    PointNext(nextLevelNode);
}

int main()
{
//    Create BST
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
    PointNext(root);
    cout<<"Value is "<<root->left->right->right->next->value<<endl;
}
