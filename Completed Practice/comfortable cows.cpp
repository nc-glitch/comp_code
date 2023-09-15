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
typedef vector<string> vstr;

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


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#if 0
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
#endif

    //nlogn
    int n; cin >> n;
    bool plcs[1002][1002];
    int cnts[1002][1002];
    for(int i = 0; i < 1002; i++)
    {
        for(int j = 0; j < 1002; j++)
        {
            cnts[i][j] = 0;
            plcs[i][j] = 0;
        }
    }

    //exactly 3
    int comft = 0;
    map<pair<int, int>, bool> cws;
    for(int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        x++; y++;
        plcs[y][x] = 1; if(cnts[y][x] == 3) comft++;

        cnts[y+1][x]++; cnts[y-1][x]++; cnts[y][x+1]++; cnts[y][x-1]++;

        if(plcs[y+1][x] && cnts[y+1][x] == 4) comft--;
        else if(plcs[y+1][x] && cnts[y+1][x] == 3) comft++;
        if(plcs[y-1][x] && cnts[y-1][x] == 4) comft--;
        else if(plcs[y-1][x] && cnts[y-1][x] == 3) comft++;
        if(plcs[y][x+1] && cnts[y][x+1] == 4) comft--;
        else if(plcs[y][x+1] && cnts[y][x+1] == 3) comft++;
        if(plcs[y][x-1] && cnts[y][x-1] == 4) comft--;
        else if(plcs[y][x-1] && cnts[y][x-1] == 3) comft++;

        cout << comft << endl;
    }

    return 0;
}