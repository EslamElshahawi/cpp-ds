class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string firstWord;
        string secondWord;

        for(int i= 0; i < word1.size(); i++){
            firstWord += word1[i];
        }
        for(int i = 0; i < word2.size(); i++){
            secondWord += word2[i];
        }
        return firstWord == secondWord;
    }
};