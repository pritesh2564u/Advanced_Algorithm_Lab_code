#include <bits/stdc++.h>

using namespace std;

bool bfs(vector<vector<int>> rgraph, int s, int t, vector<int>& parent) {
	vector<int> vis(rgraph.size(), 0);
	queue<int> q;
	q.push(s);
	vis[s] = 1;
	parent[s] = -1;
    
	while(!q.empty()) {
    	int u = q.front();
    	q.pop();
    	for(int v = 0 ; v < rgraph.size() ; v++) {
        	if(!vis[v] && rgraph[u][v] > 0) {
            	if(v == t) {
                	parent[v] = u;
                	return true;
            	}
            	q.push(v);
            	vis[v] = 1;
            	parent[v] = u;
        	}
    	}
	}
	return false;
}

int ford_fulkerson(vector<vector<int>>& graph, int s, int t) {
	vector<vector<int>> rgraph(graph.size(), vector<int>(graph[0].size()));
	int u, v;
	for(u = 0 ; u < graph.size() ; u++) {
    	for(v = 0 ; v < graph.size() ; v++) {
        	rgraph[u][v] = graph[u][v];
    	}
	}
	vector<int> parent(graph.size());
	int max_flow = 0;
	while(bfs(rgraph, s, t, parent)) {
    	int path_flow = INT_MAX;
    	for(int v = t ; v != s ; v = parent[v]) {
        	u = parent[v];
        	path_flow = min(path_flow, rgraph[u][v]);
    	}
    	for(int v = t ; v != s ; v = parent[v]) {
        	u = parent[v];
        	rgraph[u][v] -= path_flow;
        	rgraph[v][u] += path_flow;
    	}
    	max_flow += path_flow;
	}
	return max_flow;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n, vector<int>(m, 0));
	for(int i = 0 ; i < m ; i++) {
    	int u, v, wt;
    	cin >> u >> v >> wt;
    	graph[u][v] = wt;
	}
	int max_flow = ford_fulkerson(graph, 0, n - 1);
	cout << max_flow << endl;
	return 0;
}
