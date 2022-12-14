// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    bool isValid(vector<vector<int>> &m, int x, int y, int n, vector<vector<bool>> &vis) {
        return x >= 0 && y >= 0 && x < n && y < n && m[x][y] == 1 && vis[x][y] == false;
    }

    char direction(int x, int y) {
        if (x == 0 && y == 1) return 'R';
        else if (x == 0 && y == -1) return 'L';
        else if (x == 1 && y == 0) return 'D';
        else if (x == -1 && y == 0) return 'U';
    }

    void solve(vector<vector<int>> &m, int x, int y, int n, string t, vector<string> &res, vector<pair<int, int>> &dir, vector<vector<bool>> &vis) {
        if (n - 1 == x && y == n - 1) {
            res.push_back(t);
            return;
        }
        for (auto &it : dir) {
            int x1 = it.first;
            int y1 = it.second;
            int X = x1 + x;
            int Y = y + y1;
            if (isValid(m, X, Y, n, vis)) {
                t.push_back(direction(x1, y1));
                vis[X][Y] = true;
                solve(m, X, Y, n, t, res, dir, vis);
                t.pop_back();
                vis[X][Y] = false;
            }
        }
    }
public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> res;
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        vis[0][0] = true;
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, { -1, 0}, {0, -1}};
        if (m[0][0] == 0) return res;
        solve(m, 0, 0, n, "", res, dir, vis);
        return res;
    }
};




// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
