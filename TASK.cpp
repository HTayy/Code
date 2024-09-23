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

int n;
double p;

double pw(double x, int y) {
    double ans = 1;
    double mul = x;
    while (y > 0) {
        if (y & 1) ans = 1. * ans * mul;
        mul = 1. * mul * mul;

        y >>= 1;
    }

    return ans;
}

void solve(int t) {
    cin >> n >> p;
    p = p / 100;
    double tmp = pw(p, n - 1);

    double l = 0, r = 100;
    while (r - l > 0.00000000001) {
        double mid = (l + r) / 2;
        if (pw(mid, n) > tmp) r = mid;
        else l = mid;
    }

    double ans = (r - p) * 100;

    cout << "Case #" << t << ": " << fixed << setprecision(8) << ans << '\n';
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