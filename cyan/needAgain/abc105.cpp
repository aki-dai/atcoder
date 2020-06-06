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
    string ans = "";
    int digit = 1;
    while(N != 0){
        int r = N%2;
        if(r < 0) r += 2;
        N = (N-r)/(-2);
        ans += (char)('0'+r);        
    }
    reverse(ans.begin(), ans.end());
    if(ans == "") ans = "0";
    cout << ans << endl;
}