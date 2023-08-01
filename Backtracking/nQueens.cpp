#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool canPlace(int row, int col, vector<int> temp)
{
    for (int i = 0; i < temp.size(); i++)
    {
        if (i == row || temp[i] == col || abs(col - temp[i]) == abs(row - i))
        {
            return false;
        }
    }

    return true;
}

void nQueens(int n, int row, vector<vector<int>> &sol, vector<int> &temp)
{
    if (row == n)
    {
        sol.push_back(temp);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (canPlace(row, i, temp))
        {
            temp.push_back(i);
            nQueens(n, row + 1, sol, temp);
            temp.pop_back();
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> res;

    vector<vector<int>> sol;
    vector<int> temp;

    nQueens(n, 0, sol, temp);

    for (int i = 0; i < sol.size(); i++)
    {
        vector<string> tmp;
        for (int j = 0; j < n; j++)
        {
            string s(n , '.');
            s[sol[i][j]] = 'Q';

            // for (int k = 0; k < n; k++)
            // {
            //     if (k == sol[i][j])
            //     {
            //         s.push_back('Q');
            //     }
            //     else
            //     {
            //         s.push_back('.');
            //     }
            // }
            tmp.push_back(s);
        }
        res.push_back(tmp);
    }

    return res;
}

int main()
{

    vector<vector<string>> res = solveNQueens(4);
    cout << res.size() << endl;

    for (int j = 0; j < res.size(); j++)
    {
        for (int i = 0; i < res[j].size(); i++)
        {
            cout << res[j][i] << "  ";
        }
        cout << endl;
    }
    return 0;
}