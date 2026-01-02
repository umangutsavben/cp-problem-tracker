class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> last(3, -1);  // last indices of 'a', 'b', 'c'
        int ans = 

        for (int j = 0; j < s.size(); j++) {
            last[s[j] - 'a'] = j; // example : a b c a b c --> so abca jab aega toh last seen b ka min hoga that is 1toh from 0th se 1st tak sare substring valid honge!

            if (last[0] != -1 && last[1] != -1 && last[2] != -1) {
                ans += min({last[0], last[1], last[2]}) + 1;
            }
        }
        return ans;
    }
};

Observation:
- A substring ending at index j is valid if it starts at or before the minimum last index of 'a', 'b', and 'c'
- We only need the latest positions of 'a', 'b', 'c', not a full window

Pattern:
- Last Occurrence Tracking + Greedy Counting

Invariant:
- last[x] always stores the most recent index of character x up to j
- All substrings starting in [0 .. min(last)] and ending at j are valid

Why this works:
- The earliest required start index is min(last[a], last[b], last[c])
- This guarantees at least one of each character in the substring

Common Trap:
- Thinking sliding window is mandatory
- Forgetting to add +1 when counting valid start positions

One-Line Recall:
- For each j: add min(last[a], last[b], last[c]) + 1
counting

One-Line Recall:
- First valid window ⇒ add (n - r), then move left
