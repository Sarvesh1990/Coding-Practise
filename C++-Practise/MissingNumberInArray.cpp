#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

void FindRepeatedNumber(int array[]){
    for (int i = 0; i < sizeof(array); i++) {
        if(array[abs(array[i])] > 0){
            array[abs(array[i])]=-array[abs(array[i])];
        }
        else{
            cout<<"Repeated number is "<<abs(array[i])<<endl;
            break;
        }
    }
}
int main()
{
    int length;
    cout<<"Give length of array"<<endl;
    cin>>length;
    int array[length];
    int i;      
    for (i = 0; i < length; i++) {
        cin>>array[i];                      
    }
    FindRepeatedNumber(array);
}
















