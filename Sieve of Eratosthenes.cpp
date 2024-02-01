#include <bits/stdc++.h>

using namespace std;
const int N = 100000000;
vector<char> is_prime(N+1, true);

void sieve(){
    is_prime[0] = false; is_prime[1] = false;
    for (int i = 2; (long long)i*i <= N; i++){
        if (is_prime[i] == true)
        for (int j = i*i; j <= N; j+=i){
            is_prime[j] = false;
        }
    }
}


int main()
{
    sieve();
return 0;
}