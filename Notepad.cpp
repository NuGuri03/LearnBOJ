#include <iostream>
#include <climits>

int n;
int min = INT_MAX;
void back_tracking(int cost[][3], int cnt, int sum, int selected) {
    if (cnt == n) {
        if (sum < min) {
            min = sum;
        }
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (i == selected) continue;
        sum += cost[cnt][i];
        back_tracking(cost, cnt + 1, sum, i);
        sum -= cost[cnt][i];
    }
}

int main() {
    std::cin >> n;
    int cost[1000][3];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) std::cin >> cost[i][j];
    }

    back_tracking(cost, 0, 0, - 1);
    std::cout << min << '\n';
}