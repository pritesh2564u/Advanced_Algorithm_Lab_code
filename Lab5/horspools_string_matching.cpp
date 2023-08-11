#include <bits/stdc++.h>

using namespace std;

int main()
{
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);
    int n = text.size(), m = pattern.size();
    
    unordered_map<char, int> mp;
    for(int i = 0 ; i < m - 1 ; i++) {
        mp[pattern[i]] = m - 1 - i;
    }
    
    for(int i = 0 ; i < n ; i++) {
        if(!mp[text[i]]) {
            mp[text[i]] = m;
        }
    }
    
    int j = 0, matches = 0;
    while(j + m <= n) {
        if(text[j + m - 1] = pattern[m - 1]) {
            int i = m - 2;
            while(i >= 0 && pattern[i] == text[j + i])
                i--;
            if(i == -1)
                matches++;
        }
        j += mp[text[j + m - 1]];
    }

    cout << "No. of pattern string present in text string is " << matches << endl;
    return 0;
}