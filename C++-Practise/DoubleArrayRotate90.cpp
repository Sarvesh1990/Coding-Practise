#include <iostream>

using namespace std;

int main()
{
    int m=3;
    int n=4;
    int a[m][n];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];

    int ia[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            ia[i][j] = a[m-j-1][i];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cout<<ia[i][j]<<endl;
}
