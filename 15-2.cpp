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

    // Probably a terrible solution, couldn't think of a faster one

    int input[] = {2,20,0,4,1,17};

    map<int, int> age;
    int last = 17;
    int turn = 7;

    for(int i=0; i<5; i++){
        age[input[i]] = i+1;
    }

    for(int i=turn; i<=30000000; i++){
        int temp = last;

        if(age.count(last)){
            last = i-age[last]-1;
        }else{
            last = 0;
        }

        age[temp] = i-1;
    }

    cout << last;

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}