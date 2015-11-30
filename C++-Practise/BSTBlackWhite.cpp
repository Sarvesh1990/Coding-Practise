#include <iostream>
using namespace std;

class Node{
    public:
    int colour;//1 for black, 2 for white
    Node * quad1;
    Node * quad2;
    Node * quad3;
    Node * quad4;
    Node (int colour){
        this->colour=colour;
        this->quad1=this->quad2=this->quad3=this->quad4=NULL;
    }
};
        
Node * CreateIntersection(Node * root1, Node * root2){
    Node * interRoot = new Node(0);
    if(root1->colour==1 && root2->colour==1){//Both are black, make intersection black
        interRoot->colour=1;
        return interRoot;
    }
    if(root1->colour!=0 && root2->colour!=0){//Both fully coloured but not black i.e. atleast one white, make intersection white
        interRoot->colour=2;
        return interRoot;
    }
    if(root1->colour==0 && root2->colour!=0){//One is fully coloured, if colour black, intersection will be like other root, if colour white, intersection will be white
        if(root2->colour==1){
            interRoot=root1;
            return interRoot;
        }
        if(root2->colour==2){
            interRoot=root2;
            return interRoot;
        }
    }
    if(root1->colour!=0 && root2->colour==0){
        if(root1->colour==1){
            interRoot=root2;
            return interRoot;
        }
        if(root1->colour==2){
            interRoot=root1;
            return interRoot;
        }
    }
    //If both non-coloured
    interRoot->quad1 = CreateIntersection(root1->quad1, root2->quad1);
    interRoot->quad2 = CreateIntersection(root1->quad2, root2->quad2);
    interRoot->quad3 = CreateIntersection(root1->quad3, root2->quad3);
    interRoot->quad4 = CreateIntersection(root1->quad4, root2->quad4);
    return interRoot;
}

int main(){
 Node * root1 = new Node(0);
 Node * root2 = new Node(0);
 root1->quad1 = new Node(0);
 root2->quad4 = new Node(0);
 root1->quad1->quad1 = new Node(1);
 root1->quad1->quad2 = new Node(2);
 root1->quad1->quad3 = new Node (2);
 root1->quad1->quad4 = new Node (2);
 root1->quad2= new Node(2);
 root1->quad3 = new Node(2);
 root1->quad4 = new Node(1);;
 root2->quad4->quad1 = new Node(2);
 root2->quad4->quad2 = new Node(1);
 root2->quad4->quad3 = new Node(1);
 root2->quad4->quad4 = new Node(2);
 root2->quad1 = new Node(1);
 root2->quad2 = new Node(2);
 root2->quad3 = new Node(1);
 Node * intersectingRoot = CreateIntersection(root1, root2);
 cout<<"Colour is "<<
}
