#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;

const int dim = 30;

bool space1[dim][dim][dim];
bool space2[dim][dim][dim];

int main(){

    #ifdef DEBUG
        freopen("..\\input.txt", "r", stdin);
        clock_t tStart = clock();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            for(int k=0; k<dim; k++){
                space1[i][j][k] = false;
                space2[i][j][k] = false;
            }
        }
    }

    string s;

    int o = dim/2;

    // space[z][y][x]

    int row=0;
    while(getline(cin, s)){
        for(int col=0; col<s.length(); col++){
            if(s[col] == '#'){
                space1[o][o+row][o+col] = true;
            }
        }
        row++;
    }
   


    // This is the ugliest piece of code I have ever written in my life

    for(int r=0; r<6; r++){

        for(int i=0; i<dim; i++){
            for(int j=0; j<dim; j++){
                for(int k=0; k<dim; k++){
                    space2[i][j][k] = false;
                }
            }
        }

        // a big part of these z, y, x triples is irrelevant and shouldn't even be visited
        
        for(int z=1; z<dim-1; z++){
            for(int y=1; y<dim-1; y++){
                for(int x=1; x<dim-1; x++){

                    int num = 0;

                    for(int i=-1; i<=1; i++){
                        for(int j=-1; j<=1; j++){
                            for(int k=-1; k<=1; k++){

                                if(i==0 && j==0 && k==0) continue;

                                if(space1[z+i][y+j][x+k]){
                                    num++;
                                    // cout << "a";
                                }

                            }
                        }
                    }

                    if(((space1[z][y][x] && (num == 2 || num == 3)) || ((!space1[z][y][x]) && num == 3))){
                        space2[z][y][x] = true;
                    }

                    
                    
                }
            }
        }

        for(int i=0; i<dim; i++){
            for(int j=0; j<dim; j++){
                for(int k=0; k<dim; k++){
                    space1[i][j][k] = space2[i][j][k];
                }
            }
        }

    }

    int res = 0;


    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            for(int k=0; k<dim; k++){
                if(space1[i][j][k]) res++;
            }
        }
    }

    cout << res;


    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}