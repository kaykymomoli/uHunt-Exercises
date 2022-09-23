#include <bits/stdc++.h>
using namespace std;
char mat[101][101];
bool vis[101][101];
int vetl[8]={-1,1,0,0,1,-1,-1,1};
int vetc[8]={0,0,-1,1,1,-1,1,-1};
int cont= 0;

bool isValid(int i, int j, int n, int m){
	if(i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && mat[i][j] == '@') return true;
	return false;
}

void dfs(int x, int y, int n, int m){
	vis[x][y]= true;
	for(int i= 0; i < 8; i++){
		int linha= vetl[i]+x;
		int coluna= vetc[i]+y;
		if(isValid(linha, coluna, n, m)){
			dfs(linha, coluna, n, m);
		}
	}
	
}
// VAI SE FUDER QUEZADA
int main(){
	int n, m;
	while(cin >> n >> m && n && m){
		cont= 0;
		memset(vis,0,sizeof(vis));
		for(int i= 0; i < n; i++){
			for(int j= 0; j < m; j++){
				cin >> mat[i][j];
			}
		}
		
		for(int i= 0; i < n; i++){
			for(int j= 0; j < m; j++){
				if(!vis[i][j] && mat[i][j] == '@'){
					dfs(i,j,n, m);
					cont++;
				}
			}
		}
		cout << cont << endl;
	}
}
