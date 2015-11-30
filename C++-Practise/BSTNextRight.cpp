//This program does level order traversal in a BST using Queue with a new pointer called next right
//Initially next right is null
//While doing LO, while inserting in queue we keep level value
//While dequeuing, we check next in queue, if level same, add in next otherwise ditch
#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Node
{
    int value;
    Node * left;
    Node * right;
    Node * nextRight;
};

struct QueueNode{
    int level;
    Node * node;
};

Node * newNode(int number){
    Node * myNode = new Node();
    myNode->value = number;
    myNode->left=myNode->right=myNode->nextRight=NULL;
    return myNode;
};

QueueNode * newQueueNode(int level, Node * node)
{
    QueueNode * myNode = new QueueNode();
    myNode->level = level;
    myNode->node = node;
    return myNode;
};

void LevelOrder(Node * root)
{
    queue <QueueNode *> myQueue;
    QueueNode * queueRoot = newQueueNode(0, root);
    myQueue.push(queueRoot);
    while(!myQueue.empty())
    {
        QueueNode * tempQueue = new QueueNode();
        Node * temp = new Node();
        tempQueue = myQueue.front();
        temp = tempQueue->node;
        myQueue.pop();
        if(myQueue.front()){
            if(myQueue.front()->level == tempQueue->level){
                temp->nextRight=myQueue.front()->node;
            }
        }       
        cout<<"Key is "<<temp->value<< " and next right is "<<temp->nextRight<<endl;
        if(temp->left)
            myQueue.push(newQueueNode(tempQueue->level+1, temp->left));
        if(temp->right)
            myQueue.push(newQueueNode(tempQueue->level+1, temp->right));
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