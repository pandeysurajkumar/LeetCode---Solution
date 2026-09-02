class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // data set required
        unordered_set<string> words(wordList.begin(),wordList.end());
        // check if not exist any path
        if(!words.count(endWord))
            return 0;
    
        unordered_set<string> beginSet;
        unordered_set<string> endSet;
        beginSet.insert(beginWord);
        endSet.insert(endWord);

        int level = 1;

        while(!beginSet.empty() && !endSet.empty())
        {
            // apply for sorter one
            if(beginSet.size()>endSet.size())
            {
                swap(beginSet,endSet);
            }

            unordered_set<string> nextLevel;

            for(string word : beginSet)
            {
                for(int i=0;i<word.size();i++)
                {
                    char original = word[i];
                    for(char ch = 'a'; ch<='z';ch++)
                    {
                        if(ch == original)
                            continue;
                        word[i] = ch;
                        if(endSet.count(word))
                        {
                            return level+1;
                        }

                        if(words.count(word))
                        {
                            nextLevel.insert(word);
                            words.erase(word);
                        }
                    }
                    word[i] = original;
                }
            }
            beginSet = nextLevel;
            level++;
        }
        return 0;

    }
};