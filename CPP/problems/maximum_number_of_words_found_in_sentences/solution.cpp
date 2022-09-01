class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
    int n = sentences.size();
    int max = 0;

    for (int i = 0; i < n; i++) {
        int counter = 0;
        for (int j = 0; j < sentences[i].size(); j++) {
            if (sentences[i][j] == ' ') counter++;
        }
        if (max < counter) max = counter;
    }
    return max + 1;
}
};