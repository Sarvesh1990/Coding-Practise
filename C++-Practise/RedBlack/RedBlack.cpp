#include <iostream>
#include <string>
using namespace std;

class RedBlack
{
    public:
    char key;
    RedBlack * top;
    RedBlack * left;
    RedBlack * right;
    bool color;
    RedBlack(char Key, RedBlack * Top, RedBlack * Left, RedBlack * Right, bool Color)
    {
        key = Key;
        top = Top;
        left = Left;
        right = Right;
        color = Color;
    }
    
};

RedBlack * Insert(RedBlack * head, char key);
RedBlack * RotateRight(RedBlack * head);
RedBlack * RotateLeft(RedBlack * head);
void ColorFlip(RedBlack * head);
RedBlack * CheckTree(RedBlack * head);
void Iterate (RedBlack * head);

int main()
{
    RedBlack * head = new RedBlack('S', NULL, NULL, NULL, false);
    head=Insert(head, 'E');
    head=Insert(head, 'A');
    head=Insert(head, 'R');
    head=Insert(head, 'C');
    head=Insert(head, 'H');
    head=Insert(head, 'X');
    head=Insert(head, 'M');
    head=Insert(head, 'P');
    head=Insert(head, 'L');
    head=Insert(head, 'D');
    head=Insert(head, 'S');
    head=Insert(head, '1');
    head=Insert(head, '5');
    head=Insert(head, '4');
    head=Insert(head, '1');
    head=Insert(head, '9');
    head=Insert(head, '3');
    cout<<"Head is "<<head->key<<endl;
    Iterate(head);
}
RedBlack * Insert (RedBlack * head, char Key)
{
    if(Key<=head->key)
    {
        if(head->left)
        {
            head=Insert(head->left, Key);
        }
        else
        {
            RedBlack * node = new RedBlack(Key, head, NULL, NULL, true);
            head->left=node;
            head=CheckTree(head);
        }
    }
    else
    {
        if(head->right)
        {
            head=Insert(head->right, Key);
        }
        else
        {
            RedBlack * node = new RedBlack(Key, head, NULL, NULL, true);
            head->right=node;
            head=CheckTree(head);
        }
    }
    return head;
}

RedBlack * CheckTree(RedBlack * head)
{
    if(head->left && head->right)
    {
        if(!head->left->color && head->right->color)
        {
            head=RotateLeft(head);
        }
    }
    else if (head->right)
    {
        head=RotateLeft(head);
    }
    else
    {
        //cout<<"Peace"<<endl;
    }
    if(head->left)
    {
        if(head->left->color && head->color)
        {
            if(head->top)
            {
                head = RotateRight(head);
            }
            else
            {
                //cout<<"Top most pains, peace maar"<<endl;
            }
        }
    }
    if(head->right && head->left)
    {
        if(head->left->color && head->right->color)
        {
            ColorFlip(head);
        }
    }
    if(head->top)
    {
        head = CheckTree(head->top);
    }
    return head;
}

RedBlack * RotateRight(RedBlack * head)
{
    head->top->left=head->right;
    if(head->right)
    {
        head->right->top=head->top;
    }
    head->right=head->top;
    if(head->top->top)
    {
        if(head->top->top->left->key==head->top->key)
        {
            head->top->top->left = head;
        }
        else
        {
            head->top->top->right=head;
        }
        head->top=head->top->top;
    }
    else
        head->top=NULL;
    head->right->top=head;
    head->color=false;
    head->right->color=true;
    return head;
}

RedBlack * RotateLeft(RedBlack * head)
{
    if(head->top)
    {
        if(head->top->left->key==head->key)
        {
            head->top->left=head->right;
        }
        else
        {
            head->top->right=head->right;
        }
    }
    head->right->top=head->top;
    head->top=head->right;
    head->right=head->right->left;
    if(head->right)
    {
        head->right->top=head;
    }
    head->top->left=head;
    head->top->color=head->color;   
    head->color=true;
    return head->top;
}

void ColorFlip(RedBlack * head)
{
    head->left->color=false;
    head->right->color=false;
    head->color=true;
    return;
}

void Iterate(RedBlack * head)
{
    if(!head->left)
    {
        cout<<head->key<<endl;
    }
    else
    {
        Iterate(head->left);
        cout<<head->key<<endl;
        if(head->right)
            Iterate(head->right);
    }
}
