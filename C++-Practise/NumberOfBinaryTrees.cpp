#include <iostream>
using namespace std;

int TotalBinaryTree(int n){
    if(n==0)
        return 1;
    if(n==1)
        return 1;
    int i=0;
    int j=0;
    int TotalTree=0;
    for(int i=0; i<n; i++){
            TotalTree+=TotalBinaryTree(i)*TotalBinaryTree(n-i-1);
    }
    return TotalTree;
}

int main(){
	cout<<"Enter"<<endl;
	int n;
	cin>>n;
	cout<<"Total tree is "<<TotalBinaryTree(n)<<endl;
}

