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

vector<ii>E;
set<int>adj[1001];
bool vis[1001];
int n, m;

void dfs(int u){
	vis[u] = true;
	for(auto v : adj[u]){
		if(!vis[v]) dfs(v); 
	} 
} 

int total(){
	int cnt = 0;
	FOR(i, 1, n){
		if(!vis[i]){
			cnt++; 
			dfs(i); 
		}
	} 
	return cnt; 
} 

void solve(){
	cin >> n >> m;
	FOB(i, 0, m){
		int x, y;
		cin >> x >> y;
		E.pb({x, y});
		adj[x].insert(y);
		adj[y].insert(x); 
	} 
	int diff = total(); int cur = 0; 
	for(auto it : E){
		int x = it.fi;
		int y = it.se;
		adj[x].erase(y);
		adj[y].erase(x);
		mem(vis, 0);
		if(diff < total()){
			cout << x << ' ' << y << endl; cur++; 
		} 
		adj[x].insert(y);
		adj[y].insert(x); 
	} 
	cout << cur << endl; 
} 
   

int main() {
    faster();
    //freopen("input.INP", "r", stdin);
   // freopen("output.OUT", "w", stdout);
     int t; t = 1; 
    //cin >> t;
    while(t--) 
        solve();
    return 0;
}
