#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
using namespace std;

int LongestPalinSubStr(string str1, int length1);

int main(){
    int length1;
    cout<<"Enter lengths of string"<<endl;
    cin>>length1;
    cout<<"Enter first string"<<endl;
    string str1;
    cin>>str1;
    cout<<"Maximum length of palindromic substring is "<<LongestPalinSubStr(str1, length1)<<endl;
}

int LongestPalinSubStr(string str1, int length1){
    int SubStrLength[length1][length1];
    for(int i=0; i<length1; i++)
        SubStrLength[i][i]=1;
    int gap;
    for(gap=2; gap<=length1; gap++ ){
        for(int i=0; i<length1-gap+1; i++){
            int j=i+gap-1;
            if(str1[i]==str1[j] && gap==2){
                SubStrLength[i][j]=2;
            }
            else if(str1[i]==str1[j]){
                SubStrLength[i][j]=SubStrLength[i+1][j-1]+2;
            }
            else
                SubStrLength[i][j]=(SubStrLength[i+1][j]>SubStrLength[i][j-1])? SubStrLength[i+1][j]:SubStrLength[i][j-1];
        }
    }
    return SubStrLength[0][length1-1];
}
