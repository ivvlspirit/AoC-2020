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

    // Map allergen -> possible ingredients
    map<string, set<string>> possibleIng;

    // Map ingredient -> possible allergens
    map<string, set<string>> possibleAll;

    vector<string> allAllergens;
    vector<string> allIngredients;
    
    while(getline(cin, s)){
        set<string> ingredients;
        set<string> allergens;

        int space = -1;

        string ingStr, allStr;
        ingStr = s.substr(0, s.find("("));
        allStr = s.substr(s.find("(")+9);

        for(int i=0; i<ingStr.length(); i++){
            if(ingStr[i] == ' '){
                string ing = ingStr.substr(space+1, i-space-1);

                allIngredients.push_back(ing);
                ingredients.insert(ing);
                space = i;
            }
        }

        space = 0;

        for(int i=0; i<allStr.length(); i++){
            if(allStr[i] == ' ') space = i;

            if(allStr[i] == ',' || allStr[i] == ')'){
                string all = allStr.substr(space+1, i-space-1);

                allAllergens.push_back(all);
                allergens.insert(all);
            }
        }

        for(auto all : allergens){
            if(possibleIng[all].size() == 0){
                for(auto ing : ingredients){
                    possibleIng[all].insert(ing);
                }
            }else{
                set<string> removeSet;

                for(auto posIng : possibleIng[all]){
                    if(ingredients.count(posIng) == 0){
                        removeSet.insert(posIng);
                    }
                }

                for(auto rem : removeSet){
                    possibleIng[all].erase(rem);
                }
            }
        }
    }

    for(auto entry : possibleIng){
        for(auto ing : entry.second){
            possibleAll[ing].insert(entry.first);
        }
    }

    set<string> allPossibleIng;

    for(auto entry : possibleIng){
        for(auto ing : entry.second){
            allPossibleIng.insert(ing);
        }
    }

    int res = 0;

    for(auto ing : allIngredients){
        if(allPossibleIng.count(ing) == 0){
            res++;
        }
    }

    cout << res;


    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}