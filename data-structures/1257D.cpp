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

int t, n, m;

int main() {
	// freopen("Task.in","r",stdin);
 //    freopen("Task.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>t;
	while(t--){
		cin>>n;
		int monsters[n+1];
		int max_pow = -1, max_monster = -1;
		for(int i = 0; i < n; i++){
			cin>>monsters[i];
			max_monster = max(monsters[i], max_monster);
		}
		cin>>m;
		int l[m+1], r[m+1];
		for(int i = 0; i < m; i++) {
			cin>>l[i]>>r[i];
			max_pow = max(max_pow, l[i]);
		}
		if(max_monster > max_pow) {
			cout<<-1<<"\n";
			continue;
		}
		if(n == 1) {
			cout<<1<<"\n";
			continue;
		}
		set <pair<int,int> > s,p;
		for(int i = 0; i < m; i++) {
			s.insert(make_pair(r[i], l[i]));
		}
		int max_guy = -1;
		for(set<pair<int,int> >::reverse_iterator it = s.rbegin(); it!=s.rend(); it++) {
			if(it->second > max_guy) {
				p.insert(make_pair(it->first, it->second));
			}
			max_guy = max(it->second, max_guy);
		}
		int start = 0, end = 1, current_max = max(monsters[0], monsters[1]), sum = 0;
		while(end < n) {
			set<pair<int,int> >:: iterator it = p.lower_bound(make_pair(end-start+1,0));
			if(it != p.end() && (*it).second >= current_max){
				end++;
				current_max = max(current_max, monsters[end]);
			}
			else {
				sum++;
				start = end;
				end = start + 1;
				current_max = max(monsters[start], monsters[end]);
			}
		}
		sum++;
		cout<<sum<<"\n";
	}
 
}