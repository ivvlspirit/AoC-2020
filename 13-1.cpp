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

    int ts;
    cin >> ts;
    
    string buses;
    cin >> buses;

    vector<int> timestamps;
    int comma = -1;

    for(int i=0; i<=buses.length(); i++){
        if(i==buses.length() || buses[i] == ','){
            string part = buses.substr(comma+1, i-comma-1);

            if(part != "x"){
                timestamps.push_back(atoi(part.c_str()));
            }

            comma = i;
        }
    }

    int mn = 1e9;
    int res;

    for(auto it : timestamps){
        int earliest = it*(int)ceil((float)ts/it);

        if(earliest < mn){
            mn = earliest;
            res = it * (earliest-ts);
        }
    }

    cout << res;

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}