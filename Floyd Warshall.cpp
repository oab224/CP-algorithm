#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN = 5e2+1; ll INF = 1e18;
ll d[mxN][mxN], n, m, q;

int main(){
    cin >> n >> m >> q;
    memset(d, 0x3f3f3f3f , sizeof(d));
    for (int i = 0, u, v, w; i < m; i++){
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], (ll)w);
        d[v][u] = min(d[v][u], (ll)w);
    }
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    for (int k = 1; k <= n; k++){      
        for (int i = 1; i <= n; i++){   
            for (int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for (int i = 0, a, b; i < q; i++){
        cin >> a >> b;
        cout << (d[a][b] >= INF ? -1 : d[a][b]) << "\n";
    }

}