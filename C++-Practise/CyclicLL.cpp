#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int value;
    Node * next;
};

Node * newNode(int Value)
{
    Node *  myNode = new Node();
    myNode->value = Value;
    myNode->next = NULL;
    return myNode;
};

int GetCycleValue(Node * start)
{
    Node * root = start;
    Node * dblStart=start->next->next;
    start=start->next;
    while(dblStart!=start)
    {
        dblStart=dblStart->next->next;
        start=start->next;
    }
/*    while(root!=start)
    {
        root=root->next;
        start=start->next;
    }*/
    return start->value;
};

int main()
{
    Node * start = newNode(1);
    start->next=newNode(2);
    start->next->next=newNode(3);
    start->next->next->next=newNode(4);
    start->next->next->next->next=newNode(5);
    start->next->next->next->next->next=newNode(6);
    start->next->next->next->next->next->next=newNode(7);
    start->next->next->next->next->next->next->next=newNode(8);
    start->next->next->next->next->next->next->next->next=newNode(9);
    start->next->next->next->next->next->next->next->next->next=start->next->next;
    int Value = GetCycleValue(start);
    cout<<"Cycle starts at "<<Value<<endl;
}
