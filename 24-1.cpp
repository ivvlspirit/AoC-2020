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
    int N = 300;
    vector<vector<bool>> grid(N, vector<bool>(N, false));

    while(getline(cin, s)){
        vector<string> comms;
        for(int i=0; i<s.length(); i++){
            if(s[i] == 'e' || s[i] == 'w'){
                comms.push_back(s.substr(i, 1));
            }else if(s[i] == 'n' || s[i] == 's'){
                comms.push_back(s.substr(i, 2));
                i++;
            }
        }

        int x = 100, y = 100;

        for(auto comm : comms){
            if(comm == "w") x--;
            if(comm == "e") x++;

            if(comm == "sw"){
                y--;

                if(y%2!=0){
                    x--;
                }
            }
            
            if(comm == "se"){
                y--;

                if(y%2==0){
                    x++;
                }
            }

            if(comm == "nw"){
                y++;

                if(y%2!=0){
                    x--;
                }
            }

            if(comm == "ne"){
                y++;

                if(y%2==0){
                    x++;
                }
            }
        }

        grid[x][y] = !grid[x][y];
    }

    int res = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(grid[i][j]) res++;
        }
    }

    cout << res;

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}