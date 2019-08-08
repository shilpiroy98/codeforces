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

long long int max_dist[2002];
vector <pair<long long int, long long int>> sorted_by_dist;

long long int cal_dist(long long int x1, long long int y1, long long int x2, long long int y2) {
     return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long int n, x1, y1, x2, y2, p1, p2, min_rad = 1e16, d1, d2;
    cin>>n>>x1>>y1>>x2>>y2;
    for(int i = 0; i < n; i++) {
        cin>>p1>>p2;
        d1 = cal_dist(p1, p2, x1, y1);
        d2 = cal_dist(p1, p2, x2, y2);
        sorted_by_dist.push_back(make_pair(d1, d2));
    }
    sort(sorted_by_dist.begin(), sorted_by_dist.end());
    max_dist[n-1] = sorted_by_dist[n-1].second;
    
    for(int i = n - 2; i >= 0; i--) {
        max_dist[i] = max(max_dist[i+1], sorted_by_dist[i].second);
    }
    min_rad = min(max_dist[0], sorted_by_dist[n-1].first);
    for(int i = 0; i < n; i++) {
        min_rad = min(min_rad, max_dist[i+1] + sorted_by_dist[i].first);
    }
    cout<<min_rad;
}