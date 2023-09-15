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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#if 1
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
#endif

    //3cows: b, e, & m
    //initially: 7 gallons/day
    //change over time
    //first: day, second: name, third: change since last time

    int n;
    cin >> n;
    int tries = n;
    int bes[101], els[101], mil[101];
    bes[0] = els[0] = mil[0] = 7;
    for(int i = 1; i < 101; i++)
    {
        bes[i] = els[i] = mil[i] = 0;
    }
    while(tries--)
    {
        int d; cin >> d;
        string n; cin >> n;
        string num; cin >> num;
        int nm = stoi(num);
        if(n == "Bessie") bes[d] = nm;
        else if(n == "Elsie") els[d] = nm;
        else mil[d] = nm;
    }
    for(int i = 1; i < 101; i++)
    {
        bes[i] += bes[i-1];
        els[i] += els[i-1];
        mil[i] += mil[i-1];
    }

    int chgs[101]; chgs[0] = 0;
    for(int i = 1; i < 101; i++)
    {
       if(bes[i] > els[i] && bes[i] > mil[i])
       {
           chgs[i] = 1;
       }
       else if(els[i] > bes[i] && els[i] > mil[i])
       {
           chgs[i] = 2;
       }
       else if(mil[i] > bes[i] && mil[i] > els[i])
       {
           chgs[i] = 3;
       }
       else if(bes[i] == els[i] && bes[i] > mil[i])
       {
           chgs[i] = 4;
       }
       else if(bes[i] == mil[i] && bes[i] > els[i])
       {
           chgs[i] = 5;
       }
       else if(els[i] == mil[i] && els[i] > bes[i])
       {
           chgs[i] = 6;
       }
       else
       {
           chgs[i] = 0;
       }
    }

    int chg = 0;
    for(int i = 1; i < 101; i++)
    {
        if(chgs[i] != chgs[i-1]) chg++;
    }

    cout << chg;

    return 0;
}
