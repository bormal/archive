// https://www.hackerrank.com/challenges/ctci-ransom-note/submissions/code/177362658

#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> createHash(vector<string> const & text) {
    unordered_map<string, int> words;
    for(auto const &word: text) {
        words[word]++;
    }

    return words;
}

bool check(vector<string> const & magazine, vector<string> const & note) {
    unordered_map<string, int> magWords = createHash(magazine);
    unordered_map<string, int> noteWords = createHash(note);

    for(auto &word: noteWords) {
        if(magWords[word.first] < word.second) {
            // cout << word.first << " in note " << word.second << " in mag " << magWords[word.first] << endl;
            return false;
        }
    }

    return true;
}

int main()
{
    int m;
    int n;
    cin >> m >> n;

    vector<string> magazine;
    string word;
    for(int i = 0; i < m; i++) {
        cin >> word;
        magazine.emplace_back(word);
    }

    vector<string> note;
    for(int i = 0; i < n; i++) {
        cin >> word;
        note.emplace_back(word);
    }

    bool result = check(magazine, note);

    cout << (result ? "Yes" : "No") << endl;

    return 0;
}
