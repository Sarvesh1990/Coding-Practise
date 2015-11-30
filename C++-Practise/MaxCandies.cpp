//This program returns maximum number of candies we can collect while traversing a matrix where each cell contains some candies from left upper corner to right bottom corner.
//Use Dynamic Programming
#include <iostream>
using namespace std;

int FindSum(int matrix[3][3], int row, int column) 
{
    int cost[3][3];
    int i, j;
    cost[0][0]=matrix[0][0];
    for(i=1; i<row; i++)
    {
        cost[i][0]=cost[i-1][0]+matrix[i][0];
    }
    for(j=1; j<column; j++)
    {
        cost[0][j]=cost[0][j-1]+matrix[0][j];
    }
    for(i=1; i<row; i++)
        for(j=1; j<column; j++)
        {
            cost[i][j]=max(cost[i-1][j],cost[i][j-1])+matrix[i][j];
        }
    return cost[row-1][column-1];
}
int main()
{
        int matrix[3][3]={{1,2,3}, {4,8,2} ,{1,5,3}};
        int sum = FindSum(matrix, 3, 3);
        cout<<"Maximum candies collected can be "<<sum<<endl;
}

