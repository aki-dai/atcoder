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
    long H, W, S1, S2, S3, Smin, Smax, ans = __LONG_MAX__;
    cin>>H>>W;
    long S = H*W; 
    if(H%3 == 0 || W%3 == 0) ans = 0;
    else{
        REP(j, 0, 3){
            REP(i, 0, 3){
                long h = (H+i)/3;
                long w = (W+j)/3;
                
                S1 = H*w;
                S2 = (H-h)*((H-h)/2);
                S3 = S - S1 - S2;
                ans = min(ans, max({S1, S2, S3})-min({S1, S2, S3}));
                
                S2 = (H-h)*(W/2);
                S3 = S - S1 - S2;
                ans = min(ans, max({S1, S2, S3})-min({S1, S2, S3}));
                
                S1 = W*h;
                S2 = (W-w)*((W-w)/2);
                S3 = S - S1 - S2;
                ans = min(ans, max({S1, S2, S3})-min({S1, S2, S3}));
                
                S2 = (W-w)*(H/2);
                S3 = S - S1 - S2;
                ans = min(ans, max({S1, S2, S3})-min({S1, S2, S3}));
            }
        }
    }
    cout << ans << endl;
}
