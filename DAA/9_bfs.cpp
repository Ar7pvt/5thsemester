// #include <bits/stdc++.h>
// using namespace std;

// class Graph {

// 	// No. of vertices
// 	int V;
// 	// Pointer to an array containing adjacency lists
// 	vector<list<int> > adj;

// public:
// 	// Constructor
// 	Graph(int V)
//     {
//         this->V = V;
//         adj.resize(V);
//     }

// 	// Function to add an edge to graph
// 	void addEdge(int v, int w)
//     {
//         // Add w to v’s list.
//         adj[v].push_back(w);
//     }

// 	// Prints BFS traversal from a given source s
// 	void BFS(int s)
//     {
//         // Mark all the vertices as not visited
//         vector<bool> visited;
//         visited.resize(V, false);

//         // Create a queue for BFS
//         list<int> queue;

//         // Mark the current node as visited and enqueue it
//         visited[s] = true;
//         queue.push_back(s);

//         while (!queue.empty()) {

//             // Dequeue a vertex from queue and print it
//             s = queue.front();
//             cout << s << " ";
//             queue.pop_front();

//             // Get all adjacent vertices of the dequeued
//             // vertex s.
//             // If an adjacent has not been visited,
//             // then mark it visited and enqueue it
//             for (auto adjacent : adj[s]) {
//                 if (!visited[adjacent]) {
//                     visited[adjacent] = true;
//                     queue.push_back(adjacent);
//                 }
//             }
//         }
//     }
// };

// // Driver code
// int main()
// {
// 	// Create a graph given in the above diagram
// 	Graph g(4);
// 	g.addEdge(0, 1);
// 	g.addEdge(0, 2);
// 	g.addEdge(1, 2);
// 	g.addEdge(2, 0);
// 	g.addEdge(2, 3);
// 	g.addEdge(3, 3);

// 	cout << "Following is Breadth First Traversal "
// 		<< "(starting from vertex 2) \n";
// 	g.BFS(2);

// 	return 0;
// }
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[],int s) {
        vector<int>ans;
        int visited[V];
        for(int i=0;i<V;i++){
            visited[i]=0;
        }
        queue<int>q;
        q.push(s);
        visited[s]=1;
        while(!q.empty())
        {
            int k=q.front();
            ans.push_back(k);
            for(int i=0;i<adj[k].size();i++){
                if(!visited[adj[k][i]])
                {
                    q.push(adj[k][i]);
                    
                }
                visited[adj[k][i]]=1;
            }
            q.pop();
        }
        return ans;
    }
};

int main() 
{    
    int V, E;
    cout<<"Enter no of vertex and edhes of graph ";
    cin >> V >>E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v;
        cout<<"Enter the edge of graph ";
        cin >> u >> v;
        adj[u].push_back(v);
        // 		adj[v].push_back(u);
    }
    int s;
    cout<<"Enter the starting index ";
    cin>>s;
    Solution obj;
    vector<int> ans = obj.bfsOfGraph(V, adj,s);
    cout<<"BFS traversal of graph is ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}