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
    //    }
};

#define MAX 300009
ll n,m;
str s;

static vector<int> chars(string a, string b)
{
    vector<int> ret;
    int A[26], B[26];
    for(int i = 0; i < 26; i++)
    {
        A[i] = B[i] = 0;
    }
    for(int i = 0; i < a.size(); i++)
    {
        //A[-97 + static_cast<int>(a[i])]++;
        A[-97 + (int(a[i]) + 0)]++;
    }
    for(int i = 0; i < b.size(); i++)
    {
        //B[-97 + static_cast<int>(b[i])]++;
        B[-97 + (int(b[i]) + 0)]++;
    }

    for(int i = 0; i < 26; i++)
    {
        ret.push_back(max(A[i], B[i]));
    }

    return ret;
}

static void sum(vector<int>& base, vector<int> extra)
{
    for(int i = 0; i < 26; i++)
    {
        base[i] += extra[i];
    }
}

static void print(vector<int> a)
{
    for(int i = 0; i < 26; i++)
        cout << a[i] << endl;
}

//USACO 2016 December Contest, Bronze
//Problem 2. Block Game

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int n;
    cin >> n;
    int tries = n;

    vector<int> ans;
    for(int i = 0; i < 26; i++)
    {
        ans.push_back(0);
    }

    while(tries--)
    {
        string a, b;
        cin >> a >> b;
        sum(ans, chars(a,b));
    }

    print(ans);

    return 0;
}
