
#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>

using namespace std;
 int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        int ans;

        for(int i=0;i<nums.size();i++){
                map[nums[i]]+=1;
        }

        // for(int i=0;i<map.size();i++){
        //     cout<<map[i].first<<" "<<map[i].second<<endl;
        // }

        for(auto i:map){
            cout<<i.first<<" "<<i.second<<endl;
        }

        for(auto i:map){
            if(i.second==1){
                ans=i.first;
            } 
        }
              
        cout<<"Return: "<<ans<<endl;
        return ans;
    }

    int main(){
        vector<int> ans;
        ans.push_back(4);
        ans.push_back(1);
        ans.push_back(2);
        ans.push_back(1);
        ans.push_back(2);
        int x=singleNumber(ans);
        cout<<"ans: "<<x<<endl;
    }