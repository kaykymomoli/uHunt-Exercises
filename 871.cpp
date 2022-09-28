#include <bits/stdc++.h>
using namespace std;
char mat[26][26];
bool vis[26][26];
int vetl[8]={1,-1,0,0,1,1,-1,-1};
int vetc[8]={0,0,-1,1,1,-1,1,-1};
int cont;

bool isValid(int x, int y, int n, int m){
	if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && mat[x][y] == '1') return true;
	return false; 
}

void dfs(int x, int y, int n, int m){
	cont++;
	vis[x][y]= true;
	for(int i= 0; i < 8; i++){
		int linha= x+vetl[i];
		int coluna= y+vetc[i];
		if(isValid(linha,coluna,n,m)){
			dfs(linha,coluna,n,m);
		}
	}
}

int main(){
	int n; cin >> n;
	string blank, x;
	cin.ignore();
	getline(cin,blank);
	for(int l= 0; l < n; l++){
		memset(mat,'-',sizeof(mat));
		memset(vis,0,sizeof(vis));
		x= "1";
		int i= 0, j= 0;
		while(x != ""){
			getline(cin,x);
			if(x != ""){
				for(int l= 0; l < x.size(); l++)
					mat[i][l]= x[l];
				j= x.size();
				i++;
			}
		}
		int maior= 0;
		for(int n= 0; n < i; n++){
			for(int m= 0; m < j; m++){
				cont= 0;
				if(!vis[n][m] && mat[n][m] == '1'){
					dfs(n,m,i,j);
				}
				if(cont > maior)
					maior= cont;
			}
		}
		if(l < n-1)
			cout << maior << endl << endl;
		else
			cout << maior << endl;
	}
}
