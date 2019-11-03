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
 
struct Pos {
    int x, y;
};
 
struct Snake_positions { 
   int row, col, common_row, common_col;
   struct Pos head_pos;
   struct Pos tail_pos;
};
 
int n, m, t;
string sheet[2001];
 
int main() {
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
 
    // freopen("Task.in","r",stdin);
    // freopen("Task.out","w",stdout);
 
    cin>>t;
    while(t--) {
        cin>>n>>m;
        for(int i = 0; i < n; i++)
            cin>>sheet[i];
 
        struct Snake_positions s[26];
        for(int i = 0; i < 26; i++) {
            s[i].row = s[i].col = s[i].common_row = s[i].common_col = -1;
        }
        bool invalid_sheet = 0;
 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(sheet[i][j] == '.')
                    continue;
                int curr = sheet[i][j]-'a';
                if(s[curr].row == -1) {
                    s[curr].row = s[curr].head_pos.x = s[curr].tail_pos.x = i;
                    s[curr].col = s[curr].head_pos.y = s[curr].tail_pos.y = j;
                }
                else {
                    if(s[curr].common_row == -1 && s[curr].common_col == -1) {
                        if(i == s[curr].row) {
                            s[curr].common_row = i;
                        }
                        else if(j == s[curr].col) {
                            s[curr].common_col = j;
                        }
                        else {
                            invalid_sheet = 1;
                        }
                    }
                    else {
                        if(i != s[curr].common_row && j != s[curr].common_col) {
                            invalid_sheet = 1;
                        }
                    }
                    s[curr].tail_pos.x = i;
                    s[curr].tail_pos.y = j;
                }
                if(invalid_sheet)
                    break;
            }
            if(invalid_sheet)
                break;
        }
 
        if(invalid_sheet) {
            cout<<"NO\n";
            continue;
        }
 
        for(int i = 25; i >=0; i--) {
            if(s[i].common_row != -1) {
                for(int j = s[i].head_pos.y; j < s[i].tail_pos.y + 1; j++) {
                    if(sheet[s[i].common_row][j] < 'a' + i) {
                        invalid_sheet = 1;
                        break;
                    }
                }
            }
            if(s[i].common_col != -1) {
                for(int j = s[i].head_pos.x; j < s[i].tail_pos.x + 1; j++) {
                    if(sheet[j][s[i].common_col] < 'a' + i) {
                        invalid_sheet = 1;
                        break;
                    }
                }
            }
        }
        if(invalid_sheet) {
            cout<<"NO\n";
            continue;
        }
 
        cout<<"YES\n";
        int last_snake_idx = -1;
        for(int i = 25; i >=0; i--) {
            if(s[i].row == -1)
                continue;
            last_snake_idx = i;
            break;
        }
 
        cout<<last_snake_idx + 1<<"\n";
        struct Snake_positions res[26], las;
 
        for(int i = last_snake_idx; i >=0; i--) {
            if(s[i].row == -1) {
                res[i] = las;
            }
            else {
                las = s[i];
                res[i] = s[i];
            }
        }
        for(int i = 0; i < last_snake_idx + 1; i++) {
            cout<<res[i].head_pos.x+1<<" "<<res[i].head_pos.y+1<<" "<<res[i].tail_pos.x+1<<" "<<res[i].tail_pos.y+1<<"\n";
        }
    }
    
}