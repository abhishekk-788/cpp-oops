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

#define IN_FOLDER "input\\"
#define OUT_FOLDER "output\\"

char letter;

string get_input_file_name()
{
    return IN_FOLDER + string(1, letter) + ".txt";
}

string get_output_file_name()
{
    return OUT_FOLDER + string(1, letter) + "_out" + ".txt";
}

struct Street
{
    int start, end, time, pos;
    string name;

    Street(int s, int e, string n, int t, int p) : start(s), end(e), name(n), time(t), pos(p) {}
};

unordered_map<string, int> street_map;

struct Car
{
    int num_paths;
    vs paths_names;
    vi paths;

    Car(int n, vs &pn) : num_paths(n), paths_names(pn)
    {
        for (string s : paths_names)
            paths.pb(street_map.at(s));
    }
};

vector<Street> streets;
vector<Car> cars;

signed main()
{
    fastio;

    scanf("%c", &letter);

#ifndef ONLINE_JUDGE
    freopen(get_input_file_name().c_str(), "r", stdin);
    freopen(get_output_file_name().c_str(), "w", stdout);
#endif

    int duration, num_intersections, num_streets, num_cars, car_points;
    cin >> duration >> num_intersections >> num_streets >> num_cars >> car_points;

    streets.resize(num_streets);
    fo(i, 0, num_streets)
    {
        int temp_start, temp_end, temp_time;
        string temp_name;
        cin >> temp_start >> temp_end >> temp_name >> temp_time;
        
        street_map.insert(mp(temp_name, i));
        streets.emplace_back(new Street(temp_start, temp_end, temp_name, temp_time, i));
    }

    cars.resize(num_cars);
    fo(i, 0, num_cars)
    {
        int temp_num_paths;
        cin >> temp_num_paths;

        vs temp_path_names(temp_num_paths);
        fo(j, 0, temp_num_paths) cin >> temp_path_names[j];

        cars.emplace_back(new Car(temp_num_paths, temp_path_names));
    }

    return 0;
}
