int missingNumber(vector<int> &nums)
{
    // sort(nums.begin(), nums.end());
    // int size = nums.size();
    // // int lastElement = nums[size-1];
    // int totalSum = 0;
    // int requiredSum = 0;
    // for(auto i: nums) {
    //     totalSum += i;
    // }
    // requiredSum = size * (size+1) /2;
    // return requiredSum - totalSum;

    // appr 2
    int result = nums.size(); // initialize result to size of vector
    int i = 0;                // initialize i to 0
    for (int num : nums)
    {                  // for each number in vector
        result ^= num; // XOR result with number
        result ^= i;   // XOR result with i
        i++;           // increment i
    }
    return result; // return result that is the missing number
}