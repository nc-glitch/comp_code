#include <bits/stdc++.h>
using namespace std;

//__builtin_popcount(n) amount of "1" bits
// log2(num & -num); rightmost bit, first bit pos
// log2(num & num); leftmost bit
//  num/ (-num & num) num without trailing zeroes 10000 = 1 not 16
//
// mask|(1<<i); modify number mask ith bit
//
//for (int i = 0; i < pow(2,n); i++){
//    for (int j = 0; j < n; j++){
//        if ((i >> j) & 1){
//            cout << 'f';
//        }else{
//            cout << 'f';
//        }
//    }
//}

//        scanf("%lld",&n);
#define ll long long
#define ld long double
//#define mod 1000000007
#define mod 998244353
#define ull unsigned long long
#define fbo(a) find_by_order(a) //will give a-th largest element
#define ook(a) order_of_key(a) //will give no. of elements strictly lesser than a
#define setbits(x)      __builtin_popcountll(x)
#define str string
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define eb emplace_back
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define ff first
#define ss second
#define pb push_back
#define sp(x,y)         fixed<<setprecision(y)<<x
#define nl '\n'
#define inf (1LL<<62)
#define si(x)    scanf("%d",&x)
#define sl(x)    scanf("%lld",&x)
#define sss(s)    scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x)    printf("%lld\n",x)
#define ps(s)    printf("%s\n",s)
#define FOR(a, c, b) for (int a = c; a < b; a++)
#define MIN3(a, b, c) std::min(std::min(a, c))

typedef map<ll, ll> mll;
typedef vector<long long> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<vector<ll> > vvll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

struct edge{
    ll ind, val;
//    str s;
    bool operator<(const edge& c1)const{
        return val < c1.val;
    }
    //    bool operator==(const cow&c1)const{
    //        if (c == c1.c) return true;
    //        return false;
    //    }
    //    bool operator!=(const cow&c1)const{
    //        if (c == c1.c) return false;
    //        return true;
    //
};

#define MAX 300009
ll n,m;
str s;

int lowerbound(vi& arr, int target, int blast)
{
    if (target == 0) return 0;
    int ind = target;

    while(ind > 0 && arr[ind - 1] >= arr[target] - blast) ind--;
    if (ind == 0) return 0;
    if (ind == target) return target;
    return lowerbound(arr, ind, blast + 1);
}
int upperbound(vi& arr, int target, int blast)
{
    int l = arr.size() - 1;
    if (target == l) return l;
    int ind = target;

    while (ind < l && arr[ind + 1] <= arr[target] + blast) ind++;
    if (ind == l) return l;
    if (ind == target) return target;
    return upperbound(arr, ind, blast + 1);
}

int test(vi& arr, int target, int blast)
{
    int a = upperbound(arr, target, blast); int b = lowerbound(arr, target, blast);
    cout << a << ", " << b << endl;
    return a - b;
}

void print(vi arr)
{
    for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#if 1
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
#endif

    int n; cin >> n;
    int tries = n;
    vi cows;
    while (tries--)
    {
        int a; cin >> a;
        cows.eb(a);
    }
    sort(cows.begin(), cows.end());
    //print(cows); cout << endl;

    int ma = 0;
    for (int i = 0; i < n; i++)
    {
        int ans = upperbound(cows, i, 1) - lowerbound(cows, i, 1);
        ma = max(ma, ans);
    }
    cout << ma + 1;

}
