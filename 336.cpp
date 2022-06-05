#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int d= 1;
vector<bool> vis;
vector<int> acesso;
set<int>::iterator its;

void bfs(vector<pair<int,list<int> > > &adj, int u, int ttl){
	vis[u]= true;
	queue<pair<int, int> > f;
	f.push({u,ttl});
	while(!f.empty()){
		int aux1= f.front().first;
		int aux= f.front().second;
		f.pop();
		if(aux > 0){
            for(int v: adj[aux1].second){
                bool fim= true;
                for(int i= 0; i < adj.size() && fim; i++){
                    if(adj[i].first == v && !vis[i]){
                        fim= false;
                        f.push({i,aux-1});
                        vis[i]= true;
                        acesso.pb(v);
                    }
                }
            }
		}
	}
}

int main(){
	int n;
	bool tem= false;
	while(cin >> n && n){
		int x, y;
		set<int> aux;
		vector<pair<int,list<int> > > adj;
		pair<int,int> aux1[n];
		for(int i= 0; i < n; i++){
			cin >> x >> y;
			aux1[i]={x,y};
			aux.insert(x);
			aux.insert(y);
		}
		int i;
		for(its= aux.begin(),i= 0; its != aux.end(); its++, i++){
			pair<int,list<int> > l;
			l.first= *its;
			adj.pb(l);
		}
		for(int i= 0; i < n; i++){
            for(int h= 0; h < adj.size(); h++){
                if(adj[h].first == aux1[i].first){
                    for(int j= 0; j < adj.size(); j++){
                        if(adj[j].first == aux1[i].second){
                            adj[h].second.pb(aux1[i].second);
                            adj[j].second.pb(aux1[i].first);
                        }
                    }
                }
            }
		}
		vis.resize(adj.size());
		while(cin >> x >> y && (x || y)){
            int cont= 0;
            bool fim= true;
            int indice;
            for(indice= 0; indice < adj.size() && fim; indice++){
                if(adj[indice].first == x){
                    fim= false;
                }
            }
			vis.assign(adj.size(),false);
			if(!fim){
                bfs(adj, indice-1, y);
			}
			for(int i= 0; i < vis.size(); i++){
                if(!vis[i])
                    cont++;
			}
			cout << "Case " << d << ": "  << cont << " nodes not reachable from node " << x << " with TTL = " << y << "."<< endl;
			acesso.clear();
			d++;
		}
	}
}
