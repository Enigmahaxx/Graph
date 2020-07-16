#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<bool> visited;
vector<int> tin, low;
int timer;
ll ans=0;
set<ll>st;
vector<ll>adj[10005];
void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
            {
                st.insert(v);
            }
            ++children;
        }
    }
    if(p == -1 && children > 1)
    {
        st.insert(v);
    }
}

void find_cutpoints(ll n) {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(1){
        ll n,m;
        cin>>n>>m;
        if(n==0 && m==0){
            break;
        }
        for(ll i=0;i<=10002;i++){
            adj[i].clear();
        }
        for(ll i=0;i<m;i++){
            ll x,y;
            cin>>x>>y;
            x--;
            y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        ans=0;
        st.clear();
        find_cutpoints(n);
        cout<<st.size()<<endl;

    }

    return 0;
}