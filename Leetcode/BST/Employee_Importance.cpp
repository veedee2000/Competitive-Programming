/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
int sum = 0;
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*>m;
        for(auto x: employees) m[x->id] = x;
        DFS(m, id);
        return sum;
    }
    
    void DFS(unordered_map<int, Employee*>& m, int id){
        sum += m[id]->importance;
        for(auto x: m[id]->subordinates) DFS(m, x);
    }
};
