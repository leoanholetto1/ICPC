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

const int MAXN = 2*1e6;

int a, b, c;
ll intgrl(ll x) {
    return 2*a*x*x*x + 3*b*x*x + 6*x*c;
}

ll defint(ll l, ll r) {
    return llabs(intgrl(r)-intgrl(l));
}

bool hasRoot() {
    return (b*b - 4*a*c) >= 0;
}

pair<ll, ll> roots() {
    return {llround((-b - sqrt(b*b - 4*a*c))/(2*a)), llround((-b + sqrt(b*b - 4*a*c))/(2*a))};
}

void solve(){
    int t;
    cin >> t;
    while(t--) {
        int l, r;
        cin >> a>>b>>c>>l>>r;
        ll num = 0;//llabs(integral(r)-integral(l));
        if(hasRoot()) {
            auto rts = roots();
            if(l <=rts.first){
                if(r<=rts.first) num =  defint(l,r);
                else if(r<=rts.second) num = defint(l,rts.first) + defint(rts.first,r);
                else num = defint(l,rts.first) + defint(rts.first,rts.second) + defint(rts.second,r);
            }
            else if(l<=rts.second){
                if(r<=rts.second) num =  defint(l,r);
                else num =  defint(l,rts.second) + defint(rts.second,r);
            }
            else num =  defint(l,r);
        }
        else num = defint(l, r);

        ll d = __gcd(num, 6LL);
        printf("%lld/%lld\n", num/d, 6/d);
    }
}

int main(){
    IOS
    solve();
    return 0;
}