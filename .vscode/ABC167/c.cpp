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
    int N, M, X;
    cin>>N>>M>>X;
    vi C(N);
    vvi A(N, vi(M));
    REP(i, 0, N){
        cin >> C[i];
        REP(j, 0, M){
            cin >> A[i][j];
        }
    }
    int count = (1<<N);
    int min_price = __INT_MAX__;
    vi bitA(N);
    REP(i, 0, count){
        int bit = i;
        REP(j, 0, N){
            bitA[j] = bit % 2;
            bit = (bit >> 1);
            //cout << bitA[j] << " ";
        }
        //cout << endl;
        vi sum(M, 0);
        int price = 0;
        REP(j, 0, N){
            if(bitA[j]){            
                REP(k, 0, M){
                    sum[k] += A[j][k];
                }
                price += C[j];
            }
        }

        bool match = true;
        REP(k, 0, M){
            if(sum[k] < X) match = false;
        }
        if(match) min_price = min(price, min_price);
    }
    if(min_price == __INT_MAX__) min_price = -1;
    cout << min_price << endl;
}