
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
    // where the connections are non-crossing and the subgraph is connected
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    
    // Base case: single node has one way (do nothing)
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    
    // Fill dp table for all intervals of increasing length
    for (int len = 1; len < n; len++) {
        for (int i = 0; i < n - len; i++) {
            int j = i + len;
            
            // Try all possible ways to connect node i to some node k (i < k <= j)
            // The edge (i,k) will divide the interval [i,j] into two parts
            for (int k = i+1; k <= j; k++) {
                if (allowed[i][k]) {
                    // When connecting i to k, the nodes are divided into two independent parts:
                    // 1. Nodes between i and k (i+1 to k-1)
                    // 2. Nodes between k and j (k+1 to j)
                    // The number of ways is the product of the ways to connect each part
                    long long left = (k > i+1) ? dp[i+1][k-1] : 1;
                    long long right = (k < j) ? dp[k+1][j] : 1;
                    dp[i][j] = (dp[i][j] + left * right) % MOD;
                }
            }
        }
    }
    
    // For the circular case, we need to count the number of non-crossing spanning trees
    // We can use the following approach:
    // Fix an edge from node 0 to node k, which divides the circle into two arcs
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
