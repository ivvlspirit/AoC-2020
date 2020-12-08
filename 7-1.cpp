#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;

map<string, map<string, int>> bags;
map<string, bool> canHold;


bool search(string s){
    if(canHold.count(s)) return canHold[s];

    bool retVal = false;

    for(auto it : bags[s]){
        if(it.first == "shiny gold"){
            canHold[s] = true;
            return true;
        }else{
            bool temp = search(it.first);

            retVal |= temp;
        }
    }

    canHold[s] = retVal;
    return retVal;
}


int main(){

    #ifdef DEBUG
        freopen("..\\input.txt", "r", stdin);
        clock_t tStart = clock();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    

    string s;

    while(getline(cin, s)){
        string keyBag;
        string valueBags;

        int keyBagsInd = s.find("bags", 0) - 1;
        int valueBagsInd = s.find("contain") + 8;

        keyBag = s.substr(0, keyBagsInd);
        valueBags = s.substr(valueBagsInd, s.length()-valueBagsInd);

        int comma = -1;

        if(valueBags != "no other bags."){
            string value;

            for(int i=0; i<valueBags.length(); i++){
                if(valueBags[i] == ',' || valueBags[i] == '.'){
                    value = valueBags.substr(comma+1, i-comma-1);

                    int numInd = value.find(" ", 0);

                    int num = atoi(value.substr(0, numInd).c_str());

                    int offset = 0;
                    if(num == 1) offset = 1;
                    string bag = value.substr(numInd+1, value.length()-numInd-6+offset);

                    bags[keyBag][bag] = num;

                    comma = i+1;
                }
            }
        }
    }

    int res = 0;

    for(auto it : bags){
        search(it.first);
    }

    for(auto it : canHold){
        if(it.second) res++;
    }

    cout << res;

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}