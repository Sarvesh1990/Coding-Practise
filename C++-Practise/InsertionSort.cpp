#include <iostream>
using namespace std;

void InsertionSort(int * a, int length){
    for(int i=0; i<length; i++){
        for(int j=i; j>0; j--){
            if(a[j]<a[j-1]){
                int temp = a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
            else
                break;
        }
    }
}

int main(){
    cout<<"Give number of elements in the array to be sorted"<<endl;
    int length;
    cin>>length;
    int array[length];
    for(int i=0; i<length; i++){
        cin>>array[i];
    }
    InsertionSort(array, length);
    cout<<"Sorted array is "<<endl;
    for(int i=0; i<length; i++)
        cout<<array[i]<<endl;
}
