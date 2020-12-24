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

        int x = N/2, y = N/2;

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

    int daysToCount = 100;

    for(int day=1; day<=daysToCount; day++){
        set<pair<int, int>> flip;

        for(int x=1; x<N-1; x++){
            for(int y=1; y<N-1; y++){
                int xOff = (y%2!=0 ? 1 : -1);

                int blacks = 0;
                if(grid[x-1][y]) blacks++;
                if(grid[x+1][y]) blacks++;
                if(grid[x][y-1]) blacks++;
                if(grid[x+xOff][y-1]) blacks++;
                if(grid[x][y+1]) blacks++;
                if(grid[x+xOff][y+1]) blacks++;

                if((grid[x][y] && (blacks == 0 || blacks > 2)) || (!grid[x][y] && blacks == 2)){
                    flip.insert({x, y});
                }
            }
        }

        for(auto f : flip){
            grid[f.first][f.second] = !grid[f.first][f.second];
        }

        if(day == daysToCount){
            int res = 0;

            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    if(grid[i][j]) res++;
                }
            }

            cout << res;
        }
    }

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}