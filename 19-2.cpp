#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;

struct transition
{
    string tr;
    vector<int> o[2];
};

map<int, transition> data;

// This solution took around 1.25 seconds to calculate on my not-so-great laptop, but I simply
// couldn't fix the bug when using the list as a global variable... I'm gonna go to sleep now

bool evaluate(string s, list<int> seq){
    if(seq.size() == 0) return false;
    if(seq.size() > s.length()) return false;

    bool res = false;

    int f = seq.front();

    seq.pop_front();

    if(data[f].tr != ""){
        if(s.substr(0, 1) == data[f].tr){
            if(s.length() == 1 && seq.empty()) return true;
            if(evaluate(s.substr(1), seq)) return true;

        }else{
            return false;
        }

    }else{
        int add = 0;
        for(auto it = data[f].o[0].rbegin(); it != data[f].o[0].rend(); it++){
            seq.push_front(*it);
            add++;
        }

        if(evaluate(s, seq)) return true;

        if(data[f].o[1].size()!=0){
            for(int i=0; i<add; i++) seq.pop_front();

            for(auto it = data[f].o[1].rbegin(); it != data[f].o[1].rend(); it++){
                seq.push_front(*it);
            }

            if(evaluate(s, seq)) return true;
        }
    }

    return false;
}

int main(){

    #ifdef DEBUG
        freopen("..\\input.txt", "r", stdin);
        clock_t tStart = clock();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    getline(cin, s);

    while(s!=""){
        int space = s.find(" ");

        int key = atoi(s.substr(0, space-1).c_str());

        int ind = 0;

        int qts = s.find("\"");
        if(qts != s.npos){
            data[key].tr = s.substr(qts+1, s.length()-qts-2);
        }else{
            data[key].tr = "";

            for(int i=space+1; i<s.length()+1; i++){
                if(s[i] == '|'){
                    ind++;
                    i++;
                    space = i;
                }else if(i==s.length() || s[i] == ' '){
                    data[key].o[ind].push_back(atoi(s.substr(space+1, i-space).c_str()));
                    space = i;
                }
            }
        }

        getline(cin, s);
    }

    int res = 0;
    
    while(getline(cin, s)){
        list<int> seq;

        for(auto it : data[0].o[0]){
            seq.push_back(it);
        }

        if(evaluate(s, seq)){
            res++;
        }
    }

    cout << res;

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}