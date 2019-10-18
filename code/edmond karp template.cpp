//O(V*E^2) implementation of Edmond Karp's Algorithm
//rGraph-Adjacency Matrix,V-Number of vertices,s-Source vertex,t-Sink vertex
const int size=101;
vector<int> adj[size];
bool bfs(int rGraph[size][size],int V, int s, int t, int parent[])
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        for (int x=0;x<adj[u].size();x++)
        {
            int v=adj[u][x];
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}
long long edmondKarp(int graph[][size],int s, int t)
{
    int u, v;
    int rGraph[size][size];   
    for (u = 0; u < size; u++)
        for (v = 0; v < size; v++)
             rGraph[u][v] = graph[u][v];
    int parent[size]; 
    int max_flow = 0;
    while (bfs(rGraph,size, s, t, parent))
    {
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}