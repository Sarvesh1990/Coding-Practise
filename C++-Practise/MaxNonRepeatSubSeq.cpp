#include <iostream>
#include <map>
using namespace std;

int FindMaximumNonRepeatingSequence(char * array, int length){
    int arrayInt[length];
    map<char, int> mapLastOccur;
    arrayInt[0]=1;
    mapLastOccur[array[0]]=1;
    int max=1;
    for(int i=1; i<length; i++){
        if(mapLastOccur[array[i]]>0){
            if(arrayInt[i-1]<i-mapLastOccur[array[i]]-1){
                arrayInt[i]=arrayInt[i-1]+1;
                if(max<arrayInt[i])
                    max=arrayInt[i];
            }
            else{
                arrayInt[i]=i-mapLastOccur[array[i]];
            }
            mapLastOccur[array[i]]=i+1;
        }
        else{
            arrayInt[i]=arrayInt[i-1]+1;
            mapLastOccur[array[i]]=i+1;
            if(max<arrayInt[i])
                max=arrayInt[i];
        }
    }
    return max;
}


int main(){
    cout<<"Enter length of character array"<<endl;
    int length;
    cin>>length;
    char array[length];
    for(int i=0; i<length; i++){
        cin>>array[i];
    }
    int max = FindMaximumNonRepeatingSequence(array, length);
    cout<<"Maximum length is "<<max<<endl;
}
