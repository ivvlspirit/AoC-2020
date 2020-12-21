#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;

const int D = 10;

struct tile{
    string data[D];
    string types[8][D];

    vector<int> sides;
};

vector<set<int>> sideFreq(2048);
map<int, tile> tiles;

void generateTypes(int key){
    vector<string> data(D);
    for(int i=0; i<D; i++){
        data[i] = tiles[key].data[i];
    }


    for(int i=0; i<4; i++){
        for(int j=0; j<D; j++){
            tiles[key].types[2*i][j] = data[j];
            // if(key == 3301) cout << data[j] << endl;
            tiles[key].types[2*i+1][j] = data[D-j-1];
        }
        // if(key==3301) cout << endl;

        vector<string> dataRot(D);

        for(int j=0; j<D; j++){
            string temp = "";
            for(int k=D-1; k>=0; k--){
                temp += data[k][j];
            }

            dataRot[j] = temp;
        }

        data = dataRot;
    }
}

int main(){

    #ifdef DEBUG
        freopen("..\\input.txt", "r", stdin);
        clock_t tStart = clock();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // This code assumes a lot of things that are not true in general case, but are in this particular case
    // This code would probably break even on the examples from the task
    
    int N = 144;

    for(int rep=0; rep<N; rep++){
        string s;
        getline(cin, s);

        tile t;

        int key = atoi(s.substr(s.find(" ")+1, 4).c_str()); // it can be checked with ctrl+f and regex "Tile [0-9]{4}:" that all the keys are 4-digit numbers

        for(int i=0; i<D; i++){
            getline(cin, s);
            t.data[i] = s;
        }

        vector<int> sideNums(8, 0);

        for(int i=0; i<D; i++){
            for(int j=0; j<8; j++) sideNums[j] = sideNums[j] << 1;

            if(t.data[0][i] == '#') sideNums[0] |= 1;
            if(t.data[0][D-i-1] == '#') sideNums[1] |= 1;
            if(t.data[D-1][i] == '#') sideNums[2] |= 1;
            if(t.data[D-1][D-i-1] == '#') sideNums[3] |= 1;
            if(t.data[i][0] == '#') sideNums[4] |= 1;
            if(t.data[D-i-1][0] == '#') sideNums[5] |= 1;
            if(t.data[i][D-1] == '#') sideNums[6] |= 1;
            if(t.data[D-i-1][D-1] == '#') sideNums[7] |= 1;
        }

        for(int i=0; i<8; i++){
            t.sides.push_back(sideNums[i]);
            sideFreq[sideNums[i]].insert(key);
        }

        tiles[key] = t;
        generateTypes(key);

        getline(cin, s);
    }

    map<int, set<int>> graph;

    for(int i=0; i<1024; i++){
        if(sideFreq[i].size() != 0){
            for(auto u : sideFreq[i]){
                for(auto v : sideFreq[i]){
                    if(u != v){
                        graph[u].insert(v);
                    }
                }
            }
        }
    }

    set<int> visited;
    int image[12][12];

    int topLeft;

    for(auto it : graph){
        if(it.second.size() == 2){
            topLeft = it.first;
            break;
        }
    }


    // Putting one of the corners in the top Left corner;
    image[0][0] = topLeft;
    visited.insert(image[0][0]);


    // Constructing the first row
    for(int i=0; i<11; i++){
        for(auto it : graph[image[0][i]]){
            if(visited.count(it) == 0 && graph[it].size() != 4){
                image[0][i+1] = it;
                break;
            }
        }
        visited.insert(image[0][i+1]);
    }

    // Adding the second neighbour of the top left
    for(auto it : graph[image[0][0]]){
        if(visited.count(it) == 0){
            image[1][0] = it;
            visited.insert(it);
        }
    }

    // Constructing other rows
    for(int i=1; i<12; i++){
        for(int j=1; j<12; j++){
            for(auto it : graph[image[i][j-1]]){
                if(visited.count(it) == 0 && graph[image[i-1][j]].count(it)){
                    image[i][j] = it;
                    break;
                }
            }

            visited.insert(image[i][j]);
        }

        if(i!=11){
            for(auto it : graph[image[i][0]]){
                if(visited.count(it) == 0 && graph[it].size() != 4){
                    image[i+1][0] = it;
                    visited.insert(it);
                    break;
                }
            }
        }
    }

    // Declaring the orientation of each segment
    vector<vector<int>> orientation(12, vector<int>(12, -1));

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            for(int k=0; k<8; k++){
                string right = "", left = "";
                for(int l=0; l<D; l++){
                    right += tiles[image[0][0]].types[i][l][D-1];
                    left += tiles[image[0][1]].types[j][l][0];
                }

                if(tiles[image[0][0]].types[i][D-1] == tiles[image[1][0]].types[k][0] && left == right){
                    orientation[0][0] = i;
                    orientation[0][1] = j;
                    orientation[1][0] = k;
                }
            }
        }
    }

    for(int i=0; i<12; i++){
        for(int j=1; j<12; j++){
            for(int k=0; k<8; k++){
                string right = "", left = "";

                for(int l=0; l<D; l++){
                    right += tiles[image[i][j-1]].types[orientation[i][j-1]][l][D-1];
                    left += tiles[image[i][j]].types[k][l][0];
                }

                if(left == right){
                    orientation[i][j] = k;
                    break;
                }
            }
        }

        for(int j=0; j<8; j++){
            string bottom = tiles[image[i][0]].types[orientation[i][0]][D-1];
            string top = tiles[image[i+1][0]].types[j][0];

            if(bottom == top){
                orientation[i+1][0] = j;
                break;
            }
        }
    }


    // Constructing the final picture
    vector<vector<char>> pic(96, vector<char>(96));

    for(int i=0; i<12; i++){
        for(int j=0; j<12; j++){
            for(int y=1; y<D-1; y++){
                for(int x=1; x<D-1; x++){
                    pic[(D-2)*i + y - 1][(D-2)*j + x - 1] = tiles[image[i][j]].types[orientation[i][j]][y][x];
                }
            }
        }
    }

    // Calculating the solution
    vector<string> match(3);
    match[0] = "                  # ";
    match[1] = "#    ##    ##    ###";
    match[2] = " #  #  #  #  #  #   ";


    for(int rot=0; rot<8; rot++){
        set<pair<int, int>> withSolution;

        for(int i=0; i<94; i++){
            for(int j=0; j<77; j++){
                set<pair<int, int>> found;
                bool cond = true;

                for(int k=0; k<3 && cond; k++){
                    for(int l=0; l<match[k].length() && cond; l++){
                        if(match[k][l] == ' ') continue;

                        if(pic[i+k][j+l] == '#'){
                            found.insert({i+k, j+l});
                        }else{
                            cond = false;
                        }
                    }
                }

                if(cond){
                    for(auto it : found){
                        withSolution.insert(it);
                    }
                }
            }
        }

        int hashtags = 0;

        for(int i=0; i<96; i++){
            for(int j=0; j<96; j++){
                if(pic[i][j] == '#') hashtags++;
            }
        }

        if(withSolution.size() != 0){
            cout << hashtags-withSolution.size();
        }        

        vector<vector<char>> temp(96, vector<char>(96));

        if(rot == 3){
            for(int i=0; i<96; i++){
                for(int j=0; j<96; j++){
                    temp[i][j] = pic[j][i];
                }
            }
        }else{
            for(int i=0; i<96; i++){
                for(int j=0; j<96; j++){
                    temp[i][j] = pic[96-j-1][i];
                }
            }
        }
        
        pic = temp;
    }


    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}