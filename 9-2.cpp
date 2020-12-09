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

    int n = 1000;
    int p = 25;

    vector<ll> input;
    for(int i=0; i<n; i++){
        ll x;
        cin >> x;

        input.push_back(x);
    }

    ll invalid;

    for(int i=p; i<n; i++){
        bool cond = false;

        for(int j=0; j<p; j++){
            for(int k=0; k<p; k++){
                if(j!=k && input[i-p+j] + input[i-p+k] == input[i]){
                    cond = true;
                }
            }
        }

        if(!cond){
            invalid = input[i];
            break;
        }
    }

    ll ps[n+1];
    ps[0] = 0;

    for(int i=1; i<=n; i++){
        ps[i] = ps[i-1] + input[i-1];
    }

    ll res;

    for(int i=0; i<n; i++){
        for(int j=i+2; j<=n; j++){

            if(ps[j] - ps[i] == invalid){
                ll mn = 1e18;
                ll mx = -1e18;

                for(int k=i; k<=j; k++){
                    mn = min(mn, input[k]);
                    mx = max(mx, input[k]);
                }

                res = mn + mx;
                break;
            }

        }
    }

    cout << res;


    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}