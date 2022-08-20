#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class sparse_table {
private:
    vector<vector<int>> ST;
public:
    explicit sparse_table(vector<int> a) {
        size_t n = a.size();
        int h = log2(n) + 1;

        ST = vector<vector<int>>(h, vector<int>(n));
        // base case
        for (int j = 0; j < n; j++) ST[0][j] = a[j];

        // iterative dynamic programming approach
        for (int i = 1; i <= h; i++)
            for (int j = 0; j + (1 << i) <= n; j++)
                ST[i][j] = min(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
    }

    int query_min(int l, int r) {        // query in range [l,r)
        int p = 31 - __builtin_clz(r - l);
        return min(ST[p][l], ST[p][r - (1 << p)]);
    }
};

int main() {
#ifdef gsdt
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    sparse_table st(a);

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << st.query_min(l, r + 1) << endl;
    }
    return 0;
}