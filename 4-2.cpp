#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;

bool validate(string s){
    string key = s.substr(0, 3);
    string value = s.substr(4);

    if(key == "byr"){
        if(value.length() != 4) return false;

        int year = atoi(value.c_str());
        return (year >= 1920 && year <= 2002);

    }else if(key == "iyr"){
        if(value.length() != 4) return false;

        int year = atoi(value.c_str());
        return (year >= 2010 && year <= 2020);

    }else if(key == "eyr"){
        if(value.length() != 4) return false;

        int year = atoi(value.c_str());
        return (year >= 2020 && year <= 2030);

    }else if(key == "hgt"){
        if(value.length() < 3) return false;

        string unit = value.substr(value.length()-2);
        int height = atoi(value.substr(0, value.length()-2).c_str());
        if(unit == "cm"){
            return (height >= 150 && height <= 193);
        }else if(unit == "in"){
            return (height >= 59 && height <= 76);
        }else{
            return false;
        }

    }else if(key == "hcl"){
        bool cond = true;

        if(value.length() != 7) return false;

        cond &= (value[0] == '#');

        for(int i=1; i<7; i++){
            cond &= ((value[i] >= 'a' && value[i] <= 'f') || (value[i] >= '0' && value[i] <= '9'));
        }

        return cond;

    }else if(key == "ecl"){
        return (value == "amb" || value == "blu" || value == "brn" || value == "gry" || value == "grn" || value == "hzl" || value == "oth");

    }else if(key == "pid"){
        if(value.length() != 9) return false;

        bool cond = true;

        for(int i=0; i<9; i++){
            cond &= (value[i] >= '0' && value[i] <= '9');
        }

        return cond;

    }else if(key == "cid"){
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

    int res = 0;
    int pi = 0;

    vector<set<string>> pass(1000);
    string s;

    while(getline(cin, s)){
        if(s == ""){
            if(pass[pi].size() == 8 || (pass[pi].size() == 7 && pass[pi].count("cid") == 0)) res++;
            
            pi++;
        }else{
            int last = 0;

            for(int i=0; i<s.length()+1; i++){
                if(i==s.length() || s[i] == ' '){
                    if(validate(s.substr(last, i-last))) pass[pi].insert(s.substr(last, 3));

                    last = i+1;
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