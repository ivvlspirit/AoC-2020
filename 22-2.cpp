#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;

// This is very very slow, probably because of all the unnecessary string manipulation

bool playGame(list<int> &p, list<int> &c){
    set<pair<string, string>> played;

    string ps="", cs="";
    for(auto pi : p){
        ps += to_string(pi);
    }

    for(auto ci : c){
        cs += to_string(ci);
    }

    int pn = p.size(), cn = c.size();

    while(!p.empty() && !c.empty()){
        pair<string, string> temp = {ps, cs};
        if(played.count(temp)){
            return false;
        } 

        int pi = p.back();
        int ci = c.back();

        p.pop_back();
        c.pop_back();

        bool cWon;

        if(pn > pi && cn > ci){
            list<int> pNew=p, cNew=c;
            
            for(int i=0; i<pn-pi-1; i++){
                pNew.pop_front();
            }
            for(int i=0; i<cn-ci-1; i++){
                cNew.pop_front();
            }
            

            cWon = playGame(pNew, cNew);
        }else{
            if(pi > ci){
                cWon = false;
            }else{
                cWon = true;
            }
        }

        played.insert({ps, cs});

        if(cWon){
            c.push_front(ci);
            c.push_front(pi);

            string pis = to_string(pi), cis = to_string(ci);

            cs = pis + cis + cs.substr(0, cs.length()-cis.length());
            cn++;
            pn--;

            ps = ps.substr(0, ps.length()-pis.length());
        }else{
            p.push_front(pi);
            p.push_front(ci);

            string pis = to_string(pi), cis = to_string(ci);

            ps = cis + pis + ps.substr(0, ps.length()-pis.length());
            pn++;
            cn--;

            cs = cs.substr(0, cs.length()-cis.length());
        }
        
    }

    if(p.empty()){
        return true;
    }else{
        return false;
    }
}

int main(){

    #ifdef DEBUG
        freopen("..\\input.txt", "r", stdin);
        clock_t tStart = clock();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    list<int> p, c;

    string s;
    getline(cin, s);
    getline(cin, s);

    while(s!=""){
        p.push_front(atoi(s.c_str()));
        getline(cin, s);
    }

    getline(cin, s);

    while(getline(cin, s)){
        c.push_front(atoi(s.c_str()));
    }

    bool cWon = playGame(p, c);

    ll res = 0;

    if(cWon){
        int i=1;
        while(!c.empty()){
            res += c.front()*i;
            i++;
            c.pop_front();
        }
    }else{
        int i=1;
        while(!p.empty()){
            res += p.front()*i;
            i++;
            p.pop_front();
        }
    }

    cout << res;


    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}