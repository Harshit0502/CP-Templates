
const int P = 31;
const int MOD = 1e9 + 9;

long long poly_hash(const string& s) {
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % MOD;
        p_pow = (p_pow * P) % MOD;
    }
    return hash_value;
}

struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<long long>()(((long long)p.first) ^ (((long long)p.second) << 32));
    }
};

const int P = 31;
const int MOD = 1e9 + 9;

long long poly_hash(const string& s) {
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % MOD;
        p_pow = (p_pow * P) % MOD;
    }
    return hash_value;
}


// Count frequency of elements efficiently
unordered_map<int, int, custom_hash> freq;
for (int x : a) freq[x]++;

// Use unordered_set safely
unordered_set<int, custom_hash> unique_values;

// Store and look up (x, y) coordinates
unordered_map<pair<int, int>, bool, pair_hash> visited;
