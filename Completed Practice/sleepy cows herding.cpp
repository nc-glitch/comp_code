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
typedef vector<string> vs;


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#if 0
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
#endif

    int n; cin >> n;
    int tries = n - 1;
    vll arr;
    ll last; cin >> last;
    arr.eb(last);
    while(tries--)
    {
        ll a; cin >> a;
        arr.eb(a);
    } sort(arr.begin(), arr.end());

    ll mx = arr[n-1] - arr[0] - n + 1;
    if(arr[1]-arr[0] > arr[n-1] - arr[n-2]){
        mx -= (arr[n-1]-arr[n-2]-1);
    }
    else mx -= (arr[1]-arr[0]+1);


    //2 pointers problem
    int mn_moves = n-1;
    for(int i = 0; i < n; i++)
    {
        int j = i;
        while(j < n && arr[j+1] - arr[i] == n-1)
            j++;
        mn_moves = min(mn_moves, n - (j - i + 1));
    }

    if(arr[n-2] - arr[0] == n - 2 && arr[n-1] - arr[n-2] > 2il)
        mn_moves = 2;

    cout << mn_moves << endl << mx << endl;

}
