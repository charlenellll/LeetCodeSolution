class Solution {
public:
    string addBinary(string a, string b) {
        string rs = "";
        int n1 = a.size(), n2 = b.size(), carry = 0;
        for (int i = n1 - 1, j = n2 - 1; i >= 0 || j >= 0; i--, j--) {
            int op1, op2;
            if (i >= 0) op1 = a[i] - '0';
            else op1 = 0;
            if (j >= 0) op2 = b[j] - '0';
            else op2 = 0;
            int sum = op1 ^ op2 ^ carry;
            rs = (char)(sum + '0') + rs;
            carry = op1 & op2 | op1 & carry | op2 & carry;
        }
        if (carry) rs = '1' + rs;
        return rs;
    }