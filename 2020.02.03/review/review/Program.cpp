#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

#if 0
//0701 1
int main()
{
	int n;
	//可多次输入代码,使用容器
	while (cin >> n)
	{
		int sum = 0; 
		//容器的使用
		vector<int> a;
		//resize的特点:改变容器大小,能容纳()中个元素.
		//reserve的特点:预分配()中个数的元素的存储空间
		a.resize(3 * n);
		for (int i = 0; i < (3 * n); i++)
		{
			cin >> a[i];
		}
		//标准库中自带的排序
		sort(a.begin(), a.end());
		for (int i = n; i <= (3 * n) - 2; i += 2)
		{
			sum += a[i];
		}
		cout << sum << endl;

	}

	return 0;
}
#endif

#if 0
//0701 2
int main()
{
	string str1, str2;

	//此处使用getline(),因为cin遇到空格结束
	getline(cin, str1);
	getline(cin, str2);

	//哈希映射的思想统计字符出现的次数
	int hashtable[256] = { 0 };
	for (size_t i = 0; i < str2.size(); i++)
	{
		hashtable[str2[i]]++;
	}

	string ret;
	for (size_t i = 0; i < str1.size(); i++)
	{
		if (hashtable[str1[i]] == 0)
			ret += str1[i];
	}
	cout << ret << endl;

	return 0;
}

#endif

#if 0
//0702 1 
int main()
{
	int n;
	cin >> n;
	vector<int> a;
	a.resize(n + 1);
	a[n] = 0;

	int i = 0;
	for (i; i < n; i++)
	{
		cin >> a[i];
	}

	i = 0;
	int count = 0;
	while (i < n)
	{
		//非递减子序列
		if (a[i] < a[i + 1])
		{
			while (i < n && a[i] <= a[i + 1])
				i++;
			
			count++;
			i++;
		}
		else if (a[i] == a[i + 1])
		{
			i++;
		}
		//非递增子序列
		else
		{
			while (i<n && a[i]>a[i + 1])
				i++;

			count++;
			i++;
		}
	}

	cout << count << endl;

	return 0;
}

#endif

#if 0
//0702 2
int main()
{
	
	string s;
	getline(cin, s);
	reverse(s.begin(), s.end());

	auto start = s.begin();
	while (start != s.end())
	{
		auto end = start;
		while (end != s.end() && *end != ' ')
			end++;
		reverse(start, end);
		if (end != s.end())
			start = end + 1;
		else
			start = end;
	}
	cout << s << endl;

	return 0;
}

#endif

#if 0
//0703 1
int main()
{
	string str, res, cur;
	cin >> str;
	for (size_t i = 0; i <= str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			cur += str[i];
		}
		else
		{
			if (res.size() < cur.size())
				res = cur;
			else
				cur.clear();
		}
	}

	cout << res;

	return 0;
}

#endif

#if 0
//0703 2

//思路一: 将容器数组排序,	取中间数则为最优解
int main()
{
	vector<int> number;

	int n;
	cin >> n;
	number.resize(n + 1);
	for (int i = 0; i <= n; i++)
	{
		cin >> number[i];
	}

	if (number.empty())
		return 0;

	sort(number.begin(), number.end());
	int middle = number[number.size() / 2];

	size_t count = 0;
	for (size_t i = 0; i < number.size(); i++)
	{
		if (number[i] == middle)
			count++;
	}

	cout << ((count > number.size() / 2) ? middle : 0);

	return 0;
}

#endif

#if 0
//0704 1

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = (a + c) / 2;
	int C = (d - b) / 2;
	int B1 = (b + d) / 2;
	int B2 = (c - a) / 2;

	if (B1 != B2)
		cout << "wrong!";
	else
		cout << A << " " << B1 << " " << C << endl;

	return 0;
}

#endif

#if 0
//0704 2

int main()
{
	string s, table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	bool flag = false;

	if (m < 0)
	{
		m = 0 - m;
		flag = true;
	}

	while (m)
	{
		s += table[m%n];
		m /= n;
	}

	if (flag)
		s += '-';
	reverse(s.begin(), s.end());
	cout << s << endl;

	return 0;
}

#endif

#if 0
//0705 1

