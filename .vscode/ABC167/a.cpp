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
    string S, T; 
    cin>>S>>T;
    string ans = "No";
    for(char c = 'a'; c <= 'z'; c++){
        string st = S + c;
        if(st == T) ans = "Yes";
    }
    cout << ans << endl;
    
}