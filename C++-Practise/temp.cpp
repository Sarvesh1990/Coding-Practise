<<<<<<< HEAD
#include <iostream>
#include <string>

=======
#include<map>
#include<iostream>
>>>>>>> 0968b71cd39efb9ccea65cb37e054c17593bad52
using namespace std;

struct Node
{
    int value;
    Node * next;
};

Node * newNode(int Value)
{
    Node * myNode = new Node();
    myNode->value = Value;
    myNode->next=NULL;
    return myNode;
}

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
            return NULL;    //Returns null if number of nodes left is less than n (k from problem)
    }
//    return end;
};

void Reverse(Node * begin, int k)
{
    int tempK=k;
    Node * tempB=begin;
    if(tempB==NULL)
        return;

    while(tempK>1)
    {
        Node * end = swapNode(tempB, tempK); //To get the node after k moves
        if(end != NULL)
        {
            int temp = tempB->value;
            tempB->value = end->value;
            end->value=temp;
            tempK=tempK-2;   // As both first and last swapped
            tempB=tempB->next;
        }
        else
            return;
    }
    Reverse(swapNode(begin,k+1),k); //To reverse next k nodes
};   

int main()
{
    Node * first = newNode(1);
    first->next = newNode(2);
    first->next->next = newNode(3);
    first->next->next->next = newNode(4);
    first->next->next->next->next = newNode(5);
    first->next->next->next->next->next = newNode(6);
    int k=3;

    Reverse(first, k);  //Function to reverse k node

    while(first != NULL)
    {
        cout<<first->value;
        if(first->next)
            cout<<"->";     //To print arrow only till last element;
        first=first->next;
    }
    cout<<endl;
}
