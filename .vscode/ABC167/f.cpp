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
    int N, count = 0;
    cin >> N;
    vvi S(N); 
    vector<vector<int>> Least(N);
    REP(i, 0, N){
        string s;
        cin >> s;
        int best = 0, least = 0;
        int counter = 0;
        REP(j, 0, s.size()){
            if(s[j] == '('){
                count++;
                counter++;
                best = max(counter, best);
            }else{
                count--;
                counter--;
                least = min(counter, least);
            }        
        }
        Least[i] = {counter, least, best};
    }
    if(count != 0){
        cout << "No" << endl;
        return 0;
    }
    sort(Least.rbegin(), Least.rend());
    /*
    REP(i, 0, N){
        cout << Least[i][0] << " " << Least[i][1] << " " << Least[i][2] << endl;
    }*/
    count = 0;
    REP(i, 0, N){
        if(count + Least[i][1] < 0){            
            cout << "No" << endl;
            return 0;
        }
        else{
            count += Least[i][0];
        }
    }
    cout << "Yes" << endl;
}