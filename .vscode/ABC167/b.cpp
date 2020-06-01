#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>

int main() {
    int A, B, C, K;
    cin>>A>>B>>C>>K;
    int rest = K, ans = 0;
    if(rest >= A){
        rest -= A;
        ans += A;
    }else{
        ans = rest;
        rest = 0;
    }
    if(rest >= B){
        rest -= B;
    }else{
        rest = 0;
    }
    
    if(rest >= 0){
        ans -= rest;
        rest = 0;
    }
    cout << ans << endl;
}