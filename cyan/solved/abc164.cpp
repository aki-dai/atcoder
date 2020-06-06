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
    string S;
    cin>>S;
    int keta = S.size();
    vi Mod(keta), BekiMod(keta), rest(2019);
    rest[0]++;
    Mod[keta-1] = S.back() - '0';
    BekiMod[keta-1] = 1;
    for(int i = S.size()-2; i >= 0; i--){
        BekiMod[i] = (BekiMod[i+1] * 10) % 2019;
    }
    for(int i = S.size()-2; i >= 0; i--){
        int digit = S[i] - '0';
        Mod[i] = (BekiMod[i] * digit + Mod[i+1]) % 2019;
    }
    REP(i, 0, keta){
        rest[Mod[i]]++;
    }
    long ans = 0;
    REP(i, 0, 2019) ans += rest[i] * (rest[i]-1) / 2; 
    cout << ans << endl;
}