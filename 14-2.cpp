#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;

vector<int> maskInds;
map<unsigned ll, unsigned ll> memory;

void addToMemory(unsigned ll addr, int n, unsigned ll val){
    if(n==(int)maskInds.size()){
        memory[addr] = val;
        return;
    }

    int ind = maskInds[n];

    unsigned ll oneMask = 1, zeroMask = 0;

    oneMask = oneMask << ind;
    zeroMask = ~oneMask;
    
    addToMemory(addr | oneMask, n+1, val);
    addToMemory(addr & zeroMask, n+1, val);
    
    return;
}

int main(){

    #ifdef DEBUG
        freopen("..\\input.txt", "r", stdin);
        clock_t tStart = clock();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    unsigned ll oneMask = 0;

    while(getline(cin, s)){
        // really lazy way to check if the first word is "mask"
        if(s[1] == 'a'){
            string mask = s.substr(7);
            maskInds.clear();
            oneMask = 0;
            
            for(int i=0; i<36; i++){
                if(mask[i] == 'X'){
                    maskInds.push_back(35-i);
                }
                if(mask[i] == '1'){
                    oneMask |= (1ULL<<(35-i));
                }
            }
        }else{
            int rightBracket = s.find("]");
            int equalSign = s.find("=");

            unsigned ll addr = atoi(s.substr(4, rightBracket-4).c_str());
            unsigned ll val = atoll(s.substr(equalSign+2).c_str());

            addToMemory(addr | oneMask, 0, val);
        }
    }

    ll sum = 0;

    for(auto it : memory){
        sum += it.second;
    }

    cout << sum;

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}