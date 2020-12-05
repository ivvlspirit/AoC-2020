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

    int n = 824;

    int res = 0;

    for(int I=0; I<n; I++){
        string s;
        cin >> s;

        int r = 0;
        int c = 0;

        int pot = 64;
        for(int i=0; i<7; i++){
            if(s[i] == 'B') r+=pot;
            pot/=2;
        }

        pot = 4;
        for(int i=7; i<10; i++){
            if(s[i] == 'R') c+=pot;
            pot/=2;
        }

        res = max(res, r*8+c);
    }

    cout << res;

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}