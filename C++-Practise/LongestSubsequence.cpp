#include <iostream>
#include <string>
using namespace std;

int LongestSubsequenceSize(string string1, string string2){
    int length1 = string1.size();
    int length2 = string2.size();
    int subsequenceArray[length1+1][length2+1];
    int count=0;
    string longestSub;
    for(int i=0; i<=length1; i++){
        for(int j=0; j<=length2; j++){
            if(i==0 || j==0){
                subsequenceArray[i][j]=0;
            }
            else if(string1[i-1]==string2[j-1]){
                subsequenceArray[i][j]=subsequenceArray[i-1][j-1]+1;
                if(subsequenceArray[i][j]>count){
                    cout<<"String is "<<string1[i-1]<<endl;
                    count++;
                }
            }
            else{
                subsequenceArray[i][j]=max(subsequenceArray[i-1][j], subsequenceArray[i][j-1]);
            }
        }
    }
    //cout<<"Longest subsequence is "<<longestSub<<endl;
    return count;
}

int main(){
    cout<<"Enter string 1"<<endl;
    string string1;
    string string2;
    cin>>string1;
    cout<<"Enter string 2"<<endl;
    cin>>string2;
    int longestSubsequence = LongestSubsequenceSize(string1, string2);
    cout<<"Size of longest subsequence is "<<longestSubsequence<<endl;
}
