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
    int res = 0;

    for(int i=0; i<N; i++){
        cin >> in[i];

        if(in[i][pos] == '#') res++;

        pos = (pos+3)%in[i].length();
    }

    cout << res;


    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}