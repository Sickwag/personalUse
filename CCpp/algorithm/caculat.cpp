#include <assert.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// class IntegerBigCalcu {
// private:
//     string removeLeadingZeros(string s) {
//         if (s.empty()) return "0";
//         bool isNegative = s[0] == '-';
//         if (isNegative) s.erase(0, 1);
//         s.erase(0, s.find_first_not_of('0'));
//         if (s.empty()) return "0";
//         return isNegative ? "-" + s : s;
//     }

//     string adjustDecimal(string num, int decimalPos) {
//         if (decimalPos <= 0) {
//             return num + ".0";
//         }
//         if (num.length() < decimalPos) {
//             num = string(decimalPos - num.length(), '0') + num;
//         }
//         return num.insert(num.length() - decimalPos, ".");
//     }

//     int compare(string a, string b) {
//         a = removeLeadingZeros(a);
//         b = removeLeadingZeros(b);

//         bool a_neg = (a[0] == '-');
//         bool b_neg = (b[0] == '-');

//         // Different signs
//         if (a_neg && !b_neg) return -1;
//         if (!a_neg && b_neg) return 1;

//         // Both negative: compare absolute values in reverse
//         if (a_neg && b_neg) {
//             a = a.substr(1);
//             b = b.substr(1);
//             int cmp = compare(a, b);
//             return -cmp; // Reverse the result for negatives
//         }

//         // Both positive
//         if (a.length() != b.length()) {
//             return a.length() > b.length() ? 1 : -1;
//         }
//         for (int i = 0; i < a.length(); ++i) {
//             if (a[i] != b[i]) {
//                 return a[i] > b[i] ? 1 : -1;
//             }
//         }
//         return 0;
//     }
// public:
//     string addString(string num1, string num2) {
//         string res;
//         int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
//         while (i >= 0 || j >= 0 || carry) {
//             int a = i >= 0 ? num1[i--] - '0' : 0;
//             int b = j >= 0 ? num2[j--] - '0' : 0;
//             int sum = a + b + carry;
//             res.push_back(sum % 10 + '0');
//             carry = sum / 10;
//         }
//         reverse(res.begin(), res.end());
//         return removeLeadingZeros(res);
//     }

//     /**
//      * @brief num1 must bigger than num2 and they all positive
//      */
//     string subString(string num1, string num2) {
//         string res;
//         int i = num1.size() - 1, j = num2.size() - 1, borrow = 0;
//         while (i >= 0) {
//             int a = num1[i--] - '0' - borrow;
//             int b = j >= 0 ? num2[j--] - '0' : 0;
//             borrow = a < b ? 1 : 0;
//             res.push_back((a + borrow * 10 - b) + '0');
//         }
//         reverse(res.begin(), res.end());
//         return removeLeadingZeros(res);
//     }

//     string mulString(string num1, string num2) {
//         string res(num1.size() + num2.size(), '0');
//         for (int i = num1.size() - 1; i >= 0; --i) {
//             int carry = 0;
//             for (int j = num2.size() - 1; j >= 0; --j) {
//                 int tmp = (num1[i] - '0') * (num2[j] - '0') + (res[i + j + 1] - '0') + carry;
//                 res[i + j + 1] = tmp % 10 + '0';
//                 carry = tmp / 10;
//             }
//             res[i] += carry;
//         }
//         return removeLeadingZeros(res);
//     }

//     /**
//      * @brief num1 must bigger than num2, result is a integer
//      */
//     string divString(string num1, string num2) {
//         string res, current;
//         for (char c : num1) {
//             current += c;
//             current = removeLeadingZeros(current);
//             int cnt = 0;
//             while (compare(current, num2) >= 0) {
//                 current = subString(current, num2);
//                 ++cnt;
//             }
//             res += cnt + '0';
//         }
//         return removeLeadingZeros(res);
//     }

//     string addStringWithNeg(string num1, string num2) {
//         bool neg1 = num1[0] == '-', neg2 = num2[0] == '-';
//         string a = neg1 ? num1.substr(1) : num1;
//         string b = neg2 ? num2.substr(1) : num2;

//         if (!neg1 && !neg2) return addString(a, b);
//         if (neg1 && neg2) return "-" + addString(a, b);
//         if (neg1) {
//             if (compare(b, a) >= 0) return subString(b, a);
//             return "-" + subString(a, b);
//         }
//         if (compare(a, b) >= 0) return subString(a, b);
//         return "-" + subString(b, a);
//     }

