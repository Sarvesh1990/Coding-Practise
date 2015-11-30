#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

//void Sort(map<char, int> map, map<char, int>::iterator it, int size);
//void Merge(map<char, int> map, map<char, int>::iterator it, int size);

using namespace std;
int main()
{
    int nTest;
    cin>>nTest;
    string freq[nTest];
    string cipher[nTest];
    string temp;
    //cout<<"Enter"<<endl;
    getline(cin, temp);
   // map<char,int> freqMap;
   // map<char, int>::iterator freqIt;
    for(int i=0; i<nTest; i++)
    {
        //tline(cin, temp);
      //  cout<<"Give frequency of alphabets"<<endl;
        getline(cin, freq[i]);
        getline(cin, cipher[i]);
    }
    for(int k=0; k<nTest; k++)
    {
        map<char,int> cipherMap;
        map<char,char> Map;
        map<char, int>::iterator mapIt, mapItTemp;
        for(int i=0; i<cipher[k].size(); i++)
        {
            if(int(cipher[k][i])>=97 && int(cipher[k][i])<=122)
            {
                mapIt=cipherMap.find(cipher[k][i]);
                if(mapIt->second==0)
                {
                    cipherMap[cipher[k][i]]=1;
                }
                else
                {
                    mapIt->second=mapIt->second+1;
                }
            }
            else if(int(cipher[k][i])>=65 && int(cipher[k][i])<=90)
            {
                char a = char(int(cipher[k][i])+32);
                //        cout<<"Lowercase is "<<a<<endl;
                mapIt=cipherMap.find(a);
                if(mapIt->second==0)
                {
                    cipherMap[a]=1;
                }
                else
                {
                    mapIt->second=mapIt->second+1;
                }
            }
        }
        // cout<<cipherMap[cipher[1]]<<endl;
        int i=0;
        int size=cipherMap.size();
        char cipherSort[size];
        while(cipherMap.size()>0)
        {
            mapItTemp=cipherMap.begin();
            for(mapIt=cipherMap.begin(); mapIt!=cipherMap.end();mapIt++)
            {
                if(mapIt->second>mapItTemp->second)
                {
                    mapItTemp=mapIt;
                }
                else if(mapIt->second==mapItTemp->second)
                {
                    if(mapIt->first>mapItTemp->first)
                    {
                        mapItTemp=mapIt;
                    }
                }
            }
            cipherSort[i]=mapItTemp->first;
            // cout<<"value of temp"<<mapItTemp->second<<mapItTemp->first<<endl;
            i++;
            cipherMap.erase(mapItTemp);
        }   
        //cout<<cipherSort<<endl;

        int freqSize=freq[k].size();
       // cout<<"Ciphered word is : ";
        for(int l=0; l<size; l++)
        {
            Map[cipherSort[l]]=freq[k][freqSize-1];
            freqSize--;
        }
        for(int m=0; m<cipher[k].size(); m++)
        {
            if(int(cipher[k][m])>=65 && int(cipher[k][m])<=90)
            {
                cout<<char(int(Map[char(int(cipher[k][m])+32)])-32);
            }
            else if(int(cipher[k][m])>=97 && int(cipher[k][m])<=122)
            {
                cout<<Map[cipher[k][m]];
            }
            else
            {
                cout<<cipher[k][m];
            }
        }
        cout<<endl;
    }
	return 0;
}
