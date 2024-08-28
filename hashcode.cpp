#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define ss(s) getline(cin, s)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define ps(s) cout << (s) << "\n"
#define ll long long
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define rof(i, k, n) for (ll i = k; i >= n; i--)
#define deb(x) cout << #x << "=" << x << "\n"
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define set(x, i) memset(x, i, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(a, it) for (auto it = a.begin(); it != a.end(); it++)
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c), x) != c.end())

#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define randomize srand(chrono::high_resolution_clock::now().time_since_epoch().count())

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

char letter;

struct Street
{
    int start, end, time, id;
    Street(int s, int e, int t, int i) : start(s), end(e), time(t), id(i){};
};

struct Car
{
    vi path;
    Car(vi &p) : path(p) {}
};

vector<Street> streets;
vector<Car> cars;

unordered_map<string, ll> st_map;
unordered_map<ll, string> st_rev_map;

unordered_map<ll, ll> st_time_map;
unordered_map<ll, pii> st_loc_map;

signed main()
{
    fastio;

    scanf("%c", &letter);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll duration, num_int, num_st, num_car, car_points;
    cin >> duration >> num_int >> num_st >> num_car >> car_points;

    streets.reserve(num_st);
    cars.reserve(num_car);

    fo(i, 0, num_st)
    {
        ll s, e, t;
        string n;
        cin >> s >> e >> n >> t;

        st_map.insert(mp(n, i));
        st_rev_map.insert(mp(i, n));

        st_time_map.insert(mp(i, t));
        st_loc_map.insert(mp(i, mp(s, e)));

        streets[i] = Street(s, e, t, i);
    }

    fo(i, 0, num_car)
    {
        ll n;
        cin >> n;

        vi p(n);
        fo(j, 0, n)
        {
            string temp;
            cin >> temp;

            p.pb(st_map.at(temp));
        }

        cars[i] = Car(p);
    }

    vvi car_pos;
    fo(i, 0, num_car)
    {
        int pos = 0;
        vi temp(duration, -1);
        fo(j, 0, cars[i].path.size() - 1)
        {
            fo(k, 0, st_time_map.at(cars[i].path[j]) - 1)
                temp[pos++] = 0;
            temp[pos++] = cars[i].path[j];
        }
        car_pos.pb(temp);
    }

    return 0;
}