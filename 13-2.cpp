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
            }else{
                timestamps.push_back(1);
            }

            comma = i;
        }
    }

    ll incr = timestamps[0];
    ll res = timestamps[0];

    for(int i=1; i<timestamps.size(); i++){
        while((res+i)%timestamps[i] != 0){
            res += incr;
        }

        incr *= timestamps[i];
    }

    cout << res;

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}