#include <bits/stdc++.h>
#define endl '\n'
#define int long long int
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define all(v) v.begin(),v.end()
#define print(v) for(auto x : v) cout << x << " "; cout << endl;
int mypow(int a, int b){ int ans = 1; while(b){ if (b&1) ans = (ans*a); b >>= 1; a = (a*a); } return ans; }
int bigmod(int a, int b, int m) { int ans = 1; for (a %= m; b; b >>= 1, a = (1LL * a * a) % m) if (b & 1) ans = (1LL * ans * a) % m; return ans; }
#define init(arr, val) memset(arr, val, sizeof(arr))
using namespace std;
void setIO(){ios_base::sync_with_stdio(false); cin.tie(NULL);}
const int MOD = 1e9+7;
const int inf = 1e9;
typedef pair<int, int> pii;


int dfs(int i,int j,vector<string>&graph,vector<vector<int>>&dp){
    if(i>=graph.size() || i<0 || j>=graph[0].size() || j<0) return 0;
    if(i==graph.size()-1 && j==graph[0].size()-1) return 1;
    if(graph[i][j]=='#') return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j] = (dfs(i+1,j,graph,dp) + dfs(i,j+1,graph,dp))%MOD;
}

void solve() {
    int n,m; cin >> n >> m;
    vector<string>v(n);
    for(auto &x : v) cin >> x;
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    cout <<  dfs(0,0,v,dp) % MOD << endl;
}

int32_t main() {
    setIO();
    int t = 1;
    // cin >> t;
    int test=1;
    while (t--) {
        // cout << "Case " << "#"<<test++<<": ";
        solve();
    }
}
