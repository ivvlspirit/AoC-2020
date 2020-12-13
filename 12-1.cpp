#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;
const double DEG2RAD = 0.017453292;

int main(){

    #ifdef DEBUG
        freopen("..\\input.txt", "r", stdin);
        clock_t tStart = clock();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double phi = 0.0f, x=0.0f, y=0.0f;

    string s;
    while(getline(cin, s)){
        char comm = s[0];
        double arg = atof(s.substr(1).c_str());

        switch(comm){
            case 'E':
                x+=arg;
                break;
            case 'N':
                y+=arg;
                break;
            case 'W':
                x-=arg;
                break;
            case 'S':
                y-=arg;
                break;
            case 'L':
                phi+=arg;
                break;
            case 'R':
                phi-=arg;
                break;
            case 'F':
                x+=arg*cos(phi * DEG2RAD);
                y+=arg*sin(phi * DEG2RAD);
                break;
        }

    }

    cout << abs(x)+abs(y);


    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}