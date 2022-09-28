#include <bits/stdc++.h>
using namespace std;
char mat[51][51];
bool vis[51][51];
int cont, n, m;
int vetl[4]={0,1,0,-1};
int vetc[4]={1,0,-1,0};

bool HaveT(int x, int y){
	for(int i= 0; i < 4; i++)
		if(mat[x+vetl[i]][y+vetc[i]] == 'T') return true;
	return false;
}

bool isValid(int x, int y){
	if(x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && mat[x][y] != '#' && mat[x][y] != 'T')
		return true;
	return false;
}

void FloodFill(int x, int y){
	int linha, coluna;
	vis[x][y]= true;
	if(mat[x][y] == 'G'){
		cont++;
	}
	if(HaveT(x,y)) return;
	for(int i= 0; i < 4; i++){
		linha= x+vetl[i];
		coluna= y+vetc[i];
		if(isValid(linha, coluna))
			FloodFill(linha,coluna);
	}
	
}

int main(){
	int x, y;
	while(cin >> n >> m){
		cont= 0;
		memset(mat,'%',sizeof(mat));
		memset(vis,false,sizeof(vis));
		for(int i= 0; i < m; i++){
			for(int j= 0; j < n; j++){
				cin >> mat[i][j];
				if(mat[i][j] == 'P'){
					x= i;
					y= j;
				}
			}
		}
		FloodFill(x,y);
		cout << cont << endl;
		
	}
}
