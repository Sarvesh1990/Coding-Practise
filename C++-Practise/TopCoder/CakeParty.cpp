#include <iostream>
#include <algorithm> 
#include <string> 
#include <vector> 
#include <math.h> 
using namespace std; 

typedef long long ll; 

#define LS < 
#define Size(x) (int(x.size())) 
#define LET(k,val) typeof(val) k = (val) 
#define CLC(act,val) (*({act; static typeof(val) CLCR; CLCR = (val); &CLCR;})) 
#define FOR(k,a,b) for(typeof(a) k=(a); k LS (b); ++k) 
#define FOLD1(k,a,b,init,act) CLC(LET(k, a); LET(R##k, init); for(++k; k LS (b); ++k) act, R##k) 
#define MAX(k,a,b,x) FOLD1(k,a,b,x, R##k >?= (x)) 

#line 3 "CakeParty.cc" 

string itos(int i){ 
    char buf[64]; 
    sprintf(buf, "%d", i); 
    return buf; 
} 

class CakeParty 
{ 
    public: 
        string makeMove(vector <int> pieces) 
        { 

            cout<<"Making move"<<endl;
            int N = Size(pieces); 

            int M = MAX(k,0,N, pieces[k]); 

            int X = 0; 

            FOR(k,0,N) if(pieces[k] == M) X++; 

            string xx = "a"; 
            FOR(k,0,N) if(pieces[k] == M && itos(k) < xx) xx = itos(k); 

            if(X&1)
            { 

                cout<<"Winning position"<<endl;
                if(X>1) return "CAKE "+xx+" PIECES 1"; 
                int M2 = MAX(k,0,N, pieces[k] == M ? 0 : pieces[k]); 
                if(M2 == 0) return "CAKE "+xx+" PIECES "+itos(M); 
                int X2 = 0; 
                FOR(k,0,N) if(pieces[k] == M2) X2++; 

                if(X2&1) return "CAKE "+xx+" PIECES "+itos(M-M2); 

                int take = M-M2+1; 
                ll pow = 1; 
                while(pow < take) pow *= 10; 
                if(pow <= M) take = pow; 
                return "CAKE "+xx+" PIECES "+itos(take); 
            } 
            
            else 
            { 
                cout<<"Losing postion"<<endl;
                return "CAKE "+xx+" PIECES 1"; 
            } 
            
            return 0; 
        }
};

int main()
{
    vector <int> pieces;
    pieces.push_back(2);
    pieces.push_back(3);
    pieces.push_back(1);
    CakeParty a;
    string str;
    str=a.makeMove(pieces);
    cout<<str<<endl;
    return 0;
} 

