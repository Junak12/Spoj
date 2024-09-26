#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

int dx[] = {0, 0, 1, -1, 1, 1, -1, -1}; 
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1}; 

int mx1 = 51, mx2 = 51;
vector<vector<char>> grid (mx1, vector<char> (mx2));
vector<vector<bool>> vis(mx1, vector<bool>(mx2, false));

int dfs (int i , int j, int n, int m) {
    vis[i][j] = true;
    int cnt = 1;
    for (int k = 0; k < 8; ++k) {
        int ni = dx[k] + i;
        int nj = dy[k] + j;
        if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj] && grid[ni][nj] == grid[i][j] + 1) {
            cnt = max(cnt, 1 + dfs(ni, nj, n, m));
        } 
    }
    return cnt;
}


int main(){
    opt();
    int t;
    //cin>>t;
    t = 0;
    int h, w;

    while(true){
        t++;
        cin >> h >> w;
        if(h == 0 && w == 0) {
            break;
        }
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> grid[i][j];
            }
        }
        for (int i = 0; i < h; ++i) {
            fill(vis[i].begin(), vis[i].begin() + w, false);
        }
        //cout << "Hi" << endl;
        int mx = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if(grid[i][j] == 'A') {
                    mx = max(mx, dfs(i, j, h, w));
                }
            }
        }
        cout << "Case " << t << ": " << mx << endl;
    }
    return 0;
}
