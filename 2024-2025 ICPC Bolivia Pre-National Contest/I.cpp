#include<bits/stdc++.h>

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) x.begin(), x.end()
#define s second
#define f first 
#define pb push_back
#define sz size()
#define vt vector 
#define turnOffLastBit(S) ((S) & (S-1))

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int MAXN = 1e5+5;
const ll mod = 1e9+7;
vi adj[MAXN];
vt<bool> vis(MAXN);
ll c;

void dfs(int u){
    vis[u] = 1;
    c++;
    for(auto v: adj[u]){
        if(vis[v]) continue;
        dfs(v);
    }
}

void solve(){
    int n,m,a,b;
    ll ans=1;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            c=0;
            dfs(i);
            ans*=c;
            ans%=mod;
        }
    }
    cout << ans << endl;
}

int main(){
    IOS
    solve();
    return 0;
}