#include"iostream"
#include"vector"
#include"algorithm"
#include"numeric"
#include"map"

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        map<int, bool> mem;
        int res = 0;
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
        {
            return -1;
        }

        int gas_save = 0;
        int gas_use = 0;

        if (size == 1)
        {
            return -1;
        }
        for (int i = 0; i < size; i++)
        {
            int j = i;
            while (gas_save >= 0)
            {
                gas_save += (gas[j] - cost[j]);
                j = (j + 1 == size ? 0 : j + 1);
                if (j == i)
                {
                    return j;
                }
            }
            gas_save = 0;
        }
        
    }
};

int main()
{
    Solution a;
    vector<int>gas = {1, 2, 3, 4, 5};
    vector<int>cost = { 4,5,1,2,3 };
    cout << a.canCompleteCircuit(gas, cost);
}