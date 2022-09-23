#include <bits/stdc++.h>
using namespace std;
char mat[101][101];
bool vis[101][101];
int vetl[8]={-1,1,0,0};
int vetc[8]={0,0,-1,1};
int cont= 0;

bool isValid(int i, int j, int n){
	if(i >= 0 && i < n && j >= 0 && j < n && !vis[i][j] && (mat[i][j] == 'x' || mat[i][j] == '@')) return true;
	return false;
}

void dfs(int x, int y, int n){
	vis[x][y]= true;
	for(int i= 0; i < 8; i++){
		int linha= vetl[i]+x;
		int coluna= vetc[i]+y;
		if(isValid(linha, coluna, n)){
			dfs(linha, coluna, n);
		}
	}
	
}
// VAI SE FUDER QUEZADA
int main(){
	freopen("a.txt","w",stdout);
	int n, h, aux= 1; cin >> h;
	for(int x= 0; x < h; x++){
		cin >> n;
		cont= 0;
		memset(vis,0,sizeof(vis));
		for(int i= 0; i < n; i++){
			for(int j= 0; j < n; j++){
				cin >> mat[i][j];
			}
		}
		
		for(int i= 0; i < n; i++){
			for(int j= 0; j < n; j++){
				if(!vis[i][j] && mat[i][j] == 'x'){
					dfs(i,j,n);
					cont++;
				}
			}
		}
		cout << "Case " << aux << ": " << cont<< endl;
		aux++;
	}
}
