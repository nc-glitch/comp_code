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

void print(vector<string>& ranks)
{
    for(const string& s : ranks) cout << s << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#if 0
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
#endif

    //o(n^3)

    int n, k; cin >> k >> n;
    map<string, int> ppl; int c = 0;
    for(int i = 0; i < n; i++)
    {
        string s; cin >> s;
        ppl[s] = i;
    }

    vector<string> ranks;
    for(int i = 0; i < n; i++)
    {
        string s = "";
        for(int j = 0; j < n; j++) s += '?';
        ranks.eb(s); ranks[i][i] = 'B';
    }

    for(int i = 0; i < k; i++)
    {
        vector<string> ppr;
        for(int j = 0; j < n; j++)
        {
            string s; cin >> s;
            ppr.eb(s);
        }
        for(int j = 1; j < n; j++)
        {
            string sr = ppr[j];
            for(int k = j-1; k >= 0; k--)
            {
                bool noalph = 0;
                string jr = ppr[k];
                if(noalph || sr.compare(jr) < 0) // for alphabetical, j should be greater than zero bc later index
                {
                    ranks[ppl[sr]][ppl[jr]] = '1';
                    ranks[ppl[jr]][ppl[sr]] = '0';
                    noalph = 1;
                }
            }
        }
    }

    print(ranks);

    return 0;
}