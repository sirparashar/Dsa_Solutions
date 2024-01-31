class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        
        unordered_map<int, vector<int>>m;

        for(int i=0; i<pre.size(); i++){
           m[pre[i][0]].push_back(pre[i][1]);
        }

        vector<int> res;
        unordered_set<int> cycle;
        unordered_set<int> visit;

        for(int i=0; i<numCourses; i++){
            if(!dfs(m,i,res,cycle, visit)){
                return {};
            }
        }
       
       return res;
    }

    bool dfs(unordered_map<int, vector<int>>&m, int course, vector<int>&res,unordered_set<int> &cycle,unordered_set<int> &visit ){
     
     if(cycle.find(course)!=cycle.end()){
         return false;
     } 

     if(visit.find(course)!=visit.end()){
         return true;
     }

     cycle.insert(course);

     for(int i=0; i<m[course].size(); i++){
         if(!dfs(m,m[course][i],res,cycle,visit)){
             return false;
         }
     }
     cycle.erase(course);
     visit.insert(course);
     res.push_back(course);
     return true;

    }
};