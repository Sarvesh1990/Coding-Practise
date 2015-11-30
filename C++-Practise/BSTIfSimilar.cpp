#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

struct Node
{
    int value;
    Node * left;
    Node * right;
};

Node * newNode(int number)
{
    Node * myNode = new Node();
    myNode->value = number;
    myNode->left=myNode->right=NULL;
    return myNode;
};   

bool IfSimilar(Node * root1, Node * root2){
   stack <Node *> myStack1;
   stack <Node *> myStack2;
   map<int, int> myMap;
   if(root1==NULL && root2==NULL)
       return true;
   if(root1==NULL || root2==NULL)
       return false;
   while((!myStack1.empty() || root1!=NULL) || (!myStack2.empty() || root2!=NULL)){
        if(root1 != NULL){
            myStack1.push(root1);
            root1=root1->left;
        }
        else{
            if(!myStack1.empty()){
                root1 = myStack1.top()->right;
                if(myMap[myStack1.top()->value])
                    myMap[myStack1.top()->value]=myMap[myStack1.top()->value]+1;
                else
                    myMap[myStack1.top()->value]=1;
                 myStack1.pop();
            }
        }
        if(root2 != NULL){
            myStack2.push(root2);
            root2=root2->left;
        }
        else{
            if(!myStack2.empty()){
                root2 = myStack2.top()->right;
                if(myMap[myStack2.top()->value])
                    myMap[myStack2.top()->value]=myMap[myStack2.top()->value]-1;
                else
                    myMap[myStack2.top()->value]=-1;
                myStack2.pop();
            }
        }
   }
   map<int, int> :: iterator myIter;
   bool flag = true;
   for(myIter=myMap.begin(); myIter!=myMap.end(); myIter++){
       if(myIter->second!=0){
           flag=false;
           cout<<"Extra value "<<myIter->first<<endl;
           break;
       }
   }
   return flag;
}

int main()
{
    //Create BST
    Node * root1 = newNode(25);
    root1->left=newNode(14);
    root1->left->left=newNode(10);
    root1->left->right=newNode(18);
    root1->left->right->left=newNode(17);
    root1->left->right->right=newNode(14);
    root1->right=newNode(35);
    root1->right->left=newNode(30);
    root1->right->right=newNode(45);
    root1->right->right->right=newNode(55);
    
    Node * root2 = newNode(25);
    root2->left=newNode(14);
    root2->left->left=newNode(17);
    root2->left->right=newNode(14);
    root2->left->right->left=newNode(18);
    root2->left->right->right=newNode(10);
    root2->right=newNode(45);
    root2->right->left=newNode(30);
    root2->right->left->right=newNode(55);
    
    bool ifSimilar = IfSimilar(root1, root2);
    if(ifSimilar)
        cout<<"Both the binary trees are similar"<<endl;
    else
        cout<<"Given binary trees are not similar"<<endl;
}
