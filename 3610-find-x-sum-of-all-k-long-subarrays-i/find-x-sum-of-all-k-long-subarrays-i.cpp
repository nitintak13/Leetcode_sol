class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> answer;
        unordered_map<int, int> freq;

        // Initialize frequency map for the first window
        for (int j = 0; j < k; j++) {
            freq[nums[j]]++;
        }

        answer.push_back(calculateXSum(freq, x));

        // Slide the window
        for (int i = 1; i <= n - k; i++) {
            // Remove the element going out of the window
            freq[nums[i - 1]]--;
            if (freq[nums[i - 1]] == 0) {
                freq.erase(nums[i - 1]);
            }

            freq[nums[i + k - 1]]++;
            answer.push_back(calculateXSum(freq, x));
        }

        return answer;
    }

private:
    int calculateXSum(const unordered_map<int, int>& freq, int x) {
        priority_queue<pair<int, int>> pq; // (frequency, value)

        for (const auto& entry : freq) {
            pq.push({entry.second, entry.first});
        }

        int sum = 0;
        for (int i = 0; i < x && !pq.empty(); i++) {
            auto top = pq.top();
            pq.pop();
            sum += top.second * top.first; 
        }

        return sum;
    }
};