#include "KowerKoint/base.hpp"
#include "rainbou/cpp/modint.hpp"

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<LP>> g(n);
    REP(i, m){
        ll a, b, c; cin >> a >> b >> c;
        a--; b--; c -= 2;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    VVL weight(2, VL(n, LINF));
    stack<P> stk;
    weight[0][0] = 0;
    stk.emplace(0, 0);
    while(!stk.empty()) {
        auto [s, u] = stk.top(); stk.pop();
        for(auto [v, c] : g[u]) {
            ll w = c - weight[s][u];
            if(weight[s^1][v] == LINF) {
                weight[s^1][v] = w;
                stk.emplace(s^1, v);
            } else if(weight[s^1][v] != w) {
                print(0);
                return;
            }
        }
    }
    ll lb = 0, ub = LINF;
    REP(i, n) {
        if(weight[0][i] != LINF && weight[1][i] != LINF) {
            if((weight[1][i] - weight[0][i]) % 2 != 0) {
                print(0);
                return;
            }
            ll ans = (weight[1][i] - weight[0][i]) / 2;
            lb = max(lb, ans);
            ub = min(ub, ans);
        }
        if(weight[0][i] != LINF) {
            lb = max(lb, -weight[0][i]);
        }
        if(weight[1][i] != LINF) {
            ub = min(ub, weight[1][i]);
        }
    }
    if(lb > ub) {
        print(0);
        return;
    }
    print(ub - lb + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    // cin >> t;
    for(int case_id = 1; case_id <= t; case_id++) solve();
    return 0;
}
