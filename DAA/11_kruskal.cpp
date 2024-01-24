// // C++ program for the above approach 

// #include <bits/stdc++.h> 
// using namespace std; 

// // DSU data structure 
// // path compression + rank by union 
// class DSU { 
// 	int* parent; 
// 	int* rank; 

// public: 
// 	DSU(int n) 
// 	{ 
// 		parent = new int[n]; 
// 		rank = new int[n]; 

// 		for (int i = 0; i < n; i++) { 
// 			parent[i] = -1; 
// 			rank[i] = 1; 
// 		} 
// 	} 

// 	// Find function 
// 	int find(int i) 
// 	{ 
// 		if (parent[i] == -1) 
// 			return i; 

// 		return parent[i] = find(parent[i]); 
// 	} 

// 	// Union function 
// 	void unite(int x, int y) 
// 	{ 
// 		int s1 = find(x); 
// 		int s2 = find(y); 

// 		if (s1 != s2) { 
// 			if (rank[s1] < rank[s2]) { 
// 				parent[s1] = s2; 
// 			} 
// 			else if (rank[s1] > rank[s2]) { 
// 				parent[s2] = s1; 
// 			} 
// 			else { 
// 				parent[s2] = s1; 
// 				rank[s1] += 1; 
// 			} 
// 		} 
// 	} 
// }; 

// class Graph { 
// 	vector<vector<int> > edgelist; 
// 	int V; 

// public: 
// 	Graph(int V) { this->V = V; } 

// 	// Function to add edge in a graph 
// 	void addEdge(int x, int y, int w) 
// 	{ 
// 		edgelist.push_back({ w, x, y }); 
// 	} 

// 	void kruskals_mst() 
// 	{ 
// 		// Sort all edges 
// 		sort(edgelist.begin(), edgelist.end()); 

// 		// Initialize the DSU 
// 		DSU s(V); 
// 		int ans = 0; 
// 		cout << "Following are the edges in the "
// 				"constructed MST"
// 			<< endl; 
// 		for (auto edge : edgelist) { 
// 			int w = edge[0]; 
// 			int x = edge[1]; 
// 			int y = edge[2]; 

// 			// Take this edge in MST if it does 
// 			// not forms a cycle 
// 			if (s.find(x) != s.find(y)) { 
// 				s.unite(x, y); 
// 				ans += w; 
// 				cout << x << " -- " << y << " == " << w 
// 					<< endl; 
// 			} 
// 		} 
// 		cout << "Minimum Cost Spanning Tree: " << ans; 
// 	} 
// }; 

// // Driver code 
// int main() 
// { 
// 	Graph g(4); 
// 	g.addEdge(0, 1, 10); 
// 	g.addEdge(1, 3, 15); 
// 	g.addEdge(2, 3, 4); 
// 	g.addEdge(2, 0, 6); 
// 	g.addEdge(0, 3, 5); 

// 	// Function call 
// 	g.kruskals_mst(); 

// 	return 0; 
// }

#include <bits/stdc++.h>
using namespace std;

#define V 5
int parent[V];
int find(int i)
{
	while (parent[i] != i)
		i = parent[i];
	return i;
}
void union1(int i, int j)
{
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}
void kruskalMST(int cost[][V])
{
	int mincost = 0;
	for (int i = 0; i < V; i++)
		parent[i] = i;

	int edge_count = 0;
	while (edge_count < V - 1) {
		int min = INT_MAX, a = -1, b = -1;
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (find(i) != find(j) && cost[i][j] < min) {
					min = cost[i][j];
					a = i;
					b = j;
				}
			}
		}

		union1(a, b);
		printf("Edge %d:(%d, %d) cost:%d \n", edge_count++, a, b, min);
		mincost += min;
	}
	printf("\n Minimum cost= %d \n", mincost);
}
int main()
{
	/* Let us create the following graph
		2 3
	(0)--(1)--(2)
	| / \ |
	6| 8/ \5 |7
	| /	 \ |
	(3)-------(4)
			9		 */
	int cost[][V] = {
		{ INT_MAX, 2, INT_MAX, 6, INT_MAX },
        { 2, INT_MAX, 3, 8, 5 },
        { INT_MAX, 3, INT_MAX, INT_MAX, 7 },
        { 6, 8, INT_MAX, INT_MAX, 9 },
        { INT_MAX, 5, 7, 9, INT_MAX },
	};
	kruskalMST(cost);

	return 0;
}
