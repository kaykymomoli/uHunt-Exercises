#include <iostream>
#include <vector>
#include <list>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int> ts;
bool vis[1000001], vf[1000001];
int fim;

void dfs(vector<list<int>> &adj, int n, int u){
	vis[u]= true;
	for(int v: adj[u]){
		if(!vis[v]){
			dfs(adj, n, v);
		}
		else if(!vf[v]){
			fim= false;
		}
	}
	ts.push_back(u);
	vf[u]= true;
}

int main(){
	int n, m;
	while(cin >> n >> m && (n || m)){
		memset(vis,false,sizeof(vis));
		memset(vf,false,sizeof(vf));
		vector<list<int>> adj(n);
		for(int i= 0; i < m; i++){
			int x, y; cin >> x >> y;
			adj[x-1].push_back(y-1);
		}
		fim= true;
		for(int i= 0; i < n; i++){
			if(!vis[i])
				dfs(adj, n, i);
		}
		reverse(ts.begin(),ts.end());
		if(fim){
			for(int i= 0; i < ts.size(); i++){
				cout << ts[i]+1 << endl;
			}
		}
		else
			cout << "IMPOSSIBLE" << endl;
		ts.clear();
	}
}
