#include <bits/stdc++.h>
using namespace std;

char mat[9][9];
bool vis[9][9];
int vetl[4]={1,-1,0,0};
int vetc[4]={0,0,1,-1};
int cont;
bool elX,elO;

bool isValid(int x, int y){
	if(x >= 0 && x < 9 && y >= 0 && y < 9 && !vis[x][y]) return true;
	return false;
}

bool haveO(int x, int y){
	for(int i= 0; i < 4; i++){
		int linha= x+vetl[i];
		int coluna= y+vetc[i];
		if(isValid(linha,coluna) && mat[linha][coluna] == 'O') return true;
	}
	return false;
}

bool haveX(int x, int y){
	for(int i= 0; i < 4; i++){
		int linha= x+vetl[i];
		int coluna= y+vetc[i];
		if(isValid(linha,coluna) && mat[linha][coluna] == 'X') return true;
	}
	return false;
}

void dfs(int x, int y){
	vis[x][y]= true;
	if(haveO(x,y)) elO= true;
	if(haveX(x,y)) elX= true;
	for(int i= 0; i < 4; i++){
		int linha= x+vetl[i];
		int coluna= y+vetc[i];
		if(isValid(linha,coluna) && mat[linha][coluna] == '.'){
			cont++;
			dfs(linha,coluna);
		}
	}
}


int main(){
	int n; cin >> n;
	for(int c= 0; c < n; c++){
		int contW= 0, contB= 0;
		memset(mat,'p',sizeof(mat));
		memset(vis,false,sizeof(vis));
		for(int i= 0; i < 9; i++){
			for(int j= 0; j < 9; j++){
				cin >> mat[i][j];
			}
		}	
		for(int i= 0; i < 9; i++){
			for(int j= 0; j < 9; j++){
				elX= false;
				elO= false;
				cont= 0;
				if(mat[i][j] == '.' && !vis[i][j]){
					dfs(i,j);
					cont++;
				}
				if(elO && !elX)
					contW+= cont;
					
				if(elX && !elO)
					contB+= cont;
				
			}
		}
		for(int i= 0; i < 9; i++){
			for(int j= 0; j < 9; j++){
				if(mat[i][j] == 'X') contB++;
				if(mat[i][j] == 'O') contW++;
			}
		}
		cout << "Black " << contB << " White " << contW << endl;
	}
}
