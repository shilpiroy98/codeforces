#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

int n, m;
int t,l,r, a[1003];
set<pair<int, int> > sorted_intervals;
vector<pair<int,int> > intervals, v;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

 //    freopen("Task.in","r",stdin);
	// freopen("Task.out","w",stdout);

	cin>>n>>m;
	for(int i = 0; i < m ; i++) {
		cin>>t>>l>>r;
		if(t == 1)
			sorted_intervals.insert(make_pair(l,r));
		else
			v.push_back(make_pair(l,r));
	}


	for(set<pair<int,int> >::iterator it = sorted_intervals.begin(); it!=sorted_intervals.end(); it++) {
		if(it == sorted_intervals.begin()) {
			intervals.push_back(make_pair(it->first, it->second));
		}
		else {
			int l1 = intervals.back().first, r1 = intervals.back().second;
			if(it->first<=r1) {
				intervals.pop_back();
				intervals.push_back(make_pair(l1, max(it->second, r1)));
			}
			else {
				intervals.push_back(make_pair(it->first, it->second));
			}
		}
	}

	for(int i = 0; i <v.size(); i++) {
		for(int j = 0; j < intervals.size(); j++) {
			if(v[i].first>=intervals[j].first && v[i].second<=intervals[j].second) {
				cout<<"NO";
				return 0;
			}
		}
	}
	
	for(int i = 1; i < n + 1; i++)
		a[i] = 2000 - i;
	for(int i = 0; i < intervals.size(); i++) {
		sort(a + intervals[i].first, a + intervals[i].second + 1);
	}
	
	cout<<"YES\n";
	for(int i = 1; i < n + 1; i++)
		cout<<a[i]<<" ";

}
