#include <iostream>

using namespace std;

int main()
{
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern: ";
    cin >> pattern;
    int n = text.size(), m = pattern.size();
    
    int matches = 0;
    for(int i = 0 ; i < n - m + 1 ; i++) {
        int j;
        for(j = 0 ; j < m ; j++) {
            if(text[i + j] != pattern[j])
                break;
        }
        if(j == m)
            matches++;
    }
    cout << "No. of pattern string present in text string is " << matches << endl;
    return 0;
}