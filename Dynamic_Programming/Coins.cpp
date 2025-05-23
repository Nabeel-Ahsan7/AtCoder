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



void solve() {
    int n; cin >> n;
    vector<double>v(n);
    for(auto &x : v) cin >> x;
    vector<vector<double>>dp(n+1,vector<double>(n+1,0.0));
    dp[0][0] = 1.0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            dp[i][j] += dp[i-1][j]  *  (1-v[i-1]);
            dp[i][j] += dp[i-1][j-1] * v[i-1];
        }
    }
    double ans = 0.0;
    for(int i=1;i<=n;i++){
        if(i>n-i){
            ans += dp[n][i];
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
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
