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

    int N = 323;
    string in[N];

    int pos = 0;
    ll res = 1;

    vector<pair<int, int>> slopes;

    slopes.push_back({1, 1});
    slopes.push_back({3, 1});
    slopes.push_back({5, 1});
    slopes.push_back({7, 1});
    slopes.push_back({1, 2});


    for(auto it : slopes){
        int trees = 0;
        pos = 0;

        for(int i=0; i<N; i+= it.second){
            cin >> in[i];

            if(in[i][pos] == '#') trees++;

            pos = (pos+it.first)%in[i].length();
        }

        cout << trees << endl;

        res *= trees;
    }

    cout << res;


    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}