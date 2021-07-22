#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, k, c[2000001][26], m, cnt[2000001];
ll ans;

void dfs(int u=0, int d=0) {
    for(int v=0; v<26; ++v) {
        if (c[u][v]) {
            dfs(c[u][v], d + 1);
            cnt[u] += cnt[c[u][v]];
        }
    }
    while(cnt[u]>=k) {
        cnt[u]-=k;
        ans+=d;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, test=1;
    cin >> t;
    while(t--) {
        cout << "Case #" << test++ << ": ";

        cin >> n >> k;
        m=1;
        for(int i=0; i<n; ++i) {
            string s;
            cin >> s;
            int u=0;
            for(char d : s) {
                if(!c[u][d-'A']) {
                    c[u][d - 'A'] = m++;
                }
                u=c[u][d-'A'];
            }
            ++cnt[u];
        }
        ans=0;
        dfs();
        cout << ans << "\n";
        memset(c, 0, m*sizeof(c[0]));
        memset(cnt, 0, m*4);
    }
}