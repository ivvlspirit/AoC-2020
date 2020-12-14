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

    string s;
    unsigned ll oneMask=0, zeroMask=1;

    map<int, unsigned ll> memory;

    while(getline(cin, s)){
        // really lazy way to check if the first word is "mask"
        if(s[1] == 'a'){
            string mask = s.substr(7);
            oneMask = 0;
            zeroMask = 1;

            for(int i=0; i<36; i++){
                if(mask[i] == '1'){
                    oneMask |= 1;
                    zeroMask |= 1;
                }
                if(mask[i] == 'X'){
                    zeroMask |= 1;
                }

                oneMask = oneMask<<1;
                zeroMask = zeroMask<<1;
            }

            oneMask = oneMask >> 1;
            zeroMask = zeroMask >> 1;
        }else{
            int rightBracket = s.find("]");
            int equalSign = s.find("=");

            int addr = atoi(s.substr(4, rightBracket-4).c_str());
            unsigned ll val = atoll(s.substr(equalSign+2).c_str());

            val |= oneMask;
            val &= zeroMask;

            memory[addr] = val;
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