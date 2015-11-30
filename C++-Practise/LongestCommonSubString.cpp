#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
using namespace std;

int LongestCommonSubStr(string str1, string str2, int length1, int length2);

int main(){
    int length1, length2;
    cout<<"Enter lengths of string"<<endl;
    cin>>length1;
    cin>>length2;
    cout<<"Enter first string"<<endl;
    string str1, str2;
    cin>>str1;
    cout<<"Enter second string"<<endl;
    cin>>str2;
    cout<<"Maximum length of common substring is "<<LongestCommonSubStr(str1, str2, length2, length2)<<" okay "<<endl;
}

int LongestCommonSubStr(string str1, string str2, int length1, int length2){
    int SubStrLength[length1+1][length2+1];
    for(int i=0; i<=length1; i++){
        for(int j=0; j<=length2; j++){
            cout<<"Inside for loop"<<endl;
            if(i==0 || j==0)
                SubStrLength[i][j]=0;
            else if(str1[i]==str2[j]){
                SubStrLength[i][j]=SubStrLength[i-1][j-1]+1;
                cout<<"Equal found"<<endl;
            }
            else
                SubStrLength[i][j]=(SubStrLength[i-1][j]>SubStrLength[i][j-1])? SubStrLength[i-1][j]:SubStrLength[i][j-1];
        }
    }
    return SubStrLength[length1][length2];
}
