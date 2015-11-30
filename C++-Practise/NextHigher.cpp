#include <iostream>
using  namespace std;

struct Node{
    int value;
    Node * next;
};

Node * GenerateNode(int value){
    Node * newNode = new Node ();
    newNode->value = value;
    newNode->next=NULL;
    return newNode;
};

Node * Push (Node * first, int value){
    Node * temp = GenerateNode(value);
    temp->next=first;
    first=temp;
    return first;
};

int Peek(Node * first){
    if(first)
        return first->value;
    else
        return -33;
};

Node * Pop (Node * first){
    first=first->next;
    return first;
};    

void NextHigher(int * array, int length){
    Node * first = NULL;
    for(int i=0; i<length; i++){
        if(Peek(first)==-33){
            first=Push(first, i);
        }
        else{
            while(array[Peek(first)]<array[i]){
                array[Peek(first)]=array[i];
                first=Pop(first);
                if(first==NULL)
                    break;
            }
            first=Push(first, i);
        }
    }
    array[length-1]=-1;
}

int main()
{
    cout<<"Give number of elements in the array"<<endl;
    int length;
    cin>>length;
    int array[length];
    int i=0;
    for (i = 0; i < length; i++) {
        cin>>array[i];
    }
    NextHigher(array, length);
    for(int i=0; i<length; i++)
        cout<<array[i]<<endl;
}
