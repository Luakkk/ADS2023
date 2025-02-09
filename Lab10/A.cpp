#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[1001][1001];
bool used[1001][1001];
queue< pair<int, int > > q;

int res = 0;
int grib = 0;
int killed = 0;

void bfs() {
    while (q.empty() == false){
        queue< pair<int, int > > qq;
        while (q.empty() == false) {
            int el_x = q.front().first;
            int el_y = q.front().second;
            q.pop();
            qq.push({el_x, el_y});
        }

        while (qq.empty() == false)  {
            pair<int, int> current = qq.front();
            qq.pop();

            int i = current.first;
            int j = current.second;

            if (i + 1 < n && a[i + 1][j] == 1) {
                killed++;
                q.push({i + 1, j});
                a[i + 1][j] = 2;
            }
            if (j + 1 < m && a[i][j + 1] == 1) {
                killed++;
                q.push({i, j + 1});
                a[i][j + 1] = 2;
            }
            if (i - 1 >= 0 && a[i - 1][j] == 1) {
                killed++;
                q.push({i - 1, j});
                a[i - 1][j] = 2;
            }
            if (j - 1 >= 0 && a[i][j - 1] == 1) {
                killed++;
                q.push({i, j - 1});
                a[i][j - 1] = 2;
            }
        }
        res++;
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) {
                q.push({i, j});  
            }
            if (a[i][j] == 1) {
                grib++;
            }
        }
    }
    if (q.size() == 0 && grib == 0) {
        cout << 0;
        return 0;
    }
    else { 
        bfs();
    }
    if (killed == grib) {
        cout << res - 1;
    }
    else {
        cout << -1;
    }
}