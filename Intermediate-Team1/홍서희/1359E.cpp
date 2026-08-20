#include <iostream>
#include <vector>
using namespace std;
#define MOD 998244353
 
long long n, k;
vector<long long> fact;
 
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}
 
long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * power(fact[r] % MOD * fact[n - r] % MOD, MOD-2) % MOD;
}
 
 
int main() {
    cin >> n >> k;
 
    fact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
 
    long long ans = 0;
    for(int i=1;i<=n;i++){
        long long numer=n/i-1;
        long long denom=k-1;
        if(numer<denom)continue;
        else ans=(ans+nCr(numer,denom))%MOD;
    }
    cout << ans;;
    return 0;
}
