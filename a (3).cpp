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
    int start, end, time, id;
    Street() {}
    Street(int s, int e, int t, int i) : start(s), end(e), time(t), id(i) {}
};

struct Car
{
    vi path;
    Car() {}
    Car(vi &p) : path(p) {}
};

struct Intersection
{
    vi in, out;
    Intersection() {}
};

unordered_map<string, ll> st_map;
unordered_map<ll, string> st_rev_map;

unordered_map<ll, ll> st_time_map;
unordered_map<ll, pii> st_loc_map;

vs break_str(string temp)
{
    vs strs;
    string word = "";
    for (auto x : temp)
    {
        if (x == ' ')
        {
            strs.pb(word);
            word = "";
        }
        else
            word = word + x;
    }
    strs.pb(word);
    return strs;
}

signed main()
{
    fastio;

    scanf("%c", &letter);

    ifstream input_file(get_input_file_name());
    if (!input_file.is_open())
    {
        ps("Could not open file " + get_input_file_name());
        return 1;
    }

    string temp;

    ll duration = 0, num_int = 0, num_st = 0, num_car = 0, car_points = 0;
    getline(input_file, temp);

    vs strs = break_str(temp);

    if (strs.size() == 5)
    {
        duration = stoll(strs[0]);
        num_int = stoll(strs[1]);
        num_st = stoll(strs[2]);
        num_car = stoll(strs[3]);
        car_points = stoll(strs[4]);
    }

    vector<Street> streets(num_st);
    vector<Car> cars(num_car);
    vector<Intersection> intersections(num_int);

    fo(i, 0, num_st)
    {
        ll s, e, t;
        string n;

        getline(input_file, temp);

        vs strs = break_str(temp);

        if (strs.size() == 4)
        {
            s = stoll(strs[0]);
            e = stoll(strs[1]);
            n = strs[2];
            t = stoll(strs[3]);

            // if (i < 5)
            //     cout << s << " " << e << " " << n << " " << t << "\n";
        }

        st_map.insert(mp(n, i));
        st_rev_map.insert(mp(i, n));

        st_time_map.insert(mp(i, t));
        st_loc_map.insert(mp(i, mp(s, e)));

        intersections[s].out.pb(i);
        intersections[e].in.pb(i);

        streets.pb(Street(s, e, t, i));
    }

    // fo(i, 0, num_car)
    // {
    //     ll n;
    //     cin >> n;

    //     vi p(n);
    //     fo(j, 0, n)
    //     {
    //         string temp;
    //         cin >> temp;

    //         p.pb(st_map.at(temp));
    //     }

    //     cars.pb(Car(p));
    // }

    // // vvi car_pos;
    // // fo(i, 0, num_car)
    // // {
    // //     ll pos = 0;
    // //     vi temp(duration + 1, -1);

    // //     temp[pos++] = cars[i].path[0];
    // //     fo(j, 1, cars[i].path.size())
    // //     {
    // //         fo(k, 0, st_time_map.at(cars[i].path[j]) - 1)
    // //             temp[pos++] = 0;

    // //         temp[pos++] = cars[i].path[j];
    // //     }
    // //     car_pos.pb(temp);
    // // }

    ll ints = 0;
    fo(i, 0, num_int) if (intersections[i].in.size() == 1) ints++;

    ofstream output_file(get_output_file_name());

    output_file << ints << "\n";
    fo(i, 0, num_int)
    {
        if (intersections[i].in.size() == 1)
        {
            output_file << i << "\n"
                        << 1 << "\n";
            output_file << st_rev_map.at(intersections[i].in[0]) << " " << duration << "\n";
        }
    }

    input_file.close();
    output_file.close();

    return 0;
}