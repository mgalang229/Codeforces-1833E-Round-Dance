#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 1;
vector<int> adj[MAX_N];
set<int> s[MAX_N], sz;
bool vis[MAX_N];
int a[MAX_N];

void dfs(int u) {
	vis[u] = true;
	sz.insert(adj[u].size());
	for (int v : adj[u]) {
		if (!vis[v]) {
			dfs(v);
		}
	}
}

void test_case(int& tc) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int u = i, v = a[i] - 1;
		if (s[u].find(v) != s[u].end()) {
			continue;
		}
		adj[u].push_back(v);
		adj[v].push_back(u);
		s[u].insert(v);
		s[v].insert(u);
	}
	memset(vis, false, sizeof(vis));
	int mn = 0, mx = 0;
	bool acyclic_exists = false;
	for (int u = 0; u < n; u++) {
		if (!vis[u]) {
			sz.clear();
			dfs(u);
			if (sz.find(1) == sz.end()) {
				mn++;
			} else {
				acyclic_exists = true;
			}
			mx++;
		}
	}
	cout << mn + (acyclic_exists ? 1 : 0) << " " << mx << "\n";
	for (int u = 0; u < n; u++) {
		adj[u].clear();
		s[u].clear();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}
