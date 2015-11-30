#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define size (high-low)+1
class Node
{
    public:
    Node* node;
    int value;
};

int main()
{
    string line;
    Node* first; 
    Node* last;
    last = new Node();
    first = new Node();
    Node* push(Node* first, int value);
    Node* Kill(Node* first);
    string path = getenv("FLEXSYS");
    path.erase((path.end()-7),path.end());
    path+= "Practise/";
    path+= "Last.txt";    
    ifstream myfile (path.c_str());
    if (myfile.is_open())
    {
        getline(myfile,line);
        last=push(first, atoi(line.c_str()));
        first=last;
        while ( getline (myfile,line) )
        {
            first=push(first, atoi(line.c_str()));
           // cout<<first->value<<endl;
        }
        first->node=last;
        myfile.close();
    }
    else cout << "Unable to open file";
    first=Kill(last);
    cout<<first->value<<endl;
}

Node* push(Node* first, int value)
{
    if(!first->value)
    {
        Node* temp = new Node();
        temp->value=value;
        temp->node = NULL;
        return temp;
    }
    else
    {
        Node* temp = new Node();
        temp->value=value;
        first->node=temp;
        return temp;
    }
}

Node* Kill(Node* first)
{
    while(first->node != first)
    {
        first->node=first->node->node;
        first=first->node;
    }
    return first;
}
