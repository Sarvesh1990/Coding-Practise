#include<iostream>
#include<cstdio>
using namespace std;
int scanInt()
{
int noRead=0;
char p=getchar_unlocked();
for(;p<33;){p=getchar_unlocked();};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();
}
return noRead;
};
int check_valid(int n, int check[])
{
    for(int i = 1; i <= n; i ++)
    if(check[i] == 0) return i;
    return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,w,m,wc[505][505],mc[505][505],men[505]={0},women[505]={0},check[505]={0};
        //scanf("%d",&n);
        n = scanInt();
        for(int i = 0; i < n; i ++)
        {
            //scanf("%d",&w);
            w = scanInt();
            int c = 1;
            for(int j = 1; j <= n; j++)
            {
              //  scanf("%d",&m);
                m = scanInt();
                wc[w][m]=c++;
            }
        }
        for(int i = 0; i < n; i ++)
        {
            //scanf("%d",&m);
            m = scanInt();
            for(int j = 1; j <= n; j++)
            {
                //scanf("%d",&w);
                w = scanInt();
                mc[m][j]=w;
            }
        }
       /* for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j++)
            cout<<wc[i][j]<<" ";
            cout<<endl;}*/
        int unmat = 1;
        int g;
        int flag = 1;
        while(1){
            int i;
            for(i = 1; i <= n; i ++)
            {
                w = mc[unmat][i];
                m = women[w];
                if(!m)
                {
                    men[unmat] = w;
                    women[w] = unmat;
                    check[unmat] = 1;
                    break;
                }
              //  cout<<"\n\twoman of preference : "<<w<<"\n\tshe is married to : "<<m;
                if(wc[w][m] < wc[w][unmat])
                continue;
                else if(wc[w][m] == wc[w][unmat])
                {
                    check[unmat] = 1;
                    break;
                }
                if(wc[w][m] > wc[w][unmat])
                {
                    check[unmat] = 1;
                //    cout<<"\n\tI am making check of "<<unmat<<" 1";
                    int w_swap = men[unmat];
                    women[w] = unmat;
                    men[unmat] = w;
                    men[m] = 0;
                    women[w_swap] = 0;
                    unmat = m;
                    flag = 1;
                    check[unmat] = 0;
                  //  cout<<"\n\tnow she is married to :"<<women[w]<<"\n\tnow "<<unmat<<" is unmatched!!\n";
                    break;
                }
            }
            if(i == n+1 && !flag)
            check[unmat] = 1;
        if(!(unmat = check_valid(n,check))) break;
    }
        for(int i = 1; i <= n; i ++)
        printf("%d %d\n",i,men[i]);
    }
    return 0;
}
 