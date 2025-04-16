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
    string s1,s2; cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    // cout << dp[n][m] << endl;
    int i=n,j=m;
    string lcs = "";
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            lcs+=s1[i-1];
            i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(all(lcs));
    cout << lcs << endl;
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
