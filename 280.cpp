#include <bits/stdc++.h>
using namespace std;
bool vis[1000007];
vector<int> oVis;

void dfs(vector<list<int> > &adj, int u){
	for(int v: adj[u]){
		if(!vis[v]){
			vis[v]= true;
			dfs(adj, v);
		}
	}
}

int main(){
	int n;
	while(cin >> n && n){
		vector<list<int>> adj(n);
		int x;
		while(cin >> x && x){
			int z;
			while(cin >> z && z){
				adj[x-1].push_back(z-1);
			}
		}
		int z; cin >> z;
		while(z){
			memset(vis,false,sizeof(vis));
			cin >> x;
			dfs(adj, x-1);
			for(int i= 0; i < n; i++){
				if(!vis[i]){
					oVis.push_back(i+1);
				}
			}
			cout << oVis.size();
			for(int i= 0; i < oVis.size(); i++){
				cout << " " << oVis[i];
			}
			cout << endl;
			oVis.clear();
			z--;
		}
	}
}
