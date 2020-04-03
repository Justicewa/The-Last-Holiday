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
	//�ɶ���������,ʹ������
	while (cin >> n)
	{
		int sum = 0; 
		//������ʹ��
		vector<int> a;
		//resize���ص�:�ı�������С,������()�и�Ԫ��.
		//reserve���ص�:Ԥ����()�и�����Ԫ�صĴ洢�ռ�
		a.resize(3 * n);
		for (int i = 0; i < (3 * n); i++)
		{
			cin >> a[i];
		}
		//��׼�����Դ�������
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

	//�˴�ʹ��getline(),��Ϊcin�����ո����
	getline(cin, str1);
	getline(cin, str2);

	//��ϣӳ���˼��ͳ���ַ����ֵĴ���
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
		//�ǵݼ�������
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
		//�ǵ���������
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

//˼·һ: ��������������,	ȡ�м�����Ϊ���Ž�
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
		//  ��������  һ��str,Ϊ���ǲ��ı�str1������
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

//�����������,��Ҫ��һ��

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
	// static ��̬��Ա����
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

//�������Ҫ,��Ҫ��ѧһ��

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
		cout << "��Ҫ��" << pathNum(n, m) << "��" << endl;
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
	//����ASCII���ж���ĸ��Сд
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
	//����ASCII���ж����ָ���,��ȥ�ַ�'0'֮����0~9֮��ļ�Ϊ����
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
		//��ȥ��ĸ, ����,������Ϊ����
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

#if 0
//0713 2

bool isPrime(int num)
{
	int tmp = (int)sqrt(num);
	for (int i = 2; i <= tmp; i++)
	{
		if (num%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int num, half, i;
	while (cin >> num)
	{
		half = num / 2;
		for (i = half; i > 0; i--)
		{
			if (isPrime(i) && isPrime(num - i))
				break;
		}
		cout << i << endl << num - i << endl;
	}

	return 0;
}

#endif

#if 0
//0715 1

int main()
{
	string str;
	while (getline(cin, str))
	{
		int count = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '"')
			{
				do 
				{
					i++;
				} while (str[i] != '"');
			}
		}

		cout << count + 1 << endl;
		int flag = 1;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '"')
				flag ^= 1;
			if (str[i] != ' ' && str[i] != '"')
				cout << str[i];
			if (str[i] == ' ' && (!flag))
				cout << str[i];
			if (str[i] == ' ' && flag)
				cout << endl;
		}
		cout << endl;
	}
	return 0;
}

#endif

#if 0
//0715 2

#endif

#if 0
//0716 1

int main()
{
	int arrary[12] = { 31, 59, 90, 120, 151, 181, 21, 243, 273, 304, 334, 365 };
	int year, month, day, sum = 0;
	while (cin >> year >> month >> day)
	{
		sum = 0;
		sum += arrary[month - 2];
		sum += day;
		if (month > 2)
		{
			if ((year % 4 == 0 && year % 100 != 0)
								|| year % 400 == 0)
			{
				sum += 1;
			}
		}
		cout << sum << endl;
	}
}

#endif

#if 0
//0717 1

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		while (n)
		{
			if (n & 1)
			{
				count++;
			}
			n >>= 1;
		}
		cout << count << endl;
	}

	return 0;
}

#endif

#if 0
//0717 2

class Gloves
{
public:
	int findMinimum(int n, vector<int> left, vector<int> right)
	{
		int left_sum = 0, left_min = INT_MAX;
	}
};

#endif


#if 0
//0713 2 �ж�����

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
	int num;
	int half;
	int i;
	while (cin >> num)
	{
		half = num / 2;
		for (i = half; i > 0; i--)
		{
			if (isPrime(i) && isPrime(num - i))
				break;
		}

		cout << i << endl << num - i << endl;
	}
	return 0;
}

#endif

#if 0
//0715 1
int main()
{
	string str;
	while (getline(cin, str))
	{
		int count = 0;
		//�����������
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
				count++;
			if (str[i] == '"')
			{
				do
				{
					i++;
				} while (str[i] != '"');
			}
		}
	
		cout << count + 1 << endl;

		//��flag��ʾ�Ƿ����˫���ţ�0��ʾ��˫����
		//˫�����еĿո�Ҫ��ӡ����
		//�����ı�flag��ֵ,����˫���ſ���ʹflag��ԭ.

		int flag = 1;

		for (int i = 0; i < str.size(); i++)
		{
			//��˫����,flagͨ������Ϊ0,��һ����������1
			if (str[i] == '"')
				flag ^= 1;
			//˫���ź���ͨ�ո񲻴�ӡ
			if (str[i] != ' ' && str[i] != '"')
				cout << str[i];
			//˫�����еĿո�Ҫ��ӡ
			if (str[i] == ' ' && (!flag))
				cout << str[i];
			//����˫����֮��Ŀո�ͻ���
			if (str[i] == ' ' && flag)
				cout << endl;
		}
		cout << endl;
	}
	return 0;
}

