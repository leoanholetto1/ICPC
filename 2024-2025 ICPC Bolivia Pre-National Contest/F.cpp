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


void solve(){
    ll n,t;

    cin>>t;
    while(t--){
        cin >> n;
        vt<int> v;
        vt<int> h;
        int aux;

        for(int j=0;j<n;j++){
            cin >> aux;
            v.pb(aux);
        }
        for(int j=0;j<n-1;j++){
            cin >> aux;
            h.pb(aux);
        }
        
        bool flag=1; bool flag2=1;
        priority_queue<pii,vt<pii>,greater<pii>> pq,pq2;
        vt<ll> sum = {0},sum2={0};
        for(int i=0;i<n-1;i++){
            sum.pb(sum.back()+h[i]);
        }
        for(int i=n-2;i>=0;i--){
            sum2.pb(sum2.back()+h[i]);
        }
        pq.push({v[0],0});
        for(int i=1;i<n;i++){
            while(!pq.empty() && pq.top().f <= sum[i] - sum[pq.top().s]){
                pq.pop();
            }
            if(pq.empty()){
                flag = 0;
                break;
            }
            pq.push({v[i],i});
        }
        pq2.push({v[n-1],0});
        for(int i=n-2,j=1;i>=0;i--,j++){
            while(!pq2.empty() && pq2.top().f <= sum2[j] - sum2[pq2.top().s]){
                pq2.pop();
            }
            if(pq2.empty()){
                flag2 = 0;
                break;
            }
            pq2.push({v[i],j});
        }
        if(flag or flag2)
            cout << "habibi" << endl;
        else
            cout << "which" << endl;
    }
    
}

int main(){
    IOS
    solve();
    return 0;
}