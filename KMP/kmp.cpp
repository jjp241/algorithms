#include <bits/stdc++.h>

void countThePrefsuf(std::string pattern, int prefsuf[], int m){
    for (int i = 0; i < m; i++)
        prefsuf[i] = 0;
    int i = 0; // the first iterator
    int j = 1; // the second iterator
    prefsuf[0] = 0;
    while (j < m){
        if (pattern[i] == pattern[j]){
            prefsuf[j] = prefsuf[i] + 1;
            i++;
            j++;
        }
        else if (i > 0)
            i = prefsuf[i-1];
        else{
            prefsuf[j] = 0;
            j++;
        }
    }
}

int kmp(std::string word, std::string pattern){
    int n = word.length();
    int m = pattern.length();
    int *prefsuf = new int[m]; // the prefix-sufix array for pattern
    countThePrefsuf(pattern, prefsuf, m);

    /// <! THE MAIN ALGORITHM !> ///
    int j = 0; // the iterator in prefix-sufix array
    int x = -1; // the index of pattern found
    for (int i = 0; i < n; i++){
        if (word[i] == pattern[j])
            j++;
        else if (j > 0)
            j = prefsuf[j-1];
        if (j >= m){ // pattern found
            x = i - m + 1;
            break;
        }
    }
    return x+1;
}

int main(){
    std::string word; // the word to find pattern in
    std::string pattern; // the pattern to find
    int n; // the index of pattern in the word
    
    std::cout << "Input the word: ";
    std::cin >> word;
    std::cout << "Input the pattern: ";
    std::cin >> pattern;

    n = kmp(word, pattern);
    if (n != -1)
        std::cout << "The index of pattern is: " << n << "\n";
    else
        std::cout << "The pattern was not found in the word\n";
}
