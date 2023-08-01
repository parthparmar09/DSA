#include <iostream>
#include <vector>
using namespace std;

//for any vertice 'k' from 1 to n , if for all edges (i ,j) => D(i ,j) = min(D(i , k) + D(k ,j) , D(i ,j)) 

void floydWarshals(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][k] == -1 || matrix[k][j] == -1)
                {
                    continue;
                }
                if (matrix[i][j] == -1 || matrix[i][j] > matrix[i][k] + matrix[k][j])
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
}