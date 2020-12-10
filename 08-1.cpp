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

    vector<string> commands;
    string s;

    while(getline(cin, s)){
        commands.push_back(s);
    }

    int n = commands.size();

    vector<bool> used(n, false);

    int sp = 0;
    int acc = 0;

    while(!used[sp]){
        used[sp] = true;
        
        int space = commands[sp].find(" ");

        string command = commands[sp].substr(0, space);
        int argument = atoi(commands[sp].substr(space+1).c_str());

        if(command == "acc"){
            acc += argument;
            sp++;
        }else if(command == "jmp"){
            sp += argument;
        }else if(command == "nop"){
            sp++;
        }else{
            cout << "Error!\n";
        }
    }

    cout << acc;
    

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}