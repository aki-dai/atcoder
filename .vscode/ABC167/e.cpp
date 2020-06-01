#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>

long MOD = 998244353;
long long MODPOW(long long inv,long long pow, long long mod){
    if(pow == 1) return inv % mod;
    else{
        if(pow % 2) return inv * MODPOW(inv, pow -1, mod) % mod;
        long long res = MODPOW(inv, pow/2, mod);
        return res * res % mod; 
    }
}

long long COMMOD(int a, int b){
    long long res=1; long long resinv = 1;
    for(int i = a; i>a-b; i--){
        res = res * i % MOD;
        resinv = resinv*(a-i+1) % MOD;
    }
    return res*MODPOW(resinv, MOD-2, MOD) % MOD;
}

int main() {
    long N, M, K;
    cin>>N>>M>>K;
    vl Com(N), Color(N);
    Color[N-1]= M; 
    for(int i = N-2; i >= 0; i--){
        Color[i] = Color[i+1]*(M-1) % MOD;
        //cout << Color[i] << endl;
    }
    Com[0] = 1;
    long res = N-1; long resinv = 1;
    REP(i, 1, N){
        Com[i] = Com[i - 1] * res % MOD;
        Com[i] *= MODPOW(resinv, MOD-2, MOD);
        Com[i] %= MOD;
        res--; resinv++;
        //cout << Com[i] << endl;
    }
    long ans = 0;
    REP(i, 0, K+1){
        ans += Color[i] * Com[i] % MOD;
        if(ans > MOD) ans %= MOD;
    }
    cout << ans << endl;

}