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

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 //    freopen("Task.in","r",stdin);
	// freopen("Task.out","w",stdout);
	int n;
    string a, b;
	int cnt = 0;
	cin>>n>>a>>b;
	for(int i = 0; i < n/2 + n%2 ; i++) {
		if(n%2 == 1 && i == n/2) {
			if(a[i]!=b[i])
				cnt++;
			break;
		}
		int c[4] = { a[i] - '0', a[n-i-1] - '0', b[i] - '0', b[n-i-1] - '0' };
		sort(c,c+4);
		if((c[0] == c[1]) && (c[2] == c[3])) {
			continue;
		}
		else if(((c[0] == c[1]) && (c[1] == c[2])) || (((c[1] == c[2]) && (c[2] == c[3])))) {
			cnt+=1;
		}
		else if(c[0]!=c[1] && c[1]!=c[2] && c[2]!=c[3]) {
			cnt+=2;
		}
		else {
			if(a[i] == a[n-i-1])
				cnt+=2;
			else
				cnt+=1;
		}
	}
	cout<<cnt;
}