#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


    int n;
    cin >> n;
    set<pair<int, int>> point_set;
    vector<pair<int, int>> points(n);

    for(int i=0;i<n;i++){
        cin >> points[i].first >> points[i].second;
        point_set.insert(points[i]);
    }

    int arr_min = INT_MAX, arr_max = INT_MIN;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            auto p1 = points[i];
            auto p2 = points[j];

            if(p1.first == p2.first){
                continue;
            }
            if(p1.second == p2.second){
                continue;
            }
            if(p1.first > p2.first){
                swap(p1, p2);
            }

            int x1 = p1.first, y1 = p2.second;
            int x2 = p2.first, y2 = p1.second;

            if(point_set.count({x1, y1}) && point_set.count({x2, y2})){
                int ar = abs(p1.first - p2.first) * abs(p1.second - p2.second);
                arr_min = min(arr_min, ar);
                arr_max = max(arr_max, ar);
            }
        }
    }
    if(arr_min == INT_MAX){
        cout << -1 << '\n';
    }
    else{
        cout << arr_max - arr_min << '\n';
    }
}