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
    int q,n,k;
    cin>>q;
    while(q--){
        cin>>n;
        vi v;
        int mx=0;
        for(int i=0;i<n;i++){
            cin>>k;
            v.pb(k);
            mx = max(mx,k);
        }
        ll ans = (1LL<<mx)-1;
        ll sum=0;
        for(int i=mx-1;i>0;i--)
        {
            if(find(all(v),i)==v.end()){
                sum+=1LL<<(i-1);
            }
        }
        cout << ans-sum << endl;
    }

}

int main(){
    IOS
    solve();
    return 0;
}