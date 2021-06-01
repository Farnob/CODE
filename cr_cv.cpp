#include<bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <ciso646>
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

void ans(){
    double usd;
    double rate;
    double euro;
    rate = 84.70;

    const int COLMFT1 = 35;
    const int COLTFT2 = 15;

    cout << fixed << setprecision(2);
    cout << "Welcome to C++ Currency Converter" <<'\n';

    cout << setw(COLMFT1) << left << "Enter a Value (US DOLLAR) :- ";
    cin >> usd;
    cout << '\n';

    cout << setw(COLMFT1) << left << "US DOLLAR :- ";
    cout<< setw(COLMFT1) << right << usd << '\n';

    cout << setw(COLMFT1)<<left << "Conversion rate (per US DOLLAR):- ";
    cout<< setw(COLMFT1)<<right<< rate << '\n';

    euro = usd * rate;

    cout << setw(COLMFT1) << left <<"Euro :- " ;
    cout << setw(COLMFT1) << right << euro << '\n';

    cout << "\n--------------------------------"<<"\n";
    cout << "\nEnd of Rate Converter" << "\n";
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
//struct diye stack bananor time e stk word ta use kora lagbe instead of the word stack.. karon stl e stack keyword ase tai.