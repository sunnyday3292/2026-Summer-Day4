#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007
 
long long a, b, n;
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
 
bool isExcellent(long long sum) {
    while (sum > 0) {
        long long digit = sum % 10;
        if (digit != a && digit != b) return false;
        sum /= 10;
    }
    return true;
}
 
int main() {
    cin >> a >> b >> n;
 
    fact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
 
    long long total_excellent = 0;
    for (int i = 0; i <= n; i++) {
        long long sum = (a * i) + b * (n - i);
        
        if (isExcellent(sum)) {
            total_excellent = (total_excellent + nCr(n, i)) % MOD;
        }
    }
 
    cout << total_excellent;
    return 0;
}
