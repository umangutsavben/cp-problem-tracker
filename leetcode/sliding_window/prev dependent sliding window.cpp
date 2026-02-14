class Solution {
public:
    int func(vector<int>&v,int k,int n){
        int i=0,j=0;
        map<int,int>mp;
        int ans = 0;
        while(j<n){
            mp[v[j]]++;
            while(mp.size()>k){
                mp[v[i]]--;
                if(mp[v[i]]==0){
                    mp.erase(v[i]);
                }
                i++;
            }
            ans = ans + j - i +1;
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& v, int k) {
        int n = v.size();
        return func(v,k,n)-func(v,k-1,n);
    }
};
