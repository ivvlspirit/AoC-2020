#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;

const int dim = 30;

bool space1[dim][dim][dim][dim];
bool space2[dim][dim][dim][dim];

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
                for(int l=0; l<dim; l++){
                    space1[i][j][k][l] = false;
                    space2[i][j][k][l] = false;
                }
            }
        }
    }

    string s;

    int o = dim/2;

    // space[w][z][y][x]

    int row=0;
    while(getline(cin, s)){
        for(int col=0; col<s.length(); col++){
            if(s[col] == '#'){
                space1[o][o][o+row][o+col] = true;
            }
        }
        row++;
    }
   


    // This is disgusting

    for(int r=0; r<6; r++){

        for(int i=0; i<dim; i++){
            for(int j=0; j<dim; j++){
                for(int k=0; k<dim; k++){
                    for(int l=0; l<dim; l++){
                        space2[i][j][k][l] = false;
                    }
                }
            }
        }

        // a huge part of these w, z, y, x quadruples is irrelevant and shouldn't even be visited

        for(int w=1; w<dim-1; w++){
            for(int z=1; z<dim-1; z++){
                for(int y=1; y<dim-1; y++){
                    for(int x=1; x<dim-1; x++){

                        int num = 0;

                        for(int i=-1; i<=1; i++){
                            for(int j=-1; j<=1; j++){
                                for(int k=-1; k<=1; k++){
                                    for(int l=-1; l<=1; l++){
                                        if(i==0 && j==0 && k==0 && l==0) continue;

                                        if(space1[w+i][z+j][y+k][x+l]){
                                            num++;
                                        }
                                    }
                                }
                            }
                        }

                        if(((space1[w][z][y][x] && (num == 2 || num == 3)) || ((!space1[w][z][y][x]) && num == 3))){
                            space2[w][z][y][x] = true;
                        }

                        
                        
                    }
                }
            }
        }

        for(int i=0; i<dim; i++){
            for(int j=0; j<dim; j++){
                for(int k=0; k<dim; k++){
                    for(int l=0; l<dim; l++){
                        space1[i][j][k][l] = space2[i][j][k][l];
                    }
                }
            }
        }

    }

    int res = 0;


    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            for(int k=0; k<dim; k++){
                for(int l=0; l<dim; l++){
                    if(space1[i][j][k][l]) res++;
                }
            }
        }
    }

    cout << res;


    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}