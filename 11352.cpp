#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
vector<vector<char>> adj;
vector<vector<bool>> vis;

int l[]={0,0,1,-1,-1,-1,1,1};
int c[]={1,-1,0,0,1,-1,1,-1};
int l1[]={-2,-2,2,2,1,-1,1,-1};
int c1[]={1,-1,1,-1,-2,-2,2,2};
bool isValid(int i, int j, int x, int y){
	if(i < x && i >= 0 && j < y && j >= 0 && !vis[i][j])
		return true;
	return false;
}

int bfs(int i, int j, int x, int y){
	queue<pair<int,pair<int,int>>> f;
	f.push({0,{i,j}});
	while(!f.empty()){
		int cont= f.front().first;
		int u= f.front().second.first;
		int v= f.front().second.second;
		f.pop();
		if(adj[u][v] == 'B') return cont;
		for(int i= 0; i < 8; i++){
			if(isValid(u+l[i], v+c[i], x, y) && adj[u+l[i]][v+c[i]] != 'Z' && adj[u+l[i]][v+c[i]] != 'X'){
				vis[u+l[i]][v+c[i]]= true;
				f.push({cont+1,{u+l[i],v+c[i]}});
			}
		}
	}
	return -1;
}

int main(){
	int n; cin >> n;
	while(n){
		int x, y; cin >> x >> y;
		adj.resize(x);
		vis.resize(x);
		for(int i= 0; i < x; i++){
			for(int j= 0; j < y; j++){
				char a;
				cin >> a;
				adj[i].push_back(a);
				vis[i].push_back(false);
				
			}
		}
		pair<int,int> org;
		for(int i= 0; i < x; i++){
			for(int j= 0; j < y; j++){
				if(adj[i][j] == 'A') org={i,j};
				if(adj[i][j] == 'Z'){
					for(int k= 0; k < 8; k++){
						if(isValid(i+l1[k],j+c1[k], x, y) && adj[i+l1[k]][j+c1[k]] != 'A' && adj[i+l1[k]][j+c1[k]] != 'B' && adj[i+l1[k]][j+c1[k]] != 'Z')
							adj[i+l1[k]][j+c1[k]]= 'X';
					}
				}
			}
		}
		
		int aux= bfs(org.first, org.second, x, y);
		if(aux == -1){
			cout << "King Peter, you can't go now!" << endl;
		}else
			cout << "Minimal possible length of a trip is " << aux << endl;
		adj.clear();
		vis.clear();
		n--;
	}
}
