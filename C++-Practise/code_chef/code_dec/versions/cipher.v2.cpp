#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main()
{
    string freq;
    string cipher;
    map<char,int> cipherMap;
    map<char, int>::iterator mapIt;
    cout<<"Give frequency of alphabets"<<endl;
    getline(cin, freq);
    cout<<"Give cipher"<<endl;
    getline(cin, cipher);
    for(int i=0; i<cipher.size(); i++)
    {
        mapIt=cipherMap.find(cipher[i]);
        if(mapIt->second==0)
        {
            cipherMap[cipher[i]]=1;
        }
        else
        {
            mapIt->second=mapIt->second+1;
        }
    }
    cout<<cipherMap[cipher[1]]<<endl;
}


