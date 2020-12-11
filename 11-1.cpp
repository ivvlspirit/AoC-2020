#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;
vector<string> s;
int N, M;

bool iterate(){
    vector<string> newS = s;
    bool ret = false;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(s[i][j] == '.') continue;

            int occ = 0;

            for(int y=-1; y<=1; y++){
                for(int x=-1; x<=1; x++){
                    if((x==0 && y==0) || (i+y >= N || i+y < 0 || j+x >= M || j+x < 0)) continue;

                    if(s[i+y][j+x] == '#') occ++;
                }
            }

            if(s[i][j] == 'L' && occ == 0){
                newS[i][j] = '#';
                ret = true;
            }
            if(s[i][j] == '#' && occ >= 4){
                newS[i][j] = 'L';
                ret = true;
            }
        }
    }

    s = newS;
    return ret;

}

int main(){

    #ifdef DEBUG
        freopen("..\\input.txt", "r", stdin);
        clock_t tStart = clock();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;

    while(getline(cin, line)){
        s.push_back(line);
    }

    N=s.size();
    M=s[0].length();

    bool cond;

    do{
        cond = iterate();
    }while(cond);

    int res = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(s[i][j] == '#') res++;
        }
    }

    cout << res;

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}