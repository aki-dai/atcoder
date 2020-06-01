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
    string s, t;
    cin>> s >> t;
    string s_double = s + s;
    int s_len = s.size();
    vvi s_next(26, vi(s_len, -1));
    long length = 1;

    for(int i = s_len * 2 - 1; i > 0; i--){
        REP(j, 0, 26){
            if(s_double[i] == 'a' + j) s_next[j][(i-1)%(s_len)] = 1;
            else if(s_next[j][i%(s_len)] != -1) s_next[j][(i-1)%(s_len)] = s_next[j][i%(s_len)] + 1;
        }
    }
    int s_pos = 0;
    REP(i, 0, t.size()){
        if(s_next[t[i]- 'a'][s_pos] == -1){
            length = -1;
        }else{
            if(i == 0 && s[i] == t[i]) continue;
            else if(length > 0) length += s_next[t[i] - 'a'][s_pos];
            s_pos += s_next[t[i] - 'a'][s_pos];
            s_pos %= s_len;
        }
    }
    cout << length << endl;
}