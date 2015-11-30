#include <iostream>
using namespace std;

bool ifValid(int * array, int index){
    if((array[index]*10+array[index+1])<=26)
        return true;
    else 
        return false;
}

int MaxCombo(int * array, int length){
    int MaxArray[length];
    int j;
    for(j=length-1; j>=0; j--){
        if(j==length-1)
            MaxArray[j]=1;
        else if (j==length-2){
            MaxArray[j]=MaxArray[j+1];
            if(ifValid(array, j))
                MaxArray[j]+=1;
        }
        else{
            MaxArray[j]=MaxArray[j+1];
            if(ifValid(array, j))
                MaxArray[j]+= MaxArray[j+2];
        }
    }
    return MaxArray[0];
}


int main(){
    cout<<"Enter number of elements in array"<<endl;
    int length;
    cin>>length;
    int array[length];
    for(int i=0; i<length; i++){
        cin>>array[i];
    }
    cout<<"Maximum possible combinations are "<<MaxCombo(array, length)<<endl;
}
