bool compare(string &num1, string &num2){
        if(num1.size()!=num2.size()){
            return num1.size()>num2.size();
        }
        return num1>num2;
    }
class Solution {
public:
    
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        priority_queue<string, vector<string>, decltype(&compare)> minHeap(&compare);
        for(int i=0;i<k;i++){
            minHeap.push(nums[i]);
        }
        for(int i=k;i<n;i++){
            string curr = minHeap.top();
            if(!compare(curr,nums[i])){
                minHeap.pop();
                minHeap.push(nums[i]);
            } 
        }
        return minHeap.top();
    }
};