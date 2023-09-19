//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // Function to perform Bellman-Ford algorithm to find the shortest distance from a source node to all other nodes in a weighted graph.
    vector<int> bellman_ford(int N, vector<vector<int>>& edges, int src) {
        int inf = 100000000;
        vector<int> dist(N, inf); // Initialize distance array with infinity.

        dist[src] = 0; // Set distance of source node to 0.

        // Run the relaxation process N-1 times.
        for (int i = 1; i <= N - 1; i++) {
            for (auto it : edges) {
                // If there is a shorter path from the source node to the current node, update the distance.
                if (dist[it[0]]!=inf && dist[it[0]] + it[2] < dist[it[1]]) {
                    dist[it[1]] = dist[it[0]] + it[2];
                }
            }
        }

        int fl = 0;
        for (auto it : edges) {
            // If there is a negative cycle, return -1.
            if (dist[it[0]]!=inf && dist[it[0]] + it[2] < dist[it[1]]) {
                return {-1};
            }
        }

        // If there is no negative cycle, return the distance array.
        if (!fl) {
            return dist;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
