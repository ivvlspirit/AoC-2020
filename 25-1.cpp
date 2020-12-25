#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 20201227;

int main(){

    #ifdef DEBUG
        freopen("..\\input.txt", "r", stdin);
        clock_t tStart = clock();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll c, d;
    cin >> c >> d;

    ll temp = 1;
    ll sn = 7;

    int dls=0;

    while(temp != d){
        temp*=sn;
        temp%=MOD;
        dls++;
    }

    temp = 1;
    sn = c;

    for(int i=0; i<dls; i++){
        temp*=sn;
        temp%=MOD;
    }

    cout << temp;


    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}