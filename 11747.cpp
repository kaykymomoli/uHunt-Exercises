#include <bits/stdc++.h>
using namespace std;
#define pb push_back
struct UF
{
    vector<int> pai,r;
    UF(int n)
    {
        pai.resize(n);
        r.resize(n);
        for(int i=0;i<n;i++)
        {
            pai[i]=i;
            r[i]=1;
        }
    }
    UF(){}
    int acha(int x)
    {
        if(pai[x]==x) 
            return x;
        return pai[x]=acha(pai[x]);
    }
    void unir(int x, int y)
    {
        x=acha(x);
        y=acha(y);
        if(r[x]>r[y])
        {
            pai[y]=x;
            r[x]+=r[y];
        }
        else
        {
            pai[x]=y;
            r[y]+=r[x];
        }
    }
    bool mesmoConjunto(int x,int y)
    {
        return acha(x)==acha(y);
    }
};

int main()
{
    int n,m;
    while(cin >> n >> m && (n || m)){
		int soma= 0;
		bool vis[m]={};
		vector<pair<int,pair<int,int> > >arestas;
		for(int i=0;i<m;i++)
		{
			int a,b,p;
			cin>>a>>b>>p;
			soma+= p;
			arestas.pb({p,{a,b}});
		}
		sort(arestas.begin(),arestas.end());
		UF stru(n+1);
		int ans=0;
		bool flor= true;
		for(int i=0;i<arestas.size();i++)
		{
			int peso=arestas[i].first;
			int a=arestas[i].second.first;
			int b=arestas[i].second.second;
			if(!stru.mesmoConjunto(a,b))
			{
				stru.unir(a,b);
				ans+=(long long int)peso;
				vis[i]= true;
			}else{
				flor= false;
			}
		}
		if(flor){
			cout << "forest" << endl;
		}else{
			vector<int> pnvs;
			for(int i=0;i<arestas.size();i++){
				if(!vis[i]){
					pnvs.pb(arestas[i].first);
				}
			}
			for(int i= 0; i < pnvs.size(); i++){
				if(i == pnvs.size()-1){
					cout << pnvs[i] << endl;
				}else{
					cout << pnvs[i] << " ";
				}
			}
		}
	}	
}
