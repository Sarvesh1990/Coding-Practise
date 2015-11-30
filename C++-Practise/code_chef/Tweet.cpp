#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
using namespace std;

int main() 
{ 
    int nTweets=0, nChanges=0;
    cin>>nTweets;
    int tweet[nTweets];
    memset(tweet, 0, sizeof(tweet));
    cin>>nChanges;
    
  /*  for(int i=0; i<nTweets; i++)
    {
        tweet[i]=0;
    }
*/
    int count =0;
    int output[nChanges];
    int j=0;
    string action;
    
    for(int i=0; i<nChanges; i++)
    {
        cin>>action;
        if(!strcmp(action.c_str(), "CLICK"))
        {
            cin>>action;
        }
        if(strcmp(action.c_str(), "CLOSEALL"))
        {
            //tion.erase(0,6);
            int temp=atoi(action.c_str());
            //cout<<"Action is "<<action<<" and integer is "<<temp<<endl;
            if(!tweet[temp-1])
            {
                tweet[temp-1]=1;
                count++;
                output[j]=count;
                j++;
                //ut<<count<<endl;
            }
            else
            {
                tweet[temp-1]=0;
                count--;
                output[j]=count;
                j++;
                //cout<<count<<endl;
            }
        }
        else
        {
           /* for(int i=0; i<nTweets; i++)
            {
                tweet[i]=0;
            }*/
            memset(tweet, 0, sizeof(tweet));
            count=0;
            output[j]=count;
            j++;
            //cout<<count<<endl;
        }
    }
    for(int i=0; i<nChanges; i++)
    {
        cout<<output[i]<<endl;
    }
    return 0;
}
