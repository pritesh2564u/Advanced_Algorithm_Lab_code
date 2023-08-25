#include <iostream>

using namespace std;

void rabin_karp_matcher(string text, string pattern, int d, int q) {
    int n = text.length();
    int m = pattern.length();

    int h = 1;
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    int p = 0;
    int t = 0;

    for (int i = 0; i < m; i++) {
        p = ((d * p) + pattern[i] - '0') % q;
        t = ((d * t) + text[i] - '0') % q;
    }

    for (int s = 0; s <= n - m; s++) {
        if (p == t) {
            if (text.substr(s, m) == pattern) {
                cout << "Shift occurs at index " << s << endl;
            }
        }
        if (s < n - m) {
            t = (d * (t - (text[s] - '0') * h) + (text[s + m] - '0')) % q;
            if (t < 0) {
                t += q;
            }
        }
    }
}

int main() {
    string text, pattern;
    cin >> text >> pattern;
    int q;
    cin >> q;
    rabin_karp_matcher(text, pattern, 10, q);
    return 0;
}