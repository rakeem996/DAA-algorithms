#include <iostream>
#include <string>
#include <vector>
using namespace std;

class solutions
{
public:
    bool isSafe(int col, vector<string> &board, int row, int n)
    {
        int i = row , j = col ;
        while (col >= 0 && row >= 0)
        {
            if (board[row][col] == 'Q')
                return false;

            col--;
            row--;
        }

        row = i; col = j;
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        row = i; col = j;
        while (row < n && col <= 0)
        {
            if (board[row][col] == 'Q')
                return false;

            row++;
            col--;
        }

        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {

        if (col == n)
        {
            
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(col, board, row, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> NQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }

        solve(0, board, ans, n);
        for (int i = 0; i <n; i++)
        {

            for (int j = 0; j < n; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        return ans;
    }
};

int main()
{
    int n;
    cout << "enter the size : ";
    cin >> n;
    solutions sol1;
    sol1.NQueens(n);
    return 0;
}