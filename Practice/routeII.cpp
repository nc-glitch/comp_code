#include <bits/stdc++.h>
using namespace std;
#define eb emplace_back();
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

struct flight{
    ll leave, dest, time, org;
    bool operator<(const flight &a)const{
        return time < a.time;
    }
    bool operator=(const flight &a)const{
        return (leave == a.leave && dest == a.dest && time == a.time && org == a.org);
    }
};

ll n, m;
multiset<flight> paths[200002];
ll lo[200002];

vll bfs()
{
    //first set of nodes in bfs
    vector<flight> qu;
    int c = 0; int l = paths[1].size();
    for(int i = 0; i < l; i++){
        flight fl = *paths[1].begin();
        if(fl.leave >= 0){
            qu.push_back(fl);
            paths[1].erase(paths[1].begin());
        }
        else c++;
    }

    //constructing answer vector
    vll ans;
    for(int i = 0; i <= n; i++) ans.push_back(2000000000);
    ans[1] = 0;

    //bfs
    while(!qu.empty()) {
        flight curr = *qu.begin();
        qu.erase(qu.begin());
        ans[curr.dest] = min(ans[curr.dest], curr.time);
        multiset<flight> add = paths[curr.dest];
        c = 0; l = add.size();
        for(int i = 0; i < l; i++)
        {
            flight fl = *add.begin();
            if (fl.leave >= curr.time + lo[curr.dest]) {
                qu.push_back(fl);
                paths[curr.dest].erase(paths[curr.dest].lower_bound(fl));
            }
            add.erase(add.begin());
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //bfs with queue as a set ordered by shortest time -> priority queue

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        flight fl{};
        cin >> fl.org >> fl.leave >> fl.dest >> fl.time;
        paths[fl.org].insert(fl);
    }
    for(int i = 1; i <= n; i++){
        ll d; cin >> d;
        lo[i] = d;
    } lo[0] = 0; lo[n+1] = 0;

    vll ans = bfs();
    for(int i = 1; i <= n; i++){
        if(ans[i] == 2000000000) cout << -1 << endl;
        else cout << ans[i] << endl;
    }

    return 0;
}
#if 0
3 3
1 0 2 10
2 11 2 0
2 1 3 20
10 1 10
-> 0 + 0 + 20

3 3
1 0 2 10
2 10 2 0
2 1 3 20
10 1 10
-> 0 + 10 + -1
#endif