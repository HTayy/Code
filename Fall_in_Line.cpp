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

const int N = 1e6 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;

int n;
int x[N], y[N];

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l, int h) {
    return rnd() % (h - l + 1) + l;
}

bool check(int i, int j, int k) {
    pair<long long, long long> a = {x[j] - x[i], y[j] - y[i]};
    pair<long long, long long> b = {x[k] - x[i], y[k] - y[i]};

    long long ans = 1LL * a.first * b.second - 1LL * a.second * b.first;

    return (ans == 0);
}

void solve(int t) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];

    int ans = 0;
    for (int i = 1; i <= 30; i++) {
        if (n == 2) continue ;

        int a = Rand(1, n - 1), b = Rand(a + 1, n);

        int cnt = 2;
        for (int j = 1; j <= n; j++) {
            if (j == a || j == b) continue ;

            if (check(a, b, j)) cnt++;
        }

        maximize(ans, cnt);
    }

    cout << "Case #" << t << ": " << n - ans << '\n';
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