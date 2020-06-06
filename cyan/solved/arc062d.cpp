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
    string s; 
    cin>>s;
    int p_count = 0;
    REP(i, 0, s.size()){
        if(s[i] == 'p') p_count++;
    }
    int p_max = (int)s.size()/2;
    cout << p_max - p_count << endl;
}