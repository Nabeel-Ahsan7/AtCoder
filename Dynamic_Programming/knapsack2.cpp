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

void solve() {
    int n,w; cin >> n >> w;
    vector<pair<int,int>>v(n);
    int total = 0;
    for(auto &x : v){
        cin >> x.first >> x.second ;
        total+=x.second;
    }
    vector<vector<int>>dp(n+1,vector<int>(total+1,inf));
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        auto item = v[i-1];
        int weight = item.first;
        int value = item.second;
        for(int j=0;j<=total;j++){
            dp[i][j] = dp[i-1][j];
            if(j-value>=0) dp[i][j] = min(dp[i][j],dp[i-1][j-value]+weight);
        }
    }
    int ans = 0;
    for(int i=0;i<=total;i++){
        if(dp[n][i]<=w) ans = i;
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
