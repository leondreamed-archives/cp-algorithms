#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500000;

vector<int> adj[MAXN];
int n, k, start = -1, tgt = -1;
int indeg[MAXN], outdeg[MAXN], ans[250000];

bool is_invalid(){
    for(int i = 0; i < MAXN; ++i){
        if(indeg[i] == outdeg[i]) continue;
        if(indeg[i] == outdeg[i] + 1){
            if(tgt != -1) return true;
            tgt = i;
        }
        if(indeg[i] + 1 == outdeg[i]){
            if(start != -1) return true;
            start = i;
        }
    }
    if(tgt == -1 && start != -1) return true;
    if(tgt != -1 && start == -1) return true;
    return false;
}

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> k;

    for(int i = 0; i < n; ++i){
        string s; cin >> s;
        if(k == 1) cout << s;
        int fr = 0, ba = 0;
        for(int a = 0; a + 1 < k; ++a) fr = fr * 26 + (s[a] - 'a');
        for(int a = 1; a < k; ++a) ba = ba * 26 + (s[a] - 'a');
        adj[fr].push_back(ba);
        ++outdeg[fr]; ++indeg[ba];
    }

    if(k == 1){
        cout << "\n";
        return 0;
    }

    if(is_invalid()){
        cout << "-1\n";
        return 0;
    }

    vector<int> path, curpath = {start};
    int nx, cur = start;
    while(!curpath.empty()){
        if(outdeg[cur] > 0){
            --outdeg[cur];
            curpath.push_back(cur);
            nx = adj[cur].back();
            adj[cur].pop_back();
            cur = nx;
        } else {
            path.push_back(cur);
            cur = curpath.back();
            curpath.pop_back();
        }
    }
    
    int pos = 0;
    for(auto i : path){
        for(int a = 1; a < k; ++a, i /= 26)
            ans[pos + a - 1] = 'a' + i % 26;
        ++pos;
    }

    for(int i = n + k - 2; i >= 0; --i)
        cout << (char) ans[i];

    cout << "\n";

    return 0;
}