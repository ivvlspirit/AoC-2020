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

    vector<int> v(200);

    for(int i=0; i<200; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int i=0, j=199;

    while(v[i] + v[j] != 2020){
        if(v[i] + v[j] > 2020) j--;
        else i++;
    }

    cout << v[i] << " " << v[j] << endl;
    cout << v[i]*v[j];

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}