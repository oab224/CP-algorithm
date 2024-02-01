#include <bits/stdc++.h>
 
using namespace std;

void phi(int n){
    int res = n;
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0){
        while(n % i == 0)
            n /= i;
            res -= res/i;
        }
    }
    if (n > 1) res -= res/n;

    cout <<  res << '\n';
}

int main(){
    while(1){
        int n;
        cin >> n;
        if (n==1) cout << 0 << '\n'; else {
        if (n==0) exit(0);
        phi(n);
        }
    }
    return 0;
}
