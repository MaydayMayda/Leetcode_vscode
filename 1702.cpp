/*
 * @Title: 修改后的最大二进制字符串
 * @Label: 贪心、字符串
 * @Author: zhou
 * @Date: 2024-04-10 13:33:21
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {
        int k = binary.find('0');
        if (k == binary.npos) return binary;
        int n = binary.size();
        for (int i = k + 1; i < n; i++)
        {
            if (binary[i]=='0') ++k;
        }
        return string(k,'1') + '0' + string(n-k-1,'1');
    }
};
int main()
{
    string binary = "000110";
    Solution s;
    s.maximumBinaryString(binary);
    return 0;
}
