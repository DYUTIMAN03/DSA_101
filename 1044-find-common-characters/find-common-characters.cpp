class Solution {
public:
    // Function to count the frequency of each character
    void fillcount(string word, int count[26]){
        for(char ch: word){
            count[ch - 'a']++;
        }
    }

    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        int count[26] = {0};

        // Initialize count using the first word
        fillcount(words[0], count);

        // Compare character frequencies with every remaining word
        for(int i = 1; i < words.size(); i++){
            int temp[26] = {0};
            fillcount(words[i], temp);

            // Keep the minimum frequency of each character
            for(int j = 0; j < 26; j++){
                count[j] = min(count[j], temp[j]);
            }
        }
        // Add common characters according to their frequency
        for(int i = 0; i < 26; i++){
            int c = count[i];

            while(c--){
                result.push_back(string(1, i + 'a'));
            }
        }
        return result;
    }
};

/*
Approach:
1. Create a frequency array to store the character counts of the first word.
2. Iterate through the remaining words.
3. Create a temporary frequency array for each word.
4. Compare both arrays and keep the minimum frequency of each character.
5. After processing all words, add each character to the result
   according to its remaining frequency.
6. Return the result.

TC: O(n * k + 26 * n) - n is the number of words and k is the average word length.
SC: O(26) - Two fixed-size frequency arrays, excluding the output.
*/