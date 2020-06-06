#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    int N, M;
    cin>>N>>M;
    vi p(N);
    vector<pint> pair(M);
    REP(i, 0, N){
        int a;
        cin >> a;
        a--;
        p[i] = a;
    }
    REP(i, 0, M){
        int x, y;
        cin >> x >> y;
        x--; y--;
        pair[i] = {x, y};
    }
    UnionFind group(N);
    REP(i, 0, M){
        int p = pair[i].first, q = pair[i].second;
        group.unite(p, q);
    }
    int count = 0;
    REP(i, 0, N){
        if(group.same(i, p[i])) count++;
    }
    cout << count << endl;
}