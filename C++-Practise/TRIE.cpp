#include <iostream>
#include <string>
#define DIFF(c) ((int)c - (int)'a')
using namespace std;
struct Node
{
    int value;
    Node * children [26];
};

Node * newNode()
{
    Node * myNode = new Node();
    myNode->value=0;
    for(int i=0; i<26; i++)
        myNode->children[i]=NULL;
    return myNode;
}
/*
int DIFF(char c)
{
    return ((int)c - (int)'a');
}
*/
void Insert(Node * root, char * key, int myValue)
{
    int length = strlen(key);
    for(int i=0; i<length; i++)
    {
        if(!root->children[DIFF(key[i])])
            root->children[DIFF(key[i])]=newNode();
        root=root->children[DIFF(key[i])];
    }
    root->value=myValue;
}
void Search (Node * root, char * key)
{
    int length = strlen(key);
    bool flag=true;
    for(int i=0; i<length; i++)
    {
        if(!root->children[DIFF(key[i])])
        {
            flag=false;
            break;
        }
        else
        {
            root=root->children[DIFF(key[i])];
        }
    }
    if(!flag)
    {
        cout<<"Word not present"<<endl;
        return;
    }
    if(root->value > 0)
        cout<<"Word is there with value "<<root->value<<endl;
    else
        cout<<"Word not present"<<endl;
}
int main()
{
    char keys[][9] = {"the", "a", "there", "answer", "any", "by", "anything", "bye", "their"};
    Node * root = newNode();
    for(int i=0; i<9; i++)
    {
        Insert(root, keys[i], i);
    }
    Search(root, "answer");
    Search(root, "an");
    Search(root,"any");
    Search(root,"anything");
}
