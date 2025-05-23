
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
