#include <bits/stdc++.h>
using namespace std;
char mat[26][26];
bool vis[26][26];
int vetl[8]={-1,1,0,0,1,-1,-1,1};
int vetc[8]={0,0,-1,1,1,-1,1,-1};


bool isValid(int i, int j, int n){
	if(i >= 0 && i < n && j >= 0 && j < n && !vis[i][j] && mat[i][j] == '1') return true;
	return false;
}

void dfs(int x, int y, int n){
	vis[x][y]= true;
	for(int i= 0; i < 8; i++){
		int linha= vetl[i]+x;
		int coluna= vetc[i]+y;
		if(isValid(linha, coluna, n))
			dfs(linha, coluna, n);
	}
	
}
// VAI SE FUDER QUEZADA
int main(){
	int n, contaux= 1;
	while(cin >> n){
		int cont= 0;
		memset(vis,0,sizeof(vis));
		for(int i= 0; i < n; i++){
			for(int j= 0; j < n; j++){
				cin >> mat[i][j];
			}
		}
		
		for(int i= 0; i < n; i++){
			for(int j= 0; j < n; j++){
				if(!vis[i][j] && mat[i][j] == '1'){
					dfs(i,j,n);
					cont++;
				}
			}
		}
		cout << "Image number " << contaux << " contains " << cont << " war eagles.\n";
		contaux++;
	}
}
