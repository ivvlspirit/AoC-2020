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

    int x;
    int n = 0;
    string s;
    vector<int> adapters;

    while(getline(cin, s)){
        x = atoi(s.c_str());
        adapters.push_back(x);
        n++;
    }

    adapters.push_back(0);
    n++;

    sort(adapters.begin(), adapters.end());
    vector<int> diffs(4, 0);

    for(int i=1; i<n; i++){
        diffs[adapters[i]-adapters[i-1]]++;
    }

    diffs[3]++;

    cout << diffs[1]*diffs[3];


    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}