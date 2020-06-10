#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int c_arr[15][12];
int arr[15][12];
int visit[15][12];

int bomb_list[4];

int n, w, h, min_value;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void copyArr() {
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            c_arr[i][j] = arr[i][j];
        }
    }
}

void bomb(int x, int y) {
    int nx, ny;
    for (int i=0; i<4; i++) {
        for (int j=1; j<c_arr[x][y]; j++) {
            nx = x + j*dx[i];
            ny = y + j*dy[i];
            if (nx >=0 && nx <h && ny>=0 && ny<w) {
                if (!visit[nx][ny] && c_arr[nx][ny]) {
                    visit[nx][ny] = 1;
                    bomb(nx, ny);
                    c_arr[nx][ny] = 0;
                }
            } else break;
        }
    } 
}

void ivisit() {
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            visit[i][j] = 0;
        }
    }
}

void clean() {
    for (int i=0; i<w; i++) {
        for (int j=h-1; j>=0; j--) {
            if (c_arr[j][i] == 0) {
                int p = j;
                while (p>0) {
                    p--;
                    if (c_arr[p][i]) {
                        int temp = c_arr[p][i];
                        c_arr[p][i] = 0;
                        c_arr[j][i] = temp;
                        break;
                    }
                }
                if (p == 0) break;
            }
        }
    }
}

void dfs(int cnt) {
    if (min_value == 0) return;
    if (cnt == n) {
        copyArr();
        for (int i=0; i<n; i++) {
            for (int j=0; j<h; j++) {
                if (c_arr[j][bomb_list[i]]) {
                    visit[j][bomb_list[i]] = 1;
                    bomb(j, bomb_list[i]);
                    c_arr[j][bomb_list[i]] = 0;
                    break;
                }
            }
            clean(); ivisit();
        }
        int ct = 0;
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                if (c_arr[i][j]) ct++;
            }
        }
        min_value = min(min_value, ct);
    } else {
        for (int i=0; i<w; i++) {
            bomb_list[cnt] = i;
            dfs(cnt+1);
        }
    }
}

int main() {
    int tc;
    cin >> tc;
    for (int c=1; c<=tc; c++) {
        cin >> n >> w >> h;
        min_value = 15*12+1;
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                cin >> arr[i][j];
            }
        }
        dfs(0);
        cout << "#" << c << " " << min_value << endl;
    }
    return 0;
}