class Solution {
public:
  
    
vector<int> twoSum(vector<int>& nums, int target){
  vector<pair<int,int>> pt;
  for(int i=0;i<nums.size();i++){
    pt.push_back({nums[i],i});
  }
        sort(pt.begin(),pt.end());
    int i = 0;
  int j = nums.size()-1;
  vector<int> ans;
  while(i<j){
    if(pt[i].first + pt[j].first==target){
      ans.push_back(pt[i].second);
      ans.push_back(pt[j].second);
      break;
    }else if(pt[i].first + pt[j].first>target){
      j--;
    }else if(pt[i].first + pt[j].first<target){
      i++;
    }
  }
  return ans;
    }
};