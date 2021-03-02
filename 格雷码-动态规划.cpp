#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> result = { 0 };
    vector<int> grayCode(int n) {
        if (n == 0)
        {
            return result;
        }
        else if (n == 1)
        {
            result.push_back(1);
            return result;
        }
        else if (n == 2)
        {
            result.push_back(2);
            result.push_back(3);
            result.push_back(1);
            return result;
        }
        else
        {
            vector<int> temp = grayCode(n - 1);
            reverse(temp.begin(), temp.end());
            for (int i = 0; i < temp.size(); i++)
            {
                temp[i] += pow(2, n-1);
            }
            result.insert(result.end(), temp.begin(), temp.end());
            return result;
        }
    }
};

int main()
{
    Solution test;
    vector<int> res = test.grayCode(8);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}

