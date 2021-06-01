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
#define forn(i, n) for(int i=0;i<(int)n;i++)
#define form(i, n) for(int i=1;i<(int)n;i++)

void ans(){
	int n;
	cin >> n;
	int count = 1;
	int arr[n];
	int mx = INT_MAX;
	
	forn(i, n){
		cin >> arr[i];
	}
	sort(arr, arr+n);
	form(i, n){
		mx = min(mx, abs(arr[i]-arr[i-1]));
		if(mx < arr[i])
			break;
		count++;
	}
	cout << count << '\n';
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