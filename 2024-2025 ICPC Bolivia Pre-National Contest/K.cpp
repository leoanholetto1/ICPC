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
typedef pair<int,int> pii;

const int MAXN = 2*1e6;

char aux[1005][1005];

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

bool trap(int x,int y,int n,int m){
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0 or ny<0  or nx==n or ny==m) continue;
        if(aux[nx][ny]=='T') return 1;
    }
    return 0;
}

void dfs(int x,int y, int n, int m){
    vt<vt<bool>> vis(n,vt<bool>(m));
    queue<pii> q;
    if(trap(x,y,n,m)){
        cout << "0" << endl;
        return ;
    }
    q.push({x,y});
    vis[x][y]= 1;
    int sum=0;
    while(!q.empty()){
        x = q.front().f;
        y = q.front().s;q.pop();
        if(trap(x,y,n,m)){
            if(aux[x][y]>='0' && aux[x][y]<='9') sum+=aux[x][y]-'0';
            continue;
        }
        else{
            if(aux[x][y]>='0' && aux[x][y]<='9'){
                sum+=aux[x][y]-'0';
            }
        }
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 or ny<0  or nx==n or ny==m or aux[nx][ny]=='#' or vis[nx][ny]) continue;
            q.push({nx,ny});
            vis[nx][ny] = 1;
        }
    }
    cout << sum << endl;
}

void solve(){
    int n, m,x,y;
    int qtd;

    while(cin >> n >> m){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> aux[i][j];
                if(aux[i][j]=='S'){
                    x=i,y=j;
                }
            }
        }
        dfs(x,y,n,m);
    }
}

int main(){
    IOS
    solve();
    return 0;
}