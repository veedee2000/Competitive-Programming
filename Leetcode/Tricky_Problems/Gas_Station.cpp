class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), tank = 0, reqFuel = 0, start = 0;
        for(int i = 0;i < n;i++){
            tank += gas[i] - cost[i];
            if(tank < 0) reqFuel += tank, tank = 0, start = (i + 1) % n;
        }
        return tank + reqFuel >= 0 ? start : -1;
    }
};
