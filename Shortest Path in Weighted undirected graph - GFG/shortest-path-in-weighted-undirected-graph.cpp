//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>>adj[n+1];
        
        for(auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        set<pair<int,int>>st;
        vector<int>distance(n+1, INT_MAX);
        vector<int>parent(n+1);
        
        for(int i = 1; i <= n ; i++)
        {
            parent[i] = i;
        }
        
        distance[1] = 0;
        st.insert({0,1});
        
        while(!st.empty())
        {
            auto it = *(st.begin());
            
            int dist = it.first;
            int node = it.second;
            
            st.erase(it);
            
            for(auto it : adj[node])
            {
                int edgeW = it.second;
                int adjN = it.first;
                
                if(dist + edgeW < distance[adjN])
                {
                    if(distance[adjN] != INT_MAX)
                    {
                        st.erase({distance[adjN], adjN});
                    }
                    
                    distance[adjN] = dist + edgeW;
                    st.insert({distance[adjN], adjN});
                    parent[adjN] = node;
                }
            }
        }
        
        if(distance[n] == INT_MAX) return {-1};
        vector<int>ans;
        int node = n;
        
        while(parent[node] != node)
        {
            ans.push_back(node);
            node = parent[node];
        }
        
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
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

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends