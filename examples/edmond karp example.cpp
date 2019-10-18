/*Template by hemnath_d(Enlightened by chamow)*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vec vector<ll>
#define pll pair<ll,ll>
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define fx first
#define sx second
#define inf 100000000000000
#define minf -100000000000000
#define maxi 100005
int n;
vector<string> str;
map<string,int> ma;
string arr[]={"S","M","L","XL","XXL","XXXL","S,M","M,L","L,XL","XL,XXL","XXL,XXXL"};
//O(V*E^2) implementation of Edmond Karp's Algorithm
//rGraph-Adjacency Matrix, adj-Adjacency List,V-Number of vertices,s-Source vertex,t-Sink vertex
const int size=19;
bool bfs(int rGraph[size][size],vec adj[],int V, int s, int t, int parent[])
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
ll edmondKarp(int graph[][size],vec adj[], int s, int t)
{
    int u, v;
    int rGraph[size][size];   
    for (u = 0; u < size; u++)
        for (v = 0; v < size; v++)
             rGraph[u][v] = graph[u][v];
    int parent[size]; 
    int max_flow = 0;
    while (bfs(rGraph,adj,size, s, t, parent))
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
    ll ans = max_flow;
    if(ans == n){
    	cout<<"YES"<<endl;
    	int lim[5];
    	for(int i=0;i<5;i++)
    		lim[i] = rGraph[i+12][i+7];
    	for(int i=0;i<n;i++){
    		int num = ma[str[i]];
    		if(num <= 5)
    			cout<<str[i]<<endl;
    		else{
    			if(lim[num-6]){
    				lim[num-6]--;
    				cout<<arr[num-6]<<endl;
    			}
    			else
    				cout<<arr[num-5]<<endl;
    		}
    	}
    }
    else
    	cout<<"NO"<<endl;
    return max_flow;
}
int main()
{
    fastread;
    for(int i=0;i<11;i++)
    	ma[arr[i]] = i;
    vector<int> cnt(6),shcnt(11,0);
    for(int i=0;i<6;i++){
    	cin>>cnt[i];
    }
    cin>>n;
    for(int i=0;i<n;i++){
    	string s;
    	cin>>s;
    	str.pb(s);
    	shcnt[ma[s]]++;
    }
    int Graph[19][19];
    memset(Graph,0,sizeof(Graph));
    for(int i=1;i<=11;i++){
    	Graph[0][i] = shcnt[i-1];
    }
    for(int i=1;i<=6;i++){
    	Graph[i][i+11]=INT_MAX;
    }
    for(int i=7;i<=11;i++){
    	Graph[i][i+5] = Graph[i][i+6] = INT_MAX;

    }
    for(int i=12;i<=17;i++){
    	Graph[i][18] = cnt[i-12];
    }
    vec adj[19];
    for(int i=0;i<19;i++){
    	for(int j=0;j<19;j++){
    		if(Graph[i][j] != 0)
    			adj[i].pb(j);
    	}
    }
    edmondKarp(Graph,adj,0,18);

    return 0;
}