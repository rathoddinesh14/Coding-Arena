// https://www.hackerearth.com/problem/algorithm/costliest-data-plan-422373b5/?source=list_view

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
		int n;
		cin >> n;

		vector<int> a(n+1);
		int reqOr = 0;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			reqOr = reqOr | a[i];
		}

		vector<int> pref(n+2,0), suff(n+2,0);
		for(int i = 1; i <= n; i++) {
			pref[i] = pref[i-1] | a[i];
		}
		for(int i = n; i >= 1; i--) {
			suff[i] = suff[i+1] | a[i];
		}
		int max_data = 0;
		for(int i = 1; i <= n; i++) {
			if ((pref[i-1] | suff[i+1]) == reqOr) {
                max_data = max(max_data, a[i]);
            }
		}
        cout << max_data << endl;
	}
}