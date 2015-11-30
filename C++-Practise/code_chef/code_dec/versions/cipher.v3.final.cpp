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
    string freq;
    string cipher;
    map<char,int> cipherMap;
    map<char,char> Map;
    map<char, int>::iterator mapIt, mapItTemp;
    cout<<"Give frequency of alphabets"<<endl;
    getline(cin, freq);
    cout<<"Give cipher"<<endl;
    getline(cin, cipher);
    for(int i=0; i<cipher.size(); i++)
    {
        if(int(cipher[i])>=97 && int(cipher[i])<=122)
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
        else if(int(cipher[i])>=65 && int(cipher[i])<=90)
        {
            char a = char(int(cipher[i])+32);
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
    
    int freqSize=freq.size();
    cout<<"Ciphered word is : ";
    for(int k=0; k<size; k++)
    {
        Map[cipherSort[k]]=freq[freqSize-1];
        freqSize--;
    }
    for(int m=0; m<cipher.size(); m++)
    {
        if(int(cipher[m])>=65 && int(cipher[m])<=90)
        {
            cout<<Map[char(int(cipher[m])+32)];
        }
        else if(int(cipher[m])>=97 && int(cipher[m])<=122)
        {
            cout<<Map[cipher[m]];
        }
        else
        {
            cout<<cipher[m];
        }
    }
    cout<<endl;
}



/*
void Sort(map<char, int> map, map<char, int>::iterator it, int size);
{
    if(size>1)
    {
        Sort(aSort, low, (low+high)/2);
        Sort(aSort, ((low+high)/2)+1, high);
    }
    else return ;
    Merge(aSort,low,high);
}

void Sort(map<char, int> map, map<char, int>::iterator it, int size);
 {
    int aTemp[size];
    for(int i=low; i<=high; i++)
    {
        aTemp[i]=aMerge[i];
    }
    int low1=low;
    int high1=(low+high)/2;
    int low2=((low+high)/2)+1;
    int high2=high;
    while(low1<=high1 &&  low2<=high2)
    {
        if(aTemp[low1]<=aTemp[low2])
        {
            aMerge[low]=aTemp[low1];
            low++;
            low1++;
        }
        else
        {
            aMerge[low]=aTemp[low2];
            low++;
            low2++;
        }
    }
    if(low1>high1)
    {
        while(low2<=high2)
        {
            aMerge[low]=aTemp[low2];
            low2++;
            low++;
        }
    }
    else
    {
         while(low1<=high1)
        {
            aMerge[low]=aTemp[low1];
            low1++;
            low++;
        }
    }
}*/
