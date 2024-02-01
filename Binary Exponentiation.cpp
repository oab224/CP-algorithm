#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

ll last3digits(ll b, int p){
      ll ans = 1;
      while (p > 0){
        if (p&1) ans = ans * b % 1000;
          b =               b * b % 1000 ;
          p >>= 1 ;
      }
      return ans;
}

void solve(){
    ll n, k;
    cin >> n >> k;
    //n*n
    double a = k*(log10(n));
    double decimal = a - floor(a);
    double base = pow(10, decimal);
    int first3digits = base*100;
    cout << first3digits << "...";
    printf("%03d\n", last3digits(n, k));
    //setw(3), setfill('0') in a case that the last 3 digits are 012..;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}