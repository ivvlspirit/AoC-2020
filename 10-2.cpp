#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;

ll dp[1000];
vector<ll> adapters;

ll countWays(int n){
    if(dp[n] != 0) return dp[n];

    ll res = 0;
    
    for(int i=1; i<=3; i++){
        if(n+i < adapters.size() && adapters[n+i]-adapters[n] <= 3){
            res+=countWays(n+i);
        }
    }

    dp[n] = res;
    return res;
}

int main(){

    #ifdef DEBUG
        freopen("..\\input.txt", "r", stdin);
        clock_t tStart = clock();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x;
    int n = 0;
    string s;
    ll mx = 0;

    while(getline(cin, s)){
        x = atoi(s.c_str());
        adapters.push_back(x);
        mx = max(mx, x);
    }

    adapters.push_back(0);
    adapters.push_back(mx+3);
    n=adapters.size();

    sort(adapters.begin(), adapters.end());
    dp[n-1] = 1;
    

    // Other solution, both work in the same time complexity

    // for(int i=adapters.size()-2; i>=0; i--){
    //     for(int j=1; j<=3 && i+j < adapters.size(); j++){
    //         if(adapters[i+j]-adapters[i] <= 3){
    //             dp[i] += dp[i+j];
    //         }
    //     }
    // }

    cout << countWays(0) << endl;
    // cout << dp[0];


    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}