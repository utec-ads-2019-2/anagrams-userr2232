#include <set>
#include <iostream>
#include <map>

using namespace std;

int main() {
    string word;
    map<multiset<char>, string > words_with_chars;
    map<string,bool> relative_anagrams;
    while(cin >> word, word != "#") {
        multiset<char> chars_of_word;
        for(int i = 0; i < word.length(); ++i) {
            chars_of_word.insert(word[i] > 'Z' ? word[i]-('a'-'A') : word[i]);
        }
        if(words_with_chars.count(chars_of_word)) {
            relative_anagrams[word] = false;
            relative_anagrams[words_with_chars[chars_of_word]] = false;
        }
        else {
            relative_anagrams[word] = true;
            words_with_chars[chars_of_word] = word;
        }
    }
    for(map<string,bool>::iterator it = relative_anagrams.begin(); it != relative_anagrams.end(); it++) {
        if(it->second) cout << it->first << endl;
    }
}
