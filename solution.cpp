
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
    
    // dp[i][j] = number of ways to connect nodes i to j (inclusive) in a valid way
    // where the connections are non-crossing and respect the allowed constraints
    // We consider the nodes in a linear order from i to j (not wrapping around)
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    
    // Base case: single node has one way (do nothing)
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    
    // Fill dp table for all intervals of increasing length
    for (int len = 1; len < n; len++) {
        for (int i = 0; i < n - len; i++) {
            int j = i + len;
            
            // Try all possible ways to connect node i to some node k (i <= k <= j)
            // If k == i, it means i is not connected to any node in [i+1,j]
            // If k > i, it means i is connected to k
            for (int k = i; k <= j; k++) {
                if (k == i) {
                    // i is not connected to any node in [i+1,j]
                    // So we just solve for [i+1,j]
                    dp[i][j] = (dp[i][j] + dp[i+1][j]) % MOD;
                } else {
                    // i is connected to k
                    if (allowed[i][k]) {
                        // When connecting i to k, the nodes are divided into two independent parts:
                        // 1. Nodes between i and k (i+1 to k-1)
                        // 2. Nodes between k and j (k+1 to j)
                        long long left = (k > i+1) ? dp[i+1][k-1] : 1;
                        long long right = (k < j) ? dp[k+1][j] : 1;
                        dp[i][j] = (dp[i][j] + left * right) % MOD;
                    }
                }
            }
        }
    }
    
    // For the circular case, we need to count the number of non-crossing spanning trees
    // We can use the following approach:
    // The answer is the sum over all possible edges from node 0 to node k (1 <= k < n)
    // that are allowed, multiplied by the ways to connect the remaining nodes
    long long result = 0;
    
    if (n == 1) {
        result = 1;
    } else {
        // For n > 1, consider all possible edges from node 0 to node k (1 <= k < n)
        for (int k = 1; k < n; k++) {
            if (allowed[0][k]) {
                // Edge from 0 to k divides the circle into two arcs:
                // Arc 1: nodes 1 to k-1
                // Arc 2: nodes k+1 to n-1
                long long ways = 1;
                
                // Count ways for arc 1
                if (k > 1) {
                    ways = (ways * dp[1][k-1]) % MOD;
                }
                
                // Count ways for arc 2
                if (k < n-1) {
                    ways = (ways * dp[k+1][n-1]) % MOD;
                }
                
                result = (result + ways) % MOD;
            }
        }
    }
    
    cout << result << endl;
    
    return 0;
}
