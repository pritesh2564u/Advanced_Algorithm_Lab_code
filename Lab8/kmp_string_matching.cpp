#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

void compute_prefix_function(string pattern, vector<int>& pi) {
    int m = pattern.size();
    pi[1] = 0;
    int k = 0;
    
    for(int q = 2 ; q <= m ; q++) {
        while(k > 0 && pattern[k] != pattern[q - 1])
        k = pi[k];
        if(pattern[k] == pattern[q - 1])
        k++;
        pi[q] = k;
    }
}

void kmp_matcher(string text, string pattern, vector<int>& pi) {
    int n = text.length();
    int m = pattern.length();
    int q = 0;
    
    for(int i = 1 ; i <= n ; i++) {
        while(q > 0 && pattern[q] != text[i - 1])
        q = pi[q];
        if(pattern[q] == text[i - 1])
        q++;
        if(q == m) {
        cout << "shift occurs at " << i - m << endl;
        q = pi[q];
        }
    }
}

int main() {
    string text, pattern;
    cin >> text >> pattern;
    vector<int> pi(pattern.size() + 1);
    
    compute_prefix_function(pattern, pi);
    kmp_matcher(text, pattern, pi);
    return 0;
}
