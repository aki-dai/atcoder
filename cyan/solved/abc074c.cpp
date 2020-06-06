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
    int A, B, C, D, E, F;
    cin>> A >> B >> C >> D >> E >> F;
    int w = 0, ans_w = 0;
    int s = 0, ans_s = 0;
    long double max_con = 0;
    int countA, countB, countC, countD;
    countA = countB = countC = countD = 0; 
    while(A * 100 * countA <= F){
        while(A * 100 * countA + B * 100 * countB <= F){
            w = (A * countA + B * countB) * 100;
            while(w + C * countC <= F){
                while(w + C * countC + D * countD <= F){
                    s = C * countC + D * countD; 
                    if(w/100 * E < s) break;
                    long double con = 100 * (long double)s /(long double)(s + w);
                    if(con > max_con){
                        max_con = con;
                        ans_w = w + s;
                        ans_s = s;
                    }
                    countD++;
                }
                countD = 0;
                countC++;
            }
            countC = 0;
            countB++;
        }
        countB = 0;
        countA++;
    }
    if(max_con == 0){
        ans_w = 100* A;
        ans_s = 0;
    }
    cout << ans_w << " " << ans_s << endl;   
}