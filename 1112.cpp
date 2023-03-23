#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> adj;
vector<int> Vis;

void Dijkstra(int O, int D){
	int N = adj.size();
	Vis.assign(N, 100000);
	priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > myPq;
	Vis[O] = false;
	myPq.push({ 0, O });
	while(!myPq.empty())
	{
		pair<int,int>X=myPq.top();
		myPq.pop();
		if(X.first!=Vis[X.second]) continue;
		for(auto edge:adj[X.second])
		{
			int to=edge.first;
			int len=edge.second;
			if(Vis[X.second]+len<Vis[to])
			{
				Vis[to]=Vis[X.second]+len;
				myPq.push({Vis[to],to});
			}	
		}
	}
}

int main(){
	int h; cin >> h;
	string blankline;
	cin.ignore();
	while(h){
		getline(cin,blankline);
		int n, o, d, a; cin >> n >> o >> d >> a;
		adj.resize(n);
		o--;
		for(int i= 0; i < a; i++){
			int x, y, w; cin >> x >> y >> w;
			adj[x-1].push_back({y-1,w});
		}
		int cont= 0;
		for(int i= 0; i < n; i++){
			Dijkstra(i,o);
			if(Vis[o] <= d)
				cont++;
		}
		if(h > 1)
			cout << cont << endl << endl;
		else
			cout << cont << endl;
		h--;
		adj.clear();
	}
}
