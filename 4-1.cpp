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

    int pi = 0;
    int res = 0;

    vector<set<string>> pass(1000);
    string s;

    while(getline(cin, s)){
        if(s == ""){
            if(pass[pi].size() == 8 || (pass[pi].size() == 7 && pass[pi].count("cid") == 0)) res++;
            
            pi++;
        }

        for(int i=0; i<s.length(); i++){
            if(s[i] == ':'){
                pass[pi].insert(s.substr(i-3, 3));
            }
        }
    }

    cout << res;

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}