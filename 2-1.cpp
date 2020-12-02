#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;

int main(){

    #ifdef DEBUG
        freopen("..\\input.txt", "r", stdin);
        clock_t tStart = clock();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int res = 0;

    for(int i=0; i<1000; i++){
        string rs, cs, ps;
        cin >> rs >> cs >> ps;

        int a, b;
        int dash=0;

        while(rs[dash]!='-') dash++;

        a = atoi(rs.substr(0, dash).c_str());
        b = atoi(rs.substr(dash+1).c_str());

        char c = cs[0];

        int cn = 0;

        for(int j=0; j<ps.length(); j++){
            if(ps[j] == c) cn++;
        }

        if(cn >= a && cn <= b) res++;
    }

    cout << res;

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}