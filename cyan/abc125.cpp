#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>

vi devideA(vi A, int p){
    vi ret_A;
    REP(i, 0, A.size()){
        
    }
    return ret_A;
}
int gcd(long long a, long long b){
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

int main() {
    int N;
    cin>>N;
    vi A(N), L(N), R(N);
    REP(i, 0, N) cin >> A[i];
    L[0] = A[0]; R[N-1] = A[N-1];
    REP(i, 0, N-1){
        L[i+1] = gcd(L[i], A[i+1]);
        R[N-2-i] = gcd(R[N-1-i], A[N-2-i]);
    }
    int ans = 0;
    REP(i, 0, N){
        if(i == 0) ans = max(ans, R[1]);
        else if(i == N-1) ans = max(ans, L[N-2]);
        else ans = max(ans, gcd(L[i-1], R[i+1]));
    }
    cout << ans << endl;
}