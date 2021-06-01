#include<bits/stdc++.h>
using namespace std;

void print_(int a){cerr<< a;}
void print_(long long a){cerr<< a;}
void print_(char a){cerr<< a;}
void print_(string a){cerr<< a;}
void print_(bool a){cerr<< a;}
void print_(double a){cerr<<a;}
void print_(long double a){cerr<<a;}
void print_(unsigned long long a){cerr<<a;}

template<class T> void print_(vector<T> t) {
	cerr << "[ ";
	for (T i : t) {
		print_(i);
		cerr << " ";
	}
	cerr << "]";
}

template<class T, class V> void print_(map<T,V> t){
	cerr << "[ ";
	for(auto i : t){
		print_(i);
		cerr<< " ";
	}
	cerr << "]";
}

template<class T> void print_(set<T> t){
	cerr << "[ ";
	for(T i : t){
		print_(i);
		cerr <<" ";
	}
	cerr << "]";
}

template<class T,class V> void print_(pair<T,V>p){
	cerr << "{";
	print_(p.first);
	cerr<< ",";
	print_(p.second);
	cerr<<"}";
}

template<class T> void print_(multiset<T> t){
	cerr <<"[ ";
	for(T i : t){
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

void ans(){
	int n;
	cin >> n;
	vector<string> f(n);
	vector<pair<int, int>> p;
	for(int i=0;i<n;i++){
		cin >> f[i];
		for(int j=0;j<n;j++){
			if(f[i][j] == '*'){
				p.push_back({i,j});
			}
		}
	}
	p.push_back(p[0]);
	p.push_back(p[1]);
	if(p[0].first == p[1].first){
		p[2].first = (p[2].first + 1) % n;
		p[3].first = (p[3].first + 1) % n;
	}
	else if(p[0].second == p[1].second){
		p[2].second = (p[2].second + 1) % n;
		p[3].second = (p[3].second + 1) % n;
	}
	else{
		swap(p[2].first, p[3].first);
	}
	
	f[p[2].first][p[2].second] = '*';
	f[p[3].first][p[3].second] = '*';

	for(int i=0;i<n;i++){
		cout<<f[i] << '\n';
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
    while(t--){
        ans();
    }

	cerr << "\n\n\n\nTime: " << 1.0 * clock() /CLOCKS_PER_SEC << " s.";
	return 0;
}