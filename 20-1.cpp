#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;

const int D = 10;

struct tile{
    string data[D];

    set<int> sides;
};

vector<set<int>> sideFreq(2048);
map<int, tile> tiles;

int main(){

    #ifdef DEBUG
        freopen("..\\input.txt", "r", stdin);
        clock_t tStart = clock();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // This code assumes a lot of things that are not true in general case, but are in this particular case

    int N = 144;

    for(int rep=0; rep<N; rep++){
        string s;
        getline(cin, s);

        tile t;

        int key = atoi(s.substr(s.find(" ")+1, 4).c_str()); // it can be checked with ctrl+f and regex "Tile [0-9]{4}:" that all the keys are 4-digit numbers

        for(int i=0; i<D; i++){
            getline(cin, s);
            t.data[i] = s;
        }

        vector<int> sideNums(8, 0);

        for(int i=0; i<D; i++){
            for(int j=0; j<8; j++) sideNums[j] = sideNums[j] << 1;

            if(t.data[0][i] == '#') sideNums[0] |= 1;
            if(t.data[0][D-i-1] == '#') sideNums[1] |= 1;
            if(t.data[D-1][i] == '#') sideNums[2] |= 1;
            if(t.data[D-1][D-i-1] == '#') sideNums[3] |= 1;
            if(t.data[i][0] == '#') sideNums[4] |= 1;
            if(t.data[D-i-1][0] == '#') sideNums[5] |= 1;
            if(t.data[i][D-1] == '#') sideNums[6] |= 1;
            if(t.data[D-i-1][D-1] == '#') sideNums[7] |= 1;
        }

        for(int i=0; i<8; i++){
            t.sides.insert(sideNums[i]);
            sideFreq[sideNums[i]].insert(key);
        }

        getline(cin, s);
    }

    map<int, set<int>> graph;

    for(int i=0; i<1024; i++){
        if(sideFreq[i].size() != 0){
            for(auto u : sideFreq[i]){
                for(auto v : sideFreq[i]){
                    if(u != v){
                        graph[u].insert(v);
                    }
                }
            }
        }
    }

    ll res = 1;

    for(auto it : graph){
        if(it.second.size() == 2) res*=it.first;
    }

    cout << res;

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}