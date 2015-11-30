#include<iostream>
using namespace std;
#define gc getchar_unlocked()

//To get integer inputs using getchar_unlocked
long long int in()
{
    char c;
    long long int t=0;
    c=gc;
    while(c<48||c>57)
        c=gc;
    while(c>=48&&c<=57)
    {
        t=(t<<1)+(t<<3)+c-48;
        c=gc;
    }
    return t;
}
/*
long long int mulmod1(long long int a,long long int b,long long int c){
    long long int x = 0,y=a%c;
    while(b > 0){
        if(b%2== 1){
            x = (x+y)%c;
        }
        y = (y<<=1)%c;
        b >>= 1;
    }
    return x%c;
}*/

long long int mulmod(long long int val, long long int n,long long int mod)
{
    //val%=mod;
    long long int q=((double)val*(double)n/(double)mod);
    long long int res=val*n-mod*q;
    res=(res%mod+mod)%mod;
    return res;
}

int main()
{
    int t;
    t=in();//scanf("%d",&t);
    
    while(t--)
    {
        long long int n,a,b,c;
        n=in();//scanf("%lld",&n); 
        
        long long int ar[n];
        
        for(int i=0;i<n;++i)
            ar[i]=in();//scanf("%lld",&ar[i]);
        
        a=in();b=in();c=in();//scanf("%lld %lld %lld",&a,&b,&c);
        
        char s[n+10];
        scanf("%s",&s);
        
        long long int add=0,mul=1,left=0,right=n-1,x,rev=0;
        
        for(int i=0;i<n;++i)
        {
            if(rev==0)
                x=ar[left];        
            else
                x=ar[right];

            if(s[i]=='A')
            {
                add=(add%c+a%c)%c;     
            }
            else if(s[i]=='M')
            {
                mul=mulmod(mul,b,c);
                add=mulmod(add,b,c);
            }
            else
            {
                if(rev==0)
                {
                    x=ar[right];
                    rev=1;          
                }
                else
                {
                    x=ar[left];
                    rev=0;    
                }
            }      
            
            long long int ans=(mulmod(x,mul,c)+add%c)%c;
            // cout<<"x="<<mul<<" "<<add<<endl;
            printf("%lld ",ans);
            
            if(rev==0)
                left++;
            else
                right--;
        } 
        printf("\n");       
    }    
}
