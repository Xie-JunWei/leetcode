#include<vector>
#include<stdio.h>
#include<map>
#include<iostream>
using namespace std;

class Solution {
public:
    map<int, bool> mem;
    vector<int> res = { 0 };
    vector<int> result;
    int long_res = 0;
    void dfs()
    {
        if (res.size() == long_res)
        {
            result = res;
            return;
        }
        else
        {
            for (int i = 1; i < long_res; i++)
            {
                if (mem[i] == true)
                {
                    continue;
                }
                int c = 0;
                int temp = i ^ res[res.size() - 1];
                for (c = 0; temp; c++) {
                    temp &= (temp - 1);
                }
                if (c != 1)
                {
                    continue;
                }
                mem[i] = true;
                res.push_back(i);
                dfs();
                mem[i] = false;
                res.pop_back();
            }
        }
    }
    vector<int> grayCode(int n)
    {
        if (n == 0)
        {
            return res;
        }
        else if (n == 1)
        {
            res.push_back(1);
            return res;
        }
        else
        {
            long_res = pow(2, n);
            dfs();
            return result;
        }
    }
    
};

int main()
{
    Solution test;
    vector<int> a = test.grayCode(4);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << ' ';
    }
}



