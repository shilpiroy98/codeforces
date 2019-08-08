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

int n, x_king, y_king;
	int mini[9];
	bool possi[9];
	char guy[9];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 //    freopen("Task.in","r",stdin);
	// freopen("Task.out","w",stdout);


	for(int i = 1; i < 9; i++)
		mini[i] = 2000000002;

	cin>>n>>x_king>>y_king;
	int x_piece, y_piece;
	char c;

	for(int i = 0; i < n; i++) {

		cin>>c>>x_piece>>y_piece;

		if(x_piece == x_king) {
			if(y_piece > y_king) {
				if(y_piece - y_king < mini[1]) {
					mini[1] = y_piece - y_king;
					guy[1] = c;
					possi[1] = 1;
				}
			}
			else {
				if(abs(y_piece - y_king) < mini[2]) {
					mini[2] = abs(y_piece - y_king);
					guy[2] = c;
					possi[2] = 1;
				}
			}
		}

		if(y_piece == y_king) {
			if(x_piece > x_king) {
				if(x_piece - x_king < mini[3]) {
					mini[3] = x_piece - x_king;
					guy[3] = c;
					possi[3] = 1;
				}
			}
			else{
				if(abs(x_piece - x_king) < mini[4]) {
					mini[4] = abs(x_piece - x_king);
					guy[4] = c;
					possi[4] = 1;
				}
			}
		}

		if((x_piece - x_king) == (y_piece - y_king)) {
			if(x_piece > x_king){
				if(abs(x_piece - x_king) < mini[5]) {
					mini[5] = abs(x_piece - x_king);
					guy[5] = c;
					possi[5] = 1;
				}
			}
			else{
				if(abs(x_piece - x_king) < mini[6]) {
					mini[6] = abs(x_piece - x_king);
					guy[6] = c;
					possi[6] = 1;
				}
			}
		}

		if((x_piece - x_king) == -(y_piece - y_king)) {
			if(x_piece > x_king){
				if(abs(x_piece - x_king) < mini[7]) {
					mini[7] = abs(x_piece - x_king);
					guy[7] = c;
					possi[7] = 1;
				}
			}
			else{
				if(abs(x_piece - x_king) < mini[8]) {
					mini[8] = abs(x_piece - x_king);
					guy[8] = c;
					possi[8] = 1;
				}
			}
		}

	}


	for (int i = 1; i < 5; i++){
		if(possi[i] && (guy[i] == 'R' || guy[i] == 'Q')) {
			cout<<"YES";
			return 0;
	    }
	}

	for (int i = 5; i < 9; i++){
		if(possi[i] && (guy[i] == 'B' || guy[i] == 'Q')) {
			cout<<"YES";
			return 0;
	    }
	}

	cout<<"NO";
	return 0;
}
