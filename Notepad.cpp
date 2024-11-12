#include <iostream>

long long store[101][101][101] = {0};

long long recursive_w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    else if (a > 20 || b > 20 || c > 20) return recursive_w(20, 20, 20);
    else if (a < b && b < c) return recursive_w(a, b, c - 1) + recursive_w(a, b - 1, c - 1) - recursive_w(a, b - 1, c);
    else return recursive_w(a - 1, b, c) + recursive_w(a - 1, b - 1, c) + recursive_w(a - 1, b, c - 1) - recursive_w(a - 1, b - 1, c - 1);
}

void storing() {
    for (int i = 0; i <= 50; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k <= 100; k++) {
                store[i][j][k] = 1;
                store[j][i][k] = 1;
                store[j][j][i] = 1;
            }
        }
    }
    for (int i = 51; i <= 70; i++) {
        for (int j = i + 1; j <= 70; j++) {
            for (int k = j + 1; k <= 70; k++) {
                store[i][j][k] = store[i][j][k - 1] + store[i][j - 1][k - 1] - store[i][j - 1][k];
            }
        }
    }
    for (int i = 71; i < 101; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k <= 100; k++) {
                store[i][j][k] = store[70][70][70];
                store[j][i][k] = store[70][70][70];
                store[j][j][i] = store[70][70][70];
            }
        }
    }
}


long long DP_w(int a, int b, int c) {
    a += 50;
    b += 50;
    c += 50;
    if (store[a][b][c] != 0) return store[a][b][c];
    
    return store[a - 1][b][c] + store[a - 1][b - 1][c] + store[a - 1][b][c - 1] - store[a - 1][b - 1][c - 1];
}

int main() {
    storing();

    int a, b ,c;    
    while (1) {
        std::cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;

        // std::cout << "w(" << a << ", " << b << ", " << c << ") = " << recursive_w(a, b, c) << '\n';
        
        std::cout << "w(" << a << ", " << b << ", " << c << ") = " << DP_w(a, b, c) << '\n';
    }

}