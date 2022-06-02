#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
using namespace std;
bool vis[10001];
vector<int> ans;
int cont;

void dfs(vector<list<int>> &adj, int n, int u){
   vis[u]= true;
   cont++;
   for(int v: adj[u]){
       if(!vis[v]){
           dfs(adj,n,v);
       }
   }
}

int main(){
    int h; cin >> h;
    for(int f= 0; f < h; f++){
        int n, m, l, x, y; cin >> n >> m >> l;
        vector<list<int>> adj(n);
        for(int i= 0; i < 10001; i++)
            vis[i]= false;
        for(int i= 0; i < m; i++){
            cin >> x >> y;
            adj[x-1].push_back(y-1);
        }
        int v[l];
        for(int i= 0; i < l; i++){
            cin >> x;
            v[i]= x-1;
        }
        cont= 0;
        for(int i= 0; i < l; i++){
            if(!vis[v[i]]){
                dfs(adj,n,v[i]);
            }
        }
        cout << cont << endl;
    }
}
