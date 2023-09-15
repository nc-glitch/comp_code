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
//USACO 2016 December Contest, Bronze
//Problem 2. Block Game

static int ans[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,0,0,0,0};
static int need[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,0,0,0,0};

static void win(char a)
{
    int i = -65 + (int(a) + 0);
    if(ans[i] < 2) ans[i] = 2;
}

static void cwin(char a, char b)
{
    int i = -65 + (int(a) + 0);
    if(ans[i] < 1) ans[i] = 1;
    need[i] = -65 + (int(b) + 0);
}


static void crows(string a[3], int n)
{
    if(a[n][0] == a[n][1])
    {
        if(a[n][1] == a[n][2]) win(a[n][0]);
        else cwin(a[n][0], a[n][2]);
    }
    else if(a[n][1] == a[n][2]) cwin(a[n][1], a[n][0]);
    else if(a[n][0] == a[n][2]) cwin(a[n][0], a[n][1]);

}

static void ccol(string a[3], int n)
{
    if(a[0][n] == a[1][n])
    {
        if(a[1][n] == a[2][n]) win(a[0][n]);
        else cwin(a[0][n], a[2][n]);
    }
    else if(a[1][n] == a[2][n]) cwin(a[1][n], a[0][n]);
    else if(a[0][n] == a[2][n]) cwin(a[0][n], a[1][n]);

}

//XYZ
//DCA
//BBA
//NO WORK

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#if 0
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
#endif

    string input[3];
    for(int i = 0; i < 3; i++)
    {
        string in;
        cin >> in;
        input[i] = in;
    }


    for(int i = 0; i < 3; i++)
    {
        crows(input, i);
        ccol(input, i);
    }

    if(input[0][0] == input[1][1])
    {
        if(input[1][1] == input[2][2]) win(input[0][0]);
        else cwin(input[0][0], input[2][2]);
    }
    else if(input[1][1] == input[2][2]) cwin(input[1][1], input[0][0]);
    else if(input[0][0] == input[2][2]) cwin(input[0][0], input[1][1]);

    if(input[0][2] == input[1][1])
    {
        if(input[1][1] == input[2][0]) win(input[2][0]);
        else cwin(input[0][2], input[2][0]);
    }
    else if(input[1][1] == input[2][0]) cwin(input[2][0], input[0][2]);
    else if(input[0][2] == input[2][0]) cwin(input[2][0], input[1][1]);

    int could = 0; int claim = 0;
    for(int i = 0; i < 26; i++)
    {
        if(ans[i] == 2) claim++;
        else if(ans[i] == 1)
        {
            could++;
        }
    }

    cout << claim << endl;
    cout << could << endl;

    return 0;
}
