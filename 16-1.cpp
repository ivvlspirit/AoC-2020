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

    set<int> values;

    set<int> myTicket;
    string s;

    for(int dataline=0; dataline<datalines; dataline++){
        getline(cin, s);

        s = s.substr(s.find(": ")+2);

        int l = atoi(s.substr(0, s.find("-")).c_str());
        s = s.substr(s.find("-")+1);
        int r = atoi(s.substr(0, s.find(" ")).c_str());

        for(int i=l; i<=r; i++){
            values.insert(i);
        }

        s = s.substr(s.find("or")+3);

        l = atoi(s.substr(0, s.find("-")).c_str());
        s = s.substr(s.find("-")+1);
        r = atoi(s.substr(0, s.find(" ")).c_str());

        for(int i=l; i<=r; i++){
            values.insert(i);
        }
    }

    getline(cin, s);
    getline(cin, s);

    getline(cin, s);

    int comma = -1;
    for(int i=0; i<s.length()+1; i++){
        if(i==s.length() || s[i] == ','){
            myTicket.insert(atoi(s.substr(comma+1, i-comma).c_str()));
            comma = i;
        }
    }

    getline(cin, s);
    getline(cin, s);

    ll res = 0;

    for(int ticket=0; ticket<tickets; ticket++){
        comma = -1;
        getline(cin, s);

        int val;

        for(int i=0; i<s.length()+1; i++){
            if(i==s.length() || s[i] == ','){
                val = atoi(s.substr(comma+1, i-comma).c_str());
                comma = i;

                if(values.count(val) == 0){
                    res+=val;
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