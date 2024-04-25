#include <bits/stdc++.h>
using namespace std;

class Array {
public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

int dp[101][1001][101]; //matriz de memorizacion

class Solution {
public:
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        memset(dp, -1, sizeof(dp)); //inicializando matriz 

        //si la suma es 0, se puede hacer con 0 monedas
        for (int i = 0; i <= N; i++) {
            dp[i][0][0] = 0;
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= target; j++) {
                for (int k = 0; k <= K; k++) {
                    if (j == 0 || k == 0) {
                        dp[i][j][k] = 0;
                        continue;
                    }
                    if (coins[i - 1] <= j && dp[i - 1][j - coins[i - 1]][k - 1] != -1) {
                        dp[i][j][k] = max(dp[i - 1][j][k], 1 + dp[i - 1][j - coins[i - 1]][k - 1]);
                    } else {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                }
            }
        }

        //retorna si es posible obtener la suma objetivo 
        return dp[N][target][K] >= 0;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int N, K, target;
        scanf("%d%d%d", &N, &K, &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}
