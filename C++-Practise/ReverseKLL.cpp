#include <iostream>
#include <string>

using namespace std;

struct Node 
{
    int value;
    Node * next;
};

Node * newNode(int nValue)
{
    Node * myNode = new Node();
    myNode->value = nValue;
    myNode->next = NULL;
    return myNode;
};

Node * swapNode(Node * begin, int n)
{
    Node * end = begin;
    while(n>1)
    {
        if(end->next)
        {
            end=end->next;
            n--;
        }
        else
            return NULL;
    }
};

void Reverse(Node * begin, int k)
{
    int tempK=k;
    Node * tempB = begin;
    if(tempB == NULL)
        return;
    while(tempK>1)
    {
        Node * end = swapNode(tempB, tempK);
        if(end != NULL)
        {
            int temp = tempB->value;
            tempB->value = end->value;
            end->value=temp;
            tempK=tempK-2;
            tempB=tempB->next;
        }
        else 
            return;
    }
    Reverse(swapNode(begin, k+1), k);
};
int main ()
{
    Node * first = newNode(1);
    first->next = newNode(2);
    first->next->next = newNode(3);
    first->next->next->next = newNode(4);
    first->next->next->next->next = newNode(5);
    first->next->next->next->next->next = newNode(6);
    first->next->next->next->next->next->next = newNode(7);
    first->next->next->next->next->next->next->next = newNode(8);
    int k=3;
    Reverse(first, k);
    while(first->next)
    {
        cout<<"Value is "<<first->value<<endl;
        first=first->next;
    }
    cout<<"Value is "<<first->value<<endl;
}
