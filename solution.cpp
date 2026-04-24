
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
            
            // Case 1: node i is not connected to any node
            dp[i][j] = dp[i+1][j];
            
            // Case 2: node i is connected to some node k (i < k <= j)
            for (int k = i+1; k <= j; k++) {
                if (allowed[i][k]) {
                    // When connecting i to k, the nodes are divided into two independent parts:
                    // 1. Nodes between i and k (i+1 to k-1)
                    // 2. Nodes between k and j (k+1 to j)
                    long long left = (k > i+1) ? dp[i+1][k-1] : 1;  // If no nodes between i and k, there's 1 way (empty)
                    long long right = (k < j) ? dp[k+1][j] : 1;     // If no nodes between k and j, there's 1 way (empty)
                    dp[i][j] = (dp[i][j] + left * right) % MOD;
                }
            }
        }
    }
    
    // For the circular case, we need to consider all possible ways to break the circle
    // We fix node 0 and consider whether it's connected to any other node
    long long result = 0;
    
    // Case 1: node 0 is not connected to any node
    // Then we have a linear chain from 1 to n-1
    result = dp[1][n-1];
    
    // Case 2: node 0 is connected to some node k (1 <= k <= n-1)
    for (int k = 1; k < n; k++) {
        if (allowed[0][k]) {
            // When connecting 0 to k, the circle is divided into two independent regions:
            // 1. Nodes from 1 to k-1 (if any)
            // 2. Nodes from k+1 to n-1 (if any)
            long long left = (k > 1) ? dp[1][k-1] : 1;      // Region 1
            long long right = (k < n-1) ? dp[k+1][n-1] : 1; // Region 2
            result = (result + left * right) % MOD;
        }
    }
    
    cout << result << endl;
    
    return 0;
}
