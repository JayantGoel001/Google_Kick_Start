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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    int testcase = 1;
    while (t--) {
        cout<<"Case #"<<testcase++<<": ";
        int n,b;
        cin >> n>>b;
        int ar[n];
        for (int i = 0; i < n; ++i) {
            cin>>ar[i];
        }
        sort(ar,ar+n);
        int sum= 0 ;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            sum+=ar[i];
            if (sum<=b){
                count++;
            } else{
                break;
            }
        }
        cout<<count;
        cout << "\n";
    }
}