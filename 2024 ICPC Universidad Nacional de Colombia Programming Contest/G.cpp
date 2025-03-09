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

const int maxN= 1e6+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll mod = 1e9+6;
const ld PI = acos(-1.0);
const double eps = 1e-9;
const double DINF = 1e9;

//+11
// \ | /


pair<ld,ld>  reta(pair<ld,ld>  a,pair<ld,ld>  b){
	pair<ld,ld>  p;
	p.f = (b.s - a.s) / (b.f-a.f);
	p.s = b.s - p.f*b.f;
	return p;
}

ld calc(pair<ld,ld>  p,ld x1,ld x2){
	return (p.f*x2*x2/2.0+p.s*x2)-(p.f*x1*x1/2.0+p.s*x1);
}

double func(pair<double,double> p,double x1){
	return p.f*x1 + p.s;
}

void solve() {
    int n,m,k;
    cin>>n>>m;
    vt<pair<ld,ld> > v(n);
    deque<pair<ld,ld> > dq;
    for(int i=0;i<n;i++){
    	cin>>k;
    	v[i].f = k;
    }
    for(int i=0;i<n;i++){
    	cin>>k;
    	v[i].s = k;
    	dq.pb({v[i].f,v[i].s});
    }
    ld area=0.0,areaAt;
    for(int i=0;i<n-1;i++){
    	pair<ld,ld>  p = reta(v[i],v[i+1]);
    	area+=calc(p,v[i].f,v[i+1].f);
    }
    area/=m;
    areaAt = area;
    for(int i=0;i<m-1;){
    	pair<ld,ld>  p1 = dq.front();
    	dq.pop_front();
    	pair<ld,ld>  p2 = dq.front();
    	dq.pop_front();
    	pair<ld,ld>  p = reta(p1,p2);
    	if(calc(p,p1.f,p2.f)>=areaAt or fabs(calc(p,p1.f,p2.s)-areaAt)<1e-9){
    		ld ini=0,fim=p2.f-p1.f,m=-1,ponto=INF;
    		int t=100;
    		while(t--){
    			m = (ini+fim)/2.0;
    			if(calc(p,p1.f,m+p1.f)>=areaAt or fabs(calc(p,p1.f,m+p1.f)-areaAt)<1e-9){
    				ponto = m;
    				fim = m;
    			}
    			else ini = m;
    		}
    		cout << fixed << setprecision(12) << ponto + p1.f <<" ";
    		if(fabs(p2.f - (p1.f+ponto))>1e-9){
    			dq.push_front(p2);
    			dq.push_front({ponto + p1.f,func(p,ponto + p1.f)});
    		}
    		i++;
    		areaAt = area;
    	}
    	else{
    		dq.push_front(p2);
    		areaAt-=calc(p,p1.f,p2.f);
    	}
    }
    cout << endl;
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
