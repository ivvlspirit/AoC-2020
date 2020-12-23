#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MOD = 1e9+7;

struct cup{
    int val;
    int next;
};

int main(){

    #ifdef DEBUG
        freopen("..\\input.txt", "r", stdin);
        clock_t tStart = clock();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    cin >> input;

    int n = 1000000;

    vector<int> place(n+1);
    vector<cup> circle(n);

    for(int i=0; i<n; i++){
        if(i<input.length()){
            circle[i].val = input[i]-'0';
            place[input[i]-'0'] = i;
        }else{
            circle[i].val = i+1;
            place[i+1] = i;
        }
        
        circle[i].next = (i+1)%n;
    }

    int cur = 0; 
    int numOfRepetitions = 10000000;

    for(int rep=0; rep<numOfRepetitions; rep++){
        set<int> nextThreeVal;
        vector<int> nextThreePos;

        int temp = cur;
        for(int i=0; i<3; i++){
            temp = circle[temp].next;
            nextThreeVal.insert(circle[temp].val);
            nextThreePos.push_back(temp);
        }

        circle[cur].next = circle[temp].next;

        temp = circle[cur].val - 1;
        if(temp == 0) temp = n;

        while(nextThreeVal.count(temp)){
            temp--;
            if(temp==0) temp = n;
        }

        circle[nextThreePos[2]].next = circle[place[temp]].next;
        circle[place[temp]].next = nextThreePos[0];
        
        int cnt = 0;
        for(int i=0; i<n; i++){
            cnt = circle[cnt].next;
        }

        cur = circle[cur].next; 
    }


    int start = 0;

    while(circle[start].val != 1){
        start = circle[start].next;
    }

    ll res = 1;

    for(int i=0; i<2; i++){
        start = circle[start].next;
        res*= (ll) circle[start].val;
    }

    cout << res;


    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}