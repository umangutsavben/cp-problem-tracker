class Solution {
public:
    string removeStars(string s) {
        string ans;

        for (char c : s) {
            if (c == '*') {
                ans.pop_back();   // remove closest left character
            } else {
                ans.push_back(c); // keep character
            }
        }

        return ans;
    }
};


use the string itself when the space comp is o(n) use this as stack only dont use the stack data structure cuz if we do 
so then we need another string to store our ans and which will increse our space complexity 

// this is worng !!
// class Solution {
// public:
//     string removeStars(string s) {
//        stack<char>st;
//        int idx = 0;
//        for(int i=0;i<s.size();i++){
//         if(s[i]=='*'){
//             s.erase(s.begin() + i-1);
//             s.erase(s.begin() + i-1);
//             i=i-2;
//             //s.size()
//         }
//         // else{
//         //     st.push(s[i]);
//         // }
//        }
//        return s;
//        string ans;
//        while(!st.empty()){
//         ans = ans + st.top();
//         st.pop();
//        }
//        reverse(ans.begin(),ans.end());
//        return ans;
//     }
// };
