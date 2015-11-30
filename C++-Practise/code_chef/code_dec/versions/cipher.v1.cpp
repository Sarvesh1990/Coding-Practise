#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#define Size (high-low)+1
using namespace std;

string aTemp;
string Sort(const char* aSort, int low, int high);
string Merge(const char* aMerge, int low,int high);

int main()
{
    string freq;
    string cipher;
    string cipherSort;
    map<char,int> cipherMap;
    map<char, int>::iterator mapIt;
    cout<<"Give frequency of alphabets"<<endl;
    getline(cin, freq);
    cout<<"Give cipher"<<endl;
    getline(cin, cipher);
    cipherSort=Sort(cipher.c_str(),0,(cipher.size())-1);
    cout<<cipherSort[1]<<endl;
    cout<<"size of cipherSort "<<cipherSort.size()<<endl;
    int j=0;
    string final;
    for(int i=0; i<cipherSort.size(); i++)
    {
        cout<<"inside for"<<endl;
        if(cipherSort[i]==cipherSort[i+1])
        {
            cout<<"yes for "<<cipherSort[i];
        }
        else
        {
            cout<<"Assigning value of cipherSort "<<cipherSort[i]<<endl;
            final[j]=cipherSort[i];
            j++;
        }
    }
    cout<<"Sorted string is "<<final;
}

string Sort(const char* aSort, int low, int high)
{
    string cipherSort;
    if(Size>1)
    {
        Sort(aSort, low, (low+high)/2);
        Sort(aSort, ((low+high)/2)+1, high);
    }
    else return "an";
    aTemp=Merge(aSort,low,high);
    return aTemp;
}

string Merge(const char* aMerge, int low, int high)
{
    /*r(int i=low; i<=high; i++)
    {
        aTemp[i]=aMerge[i];
    }*/
    int low1=low;
    int high1=(low+high)/2;
    int low2=((low+high)/2)+1;
    int high2=high;
    while(low1<=high1 &&  low2<=high2)
    {
        if(aMerge[low1]<=aMerge[low2])
        {
            aTemp[low]=aMerge[low1];
            low++;
            low1++;
        }
        else
        {
            aTemp[low]=aMerge[low2];
            low++;
            low2++;
        }
    }
    if(low1>high1)
    {
        while(low2<=high2)
        {
            aTemp[low]=aMerge[low2];
            low2++;
            low++;
        }
    }
    else
    {
         while(low1<=high1)
        {
            aTemp[low]=aMerge[low1];
            low1++;
            low++;
        }
    }
    return aTemp;
}

