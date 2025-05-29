#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int>par,rank;
    public:
    DSU(int n){
        par.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<n;i++) par[i]=i;
    }
    int UPar(int node){
        if(par[node]==node) return node;
        return par[node]=UPar(par[node]);
    }
    void unionRank(int u, int v){
        int ulp_u= UPar(u);
        int ulp_v= UPar(v);
        if(ulp_u==ulp_v) return ;
        if(rank[ulp_u]< rank[ulp_v])
        par[ulp_u]= ulp_v;
        else if(rank[ulp_u]> rank[ulp_v])
        par[ulp_v]= ulp_u;
        else{
            par[ulp_v]= ulp_u; rank[ulp_u]++;
        }
    }
};


int main() {
    DSU ds(7);
    ds.unionRank(1, 2);
    ds.unionRank(2, 3);
    ds.unionRank(4, 5);
    ds.unionRank(6, 7);
    ds.unionRank(5, 6);
    // if 3 and 7 same or not
    if (ds.UPar(3) == ds.UPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionRank(3, 7);

    if (ds.UPar(3) == ds.UPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}