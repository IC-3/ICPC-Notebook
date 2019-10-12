#include<bits/stdc++.h>
using namespace std;

struct trio{
	int x,y,z;
};
trio mt(int x,int y,int z)
{
	trio temp;
	temp.x=x;
	temp.y=y;
	temp.z=z;
	return temp;
}
vector<int> parent,urank;
int find(int x)
{
	if(parent[x]==x)
		return x;
	return parent[x]=find(parent[x]);
}
void merge(int x,int y)
{
	int roota=find(x);
	int rootb=find(y);
	if(urank[roota]<urank[rootb])
	{
		parent[roota]=rootb;
		urank[rootb]+=urank[roota];
	}
	else
	{
		parent[rootb]=roota;
		urank[roota]+=urank[rootb];
	}
}
vector<trio> edge;
int kruskal()
{
	long long ans=0;
	for(int i=0;i<edge.size();i++)
	{
		if(find(edge[i].x)!=find(edge[i].y))
		{
			ans+=edge[i].z;
			merge(edge[i].x,edge[i].y);
		}
	}
	return ans;
}
bool func(trio a,trio b)
{
	return a.z<b.z;
}
int n,m;
long long solve(){
	cin>>n>>m;
	parent.resize(n+1);
    urank.resize(n+1);
    for(int i=1;i<=n;i++)
    	parent[i]=i;
    for(int i=0;i<m;i++)
    {
    	int a,b,c;
    	cin>>a>>b>>c;
    	edge.push_back(mt(a,b,c));
    }
    sort(edge.begin(),edge.end(),func);
    return kruskal();
}
int main()
{
    cout<<solve();
    return 0;
}