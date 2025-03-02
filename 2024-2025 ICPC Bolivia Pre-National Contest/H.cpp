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
    string M;
    int h = 0, maxH = 0, idx = 0;

    cin >> M;
    for(int i = 0; i < M.size(); i++) {
        h += (M[i] == '+' ? 1 : -1);
        if(maxH < h) {
            maxH = h;
            idx = i;
        }
    }
    printf("%d\n", idx+1);
}

int main(){
    IOS
    solve();
    return 0;
}