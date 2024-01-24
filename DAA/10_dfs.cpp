#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void travers(const vector<int> adj[], int idx, vector<int>& visted,  vector<int>& vals)
    {
        vals.push_back(idx);
        visted[idx]=1;
        
        for(int i=0;i<adj[idx].size();i++)
        {
            if(visted[adj[idx][i]]!=1)
            travers(adj, adj[idx][i], visted, vals);
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[],int s) {
        vector<int> visted(V,-1);
        vector<int> vals;
        travers(adj, s, visted, vals);
        for(int i=0;i<V;i++)
        {
            if(visted[i]!=1)
            {
                travers(adj,i,visted,vals);
            }
        }
        return vals;
        // Code here
    }
};

int main() 
{ 
    int V, E;
    cout<<"Enter vertex and edges of graph ";
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v;
        cout<<"Enter the egges of graph ";
        cin >> u >> v;
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
    int s;
    cout<<"Enter the starting node ";
    cin>>s;
    // string s1;
    // cin>>s1;
    Solution obj;
    vector<int> ans = obj.dfsOfGraph(V, adj,s);
    cout<<"Dfs traversal of graph ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}