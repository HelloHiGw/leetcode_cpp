/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> id2Employee;
        for (auto it : employees) {
            id2Employee[it->id] = it;
        }
        queue<int> q;
        q.push(id);
        int res = 0;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                int index = q.front();
                q.pop();
                res += id2Employee[index]->importance;
                for (int i : id2Employee[index]->subordinates) {
                     q.push(i);
                }
            }
        }
        return res;
    }
};