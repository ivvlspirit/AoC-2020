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

    int datalines = 20;
    int tickets = 243;

    map<string, pair<pair<int, int>, pair<int, int>>> values;

    vector<int> myTicket;
    
    string s;

    for(int dataline=0; dataline<datalines; dataline++){
        getline(cin, s);

        string key = s.substr(0, s.find(":"));

        s = s.substr(s.find(": ")+2);

        int l1 = atoi(s.substr(0, s.find("-")).c_str());
        s = s.substr(s.find("-")+1);
        int r1 = atoi(s.substr(0, s.find(" ")).c_str());

        s = s.substr(s.find("or")+3);

        int l2 = atoi(s.substr(0, s.find("-")).c_str());
        s = s.substr(s.find("-")+1);
        int r2 = atoi(s.substr(0, s.find(" ")).c_str());


        values[key] = {{l1, r1}, {l2, r2}};
    }

    getline(cin, s);
    getline(cin, s);

    getline(cin, s);

    int comma = -1;
    for(int i=0; i<s.length()+1; i++){
        if(i==s.length() || s[i] == ','){
            myTicket.push_back(atoi(s.substr(comma+1, i-comma).c_str()));
            comma = i;
        }
    }

    getline(cin, s);
    getline(cin, s);

    vector<vector<int>> nearby;

    for(int ticket=0; ticket<tickets; ticket++){
        comma = -1;
        getline(cin, s);

        int val;

        vector<int> temp;
        bool cond = true;

        for(int i=0; i<s.length()+1; i++){
            if(i==s.length() || s[i] == ','){
                val = atoi(s.substr(comma+1, i-comma).c_str());

                temp.push_back(val);
                comma = i;

                bool cond2 = false;

                for(auto it : values){
                    if((it.second.first.first <= val && it.second.first.second >= val) || (it.second.second.first <= val && it.second.second.second >= val)){
                        cond2 = true;
                    }
                }

                if(!cond2) cond = false;
            }
        }

        if(cond){
            nearby.push_back(temp);
        }
    }

    map<string, vector<bool>> possible;

    for(auto it : values){
        vector<bool> temp(myTicket.size(), true);

        possible[it.first] = temp;
    }

    for(int i=0; i<myTicket.size(); i++){
        for(auto nb : nearby){
            for(auto vl : values){
                if(!((vl.second.first.first <= nb[i] && vl.second.first.second >= nb[i]) || (vl.second.second.first <= nb[i] && vl.second.second.second >= nb[i]))){
                    possible[vl.first][i] = false;
                }
            }
        }
    }
    

    for(int repeat=0; repeat<myTicket.size(); repeat++){
        for(auto it1 : possible){
            int ones = 0;
            int lastOne = 0;
            for(int i=0; i<myTicket.size(); i++){
                if(it1.second[i]){
                    ones++;
                    lastOne = i;
                }
            }

            if(ones == 1){
                for(auto &it2 : possible){
                    if(it2.first == it1.first) continue;

                    it2.second[lastOne] = false;
                }
            }
        }
    }

    vector<string> columns(myTicket.size());

    for(auto it : possible){
        for(int i=0; i<myTicket.size(); i++){
            if(it.second[i]){
                columns[i] = it.first;
            }
        }
    }

    ll res = 1;

    for(int i=0; i<myTicket.size(); i++){
        if(columns[i].length() > 9 && columns[i].substr(0, 9) == "departure"){
            res*=myTicket[i];
        }
    }

    cout << res;    


    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}