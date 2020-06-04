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
    int N;
    cin>>N;
    vi A(N);
    vector<pint> E;
    REP(i, 0, N) cin >> A[i];
    sort(A.begin(), A.end());
    int Least = A[0];
    int M, p;
    for(int i = N-1; i > 0; i--){
        if(A[i]>=0 && A[i-1] >= 0 && i >1){
            E.push_back({Least, A[i]});
            Least -= A[i];
        }else{
            M = A[i];
            E.push_back({M, Least});
            M -= Least;
            p = i;
            break;
        }
    }
    REP(i, 1, p){
        E.push_back({M, A[i]});
        M -= A[i];
    }
    cout << M << endl;
    REP(i, 0, N-1) cout << E[i].first << " " << E[i].second << endl;
}