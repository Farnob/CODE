#include<bits/stdc++.h>
using namespace std;

void print_(int a) {cerr << a;}
void print_(long long a) {cerr << a;}
void print_(char a) {cerr << a;}
void print_(string a) {cerr << a;}
void print_(bool a) {cerr << a;}
void print_(double a) {cerr << a;}
void print_(long double a) {cerr << a;}
void print_(unsigned long long a) {cerr << a;}

template<class T> void print_(vector<T> t) {
	cerr << "[ ";
	for (T i : t) {
		print_(i);
		cerr << " ";
	}
	cerr << "]";
}

template<class T, class V> void print_(map<T, V> t) {
	cerr << "[ ";
	for (auto i : t) {
		print_(i);
		cerr << " ";
	}
	cerr << "]";
}

template<class T> void print_(set<T> t) {
	cerr << "[ ";
	for (T i : t) {
		print_(i);
		cerr << " ";
	}
	cerr << "]";
}

template<class T, class V> void print_(pair<T, V>p) {
	cerr << "{";
	print_(p.first);
	cerr << ",";
	print_(p.second);
	cerr << "}";
}

template<class T> void print_(multiset<T> t) {
	cerr << "[ ";
	for (T i : t) {
		print_(i);
		cerr << " ";
	}
	cerr << "]";
}


#ifndef ONLINE_JUDGE
#define debug(x)cerr<<#x<<" ";print_(x);cerr<<'\n';
#else
#define debug(x)
#endif

/*=><==><==><==><==><==><==><==><==><==><==><==><==><==><==><==><==><==><==><==><==><==><==><==><==>*/
#define ll long long
#define forn(i, n) for(int i=0;i<(int)n;i++)
#define form(i, n) for(int i=1;i<(int)n;i++)

const int N = 1e5 + 10;
int arr[N];

void merge(int l, int r, int mid) {
	int l_sz = mid - l + 1;
	int L[l_sz + 1];
	int r_sz = r - mid;
	int R[r_sz + 1];

	for (int i = 0; i < l_sz; i++) {
		L[i] = arr[i + l];
	}
	for (int i = 0; i < r_sz; i++) {
		R[i] = arr[i + mid + 1];
	}
	L[l_sz] = R[r_sz] = INT_MAX;

	int l_i = 0, r_i = 0;
	for (int i = l; i <= r; i++) {
		if (L[l_i] <= R[r_i]) {
			arr[i] = L[l_i];
			l_i++;
		}
		else {
			arr[i] = R[r_i];
			r_i++;
		}
	}
}

void mergeSort(int l, int r) {
	if (l == r) return;

	int mid = (l + r) / 2;

	mergeSort(l, mid);

	mergeSort(mid + 1, r);

	merge(l, r, mid);
}


void ans() {
	int n, m, k;
	cin >> n >> m ;
	vector<int> v[n + 4];
	vector<int> ans[n + 3];
	forn(i, n) {
		for (int j = 0; j < m; j++) {
			cin >> k;
			v[i].push_back(k);
		}
	}
	forn(i, n) {
		sort(v[i].begin(), v[i].end());
	}
	for (int i = 0; i < m; i++) {
		int mini = INT_MAX;
		int index = -1;
		for (int j = 0; j < n; j++) {
			if (v[j][0] < mini) {
				mini = v[j][0];
				index = j;
			}
		}
		for (int j = 0; j < n; j++) {
			if (j == index) {
				ans[j].push_back(v[j][0]);
				v[j].erase(v[j].begin());
			}
			else {
				ans[j].push_back(v[j][v[j].size() - 1]);
				v[j].pop_back();
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<ans[i].size();j++){
			cout<< ans[i][j] << " ";
		}
		cout<<'\n';
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;//kono kono time e T test case er dorkar hoy na tokhon t = 1 korlei hobe;
	while (t--) {
		ans();
	}

	cerr << "\n\n\n\nTime: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.";
	return 0;
}