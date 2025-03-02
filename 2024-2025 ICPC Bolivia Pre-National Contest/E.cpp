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

void solve(){
    int n;
    cin>>n;
    vi v;
    for(int i=2;i<=n;i++){
        while(n%i==0){
            v.pb(i);
            n/=i;
        }
    }
    for(int i=0;i<v.sz;i++){
        if(i!=0) cout <<"x";
        cout << v[i];
    }
    cout << endl;
}

int main(){
    IOS
    solve();
    return 0;
}