#include<bits/stdc++.h>
using namespace std;

#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define ALL(v) (v).begin(), (v).end()

template<class T> bool maximize(T& a, const T& b) {
    return a < b ? a = b, 1 : 0;
}
 
template<class T> bool minimize(T& a, const T& b) {
    return a > b ? a = b, 1 : 0;
}

/*==============================================*/

const int N = 3e5 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;

int n, g;
int a[N];

void solve(int t) {
    cin >> n >> g;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1, greater<int>());
    
    int ans = INF, res = 0;
    for (int i = 1; i <= n; i++) {
        if (minimize(ans, abs(a[i] - g))) {
            res = i;
        }
    }

    cout << "Case #" << t << ": " << res << ' ' << ans << '\n';
}

#define TASK "TASK"
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }

    int t; cin >> t;
    for (int i = 1; i <= t; i++) solve(i);

    return 0;
}

// louis97