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

    double x=0.0f, y=0.0f;
    double xw=10.0f, yw=1.0f;
    double r, phi;

    string s;
    while(getline(cin, s)){
        char comm = s[0];
        double arg = atof(s.substr(1).c_str());
        r=sqrt(xw*xw+yw*yw);
        phi=atan2(yw, xw);

        switch(comm){
            case 'E':
                xw+=arg;
                break;
            case 'N':
                yw+=arg;
                break;
            case 'W':
                xw-=arg;
                break;
            case 'S':
                yw-=arg;
                break;
            case 'L':
                phi+=arg*DEG2RAD;
                xw = r*cos(phi);
                yw = r*sin(phi);
                
                break;
            case 'R':
                phi-=arg*DEG2RAD;
                xw = r*cos(phi);
                yw = r*sin(phi);
                
                break;
            case 'F':
                x+=xw*arg;
                y+=yw*arg;
                break;
        }
    }

    cout << abs(x)+abs(y);


    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}