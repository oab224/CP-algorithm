#include <bits/stdc++.h>
using namespace std;
const int mxN = 100005;
vector<pair<long long, int> > v[mxN];
const long long oo = 1000000000000000000;
long long d[mxN] = {0};
int path[mxN] = {0};
typedef pair<long long, int> ii;
void djkstra(int n){
    priority_queue<ii, vector<ii>, greater<ii> > q;
    
    d[n] = 0;
    q.push({0, n});
    while(q.size()){
        int u = q.top().second; //1     
        q.pop();
      //if (d[u.first] != u.second) continue;
        for (auto x : v[u]){

            if (d[u] + x.first < d[x.second]){
                d[x.second] = d[u] + x.first; //
                q.push({d[x.second], x.second});
                path[x.second] = u;
            }
        }
    }
}

void findd (long long n)
{
 if (n!=1) findd(path[n]);
 cout<<n<<' ';
}
void solve(){
    int n, m, s; cin >> n >> m;
    for (int i = 1; i <= n; i++) v[i].clear();
    for (int i = 0, x, y, r; i < m; i++){
        cin >> x >> y >> r;
        v[x].push_back({r,y});
      //  v[y].push_back({r,x});
    }
    for (int i = 2; i <= n; i++) d[i] = 1e18;
    djkstra(1);
    /* if (d[n] == 1e18) cout << -1; else findd(n); */
    for (int i = 1; i <= n; i++) cout << d[i] << " ";
}

int main(){
        solve();
        return 0;
}