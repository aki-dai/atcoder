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
    int H, W;
    cin>>H>>W;
    vvi A(H, vi(W, 0));
    vector<pint> B;
    REP(i, 0, H){
        string S;
        cin >> S;
        REP(j, 0, W){
            if(S[j] == '#'){
                A[i][j] = 1;
                B.push_back({i, j});
            }
        }   
    }
    queue<pint> que;
    vvi Map(H, vi(W, -1));
    for(pint a: B){
        que.push(a);
        Map[a.first][a.second] = 0;
    }
    vector<pint> D = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int ans = 0;
    while(!que.empty()){
        auto cur = que.front(); que.pop();
        int count = Map[cur.first][cur.second];
        //cout << cur.first << " " << cur.second << endl;
        ans = max(ans, count);
        for(pint x: D){
            int new_x = cur.first + x.first;
            int new_y = cur.second + x.second;
            if(new_x < 0 || new_y < 0 || new_x >= H || new_y >= W) continue;
            if(Map[new_x][new_y] == -1){
                que.push({new_x, new_y});
                Map[new_x][new_y] = count + 1;
            }
        }
    }
    cout << ans << endl;
}