#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
char mat[1001][1001];
bool vis[1001][1001];

bool isValid(int u, int v, int l, int c){
	if(u < l && v < c && u >= 0 && v >= 0 && !vis[u][v])
		return true;
	return false;
}

int bfs(int l, int c, int org, int org1, int dest, int dest1){
	vis[org][org1]= true;
	queue<pair<int,pair<int,int>>> f;
	f.push({0,{org,org1}});
	while(!f.empty()){
		int cont= f.front().first;
		int u= f.front().second.first;
		int v= f.front().second.second;
		f.pop();
		if(u == dest && v == dest1) return cont;
		if(isValid(u, v+1, l, c) && mat[u][v+1] != 'X'){
			vis[u][v+1]= true;
			f.push({cont+1,{u,v+1}});
		}
		if(isValid(u+1,v,l,c) && mat[u+1][v] != 'X'){
			vis[u+1][v]= true;
			f.push({cont+1,{u+1,v}});
		}
		if(isValid(u,v-1,l,c) && mat[u][v-1] != 'X'){
			vis[u][v-1]= true;
			f.push({cont+1,{u,v-1}});
		}
		if(isValid(u-1, v, l, c) && mat[u-1][v] != 'X'){
			vis[u-1][v]= true;
			f.push({cont+1,{u-1,v}});
		}
	}
	return -1;
}

int main(){
	int r, c;
	while(cin >> r >> c && (r || c)){
		for(int i= 0; i < r; i++){
			for(int j= 0; j < c; j++){
				mat[i][j]= '.';
				vis[i][j]= false;
			}
		}
		int n; cin >> n;
		for(int i= 0; i < n; i++){
			int x, z; cin >> x >> z;
			for(int j= 0; j < z; j++){
				int y; cin >> y;
				mat[x][y]= 'X';
			}
		}
		int org, org1; cin >> org >> org1;
		int dest, dest1; cin >> dest >> dest1;
		cout << bfs(r,c,org,org1,dest,dest1) << endl;
	}
}
