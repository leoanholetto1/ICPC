#include <stdio.h>
#include <algorithm>
#include <memory>
#include <vector>
#include <cmath>
 
constexpr int maxN = 2e7 + 1000;
typedef long long ll;
constexpr ll INF = 8e18;
 
// Lowercase Trie
constexpr int ALPHABET_SIZE = 10;
int trie[maxN][ALPHABET_SIZE] = {{0}};
class Trie {
 
    int n, nNodes;
 
private:
 
public:
    Trie() : n(0), nNodes(1) {
        //this->root = this->CreateNode(0);
    }
 
    void Insert(const std::vector<int>& num) {
        this->n++;
        int node = 0;
 
        int i = 0;
        while (i < num.size() && trie[node][num[i]]) {
            node = trie[node][num[i]];
            i++;
        }
 
        while (i < num.size()) {
            trie[node][num[i]] = nNodes++;
            node = trie[node][num[i]];
            i++;
        }
    }
 
    int GetMinDigit(int d, int node) {
        int mnd = 10, pos = 0;
        for (int i = 9; i >= 0; i--)
            if (trie[node][i] && (i + d) % 10 < mnd) { mnd = (i + d) % 10; pos = i; }
        return pos;
    }
 
    ll GetMin(const std::vector<int>& num) {
        int node = 0;
        ll r = 0;
        int i = 0;
        while (i < num.size()) {
            int mxd = GetMinDigit(num[i], node);
            node = trie[node][mxd];
            mxd = (num[i] + mxd) % 10;
            r = (r * 10 + mxd);
            i++;
        }
        return r;
    }
 
    int GetMaxDigit(int d, int node) {
        int mxd = -1, pos = 0;
        for (int i = 0; i < 10; i++)
            if (trie[node][i] && (i + d) % 10 > mxd) { mxd = (i + d) % 10; pos = i; }
        return pos;
    }
 
    ll GetMax(const std::vector<int>& num) {
        int node = 0;
        ll r = 0;
        int i = 0;
        while (i < num.size()) {
            int mxd = GetMaxDigit(num[i], node);
            node = trie[node][mxd];
            mxd = (num[i] + mxd) % 10;
            r = (r * 10 + mxd);
            i++;
        }
        return r;
    }
 
};
 
int main() {
 
    int n;
    scanf("%d", &n);
    Trie trie = Trie();
    ll num;
    ll min = INF, max = 0;
    std::vector<std::vector<int>> numDigits = std::vector<std::vector<int>>(n, std::vector<int>(19, 0));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &num);
        int d = 18;
        while (num) {
            numDigits[i][d--] = (num % 10);
            num /= 10;
        }
        if (i > 0) {
            min = std::min(min, trie.GetMin(numDigits[i]));
            max = std::max(max, trie.GetMax(numDigits[i]));
        }
        trie.Insert(numDigits[i]);
    }
 
    printf("%lld %lld\n", min, max);
 
    return 0;
}