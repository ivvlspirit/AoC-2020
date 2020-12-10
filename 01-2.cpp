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

    int i, j;
    bool found = false;

    for(int k=0; k<198 && !found; k++){
        i=k+1;
        j=199;

        while(v[i] + v[j] != 2020-v[k]){
            if(v[i] + v[j] > 2020-v[k]) j--;
            else i++;
        }

        if(v[i] + v[j] + v[k] == 2020){
            found = true;
            cout << v[i] << " " << v[j] << " " << v[k] << endl;
            cout << v[i] * v[j] * v[k];
        }
    }


    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}