class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> prefixsum(arr.size() + 1, 0);

        for (int i = 0; i < arr.size(); i++)
        {
            prefixsum[i + 1] = prefixsum[i] ^ arr[i];
        }
        vector<int> ans;
        for (const auto &query : queries)
        {
            int left = query[0];
            int right = query[1];

            int result = prefixsum[left] ^ prefixsum[right + 1];
            ans.push_back(result);
        }
        return ans;
    }
};