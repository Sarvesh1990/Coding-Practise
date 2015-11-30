#include <iostream>
using namespace std;

struct Node{
    int value;
    Node * next;
};

Node * root = NULL;

Node * GenerateNode(int value){
    Node * newNode = new Node();
    newNode->next=NULL;
    newNode->value=value;
    return newNode;
}

Node * Enqueue(Node * last, int value)
{
    if(last==NULL)
        last=GenerateNode(value);
    else{
        Node * temp = GenerateNode(value);
        last->next=temp;
        last=temp;
    }
    Node * tempRoot = root;
    if(tempRoot==NULL){
        tempRoot=GenerateNode(value);
        root=tempRoot;
    }
    else if(tempRoot->value>=value){
        Node * temp = GenerateNode(value);
        temp->next=tempRoot;
        tempRoot=temp;
        root=tempRoot;
    }
    else{
        while(tempRoot->next){
            if(tempRoot->next->value <= value)
                tempRoot=tempRoot->next;
            else{
                break;
            }
        }
        Node * temp = GenerateNode(value);
        temp->next=tempRoot->next;
        tempRoot->next=temp;
    }
    return last;
}

Node * Dequeue (Node * first)
{
    int value = first->value;
    if(first==NULL);
    else
        first=first->next;
    Node * tempRoot = root;
    if(tempRoot->value == value){
        root=root->next;
    }
    else{
        while(tempRoot->next->value != value)
            tempRoot=tempRoot->next;
        tempRoot->next=tempRoot->next->next;
    }
    return first;
}

int main()
{
    Node * last = NULL;
    last=Enqueue(last, 3);
    Node * first=last;
    last=Enqueue(last, 1);
    last=Enqueue(last, 4);
    last=Enqueue(last, 2);
    Node * tempRoot = root;
    first=Dequeue(first);
    first=Dequeue(first);
    first=Dequeue(first);
    first=Dequeue(first);
    if(root)
        cout<<"Minimum is "<<root->value<<endl;
}
