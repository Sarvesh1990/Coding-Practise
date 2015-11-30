#include<iostream>
#include<cstdio>

using namespace std;

int T,n;
int res;

int main()
{
    scanf("%d",&T);

    for(int z=0; z<T; ++z)
    {
        scanf("%d",&n);

        res=0;
        int id,sid;
        for(int i=0; i<n; ++i)
        {
            scanf("%d%d",&id,&sid);
            res+=(id-sid);
        }

        printf("%d\n",res);
    }
} 


