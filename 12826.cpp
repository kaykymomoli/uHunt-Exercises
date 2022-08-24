#include <bits/stdc++.h>
using namespace std;
char mat[9][9];
int l[]={1,-1,0,0,1,-1,1,-1};
int c[]={0,0,1,-1,1,-1,-1,1};

bool isValid(int x, int y){
	if(x >= 0 && x < 8 && y >= 0 && y < 8 && mat[x][y] != '#') return true;
	return false;
}

int bfs(int x, int y, int a, int z){
	queue<pair<int,pair<int,int>>>f;
	f.push({0,{x,y}});
	while(!f.empty()){
		int cont= f.front().first;
		int linha= f.front().second.first;
		int coluna= f.front().second.second;
		f.pop();
		if(linha == a && coluna == z) return cont;
		for(int i= 0; i < 8; i++){
			if(isValid(linha+l[i],coluna+c[i])){
				f.push({cont+1,{linha+l[i],coluna+c[i]}});
				mat[linha+l[i]][coluna+c[i]]= '#';
			}
		}
	}
}

int main(){
	int x, y,a,z,r1,r2, cont= 1;
	while(cin >> x >> y >> a >> z >> r1 >> r2){
		memset(mat,'.',sizeof(mat));
		mat[r1-1][r2-1]= '#';
		cout << "Case " << cont++ << ": " << bfs(x-1,y-1,a-1,z-1) << endl;
	}
}
