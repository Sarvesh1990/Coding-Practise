#include <iostream>
#include <string>
using namespace std;

class RedBlack
{
    public:
    int key;
    RedBlack * left;
    RedBlack * right;
    bool color;
    RedBlack(int Key, RedBlack * Left, RedBlack * Right, bool Color)
    {
        key = Key;
        left = Left;
        right = Right;
        color = Color;
    }
    
};

void Insert(RedBlack * head, int key);

int main()
{
    RedBlack * head = new RedBlack(32, NULL, NULL, false);
    Insert(head, 11);
    cout<< head->left->key<<endl;
}

void Insert (RedBlack * head, int Key)
{
    if(Key<=head->key)
    {
        if(!head->left)
        {
            head->left=new RedBlack(Key, NULL, NULL, true);
        }
    }
}