//     string subStringWithNeg(string num1, string num2) {
//         bool neg1 = num1[0] == '-', neg2 = num2[0] == '-';
//         string a = neg1 ? num1.substr(1) : num1;
//         string b = neg2 ? num2.substr(1) : num2;

//         if (!neg1 && !neg2) {
//             int cmp = compare(a, b);
//             if (cmp == 0) return "0";
//             return cmp > 0 ? subString(a, b) : "-" + subString(b, a);
//         }
//         if (neg1 && neg2) {
//             int cmp = compare(b, a);
//             return cmp > 0 ? subString(b, a) : "-" + subString(a, b);
//         }
//         if (neg1) return "-" + addString(a, b);
//         return addString(a, b);
//     }

//     string mulStringWithNeg(string num1, string num2) {
//         bool neg1 = num1[0] == '-', neg2 = num2[0] == '-';
//         string a = removeLeadingZeros(neg1 ? num1.substr(1) : num1);
//         string b = removeLeadingZeros(neg2 ? num2.substr(1) : num2);
//         string res = mulString(a, b);
//         return (neg1 != neg2 && res != "0") ? "-" + res : res;
//     }

//     string divStringWithNeg(string num1, string num2) {
//         bool neg1 = num1[0] == '-', neg2 = num2[0] == '-';
//         string a = removeLeadingZeros(neg1 ? num1.substr(1) : num1);
//         string b = removeLeadingZeros(neg2 ? num2.substr(1) : num2);
//         string res = divString(a, b);
//         return (neg1 != neg2 && res != "0") ? "-" + res : res;
//     }
// };
class BigInt {
public:
    // Remove leading zeros (return "0" if all are zeros)
    static string removeLeadingZeros(const string& s) {
        int i = 0;
        while (i < s.size() && s[i] == '0') i++;
        return i == s.size() ? "0" : s.substr(i);
    }
    // Compare absolute values of two positive strings.
    // Returns 1 if a > b, 0 if equal, -1 if a < b.
    static int compareAbs(const string& a, const string& b) {
        string aa = removeLeadingZeros(a);
        string bb = removeLeadingZeros(b);
        if (aa.size() > bb.size()) return 1;
        if (aa.size() < bb.size()) return -1;
        return (aa == bb) ? 0 : (aa > bb ? 1 : -1);
    }
    // Addition of two positive numbers represented as strings.
    static string addPositive(const string& a, const string& b) {
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        string res;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) { sum += a[i] - '0'; i--; }
            if (j >= 0) { sum += b[j] - '0'; j--; }
            carry = sum / 10;
            res.push_back('0' + (sum % 10));
        }
        reverse(res.begin(), res.end());
        return removeLeadingZeros(res);
    }
    // Subtraction of two positive numbers (assumes a >= b).
    static string subPositive(const string& a, const string& b) {
        int i = a.size() - 1, j = b.size() - 1, borrow = 0;
        string res;
        while (i >= 0) {
            int diff = (a[i] - '0') - borrow;
            if (j >= 0) { diff -= (b[j] - '0'); j--; }
            if (diff < 0) { diff += 10; borrow = 1; }
            else borrow = 0;
            res.push_back('0' + diff);
            i--;
        }
        reverse(res.begin(), res.end());
        return removeLeadingZeros(res);
    }
    // addString: Supports both positive and negative numbers.
    // Both parameters may be negative (first character '-' indicates negative).
    static string addString(string num1, string num2) {
        bool neg1 = false, neg2 = false;
        if (!num1.empty() && num1[0] == '-') { neg1 = true; num1 = num1.substr(1); }
        if (!num2.empty() && num2[0] == '-') { neg2 = true; num2 = num2.substr(1); }
        string res;
        if (neg1 == neg2) { // Same sign: add and reapply sign if needed.
            res = addPositive(num1, num2);
            if (neg1 && res != "0") res = "-" + res;
        }
        else {
            // Signs differ: perform subtraction of the larger absolute value minus the smaller.
            int cmp = compareAbs(num1, num2);
            if (cmp == 0) return "0";
            if (cmp > 0) { res = subPositive(num1, num2); if (neg1) res = "-" + res; }
            else { res = subPositive(num2, num1); if (neg2) res = "-" + res; }
        }
        return res;
    }
    // subString: Compute num1 - num2 (both parameters may be negative).
    static string subString(string num1, string num2) {
        // Simply add num1 with the negation of num2.
        if (!num2.empty() && num2[0] == '-')
            num2 = num2.substr(1);
        else
            num2 = "-" + num2;
        return addString(num1, num2);
    }
    // For compatibility: subStringWithNeg does the same as subString.
    static string subStringWithNeg(string num1, string num2) {
        return subString(num1, num2);
    }
    // mulString: Multiplication supporting positive and negative numbers.
    static string mulString(string num1, string num2) {
        bool neg1 = false, neg2 = false;
        if (!num1.empty() && num1[0] == '-') { neg1 = true; num1 = num1.substr(1); }
        if (!num2.empty() && num2[0] == '-') { neg2 = true; num2 = num2.substr(1); }
        int n = num1.size(), m = num2.size();
        vector<int> result(n + m, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = result[i + j + 1] + mul;
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        string res;
        for (int num : result)
            if (!(res.empty() && num == 0))
                res.push_back('0' + num);
        if (res.empty()) res = "0";
        if ((neg1 ^ neg2) && res != "0") res = "-" + res;
        return res;
    }
    // divString: Integer division (quotient only) supporting positive and negative numbers.
    // (Returns "NaN" for division by zero.)
    static string divString(string num1, string num2) {
        bool neg1 = false, neg2 = false;
        if (!num1.empty() && num1[0] == '-') { neg1 = true; num1 = num1.substr(1); }
        if (!num2.empty() && num2[0] == '-') { neg2 = true; num2 = num2.substr(1); }
        num1 = removeLeadingZeros(num1);
        num2 = removeLeadingZeros(num2);
        if (num2 == "0") return "NaN"; // division by zero.
        if (compareAbs(num1, num2) < 0) return "0";
        string quotient, dividend;
        for (char c : num1) {
            dividend.push_back(c);
            dividend = removeLeadingZeros(dividend);
            int count = 0;
            while (compareAbs(dividend, num2) >= 0) {
                dividend = subPositive(dividend, num2);
                count++;
            }
            quotient.push_back('0' + count);
        }
        quotient = removeLeadingZeros(quotient);
        if ((neg1 ^ neg2) && quotient != "0") quotient = "-" + quotient;
        return quotient;
    }
    // Test function for BigInt.
    static void test() {
        printf("BigInt Tests:\n");
        printf("addString(123, 456) = %s\n", addString("123", "456").c_str());
        printf("addString(-123, 456) = %s\n", addString("-123", "456").c_str());
        printf("addString(123, -456) = %s\n", addString("123", "-456").c_str());
        printf("addString(-123, -456) = %s\n", addString("-123", "-456").c_str());
        printf("subString(456, 123) = %s\n", subString("456", "123").c_str());
        printf("subString(123, 456) = %s\n", subString("123", "456").c_str());
        printf("subString(123, -67) = %s\n", subString("123", "-67").c_str());
        printf("mulString(123, -456) = %s\n", mulString("123", "-456").c_str());
        printf("divString(123456, 123) = %s\n", divString("123456", "123").c_str());
    }
};

