#include "iostream"
#include "algorithm"
#include "queue"
#include "vector"
typedef std::pair<int, int> PII;

using namespace std;

int w, h;
char g[25][25];
int ans = -1e9;
int x, y;
int cnt;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs() {
    queue<PII> q;
    q.push({x, y});
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int x1 = t.first + dx[i];
            int y1 = t.second + dy[i];
            if(g[x1][y1] == '.' && x1 >= 1 && x1 <= h && y1 >= 1 && y1 <= w) 
            {
                q.push({x1, y1});
                cnt ++;
            }
        }
    }
    
    
}
int main()
{
    cin >> w >> h;
    for (int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++){ 
            cin >> g[i][j];
            if(g[i][j] == '@') {
                x = i, y = j;
            }
       }
    }      
    bfs();
   // cout << cnt << '\n';
        return 0;
}
