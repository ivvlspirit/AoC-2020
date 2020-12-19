#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;

ll evaluate(string expression){
    ll res = 1;

    int last = -1;
    int op = 2; // 1 - addition, 2 - multiplication

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

            if(op==1){
                res += val;
            }
            if(op==2){
                res *= val;
            }

            i=j;

            if(expression[i] == '+') op = 1;
            if(expression[i] == '*') op = 2;

            last = i;

        }else if(i == expression.length() || expression[i] == '+' || expression[i] == '*'){
            if(expression[i-1] != ')'){
                val = atoll(expression.substr(last+1, i-last-1).c_str());

                if(op == 1){
                    res += val;
                }
                if(op == 2){
                    res *= val;
                }

            }

            if(expression[i] == '+') op = 1;
            if(expression[i] == '*') op = 2;

            last = i;
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