class BigFloat {
public:
    // normalize:
    // - Determines sign (neg), removes the decimal point,
    // - Returns a pure integer string and the count of fractional digits (frac).
    static void normalize(const string& s, bool& neg, string& num, int& frac) {
        neg = false;
        string tmp = s;
        if (!tmp.empty() && tmp[0] == '-') { neg = true; tmp = tmp.substr(1); }
        size_t pos = tmp.find('.');
        if (pos == string::npos) { num = tmp; frac = 0; }
        else {
            num = tmp.substr(0, pos) + tmp.substr(pos + 1);
            frac = tmp.size() - pos - 1;
        }
        // Remove leading zeros.
        int i = 0;
        while (i < num.size() && num[i] == '0') i++;
        num = (i == num.size()) ? "0" : num.substr(i);
    }
    // formatResult:
    // Inserts a decimal point given the number of fractional digits and removes extraneous trailing zeros.
    static string formatResult(const string& s, int frac) {
        if (frac == 0) return s;
        int len = s.size();
        if (len <= frac)
            s = string(frac - len + 1, '0') + s, len = s.size();
        string intPart = s.substr(0, len - frac);
        string fracPart = s.substr(len - frac);
        while (!fracPart.empty() && fracPart.back() == '0') fracPart.pop_back();
        return fracPart.empty() ? (intPart == "" ? "0" : intPart)
            : (intPart == "" ? "0." + fracPart : intPart + "." + fracPart);
    }
    // Helper: pad two integer representations with leading zeros to equal length.
    static void padEqual(string& a, string& b) {
        if (a.size() < b.size()) a = string(b.size() - a.size(), '0') + a;
        else if (b.size() < a.size()) b = string(a.size() - b.size(), '0') + b;
    }
    // addString for BigFloat.
    static string addString(string num1, string num2) {
        bool neg1, neg2;
        string int1, int2;
        int frac1, frac2;
        normalize(num1, neg1, int1, frac1);
        normalize(num2, neg2, int2, frac2);
        int d = frac1 > frac2 ? frac1 : frac2;
        // Append zeros to equalize fractional digits.
        int1 += string(d - frac1, '0');
        int2 += string(d - frac2, '0');
        // Pad with leading zeros so the integer strings have equal length.
        padEqual(int1, int2);
        if (neg1) int1 = "-" + int1;
        if (neg2) int2 = "-" + int2;
        string res = BigInt::addString(int1, int2);
        bool resNeg = false;
        if (!res.empty() && res[0] == '-') { resNeg = true; res = res.substr(1); }
        res = BigInt::removeLeadingZeros(res);
        res = formatResult(res, d);
        if (resNeg && res != "0") res = "-" + res;
        return res;
    }
    // subString: Compute num1 - num2 for floats (parameters may be negative).
    static string subString(string num1, string num2) {
        // Simply add num1 with the negation of num2.
        if (!num2.empty() && num2[0] == '-')
            num2 = num2.substr(1);
        else
            num2 = "-" + num2;
        return addString(num1, num2);
    }
    // subStringWithNeg: Same as subString.
    static string subStringWithNeg(string num1, string num2) {
        return subString(num1, num2);
    }
    // mulString: Multiply two floats.
    static string mulString(string num1, string num2) {
        bool neg1, neg2;
        string int1, int2;
        int frac1, frac2;
        normalize(num1, neg1, int1, frac1);
        normalize(num2, neg2, int2, frac2);
        string prod = BigInt::mulString(int1, int2);
        int d = frac1 + frac2;
        bool neg = (neg1 ^ neg2);
        if (!prod.empty() && prod[0] == '-') prod = prod.substr(1);
        prod = BigInt::removeLeadingZeros(prod);
        prod = formatResult(prod, d);
        if (neg && prod != "0") prod = "-" + prod;
        return prod;
    }
    // divString: Division of floats with fixed precision (10 digits after the decimal point).
    static string divString(string num1, string num2) {
        const int precision = 10;
        bool neg1, neg2;
        string int1, int2;
        int frac1, frac2;
        normalize(num1, neg1, int1, frac1);
        normalize(num2, neg2, int2, frac2);
        // Adjust scale to get the desired precision.
        int scale = precision + frac2 - frac1;
        if (scale > 0) int1 += string(scale, '0');
        else if (scale < 0) int2 += string(-scale, '0');
        // No need to pad here because division algorithm in BigInt works on non-padded numbers.
        string quot = BigInt::divString(int1, int2);
        bool neg = (neg1 ^ neg2);
        quot = BigInt::removeLeadingZeros(quot);
        quot = formatResult(quot, precision);
        if (neg && quot != "0") quot = "-" + quot;
        return quot;
    }
    // Test function for BigFloat.
    static void test() {
        printf("BigFloat Tests:\n");
        printf("addString(123.000000000000045, -67.89) = %s\n", addString("123.000000000000045", "-67.89").c_str());
        printf("addString(-67.89, 123.000000000000045) = %s\n", addString("-67.89", "123.000000000000045").c_str());
        printf("subString(123.45, -67.89) = %s\n", subString("123.45", "-67.89").c_str());
        printf("subString(-67.89, 123.45) = %s\n", subString("-67.89", "123.45").c_str());
        printf("mulString(12.3, -4.56) = %s\n", mulString("12.3", "-4.56").c_str());
        printf("divString(123.45, 6.7) = %s\n", divString("123.45", "6.7").c_str());
    }
};



int main() {
    BigFloat bf;
    bf.test();
    BigInt bi;
    bi.test();
}