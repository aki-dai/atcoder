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
    vector<bool> erats(300001, true);
    vector<long> primes;
    REP(i, 2, 300000){
        if(erats[i]){
            primes.push_back(i);
            long j = i * 2;
            while(j <= 300000){
                erats[j] = false;
                j += i;
            }
        }    
    }
    vi p_five;
    for(auto p: primes){
        if(p % 5 == 1) p_five.push_back(p);
    }
    
    REP(i, 0, N) cout << p_five[i] << " ";
    cout << endl;
}