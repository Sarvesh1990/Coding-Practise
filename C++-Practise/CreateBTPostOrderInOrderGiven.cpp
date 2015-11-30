#include <iostream>
using namespace std;

struct Node{
    char value;
    Node * left;
    Node * right;
};

Node * CreateNode(char value){
    Node * root = new Node();
    root->value = value;
    root->left=root->right = NULL;
    return root;
}

Node * CreateBinaryTree(char * postOrder, char * inOrder, int low1, int low2, int length){
    if(length == 0)
        return NULL;
    char rootValue = postOrder[low1+length-1];
    Node * root = CreateNode(rootValue);
    if(length == 1)
        return root;
    int rootPos;
    for(int i=low2; i<low2+length; i++){
        if(inOrder[i]==rootValue){
            cout<<"Position of root for root value "<<rootValue<<" is "<<i<<endl;
            rootPos=i;
            break;
        }
    }
    root->left=CreateBinaryTree(postOrder, inOrder, low1, low2, rootPos-low2);
    root->right=CreateBinaryTree(postOrder, inOrder, rootPos, rootPos+1, length-rootPos-1+low2);
    return root;
}

int main(){
    cout<<"Enter length of binary tree"<<endl;
    int length;
    cin>>length;
    cout<<"Enter post order traversal"<<endl;
    char postOrder[length];
    for(int i=0; i<length; i++){
        cin>>postOrder[i];
    }
    cout<<"Enter in order traversal"<<endl;
    char inOrder[length];
    for(int i=0; i<length; i++){
        cin>>inOrder[i];
    }
    Node * root = NULL;
    root = CreateBinaryTree(postOrder, inOrder, 0, 0, length);
    cout<<"Root is "<<root->value<<" and root's right's left is "<<root->right->left->value <<" and root left is "<<root->left->value<<endl;
}