bool IsCircleText(const string& s)
{
	size_t begin = 0;
	size_t end = s.size() - 1;
	while (begin < end)
	{
		if (s[begin] != s[end])
			return false;

		begin++;
		end--;
	}

	return true;
}

int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	size_t count = 0;
	for (size_t i = 0; i <= str1.size(); i++)
	{
		//  拷贝构造  一个str,为的是不改变str1的内容
		string str = str1;
		str.insert(i, str2);
		if (IsCircleText(str))
			count++;
	}

	cout << count << endl;

	return 0;
}

#endif

#if 0

//这个还不会呢,需要搞一搞

//0706 2

int main()
{
	int size;
	cin >> size;
	vector<int> nums(size);
	for (int i = 0; i < size; i++)
		cin >> nums[i];

	int result = nums[0];
	int sum1 = 0, sum2 = 0;
	for (size_t i = 0; i < nums.size(); i++)
	{
		sum2 = sum1 >= 0 ? sum1 + nums[i] : nums[i];
		if (sum2>result)
			result = sum2;
		if (sum2 < 0)
			sum2;
		sum1 = sum2;
	}
	cout << result << endl;

	return 0;
}

#endif

#if 0
//0708 1

int main()
{
	int N, f, l = 0, r = 0, f0 = 0, f1 = 1;
	cin >> N;
	while (1)
	{
		f = f0 + f1;
		f0 = f1;
		f1 = f;
		if (f < N)
			l = N - f;
		else
		{
			r = f - N;
			break;
		}
	}
	cout << min(l, r) << endl;

	return 0;
}

#endif

#if 0
//0708 2

class Parenthesis{
public:
	// static 静态成员函数
	static bool chkParenthesis(string A, int n)
	{
		stack<char> sc;
		for (auto ele : A)
		{
			switch (ele)
			{
			case '(':
				sc.push(ele);
				break;
			case ')':
				{
						if (sc.empty() || sc.top() != '(')
							return false;
						else
							sc.pop();
				}
				break;
			default:
				return false;
			}
		}
		return true;
	}
};

int main()
{
	string A = "(()))";
	cout << Parenthesis::chkParenthesis(A, 5) << endl;

	return 0;
}

#endif

#if 0
//0709 1

int main()
{
	int n;
	cin >> n;
	vector<string> v;
	v.resize(n);
	for (auto& str : v)
		cin >> str;
	bool lenSym = true, lexSym = true;

	for (size_t i = 1; i < v.size(); i++)
	{
		if (v[i - 1].size() >= v[i].size())
		{
			lenSym = false;
			break;
		}
	}

	for (size_t i = 1; i < v.size();i++)
	{
		if (v[i - 1] >= v[i])
		{
			lexSym = false;
			break;
		}
	}

	if (lenSym && lexSym)
		cout << "both" << endl;
	else if (!lenSym && lexSym)
		cout << "lexicographically" << endl;
	else if (lenSym &&!lexSym)
		cout << "lengths" << endl;
	else if (!lenSym && !lexSym)
		cout << "none" << endl;

	return 0;
}

#endif

#if 0
//0709 2

int gcd(int a, int b)
{
	int r;
	while (r = a%b)
	{
		a = b;
		b = r;
	}
	return b;
}

int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		cout << a*b / gcd(a, b) << endl;
	}
	return 0;
}

#endif

#if 0
//0710 1

class UnusualAdd
{
public:
	static int addAB(int A, int B)
	{
		int sum = 0, carry = 0;
		while (B != 0)
		{
			sum = A^B;
			carry = (A&B) << 1;
			A = sum;
			B = carry;

		}
		return sum;
	}
};

int main()
{
	cout << UnusualAdd::addAB(3, 2) << endl;

	return 0;
}

#endif

#if 0
//0710 2

//这个很重要,需要再学一遍

int pathNum(int n, int m)
{
	if (n > 1 && m > 1)
		return pathNum(n - 1, m) + pathNum(n, m - 1);
	else if (((n >= 1) && (m == 1)) || ((n == 1) && (m >= 1)))
		return n + m;
	else
		return 0;
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		cout << "需要走" << pathNum(n, m) << "步" << endl;
	}

	return 0;
}

#endif

#if 0
//0711 1

