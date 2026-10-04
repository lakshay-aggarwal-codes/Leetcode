class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int index = 1;
        while (ss >> word) {
           string pre = word.substr(0, searchWord.size());
            if (pre == searchWord)
              return index;
            index++;
        }
        return   -1;
    }
};