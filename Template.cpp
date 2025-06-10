//1. HashMap / Frequency
unordered_map<int, int> freq;
for (int x : arr) freq[x]++; // Count frequency

// Reverse map: frequency -> list of numbers
unordered_map<int, vector<int>> rev;
for (auto &[num, f] : freq)
    rev[f].push_back(num);

//2. Sliding Window

int left = 0, sum = 0;
for (int right = 0; right < n; ++right) {
    sum += arr[right];
    while (sum > k) {
        sum -= arr[left++];
    }
    // do something with window [left, right]
}

//3. Prefix Sum
vector<int> prefix(n + 1, 0);
for (int i = 0; i < n; ++i)
    prefix[i + 1] = prefix[i] + arr[i];

// sum of arr[i...j] = prefix[j + 1] - prefix[i]


//4. Binary Search
//On Answer Space (e.g. min/max value)
int low = 1, high = 1e9, ans = -1;
while (low <= high) {
    int mid = (low + high) / 2;
    if (check(mid)) {
        ans = mid;
        high = mid - 1;
    } else {
        low = mid + 1;
    }
}

//First/Last Occurrence:
int low = 0, high = n - 1, res = -1;
while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == target) {
        res = mid;
        high = mid - 1; // for first occurrence
    } else if (arr[mid] < target) low = mid + 1;
    else high = mid - 1;
}

//5. DFS/BFS (Grid/Graph)
//DFS Grid:

void dfs(int x, int y) {
    if (outOfBoundsOrVisited(x, y)) return;
    visited[x][y] = true;
    for (auto &[dx, dy] : dir)
        dfs(x + dx, y + dy);
}

//BFS Shortest Path (Unweighted Graph):
queue<pair<int, int>> q;
q.push({sx, sy});
dist[sx][sy] = 0;

while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    for (auto &[dx, dy] : dir) {
        int nx = x + dx, ny = y + dy;
        if (valid(nx, ny) && dist[nx][ny] == -1) {
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
}


// 6. Dynamic Programming (DP)
//Climb Stairs (1D):
vector<int> dp(n + 1, 0);
dp[0] = 1;
for (int i = 1; i <= n; ++i) {
    if (i - 1 >= 0) dp[i] += dp[i - 1];
    if (i - 2 >= 0) dp[i] += dp[i - 2];
}

//0/1 Knapsack:
vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
for (int i = 1; i <= n; ++i) {
    for (int w = 0; w <= W; ++w) {
        dp[i][w] = dp[i - 1][w];
        if (w - wt[i - 1] >= 0)
            dp[i][w] = max(dp[i][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
    }
}

//7. Two Pointers
//Longest Substring Without Repeat:

unordered_set<char> s;
int left = 0, ans = 0;
for (int right = 0; right < n; ++right) {
    while (s.count(str[right])) {
        s.erase(str[left++]);
    }
    s.insert(str[right]);
    ans = max(ans, right - left + 1);
}


//8. Merge Two Sorted Arrays:

int i = 0, j = 0;
vector<int> res;
while (i < n && j < m) {
    if (a[i] < b[j]) res.push_back(a[i++]);
    else res.push_back(b[j++]);
}
while (i < n) res.push_back(a[i++]);
while (j < m) res.push_back(b[j++]);


