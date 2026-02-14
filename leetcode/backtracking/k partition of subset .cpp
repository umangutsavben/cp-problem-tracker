class Solution {
public:
    void f(vector<int>&v,int k,long long int each,int n,vector<bool>&used,long long int curr,int i,bool &flag){
        if(k==1){
            flag=1;
            return;
        }
        if(curr>each) return;
        if(i==n) return;
        if(curr == each){
            curr = 0;
            i=0;
            f(v,k-1,each,n,used,curr,i,flag);
        }
        else{
          if(curr + v[i]>each||used[i]==1){
            f(v,k,each,n,used,curr,i+1,flag);
          } 
          else{
            used[i]=1;
            curr = curr + v[i];
            f(v,k,each,n,used,curr,i+1,flag);
            used[i]=0;
            curr = curr - v[i];
            f(v,k,each,n,used,curr,i+1,flag);
          } 
        }
    } 
    bool canPartitionKSubsets(vector<int>& v, int k) {
        int n=v.size();
        vector<bool>used(n,false);
        long long sum = accumulate(v.begin(),v.end(),0);
        if(sum%k!=0) return 0;
        long long each = sum/k;
        vector<long long int>box(k);
        vector<int>ans;
        bool flag = 0;
        long long curr = 0;
        f(v,k,each,n,used,curr,0,flag);
        return flag;
    }
};
