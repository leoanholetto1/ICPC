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

long long conta(long long num) {
    if(num == 1 or num==0) return 0;
    long long total = 1;
    ll n= num;
    for (int i = 2; (long long)i * i <= num; i++) {
        if (num % i == 0) {
            int e = 0;
            do {
                e++;
                num /= i;
            } while (num % i == 0);

            long long sum = 0, pow = 1;
            do {
                sum += pow;
                pow *= i;
            } while (e-- > 0);
            total *= sum;
        }
    }
    if (num > 1) {
        total *= (1 + num);
    }
    return total-n;
}

void solve(){
    ll n,t;
    cin>>t;
    while(t--){
        cin>>n;
        ll ans = conta(n);
        if(ans == n) cout << n << " perfecto" << endl;
        else{
            ll ans2 = conta(ans);
            if(ans2 == n){
                if(ans > n) cout << n <<" romantico abundante" << endl;
                else cout << n << " romantico" << endl;
            }
            else if(ans > n) cout << n <<" abundante" << endl;
            else cout << n <<" complicado" << endl;
        }
    }
}

int main(){
    IOS
    solve();
    return 0;
}