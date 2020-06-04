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
    double n, m, d;
    cin>>n>>m>>d;
    double ans = 0;
    if(d == 0) ans = (m-1)/n;
    else ans = (m-1)* 2*(n-d)/(n*n);
    cout << setprecision(10) << ans << endl;
}