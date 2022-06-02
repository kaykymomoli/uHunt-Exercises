#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;
bool vis[11][11];
char mat[11][11];
int cont[11][11];
int c, l, tempo;
pair<int,int> result;

bool isValid(int x, int y){
	if(x < l && y < c && x >= 0 && y >= 0)
		return 1;
	return 0;
}

void dfs(int x, int y){
	vis[x][y]= true;
	cont[x][y]= tempo++;
	if(mat[x][y] == 'N'){
		if(isValid(x-1, y)){
			if(!vis[x-1][y])
				dfs(x-1, y);
			else{
				int aux= cont[x-1][y]-1;
				result={aux, cont[x][y]-aux};
			}
		}else
			result.first= cont[x][y];
	}else if(mat[x][y] == 'S'){
		if(isValid(x+1, y)){
			if(!vis[x+1][y])
				dfs(x+1, y);
			else{
				int aux= cont[x+1][y]-1;
				result={aux, cont[x][y]-aux};
			}
		}else
			result.first= cont[x][y];
	}else if(mat[x][y] == 'W'){
		if(isValid(x, y-1)){
			if(!vis[x][y-1])
				dfs(x, y-1);
			else{
				int aux= cont[x][y-1]-1;
				result={aux, cont[x][y]-aux};
			}
		}else
			result.first= cont[x][y];
	}else if(mat[x][y] == 'E'){
		if(isValid(x, y+1)){
			if(!vis[x][y+1])
				dfs(x, y+1);
			else{
				int aux= cont[x][y+1]-1;
				result={aux, cont[x][y]-aux};
			}
		}else
			result.first= cont[x][y];
	}
}

int main(){
	int n;
	while(cin >> l >> c >> n && (l || c || n)){
		tempo= 1;
		result={0,0};
		memset(vis,false,sizeof(vis));
		memset(cont,-1,sizeof(cont));
		for(int i= 0; i < l; i++){
			for(int j= 0; j < c; j++){
				cin >> mat[i][j];
			}
		}
		dfs(0,n-1);
		if(!result.second){
			cout << result.first << " step(s) to exit" << endl;
		}else{
			cout << result.first << " step(s) before a loop of " << result.second << " step(s)" << endl;
		}
	}
}
