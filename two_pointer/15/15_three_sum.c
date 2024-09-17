class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // two pointer
            int left = i + 1;
            int right = nums.size() - 1;
            int fixed = nums[i];
            while (left < right)
            {
                int sum = fixed + nums[left] + nums[right];
                if (sum == 0)
                {
                    result.push_back({fixed, nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
                else if (sum < 0)
                {
                    left++;
                }
                else
                    right--;
            }
        }
        return result;
    }
};