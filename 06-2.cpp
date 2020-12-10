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

    string s;
    int res = 0;

    vector<int> answered(26, 0);
    int pplInGroup = 0;

    while(getline(cin, s)){
        if(s==""){
            for(int i=0; i<26; i++){
                if(answered[i] == pplInGroup) res++;
                answered[i] = 0;
            }

            pplInGroup = 0;
        }else{
            pplInGroup++;
            for(int i=0; i<s.length(); i++){
                int ind = s[i] - 'a';
                answered[ind]++;
            }
        }
    }

    for(int i=0; i<26; i++){
        if(answered[i] == pplInGroup) res++;
    }

    cout << res;


    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}