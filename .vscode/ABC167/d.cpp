#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(long i = (long)(init); i < (long)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>

int main() {
    long N, K; 
    cin>>N>>K;
    vl A(N), Num(N, __INT_MAX__);
    vector<bool> Town(N, false);
    REP(i, 0, N){
        long to;
        cin >> to;
        to--;
        A[i] = to;
    }
    long cur = 0;
    long count = 0;
    while(!Town[cur]){
        if(count>=K){
            cout << cur+1 << endl;
            return 0;
        }
        Num[cur] = count;
        Town[cur] = true;
        count++;
        cur = A[cur];
    }
    long freq = count - Num[cur];
    long rest = (K - Num[cur]) % freq;
    REP(i, 0, rest){
        cur = A[cur];
    }
    cur++;
    cout << cur << endl;   
}