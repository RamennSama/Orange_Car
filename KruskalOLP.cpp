#include <bits/stdc++.h>
using namespace std;
 
// _____ ____   ___  __  __    __     ___   _ _   _    __        _____ _____ _   _ 
//|  ___|  _ \ / _ \|  \/  |   \ \   / / | | | | | |   \ \      / /_ _|_   _| | | |
//| |_  | |_) | | | | |\/| |    \ \ / /| |_| | | | |    \ \ /\ / / | |  | | | |_| |
//|  _| |  _ <| |_| | |  | |     \ V / |  _  | |_| |     \ V  V /  | |  | | |  _  |
//|_|   |_|_\_\\___/|_|__|_|      \_/  |_| |_|\___/       \_/\_/  |___| |_| |_| |_|
// _     _____     _______ 
//| |   / _ \ \   / / ____|
//| |  | | | \ \ / /|  _|  
//| |__| |_| |\ V / | |___ 
//|_____\___/  \_/  |_____| 


typedef long long ll;
typedef double db;
typedef pair<int, int> ii;
typedef pair<ll, int> lli;
typedef unsigned long long ull;
typedef unsigned long long int ulli;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<vector<ii>> vpi;
#define fi first
#define se second
#define pb push_back
#define ed cout << "\n"
#define no cout << "NO\n"
#define ye cout << "YES\n"
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)
#define FOB(i, l, r) for (int i = l; i < r; i++)
#define mem(a, b) memset(a, b, sizeof(a))
#define all(a) a.begin(), a.end()
#define sz(A) (int)A.size()
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
const int N = 5e5 + 15;
const int MOD = 1e9 + 7;

int par[1001] = {};
int sz[1001] = {};
int n, m;
struct edge{
	int x, y, w;
	bool operator < (edge const& a){
		return w < a.w;
		}
};

struct cmp{
	bool operator () (edge a, edge b){
		return a.w < b.w;
	}
};
vector<edge>E;

void make(){
	FOR(i, 1, n){
		par[i] = i;
		sz[i] = 1;
	}
}

int find(int u){
	if(u == par[u]) return u;
	return par[u] = find(par[u]);
}

bool Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return 0;
	else{
		if(sz[a] < sz[b]) swap(a, b);
		par[b] = a;
		sz[a] += sz[b];
		return 1;
	}
}

void Kruskal(){
//	sort(all(E), [](edge a, edge b){
//		return a.w < b.w;
//	});
//    sort(all(E), cmp());
    sort(all(E)); int ans = 0;
    vector<edge>MST;
    FOB(i, 0, m){
    	if(MST.size() == n - 1) break;
    	edge e = E[i];
    	if(Union(e.x, e.y)){
    		MST.pb(e);
    		ans += e.w;
		}
	}
	if(MST.size() < n - 1) cout << "NO\n";
	else{
		cout << ans << endl;
		FOB(i, 0, MST.size()){
			cout << MST[i].x << ' ' << MST[i].y << ' ' << MST[i].w << endl;
		}
	}
}

void solve(){
	cin >> n >> m;
	make();
	FOB(i, 0, m){
		int x, y, w;
		cin >> x >> y >> w;
		E.pb(edge{x, y, w});
	}
	Kruskal();
}


int main() {
    faster();
  //  freopen("input.INP", "r", stdin);
   // freopen("output.OUT", "w", stdout);
    int t; t = 1; 
   // cin >> t;
    while(t--) 
        solve();
    return 0;
}
