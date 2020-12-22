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

    while(!p.empty() && !c.empty()){
        int pi = p.back();
        int ci = c.back();

        p.pop_back();
        c.pop_back();

        if(pi > ci){
            p.push_front(pi);
            p.push_front(ci);
        }else{
            c.push_front(ci);
            c.push_front(pi);
        }
    }

    ll res = 0;

    if(p.empty()){
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