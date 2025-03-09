#include<bits/stdc++.h>
//#pragma GCC target("popcnt")
//#include <boost/multiprecision/cpp_int.hpp>
//#include <bits/extc++.h>      
//#include <ext/pb_ds/assoc_container.hpp>

                
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define vt vector
#define all(x) x.begin(),x.end()
#define unico(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin());
#define s second
#define f first
#define lc ((n)<<1)
#define rc ((n)<<1|1)
#define pb push_back
#define sz size()
#define isPowerOfTwo(S) (!(S & (S-1)))
#define LSOne(S) ((S)&-(S))
#define Log2(x) (31^__builtin_clz(x))
#define LLog2(x) (63 ^ __builtin_clzll(x))
#define mem(x,y) memset(x,y,sizeof(x))

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

//typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> pds; 
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> ost;//repetido
//gp_hash_table<int, int> sMap;  
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,ll> pil;
using cd = complex<double>;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int dxx[] = {-1,-1,0,1,1,1,0,-1};
int dyy[] = {0,1,1,1,0,-1,-1,-1};

vt<pii> mov = {
	{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
	{1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

const int maxN= 1e5+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll mod = 1e9+7;
const ld PI = acos(-1.0);
const double eps = 1e-9;
const double DINF = 1e9;

//+23
// \ | /
vi adj[maxN], start(maxN), ende(maxN);
long long val[maxN];
int timer = 1;
int n,q,a,b;
string e;
 
void euler_tour(int at, int prev) {
	start[at] = timer++;
	for (int n : adj[at]) {
		if (n != prev) { euler_tour(n, at); }
	}
	ende[at] = timer;
}

struct Node{
	ll prod=1;
	ll dois=0,tres=0,cinco=0,sete=0,onze=0,treze=0;
};

class  Seg{
private:
	vt<Node> tree;
public:
	Seg(int n){
		tree.resize(4*n);
	}

	Node merge(Node e,Node d){
		Node novo;
		novo.prod = e.prod * d.prod;
		novo.prod%=mod;
		novo.dois = e.dois+d.dois;
		novo.tres = e.tres+d.tres;
		novo.cinco =e.cinco+d.cinco;
		novo.sete = e.sete+d.sete;
		novo.onze = e.onze+d.onze;
		novo.treze = e.treze+d.treze;
		return novo;
	}

	//Complexidade: O(log n)
	void update(int pos,int ini,int fim,int id,ll val){
		if(id<ini || id>fim) return ;
		if(ini==fim){
			tree[pos].prod *= val;
			tree[pos].prod%=mod;
			while(val%2==0){tree[pos].dois++;val/=2;}
			while(val%3==0){tree[pos].tres++;val/=3;}
			while(val%5==0){tree[pos].cinco++;val/=5;}
			while(val%7==0){tree[pos].sete++;val/=7;}
			while(val%11==0){tree[pos].onze++;val/=11;}
			while(val%13==0){tree[pos].treze++;val/=13;}
			return ;
		}
		int m = (ini+fim)/2;
		int e = 2*pos, d = 2*pos +1;
		update(e,ini,m,id,val);
		update(d,m+1,fim,id,val);
		tree[pos] = merge(tree[e],tree[d]);
	}
	//Complexidade: O(log n)
	Node queryMin(int pos,int ini,int fim,int a,int b){
		if(b<ini || a>fim) return {1,0,0,0,0,0,0};
		if(a<=ini && fim<=b) return tree[pos];
		int m = (ini+fim)/2;
		int e = 2*pos, d = 2*pos+1;
		return merge(queryMin(e,ini,m,a,b), queryMin(d,m+1,fim,a,b));
	}
};
 
void solve(){
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>a>>b;
		a++,b++;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	euler_tour(1,0);
	for(int i=1;i<=n;i++){
		cin>>val[i];
	}
	Seg seg(timer);
	for(int i=1;i<=n;i++){
		seg.update(1,1,timer,start[i],val[i]);
	}
	cin>>q;
	while(q--){
		cin>>e;
		if(e=="RAND"){
			cin>>a;
			a++;
			Node ans = seg.queryMin(1,1,timer,start[a],ende[a]-1);
			ll div = 1;
			div*=(ans.dois+1);
			div%=mod;
			div*=(ans.tres+1);
			div%=mod;
			div*=(ans.cinco+1);
			div%=mod;
			div*=(ans.sete+1);
			div%=mod;
			div*=(ans.onze+1);
			div%=mod;
			div*=(ans.treze+1);
			div%=mod;
			cout << ans.prod << " " << div << endl;
		}
		else{
			cin>>a>>b;
			a++;
			seg.update(1,1,timer,start[a],b);
		}	
	}
}	

void abrir(){
	string str = "";
	if(!str.empty()){
		freopen((str+".in").c_str(), "r", stdin);
		freopen((str+".out").c_str(), "w", stdout);
	}
}


int main() {
	IOS
	#ifdef local
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	abrir();
	//clock_t tStart = clock();
	solve();
	//cerr<<fixed<<setprecision(10) << "\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl; 
	return 0;
}
