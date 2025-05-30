#include <bits/stdc++.h>
using namespace std;

class dsu {
public:
    vector<int> rank, par, size;
    dsu(int n) {
        rank.resize(n + 1, 0);
        par.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }

    int upar(int u) {
        if (par[u] == u) return u;
        return par[u] = upar(par[u]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = upar(u);
        int ulp_v = upar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            par[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            par[ulp_v] = ulp_u;
        } else {
            par[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = upar(u);
        int ulp_v = upar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            par[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            par[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class sol {
public:
    int solve(int n, vector<vector<int>>& edge) {
        dsu ob(n);
        int ext = 0;

        for (auto& it : edge) {
            if (ob.upar(it[0]) == ob.upar(it[1])) {
                ext++;
            } else {
                ob.unionBySize(it[0], it[1]);
            }
        }

        int cntC = 0;
        for (int i = 0; i < n; i++) {
            if (ob.par[i] == i) cntC++;
        }

        int ans = cntC - 1;
        if (ext >= ans) return ans;
        return -1;
    }
};

int main() {
    int V = 9;
    vector<vector<int>> edge = {
        {0, 1}, {0, 2}, {0, 3}, {1, 2}, {2, 3},
        {4, 5}, {5, 6}, {7, 8}
    };

    sol obj;
    int ans = obj.solve(V, edge);
    cout << "The number of operations needed: " << ans << endl;
    return 0;
}
