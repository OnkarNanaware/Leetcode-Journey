class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
           vector<int> temp = arr;

    // Sort the copy
    sort(temp.begin(), temp.end());

    unordered_map<int, int> rank;
    int r = 1;

    // Assign ranks only to unique elements
    for (int x : temp) {
        if (rank.find(x) == rank.end()) {
            rank[x] = r++;
        }
    }//this part is most important 

    // Replace each element with its rank
    vector<int> ans;
    for (int x : arr)
        ans.push_back(rank[x]);

    return ans;
}
};