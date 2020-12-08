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

    vector<string> commandsOriginal;
    string s;

    while(getline(cin, s)){
        commandsOriginal.push_back(s);
    }

    int n = commandsOriginal.size();


    for(int i=0; i<n; i++){
        if(commandsOriginal[i] == "acc") continue;

        bool gotInALoop = false;

        int sp = 0;
        int acc = 0;

        vector<string> commands = commandsOriginal;

        if(i==0){
            for(auto it : commands){
                cout << it << endl;
            }
        }

        vector<bool> used(n, false);

        if(commands[i].substr(0, 3) == "jmp"){
            commands[i].replace(0, 3, "nop");
        }else if(commands[i].substr(0, 3) == "nop"){
            commands[i].replace(0, 3, "jmp");
        }else{
            cout << "Error parsing commands!\n";
        }
        

        while(sp >= 0 && sp < n && !used[sp]){
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
                cout << "Error in while loop!\n";
            }

            if(sp >= 0 && sp < n && used[sp]) gotInALoop = true;
        }

        if(!gotInALoop){
            cout << acc;

            break;
        }
    }


    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}