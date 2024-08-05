class dsu {
 public:
  vector<int> p;
  int n;
 
  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
 
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
 
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};


    int n, m;
    cin >> n >> m;
    dsu d(2 * n);
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      --a; --b;
      d.unite(a, b + n);
      d.unite(b, a + n);
    }
    bool isBipartite = true;
    for (int i = 0; i < n; i++) {
      if (d.get(i) == d.get(i + n)) {
        isBipartite = false;
        break;
      }
    }

