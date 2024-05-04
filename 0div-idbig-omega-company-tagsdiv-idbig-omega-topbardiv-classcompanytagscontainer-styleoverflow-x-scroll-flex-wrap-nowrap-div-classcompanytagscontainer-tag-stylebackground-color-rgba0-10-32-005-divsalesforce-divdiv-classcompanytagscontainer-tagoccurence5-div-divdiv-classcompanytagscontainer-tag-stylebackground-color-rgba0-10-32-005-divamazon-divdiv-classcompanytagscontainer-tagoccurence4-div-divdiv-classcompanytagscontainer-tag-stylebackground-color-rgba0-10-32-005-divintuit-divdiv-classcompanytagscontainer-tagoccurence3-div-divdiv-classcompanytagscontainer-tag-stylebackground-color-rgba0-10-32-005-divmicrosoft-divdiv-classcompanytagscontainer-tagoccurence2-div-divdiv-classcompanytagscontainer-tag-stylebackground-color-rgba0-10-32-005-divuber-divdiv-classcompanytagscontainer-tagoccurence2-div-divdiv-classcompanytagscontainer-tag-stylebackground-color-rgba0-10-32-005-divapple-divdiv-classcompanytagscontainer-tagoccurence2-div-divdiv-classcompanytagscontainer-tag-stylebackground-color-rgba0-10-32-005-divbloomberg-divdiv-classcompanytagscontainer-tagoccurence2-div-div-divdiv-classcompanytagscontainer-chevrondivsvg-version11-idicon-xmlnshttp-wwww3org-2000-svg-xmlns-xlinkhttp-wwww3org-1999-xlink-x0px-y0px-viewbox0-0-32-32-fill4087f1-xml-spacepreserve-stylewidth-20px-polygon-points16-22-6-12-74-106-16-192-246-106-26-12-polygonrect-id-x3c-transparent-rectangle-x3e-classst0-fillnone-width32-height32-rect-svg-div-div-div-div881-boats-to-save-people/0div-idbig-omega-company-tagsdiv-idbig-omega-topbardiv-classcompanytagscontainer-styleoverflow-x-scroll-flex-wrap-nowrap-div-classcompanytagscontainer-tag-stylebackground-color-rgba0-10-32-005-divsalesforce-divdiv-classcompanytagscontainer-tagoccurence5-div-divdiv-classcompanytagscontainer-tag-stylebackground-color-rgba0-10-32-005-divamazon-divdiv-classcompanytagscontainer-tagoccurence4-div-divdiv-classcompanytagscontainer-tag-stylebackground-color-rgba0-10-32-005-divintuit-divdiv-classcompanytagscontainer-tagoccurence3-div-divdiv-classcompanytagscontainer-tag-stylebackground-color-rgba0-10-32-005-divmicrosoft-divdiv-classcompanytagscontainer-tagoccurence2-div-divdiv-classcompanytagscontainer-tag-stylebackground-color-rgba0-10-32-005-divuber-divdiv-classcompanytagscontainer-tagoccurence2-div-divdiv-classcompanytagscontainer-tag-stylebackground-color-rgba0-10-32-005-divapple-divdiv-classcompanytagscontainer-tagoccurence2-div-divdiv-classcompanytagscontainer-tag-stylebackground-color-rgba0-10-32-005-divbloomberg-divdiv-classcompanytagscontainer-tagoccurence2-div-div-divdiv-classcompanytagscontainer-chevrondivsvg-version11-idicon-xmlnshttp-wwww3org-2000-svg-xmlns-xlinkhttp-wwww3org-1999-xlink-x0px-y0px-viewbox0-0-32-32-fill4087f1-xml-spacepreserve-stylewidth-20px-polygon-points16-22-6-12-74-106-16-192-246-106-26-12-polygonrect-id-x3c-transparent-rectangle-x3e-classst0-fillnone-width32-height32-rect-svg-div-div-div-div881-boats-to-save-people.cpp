class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int start = 0, end = people.size()-1, trips = 0;
        if(end == 0) return 1;
        while(start < end){
            if(people[start] + people[end] <= limit){
                start++;
            }
            end--;
            trips++;
        }

        if(start == end) trips++;
        return trips;
    }
};