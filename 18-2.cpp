#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;

ll evaluate(string expression){

    vector<ll> parts; // -1 - addition, -2 - multiplication

    int last = -1;

    ll val;

    for(int i=0; i<expression.length()+1; i++){

        if(expression[i] == '('){
            int par = 1;
            int j = i+1;

            for(; par !=0; j++){
                if(expression[j] == '(') par++;
                if(expression[j] == ')') par--;
            }

            string newExpression = expression.substr(i+1, j-i-2);
            val = evaluate(newExpression);

            parts.push_back(val);

            i=j;

            if(expression[i] == '+') parts.push_back(-1);
            if(expression[i] == '*') parts.push_back(-2);

            last = i;

        }else if(i == expression.length() || expression[i] == '+' || expression[i] == '*'){
            if(expression[i-1] != ')'){
                val = atoll(expression.substr(last+1, i-last-1).c_str());

                parts.push_back(val);
            }

            if(expression[i] == '+') parts.push_back(-1);
            if(expression[i] == '*') parts.push_back(-2);

            last = i;
        }

    }

    ll res = 1;
    ll temp = 0;

    for(int i=1; i<parts.size()+2; i+=2){
        temp += parts[i-1];

        if(i >= parts.size() || parts[i] == -2){
            res *= temp;
            temp = 0;
        }
    }

    return res;
    
}

int main(){

    #ifdef DEBUG
        freopen("..\\input.txt", "r", stdin);
        clock_t tStart = clock();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    ll res = 0;

    while(getline(cin, s)){
        string expression = "";

        for(int i=0; i<s.length(); i++){
            if(s[i] != ' ') expression+=s[i];
        }

        res += evaluate(expression);
    }

    cout << res;



    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}