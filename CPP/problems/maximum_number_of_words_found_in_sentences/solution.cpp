class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
    int n = sentences.size();
    int max = 0;

    for (auto s:sentences) {
        int counter = 0;
        for (auto c:s) {
            if (c==' ') counter++;
        }
        if (max < counter) max = counter;
    }
    return max + 1;
}
};