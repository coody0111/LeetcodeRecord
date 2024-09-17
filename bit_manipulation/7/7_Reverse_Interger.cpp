class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x != 0) {
            // 提取最後一位數字
            int digit = x % 10;
            
            // 檢查溢出
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) return 0;
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8)) return 0;
            
            // 更新結果
            result = (result << 3) + (result << 1) + digit;
            
            // 去掉最後一位數字
            x /= 10;
        }
        return result;
    }
};