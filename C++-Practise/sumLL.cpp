//This program generates sum of two linked list of same size, use recursion, starts with first, reaches last using recursion and then keep passing carry
#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node * next;
};

Node * newNode(int Value)
{
    Node * myNode = new Node();
    myNode->value=Value;
    myNode->next=NULL;
    return myNode;
}
Node * sumNode = NULL;
int Sum(Node * begin1, Node * begin2)
{
    cout<<"Inside sum"<<endl;
    int carry=0;
    if(begin1->next)
    {
        carry=Sum(begin1->next, begin2->next);
    }
    Node * temp = newNode((begin1->value+begin2->value+carry)%10);
    temp->next=sumNode;
    sumNode=temp;
    return (begin1->value+begin2->value+carry)/10;
}
int main()
{
    Node * begin1 = newNode(1);
    begin1->next=newNode(2);
    begin1->next->next=newNode(3);
    begin1->next->next->next=newNode(4);
    Node * begin2 = newNode(5);
    begin2->next=newNode(6);
    begin2->next->next=newNode(7);
    begin2->next->next->next=newNode(8);
    int carry = Sum(begin1, begin2);
    if(carry>0)
    {
        Node * temp = newNode(carry);
        temp->next=sumNode;
        sumNode=temp;
    }
    while(sumNode->next)
    {
        cout<<"Value is "<<sumNode->value<<endl;
        sumNode=sumNode->next;
    }
    cout<<"Value is "<<sumNode->value<<endl;
}
