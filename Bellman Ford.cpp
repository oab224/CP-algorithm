#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
int n, m; 
ll INF = 1e17, inf = -1e17;
const int mxN = 2.5e2;
ll d[mxN + 1] = {0};

int main(){
    cin >> n >> m;
    vector<ar<ll, 3> >adj;
    for (int i = 0, u, v, w; i < m; i++){
        cin >> u >> v >> w;
        adj.push_back({u, v, -w});
    }
    d[1] = 0; 
    for (int i = 2; i <= n; i++) d[i] = INF;
    for (int i = 1; i < n; i++){
        for (auto x : adj){
            if (d[x[0]] < INF) 
            d[x[1]] = min(d[x[1]], d[x[0]] + x[2]);
        }
    }
    for (int i = 1; i < n; i++){
        for (auto x : adj){
            if (d[x[0]] == INF) continue;
            d[x[1]] = max(d[x[1]], inf);
            if (d[x[0]] + x[2] < d[x[1]]) d[x[1]] = inf;
        }
    }
    cout << (d[n] == inf ? -1 : -d[n]);
    return 0;
}