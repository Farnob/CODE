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

const int N = 1e5+10;
int arr[N];

void merge(int l, int r, int mid){
	int l_sz = mid - l + 1;
	int L[l_sz + 1];
	int r_sz = r - mid;
	int R[r_sz + 1];

	for(int i=0;i<l_sz;i++){
		L[i] = arr[i+l];
	}
	for(int i=0;i<r_sz;i++){
		R[i] = arr[i+mid+1];
	}
	L[l_sz] = R[r_sz] = INT_MAX;

	int l_i = 0, r_i = 0;
	for(int i= l;i<=r;i++){
		if(L[l_i] <= R[r_i]){
			arr[i] = L[l_i];
			l_i++;
		}
		else{
			arr[i] = R[r_i];
			r_i++;
		}
	}
}

void mergeSort(int l, int r){
	if(l == r) return;

	int mid = (l+r)/2;

	mergeSort(l, mid);

	mergeSort(mid+1, r);

	merge(l, r, mid);
}

//Prime_Num:-
bool prime(int n)
{
    if(n<2)return false;
    if(n<=3)return true;
    if(n%2==0)return false;
    for(int i=3;i*i<=n;i+=2)
    {
        if(n%i==0)return false;
    }
    return true;
}


/*GIVEN ARRAY A OF N INTEGERS. GIVEN Q QUERIES AND IN EACH QUERY GIVEN L AND R PRINT SUM OF ARRAY ELEMENTS FROM INDEX L TO R(L, R INCLUDED);

CONSTRAINTS:- 
1 <= N <= 10^5
1 <= ARR[I] <= 10^9
1 <= Q <= 10^5
1 <= L, R <= N

*/

const int Ni = 1e5+10;
int a[Ni];
int pref[Ni];

void ans(){
	//O(N) + O(Q*N) = 10 ^ 10
	//NORMAL_VERSION:-

	// int n;
	// cin >> n;
	// for(int i=1;i<=n;i++){cin >> a[i];}

	// int q; 
	// cin >> q;
	// while(q--){
	// 	int l, r;
	// 	cin >> l >> r;
	// 	ll sum = 0;
	// 	for(int i=l;i<=r;i++){
	// 		sum+=a[i];
	// 	}
	// 	cout << sum << '\n';
	// }

	//optimized version:- 

	 int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		pref[i] = pref[i - 1]+a[i];
		//N er loop;
	}

	int q; 
	cin >> q;
	while(q--){
		int l, r;
		cin >> l >> r;
		cout << pref[r] - pref[l - 1]<<'\n';
		//O(1) operation;
	}
	//O(N) + O(Q) = 10^5;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;//kono kono time e T test case er dorkar hoy na tokhon t = 1 korlei hobe;
    while(t--){
        ans();
    }

	cerr << "\n\n\n\nTime: " << 1.0 * clock() /CLOCKS_PER_SEC << " s.";
	return 0;
}