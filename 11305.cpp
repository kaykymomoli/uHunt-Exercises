#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
using namespace std;
bool vis[101];
vector<int> ans;

void dfs(vector<list<int>> &adj, int n, int u){
    vis[u]= true;
    for(int v: adj[u]){
        if(!vis[v]){
            dfs(adj, n, v);
        }
    }
	ans.push_back(u + 1);
}

int main(){
    int n, m, x, y;
    while(cin >> n >> m && (n+m)>0){
		ans.clear();
        vector<list<int> > adj(n);
        for(int i= 0; i < 101; i++)
			vis[i]= false;
        for(int i= 0; i < m; i++){
            cin >> x >> y;
            adj[x-1].push_back(y-1);
        }
        for(int i= (n - 1); i >= 0; i--){
            if(!vis[i]){
                dfs(adj, n, i);
            }
        }
        reverse(ans.begin(), ans.end());
        for(int i= 0; i < ans.size(); i++){
			if(i == ans.size()-1){
				cout << ans[i] << endl;
			}else
				cout << ans[i] << " ";
		}
		adj.clear();
    }
}
