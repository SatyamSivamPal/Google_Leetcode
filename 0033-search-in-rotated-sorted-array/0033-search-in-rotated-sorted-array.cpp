class Solution {
    int pivot(vector<int>& nums, int n){
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;

        while(s<e){
            if(nums[mid] >= nums[0]){
                s = mid +1;
            }
            else{
                e = mid;
            }
            mid = s + (e-s)/2;
        }
        return s;
    }
    int binarysearch(vector<int>& nums ,int start , int end,int k){
        
        int s = start;
        int e = end;
        int mid= s + (e-s)/2;

        while(s<=e){
             if(nums[mid] == k){
                return mid;
            }
            else if (nums[mid] > k){
                e = mid -1;
            }
            else{
                s = mid + 1;
            }
            mid = s + (e-s)/2;
        }
        return -1;
       
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        // int piv = pivot(nums,n);
        
        // if(target >= nums[piv] && target <= nums[n-1]){
        //    return binarysearch(nums,piv,n-1,target);
        // }
        // else{
        //    return binarysearch(nums,0,piv-1,target);
        // }

        int s = 0;
        int e = n-1;

        while(s<=e)
        {
            int mid = s + (e-s)/2;

            if(nums[mid] == target)
            {
                return mid;
            }

            //left sorted
            if(nums[s] <= nums[mid])
            {
                if(target >= nums[s] && target <= nums[mid])
                {
                    e = mid - 1;
                }
                else{
                    s = mid + 1;
                }
            }

            //right sorted
            else{
                if(target >= nums[mid] && target <= nums[e])
                {
                    s = mid + 1;
                }
                else{
                    e = mid - 1;
                }
            }
        }

        return -1;

    }
};