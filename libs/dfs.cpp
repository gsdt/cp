#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <deque>
#include <map>
#include <algorithm>
#include <set>
#include <numeric>
#include <functional>
#include <cassert>

using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef gsdt
    freopen("input.txt", "r", stdin);
#endif

    int n, m, k;
    cin >> n >> m >> k;
    vector<string> g(n);
    for (string &s: g) {
        cin >> s;
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<pair<int, int>> order;

    function<void(int, int)> dfs = [&](int x, int y) {
        order.emplace_back(x, y);
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < n && 0 <= ny && ny < m && g[nx][ny] == '.' && !visited[nx][ny]) {
                dfs(nx, ny);
            }
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.' && !visited[i][j]) {
                dfs(i, j);
            }
        }
    }

    std::reverse(order.begin(), order.end());

    for (int i = 0; i < k; i++) {
        auto [x, y] = order[i];
        g[x][y] = 'X';
    }

    for (string s: g) {
        cout << s << endl;
    }


    return 0;
}