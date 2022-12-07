#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    typedef pair<int, int> P;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void solve(vector<vector<char>> &board)
    {
        int limj = board[0].size();
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < limj; j++)
            {
                if (board[i][j] == 'O')
                {
                    if (!judgeedg(board, i, j))
                    {
                        BFS(board, i, j);
                    }
                }
            }
        }
    }
    bool judgeedg(vector<vector<char>> &board, int m, int n)
    {
        queue<P> q;
        q.push(P(m, n));
        while (!q.empty())
        {
            P top = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nowx = top.first + dx[i];
                int nowy = top.second + dy[i];
                if (board[nowx][nowy] == 'O')
                {
                    if (nowx > 0 && nowx < board[0].size() - 1 &&
                        nowy > 0 && nowy < board.size() - 1)
                    {
                        q.push(P(nowx, nowy));
                    }
                    else
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    void BFS(vector<vector<char>> &board, int m, int n)
    {
        queue<P> q;
        q.push(P(m, n));
        while (!q.empty())
        {
            P top = q.front();
            q.pop();
            if (board[top.first][top.second] == 'O')
            {
                cout << 'Y' << '\n';
                board[top.first][top.second] = 'X';
                for (int i = 0; i < 4; i++)
                {
                    int nowx = top.first + dx[i];
                    int nowy = top.second + dy[i];
                    q.push(P(nowx, nowy));
                }
            }
        }
    }
};
vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};

int main()
{
    cout << 'Q' << '\n';
    Solution a;
    a.solve(board);

    cout << 'Q' << '\n';

    cout << board.size();

    return 0;
}

