#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MOD 999999893
 
long long n, k;
 
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
 
long long gcd(long long a, long long b){
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return gcd(b, a % b);
}
 
long long inv(long long a, long long b){
    a = (a % MOD + MOD) % MOD;
    b = (b % MOD + MOD) % MOD;
    long long c = gcd(a, b);
    a = a / c;
    b = b / c;
    c = power(b, MOD - 2);
    return (a * c) % MOD;
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--){
        cin >> n;
        long long two = power(2, n / 2);
        long long b = (two - 1 + MOD) % MOD;
        long long a = 0;
        
        if(n % 2 == 0) {
            a = (two - 1 + MOD) % MOD;
        } else {
            a = (power(2, n / 2 + 1) - 1 + MOD) % MOD;
        }
        
        long long temp = ((a + 1) * (a + 1)) % MOD;
        temp = (temp - 2 * b * b % MOD + MOD) % MOD;
        
        long long ans = inv(2 * b, temp);
 
        cout << (ans + MOD) % MOD << '\n';
    }
    return 0;
}
