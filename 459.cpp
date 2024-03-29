#include <bits/stdc++.h>
using namespace std;
bool vis[28];
vector<list<int>> adj;

void dfs(int u){
    vis[u]= true;
    for(auto v: adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

int main(){
    int n; cin >> n;
    string x, str;
    cin.ignore();
    getline(cin,str);
    for(int l= 0; l < n; l++){
        char h; cin >> h;
        int tam= (int)h-64;
        adj.resize(tam);
        memset(vis,false,sizeof(vis));
        str= "12";
        cin.ignore();
        while(str.size() > 1){
			getline(cin,str);
			if(str.size() > 1){
				adj[(int)(str[0]-'A')].push_back((int)(str[1]-'A'));
				adj[(int)(str[1]-'A')].push_back((int)(str[0]-'A'));
			}
        }
        int cont= 0;
        for(int i= 0; i < adj.size(); i++){
            if(!vis[i]){
                dfs(i);
                cont++;
            }
        }
        adj.clear();
        cout << cont << endl;
        if(l < n-1) cout << endl;
    }
}