class Board
{
public:
	bool checkwon(vector<vector<int>> board)
	{
		int row = board.size();
		int i, j, sum;

		for (i = 0; i < row; i++)
		{
			sum = 0;
			for (j = 0; j < row; j++)
			{
				sum += board[i][j];
			}
			if (sum == row)
				return true;
		}

		for (i = 0; i < row; i++)
		{
			sum = 0;
			for (j = 0; j < row; j++)
			{
				sum += board[j][i];
			}
			if (sum == row)
				return true;
		}
		
		sum = 0;
		for (i = 0; i < row; i++)
		{
			sum += board[i][i];
		}
		if (sum == row)
			return true;

		sum = 0;
		for (i = 0; i < row; i++)
		{
			sum += board[i][row - i - 1];
		}
		if (sum == row)
			return true;

		return false;

	}
};

#endif

#if 0
//0711 2

int numChar(string str, int k)
{
	//根据ASCII码判断字母大小写
	int small = 0;
	int big = 0;
	for (int i = 0; i < k; i++)
	{
		if (str[i] >= 65 && str[i] <= 90)
			big++;
		else if (str[i] >= 97 && str[i] <= 122)
			small++;
	}
	if ((small + big) == 0)
		return 0;
	else if (small == k || big == k)
		return 10;
	else if (small > 0 && big > 0)
		return 20;
	return 0;
}

int numNunber(string str, int k)
{
	//根据ASCII码判断数字个数,减去字符'0'之后在0~9之间的即为数字
	int num = 0;
	for (int i = 0; i < k; i++)
	{
		if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
			num++;
	}
	if (num == 0)
		return 0;
	else if (num == 1)
		return 10;
	else
		return 20;
}

int numSymbal(string str, int k)
{
	int num = 0;
	for (int i = 0; i < k; i++)
	{
		//除去字母, 数字,其它都为符号
		if (!(str[i] >= 65 && str[i] <= 90)
			&& !(str[i] >= 97 && str[i] <= 122)
			&& !(str[i] - '0' >= 0 && str[i] - '0' <= 9))
			num++;
	}
	if (num == 0)
		return 0;
	else if (num == 1)
		return 10;
	else
		return 25;
}

int main()
{
	string str;
	while (cin >> str)
	{
		int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
		int k = str.size();
		if (k <= 4)
			sum1 = 5;
		else if (k > 8)
			sum1 = 5;
		else sum1 = 10;
		sum2 = numChar(str, k);
		sum3 = numNunber1(str, k);
		sum4 = numSymbal(str, k);
		if ((sum2 > 0) && (sum3 > 0) && (sum4 > 0))
		{
			if (sum2 == 10)
				sum5 = 3;
			else
				sum5 = 5;
		}
		else if (sum2 > 0 && sum3 > 0 && sum4 == 0)
			sum5 = 2;
		if (sum1 + sum2 + sum3 + sum4 + sum5 >= 90)
			cout << "VERY_SERCURE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 80)
			cout << "SEVURE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 70)
			cout << "VERY_STRONG" << endl;
		else if (sum1+sum2+sum3+sum4+sum5>=60)
			cout << "STRONG" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 50)
			cout << "AVERAGE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 25)
			cout << "WEAK" << endl;
		else
			cout << "VERY_WEAK" << endl;
	}
	return 0;
}

#endif

#if 0
//0712 1

class LCA
{
public:
	static int getLCA(int a, int b)
	{
		while (a != b)
		{
			if (a > b)
				a /= 2;
			else
				b /= 2;
		}
		return a;
	}
};

#endif

#if 0
//0712 2

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0, maxCount = 0;
		while (n)
		{
			if (n & 1)
			{
				++count;
				maxCount = max(count, maxCount);
			}
			else
				count = 0;
			n = n >> 1;
		}
		cout << maxCount << endl;
		return 0;
	}
}

#endif

#if 0
//0713 1

class BinInsert
{
public:
	static int binInsert(int n, int m, int j, int i)
	{
		m <<= j;
		return n | m;
	}
};

int main()
{
	cout << BinInsert::binInsert(1024, 19, 2, 6);

	return 0;
}

#endif

#if 1
//0713 2

bool isPrime(int num)
{
	int tmp = sqrt(num);
	for (int i = 2; i <= tmp; i++)
	{
		if (num%i == 0)
			return false;
	}
	return true;
}

int main()
{
	

	return 0;
}

#endif