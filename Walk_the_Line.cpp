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

long long n, k;

void solve(int t) {
    cin >> n >> k;

    long long tmp = INF;
    for (int i = 1; i <= n; i++) {
        long long x; cin >> x;
        minimize(tmp, x);
    }

    if (n == 1) {
        if (tmp > k) cout << "Case #" << t << ": NO \n";
        else cout << "Case #" << t << ": YES \n";
        
        return ;
    }

    if (1LL * tmp * (2 * n - 3) > k) cout << "Case #" << t << ": NO \n";
    else cout << "Case #" << t << ": YES \n";
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