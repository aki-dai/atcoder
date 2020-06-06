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
    int H, W, D;
    cin>>H>>W>>D;
    vvi A(H, vi(W, 0));
    vector<pint> B(H*W);
    REP(i, 0, H){
        REP(j, 0, W){
            int a;
            cin >> a;
            A[i][j] = a;
            a--;
            B[a] = {i, j};
        }
    }

    vl move(H*W);
    REP(i, 0, D){
        int count = i;
        while(count < H*W){
            if(count < D){
                move[count] = 0;
            }else{
                move[count] = move[count-D] + abs(B[count].first - B[count - D].first) + abs(B[count].second - B[count - D].second);
            }
            count += D;
        }
    }
    //REP(i, 0, H*W) cout << move[i] << endl;
    int Q, L, R;
    cin >> Q;
    REP(i, 0, Q){
        cin >> L >> R;
        L--; R--;
        long ans = move[R] - move[L];
        cout << ans << endl;
    }
}