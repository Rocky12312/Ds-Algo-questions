class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
      set<string> set_word(wordList.begin(), wordList.end());
      set<string> visited;
      queue<string> q;
      q.emplace(beginWord);
      visited.emplace(beginWord);
      int ladder = 1;
      while (!q.empty()) {
          int len = q.size();
          while (len--) {
              string word = q.front();
              q.pop();
              if (word == endWord) {
                  return ladder;
              }
              for (int j = 0; j < word.size(); ++j) {
                  string next = word;
                  for (int k = 0; k < 26; ++k) {
                      next[j] = 'a' + k;
                      if (!visited.count(next) and set_word.count(next)) { 
                          visited.emplace(next);
                          q.push(next);
                      }
                  }
              }
          }
          ladder++;
      }
      return 0;
  }
};

