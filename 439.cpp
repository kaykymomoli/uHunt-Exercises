#include <bits/stdc++.h>
using namespace std;
char mat[10][10];
bool vis[10][10];
int vetl[8]={-1,-2,-2,-1,1,2,2,1};
int vetc[8]={-2,-1,1,2,2,1,-1,-2};

bool isValid(int x, int y){
	if(x < 8 && x >= 0 && y < 8 && y >= 0 && !vis[x][y]) return true;
	return false;
}

int bfs(int x, int y){
	queue<pair<int,pair<int,int>>> loc;
	loc.push({0,{x,y}});
	while(!loc.empty()){
		int linha= loc.front().second.first;
		int coluna= loc.front().second.second;
		int mov= loc.front().first;
		loc.pop();
		vis[linha][coluna]= true;
		if(mat[linha][coluna] == 'D')
			return mov;
		for(int i= 0; i < 8; i++)
			if(isValid(linha+vetl[i],coluna+vetc[i]))
				loc.push({mov+1,{linha+vetl[i],coluna+vetc[i]}});
		
	}
}

int main(){
	char c1, c2;
	int l1, l2;
	while(cin >> c1 >> l1 >> c2 >> l2){
		memset(mat,'.',sizeof(mat));
		memset(vis,false,sizeof(vis));
		mat[l1-1][c1-'a']= 'X';
		mat[l2-1][c2-'a']= 'D';
		cout << "To get from " << c1 << l1 << " to " << c2 << l2 << " takes " << bfs(l1-1,c1-'a') << " knight moves.\n";
	}
}
