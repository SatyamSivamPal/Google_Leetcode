class Solution {
public:
    int firstOccurence(vector<int>& nums, int n, int k)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;

    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (nums[mid] == k)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (nums[mid] < k)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int lastOccurence(vector<int>& nums, int n, int k)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;

    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (nums[mid] == k)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (nums[mid] < k)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        // int a = firstOccurence(nums,n,target );
        // int b = lastOccurence(nums , n , target);
       vector<int>::iterator lower, upper;

        lower = lower_bound(nums.begin(), nums.end(), target);
        upper = upper_bound(nums.begin(), nums.end(), target);

        // cout<<upper_bound(nums.begin(),nums.end(),target)-lower_bound(nums.begin(),nums.end(),target);
        if (lower != nums.end() && *lower == target) 
        {
        ans.push_back(std::distance(nums.begin(), lower));
        ans.push_back(std::distance(nums.begin(), upper) - 1);
        } 
        else 
        {
        ans.push_back(-1);
        ans.push_back(-1);
        }

        return ans;
    }
};