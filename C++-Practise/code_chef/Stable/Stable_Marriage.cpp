#include <iostream>
#include <string>
#include <map>
using namespace std;

class preference
{
    private:
        int couple;
        map<int, int> pref;
        map<int, int> order;
    public:
        int getCouple(){ return couple;}
        void setCouple(int i){ couple =i;}
        int getPref(int i){ return pref[i];}
        void setPref(int i, int j){pref[i]=j;}
        int getOrder(int i){ return order[i];}
        void setOrder(int i, int j){order[i]=j;}

};

map <int,preference *> wifeMap, husMap;

void Check(int j, int i)
{
    int wife=husMap[j]->getOrder(i);
    int prevCouple = wifeMap[wife]->getCouple();
    //cout<<"Wife's prev couple "<<prevCouple<<" with wife "<<wife<<endl;
    if(prevCouple==0)
    {
        wifeMap[wife]->setCouple(j);
        husMap[j]->setCouple(wife);
    }
    else
    {
        if(wifeMap[wife]->getPref(prevCouple)<wifeMap[wife]->getPref(j))
        {
            //cout<<"Inside if"<<endl;
            Check(j, i+1);
        }
        else
        {
           // cout<<"Inside else "<<endl;
            int prev=prevCouple;
            wifeMap[wife]->setCouple(j);
            husMap[j]->setCouple(wife);
            Check(prev, 1);
        }
    }
}
int main()
{
    int nTest, nCouples, wife, hus, wifeList, husList;
    char sWife[10], sHus[10];
    cin>>nTest;
    while(nTest--)
    {
        cin>>nCouples;
        for(int i=0; i<nCouples; i++)
        {
            preference * wifePref;
            wifePref= new preference();
            cin>>wife;
            wifePref->setCouple(0);
            for(int j=0; j<nCouples; j++)
            {
                cin>>wifeList;
                wifePref->setPref(wifeList, j+1);
                wifePref->setOrder(j+1, wifeList);
            }
            wifeMap[wife]=wifePref;
        }
        for(int i=0; i<nCouples; i++)
        {
            preference * husPref;
            husPref= new preference();
            cin>>hus;
            husPref->setCouple(0);
            for(int j=0; j<nCouples; j++)
            {
                cin>>husList;
                husPref->setPref(husList, j+1);
                husPref->setOrder(j+1, husList);
            }
            husMap[hus]=husPref;
            Check(i+1, 1);
        }
        for(int i=1; i<=nCouples; i++)
        {
            cout<<i<<" "<<husMap[i]->getCouple()<<endl;
        }
    }
}
