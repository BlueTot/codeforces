#include <bits/stdc++.h>

long long expM(long long a, long long n, long long m) {
    long long res = 1;
    while (n > 0) {
        if (n & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        n >>= 1;
    }
    return res;
}

std::vector<std::vector<char>> rabin_karp2d(
    std::vector<std::vector<char>> const& s, 
    std::vector<std::vector<char>> const& t
) {

    const int p = 31;
    const int m = 1e9 + 9;
    int TRow = t.size(), TCol = t[0].size();
    int SRow = s.size(), SCol = s[0].size();
    const int N = std::max({TRow, TCol, SRow, SCol});

    // precompute powers of p mod m
    std::vector<long long> p_pow(N + 1), inv_p_pow(N + 1);
    p_pow[0] = 1;
    for (int i = 1; i < (int) p_pow.size(); i++) {
        p_pow[i] = (p_pow[i-1] * p) % m;
    }

    // precompute inverse powers of p mod m
    inv_p_pow[N] = expM(p_pow[N], m - 2, m);
    for (int i = N - 1; i >= 0; i--) {
        inv_p_pow[i] = (inv_p_pow[i+1] * p) % m;
    }
    

    // first we compute the row hash prefixes
    std::vector<std::vector<long long>> row_hash(
        TRow, std::vector<long long>(TCol + 1)
    );
    for (int i = 0; i < TRow; i++) {
        for (int j = 0; j < TCol; j++) {
            row_hash[i][j+1] = (row_hash[i][j] + (t[i][j] - 'a' + 1) * p_pow[j]) % m;
        }
    }

    // hasing a row starting at row, col with size SCol
    auto hashRow = [&](int row, int start_col) {
        long long raw = (row_hash[row][start_col + SCol] + m - row_hash[row][start_col]) % m;
        return (raw * inv_p_pow[start_col]) % m;
    };

    // next we compute the column hash prefixes from the row hash prefixes
    // this hashes a matrix into a single number via double hashing
    std::vector<std::vector<long long>> mat_hash(
        TCol, std::vector<long long>(TRow + 1)
    );

    for (int j = 0; j < TCol - SCol + 1; j++) {
        for (int k = 0; k < TRow; k++) {
            mat_hash[j][k+1] = (mat_hash[j][k] + hashRow(k, j) * p_pow[k]) % m;
        }
    }

    // hashing a matrix starting at row, col with size SRow, SCol
    auto hashMat = [&](int row, int col) {
        long long raw = (mat_hash[col][row + SRow] + m - mat_hash[col][row]) % m;
        return (raw * inv_p_pow[row]) % m;
    };

    // lastly we compute the hash of the needle
    std::vector<long long> sRowHashes(SRow);
    for (int i = 0; i < SRow; i++) {
        long long h_s_row = 0;
        for (int j = 0; j < SCol; j++) {
            h_s_row = (h_s_row + (s[i][j] - 'a' + 1) * p_pow[j]) % m;
        }
        sRowHashes[i] = h_s_row;
    }
    long long h_s = 0;
    for (int i = 0; i < SRow; i++) {
        h_s = (h_s + sRowHashes[i] * p_pow[i]) % m;
    }

    // searching
    std::vector<std::vector<int>> iePrefix(TRow + 1, std::vector<int>(TCol + 1, 0));
    std::vector<std::vector<char>> result(TRow, std::vector<char>(TCol, '.'));

    for (int i = 0; i + SRow - 1 < TRow; i++) {
        for (int j = 0; j + SCol - 1 < TCol; j++) {
            // inclusion exclusion
            if (hashMat(i, j) == h_s) {
                iePrefix[i][j]++;
                iePrefix[i+SRow][j]--;
                iePrefix[i][j+SCol]--;
                iePrefix[i+SRow][j+SCol]++;
            }
        }
    }

    // populating the result matrix
    for (int i = 0; i <= TRow; i++) {
        for (int j = 0; j <= TCol; j++) {
            if (i > 0)
                iePrefix[i][j] += iePrefix[i-1][j];
            if (j > 0)
                iePrefix[i][j] += iePrefix[i][j-1];
            if (i > 0 && j > 0)
                iePrefix[i][j] -= iePrefix[i-1][j-1];
            if (iePrefix[i][j] > 0) {
                result[i][j] = t[i][j]; // copy
            }
        }
    }

    return result;
}

int main() {

    // io optimisation
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    // take input
    int rk, ck, rh, ch;
    std::cin >> rk >> ck;
    std::vector<std::vector<char>> key(rk, std::vector<char>(ck, 0));
    std::string s;

    for (int i = 0; i < rk; i++) {
        std::cin >> s;
        for (int j = 0; j < ck; j++) {
            key[i][j] = s[j];
        }
    }

    std::cin >> rh >> ch;
    std::vector<std::vector<char>> haystack(rh, std::vector<char>(ch, 0));
    for (int i = 0; i < rh; i++) {
        std::cin >> s;
        for (int j = 0; j < ch; j++) {
            haystack[i][j] = s[j];
        }
    }

    std::vector<std::vector<char>> result = rabin_karp2d(key, haystack);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            std::cout << result[i][j];
        }
        std::cout << "\n";
    }

    return 0;
}
