#include <bits/stdc++.h>
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


int dfs(int vertex, vector<vector<int>>&graph,vector<int>&dp){
    int ans = 0;
    if(dp[vertex]!=-1) return dp[vertex];
    for(int child : graph[vertex]){
        ans = max(ans,1 + dfs(child,graph,dp));
    }
    return dp[vertex] = ans;
}

void solve() {
    int n,m; cin >> n >> m;
    vector<vector<int>>graph(n+1);
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        graph[u].push_back(v);
    }
    vector<int>dp(n+1,-1);
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans,dfs(i,graph,dp));
    }
    cout << ans << endl;
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
