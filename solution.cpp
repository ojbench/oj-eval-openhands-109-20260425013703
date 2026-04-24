
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    
    // Read the adjacency matrix
    vector<vector<int>> allowed(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> allowed[i][j];
        }
    }
    
    // dp[i][j] = number of ways to connect nodes from i to j (inclusive) in a valid way
    // where the connections are non-crossing and respect the allowed constraints
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    
    // Base case: single node has one way (do nothing)
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    
    // Fill dp table for all intervals
    for (int len = 1; len < n; len++) {
        for (int i = 0; i < n; i++) {
            int j = (i + len) % n;
            // Case 1: node i is not connected to any node in the interval
            dp[i][j] = dp[(i + 1) % n][j];
            
            // Case 2: node i is connected to some node k in the interval
            for (int k = (i + 1) % n; k != j; k = (k + 1) % n) {
                if (allowed[i][k]) {
                    // When connecting i to k, the circle is divided into two parts:
                    // 1. Nodes between i and k (excluding i and k)
                    // 2. Nodes between k and i (excluding k and i, but including j)
                    int next_i = (i + 1) % n;
                    int prev_k = (k + n - 1) % n;
                    int next_k = (k + 1) % n;
                    int prev_i = (i + n - 1) % n;
                    
                    // Check if k is between i and j in the circular order
                    bool k_in_range = false;
                    for (int p = (i + 1) % n; p != (j + 1) % n; p = (p + 1) % n) {
                        if (p == k) {
                            k_in_range = true;
                            break;
                        }
                    }
                    
                    if (k_in_range) {
                        // Calculate the contribution from connecting i to k
                        long long left = dp[next_i][prev_k];  // nodes between i and k
                        long long right = dp[next_k][j];      // nodes between k and j
                        dp[i][j] = (dp[i][j] + left * right) % MOD;
                    }
                }
            }
            
            // Special case: connecting i to j
            if (allowed[i][j]) {
                int next_i = (i + 1) % n;
                int prev_j = (j + n - 1) % n;
                long long middle = dp[next_i][prev_j];  // nodes between i and j
                dp[i][j] = (dp[i][j] + middle) % MOD;
            }
        }
    }
    
    cout << dp[0][n-1] << endl;
    
    return 0;
}
