//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	//Function to find the shortest distance between all pairs of vertices.
	void shortest_distance(vector<vector<int>>&matrix){
		int INF = INT_MAX; //initialize INF as maximum integer value.
		int n = matrix.size(); //get the size of the matrix.

		//replace all -1 with INF in the matrix.
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(matrix[i][j] == -1)
					matrix[i][j] = INF;
			}
		}

		//perform Floyd-Warshall algorithm to find shortest distances.
		for (int k = 0; k < n; ++k) {
		    for (int i = 0; i < n; ++i) {
		        for (int j = 0; j < n; ++j) {
		            if (matrix[i][k] < INF && matrix[k][j] < INF and matrix[i][k] + matrix[k][j] < INF)
		                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]); 
		        }
		    }
		}

		//replace all INF with -1 in the matrix.
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(matrix[i][j] >= INF)
					matrix[i][j] = -1;
			}
		}
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
