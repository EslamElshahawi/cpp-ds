class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int wordSize = words.size();
        vector<int> commonCharacterCount(26, 0), currentCharacterCount(26, 0);
        vector<string> result;

        for(char &ch : words[0]){
            commonCharacterCount[ch - 'a']++;
        }

        for(int i = 1; i < wordSize; i++){
            fill(currentCharacterCount.begin(), currentCharacterCount.end(), 0);

            for(char &ch : words[i]){
                currentCharacterCount[ch - 'a']++;
            }

            for(int letter = 0; letter < 26; letter++){
                commonCharacterCount[letter] = min(currentCharacterCount[letter], commonCharacterCount[letter]);
            }
        }

        for(int letter = 0; letter < 26; letter++){
            for(int commonCount = 0; commonCount < commonCharacterCount[letter]; commonCount++){
                result.push_back(string(1, letter + 'a'));
            }
        }

        return result;
    }
};