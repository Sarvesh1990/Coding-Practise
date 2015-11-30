#include <iostream>
using namespace std;

struct Node{
    int value;
    Node * next;
};

Node * GenerateNode(int value){
    Node * tempNode = new Node();
    tempNode->value = value;
    tempNode->next = NULL;
    return tempNode;
}

Node * ReverseLinkedList(Node * first){
    Node * nextPointer = first->next;
    first->next=NULL;
    Node * temp;
    while(nextPointer){
        temp=nextPointer->next;
        nextPointer->next=first;
        first=nextPointer;
        nextPointer=temp;
    }
    return first;
}

int main(){
    Node * first = GenerateNode(1);
    first->next=GenerateNode(2);
    first->next->next=GenerateNode(3);
    first->next->next->next = GenerateNode(4);
    first = ReverseLinkedList(first);
    while(first){
        cout<<"Value is "<<first->value<<endl;
        first=first->next;
    }
}