#endif

#if 0
//0715 2

void divisorNum(int n, vector<int> & divNum)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
		{
			divNum.push_back(i);
			if (n / i != i)
				divNum.push_back(n / i);
		}
	}
}
int Jump(int N, int M)
{
	//�洢�ĵ����stepNum��Ĳ���,��ʼNΪ1��,��,��,Ϊ1��
	vector<int> stepNum(M + 1, 0);
	stepNum[N] = 1;

	for (int i = N; i < M; i++)
	{
		//N������Լ��, ��Ϊ�ӱ�������㿪ʼ���ߵ�����
		vector<int> divNum;

		//0��ʾ����㲻�ܵ�
		if (stepNum[i] == 0)
			continue;

		//���������ߵĲ����洢��divNum��������
		divisorNum(i, divNum);

		for (int j = 0; j < divNum.size(); j++)
		{
			if ((divNum[j] + i) <= M && stepNum[divNum[j] + i] != 0)
				stepNum[divisorNum(j) + i] = min(stepNum[divisorNum(j) + i], stepNum[i] + 1);
			else if ((divNum[j] + i) <= M)
				stepNum[divNum[j] + i] = stepNum[i] + 1;
		}
	}

	if (stepNum[M] == 0)
		return 0;
	else
		return stepNum[M] - 1;
}

int main()
{
	int n, m;
	cin >> n >> m;
	cout << Jump(n, m) << endl;
	return 0;
}

#endif

#if 0
//0716 1
int main()
{
	int array[12] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	int year;
	int month;
	int day;
	int sum = 0; 

	while (cin >> year >> month >> day)
	{
		sum = 0;
		sum += array[month - 2];
		sum += day;
		if (month > 2)
		{
			if ((year % 4 == 0 && year % 100 != 0)
				|| year % 400 == 0)
				sum += 1;
		}
		cout << sum << endl;
	}
}

#endif

#if 0
//0716 2

int getLuckyPacket(int x[], int n, int pos, int sum, int multi)
{
	int count;
	//ѭ��,������λ��i��ʼ�����п������
	for (int i = pos; i < n; i++)
	{
		sum += x[i];
		multi *= x[i];
		if (sum>multi)
		{
			//�ҵ�����Ҫ������,��1,�����ۼӺ�����
		}
	}
}

#endif

#if 0
//0718 1
int count(int n)
{
	int cnt = 0;
	if ((n<0) | (n>500000))
		return -1;
	else
	{
		for (int i = 2; i <= n; i++)
		{
			int sum = 0;
			double sq = sqrt(i);
			for (int j = 2; j <= sq; j++)
			{
				if (i%j == 0)
				{
					if (i / j == j)
						sum += j;
					else
						sum += j + (i / j);
				}
			}
			if (sum + 1 == i)
				cnt++;
		}
		return cnt;
	}
}

int main()
{
	int input;
	while (cin >> input)
		cout << count(input) << endl;
	return 0;
}

#endif

#if 1
int main()
{
	string line;
	while (getline(cin, line))
	{
		//��ը���,ֱ�����
		if (line.find("joker JOKER") != -1)
			cout << "joker JOKER" << endl;
		else
		{
			int dash = line.find('-');
			//�ֿ�������
			string car1 = line.substr(0, dash);
			string car2 = line.substr(dash + 1);
			//��ȡ�ո�Ĵ���,����Ϊc+1
			int c1 = count(car1.begin(), car1.end(), (' '));
			int c2 = count(car2.begin(), car2.end(), (' '));
			//�õ���һ����
			string first1 = car1.substr(0, car1.find(' '));
			string first2 = car2.substr(0, car2.find(' '));
			string str = "345678910JQKA2jokerJOKER";
			if (c1 == c2)
			{
				//ֻҪ�������,���һ���ƴ�ļ�Ϊ��
				if (str.find(first1) > str.find(first2))
					cout << car1 << endl;
				else
					cout << car2 << endl;
			}
			else
			{
				//��������ͬ,˵�����Ͳ�ͬ,ֻ��ը�����Ժ������ƱȽ�
				//���Ͷ��Ǵ����
				if (c1 == 3)
					cout << car1 << endl;
				else if (c2 == 3)
					cout << car2 << endl;
				else
					cout << "ERROR" << endl;
			}
		}
	}
}

#endif