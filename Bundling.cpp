#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define int long long int
#define double double_t
#define INF 1e18
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int GCD(int a, int b) {
    return b == 0 ? a : GCD(b, a % b);
}

int power(int x, int y, int MOD) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return power((x * x) % MOD, y / 2, MOD) % MOD;
    } else {
        return (x * power((x * x) % MOD, (y - 1) / 2, MOD) % MOD) % MOD;
    }
}
int n,k;
int ans;
void dfs(int u,int d,int **c,int *cnt){
    for (int i = 0; i < 26; ++i) {
        if (c[u][i]){
            dfs(c[u][i],d+1,c,cnt);
            cnt[u] += cnt[c[u][i]];
        }
    }
    while (cnt[u]>=k){
        cnt[u]-=k;
        ans+=d;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    int testcase = 1;
    while (t--) {
        cout<<"Case #"<<testcase++<<": ";
        cin >> n>>k;
        int *cnt = new int[2000001];
        int **c = new int*[2000001];
        for (int i = 0; i < 2000001; ++i) {
            c[i] = new int[26];
        }
        int m = 1;
        for (int i = 0; i < n; ++i) {
            string str;
            cin>>str;
            int u = 0;
            for (char d:str) {
                if (!c[u][d-'A']){
                    c[u][d-'A'] = m++;
                }
                u = c[u][d-'A'];
            }
            ++cnt[u];
        }
        ans = 0;
        dfs(0,0,c,cnt);
        cout<<ans;
        cout << "\n";
    }
}