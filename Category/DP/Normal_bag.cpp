#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct stuff {
    int w, v;
}stuff;

bool compare(const stuff &a, const stuff &b) {
    return a.w < b.w;
}

int sol(vector<stuff> s, int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j]);
            if (j + s[i - 1].w <= k) {
                dp[i][j + s[i - 1].w] = max(dp[i][j], dp[i - 1][j] + s[i - 1].v);
            }
        }
    }
    return dp[n][k];
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<stuff> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i].w >> s[i].v;
    }
    sort(s.begin(), s.end(), compare);
    
    cout << sol(s, n, k) << '\n';
}