#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
#define pb push_back
const int mxN = 1e5 + 1;
int a[mxN]; int loga[mxN];
int spt[mxN][27];
void init(){
    loga[1] = 0;
    for (int i = 2; i <= mxN; i++){
        loga[i] = loga[i/2] + 1;
    }
}
// range minimum querries
void solve(){
    init();
    
    int n, q, l, r;
    cin >> n;
    int k = loga[n] + 1;
     for (int i = 0; i < n; i++)
        cin >> a[i], spt[i][0] = a[i];
    for (int j = 1; j <= k; j++){
        for (int i = 0; i + (1<<(j-1)) < n; i++){
                spt[i][j] = min(spt[i][j-1], spt[i + (1 << (j-1))][j-1]);
        }
    }
    cin >> q;
    while(q--){
        cin >> l >> r;
        int t = loga[r - l + 1];
        cout << min(spt[l][t], spt[r - (1<<t) + 1][t]) << '\n';
    } 
}   
 
int main(){
    solve();
    return 0;
}