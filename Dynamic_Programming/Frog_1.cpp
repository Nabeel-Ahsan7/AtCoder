#include<bits/stdc++.h>
#define int long long int
#define yes cout << "YES" << endl
#define show(x) cout << x << endl;
#define no cout << "NO" << endl
#define uint unsigned long long int
#define all(v) v.begin(),v.end()
#define print(v) for(auto x : v) cout << x << " "; cout << endl;
int mypow(int a, int b){ int ans = 1; while(b){ if (b&1) ans = (ans*a); b >>= 1; a = (a*a); } return ans; }
int bigmod(int a, int b, int m) { int ans = 1; for (a %= m; b; b >>= 1, a = (1LL * a * a) % m) if (b & 1) ans = (1LL * ans * a) % m; return ans; }
#define init(arr, val) memset(arr, val, sizeof(arr))
using namespace std;
void setIO(){ios_base::sync_with_stdio(false); cin.tie(NULL);}
const int MOD = 1e9+7;
const int inf = 1e9;


void solve() {
    int n; cin >> n;
    vector<int>v(n);
    for(auto &x : v) cin >> x;

    vector<int>dp(n+1);
    for(int i=1;i<n;i++){
        dp[i] = min(dp[i-1]+abs(v[i]-v[i-1]),(i-2>=0?dp[i-2]+abs(v[i]-v[i-2]):INT_MAX));
    }
    cout << dp[n-1] << endl;
}   

int32_t main() {
    setIO();
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
