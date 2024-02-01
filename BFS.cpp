#include <bits/stdc++.h>
using namespace std;
vector<int> v[1001];
bool vis[1001] = {0};
int c[1001] = {0};
void solve(){
    int n, m, s; cin >> n >> m;
    for (int i = 0, a, b; i < m; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin >> s;
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty()){
        int u = q.front();
        vis[u] = 1;
        q.pop();
        for (auto x : v[u]){
            if (!vis[x]){
                c[x] = c[u] + 6;
                vis[x] = 1;
                q.push(x);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        v[i].clear();
        vis[i] = 0;
        if (i!=s) cout << (c[i] == 0? -1 : c[i]) << " ";
        c[i] = 0;
    }
    cout << "\n";

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}