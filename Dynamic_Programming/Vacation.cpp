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
    int days; cin >> days;
    vector<vector<int>> plan(days,vector<int>(3));
    for(int i=0;i<days;i++){
        cin >> plan[i][0] >> plan[i][1] >> plan[i][2]; 
    }
    vector<vector<int>>dp(days+1,vector<int>(3));
    for(int i=1;i<=days;i++){
        //choose swing today;
        dp[i][0] = max({dp[i][0],dp[i-1][1]+plan[i-1][0],dp[i-1][2]+plan[i-1][0]});
        //choose bug today;
        dp[i][1] = max({dp[i][1],dp[i-1][0]+plan[i-1][1],dp[i-1][2]+plan[i-1][1]});
        //choose homework today;
        dp[i][2] = max({dp[i][2],dp[i-1][0]+plan[i-1][2],dp[i-1][1]+plan[i-1][2]});
    }
    cout << *max_element(all(dp[days])) << endl;
}   

int32_t main() {
    setIO();
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
