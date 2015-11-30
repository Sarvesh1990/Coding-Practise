#include <iostream>
using namespace std;

class Node
{
    public:
    Node();
    char key;
    int value;
    int size;
    Node *left;
    Node *right;
};

Node::Node()
{
    //cout<<"Constructor called"<<endl;
    size=0; 
    value=0;
}
void Insert(Node *root, char a, int n)
{
    if(!root->key)
    {
       // cout<<"No root"<<endl;
        root->key=a;
        root->value=n;
        root->size=1;
        root->right=new Node();
        root->left=new Node();
    }
    else
    {
        //cout<<"Root is there"<<endl;
        if(a>root->key)
        {
            if(root->right->key)
            {
               // cout<<"Right is there"<<endl;
                Insert(root->right, a, n);
            }            
            else
            {
                //cout<<"Right not there"<<endl;
                root->right->key=a;
                root->right->value=n;
                root->right->size=1;
                root->right->right=new Node();
                root->right->left=new Node();
            }
            root->size=1+root->right->size+root->left->size;
        }
        else if(a<root->key)
        {
            if(root->left->key) 
            {
                //cout<<"Left is there with key "<<a<<" and root key "<<root->left->key<<endl;
                Insert(root->left, a, n);
            }                
            else
            {
                //cout<<"Left is not there"<<endl;
                root->left->key=a;
                root->left->value=n;
                root->left->size=1;
                root->left->right=new Node();
                root->left->left=new Node();
            }
            root->size=1+root->left->size+root->right->size;
        }
        else if(a==root->key)
        {
            root->value=n;
        }
    }
}

void Iterate(Node *node)
{
    if(node->left->key)
    {
        Iterate(node->left);
    }
    cout<<"Value is " <<node->key<<endl;
    if(node->right->key)
    {
        Iterate(node->right);
    }
}

void Number(Node *node, int n)
{
    if(node->size<n)
    {
        cout<<"Number of elements in tree is less than "<<n<<endl;
    }
    if(node->left->size >=n)
    {
        Number(node->left, n);
    }
    else if(node->left->size<n && n-node->left->size>1)
    {
        Number(node->right, (n-node->left->size)-1);
    }
    else
    {
        cout<<"Number is "<<node->key<<endl;
    }
}

Node* Minimum(Node* node)
{
    Node *min;
    if(node->left->key)
    {
        min=Minimum(node->left);
        return min;
    }    
    else return node;
}

void Delete(Node *node)
{
    if(!node->left->key && node->right->key)
    {
        node->key=node->right->key;
        node->size=node->right->size;
        node->value=node->right->value;
        node->left=node->right->left;
        node->right=node->right->right;
    }
    else if(!node->right->key && !node->left->key)
    {
        node->key=NULL;
        node->size=0;
        node->value=0;
    }
}

void Delete(Node *node, int n)
{
    if(node->size<n)
    {
        cout<<"Number of elements in tree is less than "<<n<<endl;
    }
    if(node->left->size >=n)
    {
        Delete(node->left, n);
    }
    else if(node->left->size<n && n-node->left->size>1)
    {
        Delete(node->right, (n-node->left->size)-1);
    }
    else
    {
        if(!node->left->key && node->right->key)
        {
            node->key=node->right->key;
            node->size=node->right->size;
            node->value=node->right->value;
            node->left=node->right->left;
            node->right=node->right->right;
        }
        else if(!node->right->key && node->left->key)
        {
            node->key=node->left->key;
            node->size=node->left->size;
            node->value=node->left->value;
            node->right=node->left->right;
            node->left=node->left->left;
        }
        else if(!node->right->key && !node->left->key)
        {
            node->key=NULL;
            node->size=0;
            node->value=0;
        }
        else
        {
            Node *min = Minimum(node->right);
            node->key=min->key;
            node->value=min->value;
            node->size=min->size;
            Delete(min);
        }
    }
}

int main()
{
    Node *root;
    root = new Node();
    Insert(root, 'A', 30); 
    Insert(root, 'D', 23);
    Insert(root, 'B', 20);
    Insert(root, 'A', 11);
    Insert(root, 'K', 12);
    Insert(root, 'G', 1);
    Insert(root, 'F', 1);
    Insert(root, 'H', 22);
    if(root)
    {
        cout<<"For key "<<root->right->key<<" size is "<<root->right->size<<endl;
    }
    Iterate(root);
    Number(root, 4);
    Delete(root, 1);
    Delete(root, 2);
    Iterate(root);
    Delete(root,2);
    Iterate(root);
}
