#include <iostream>
#include <vector>
using namespace std;

int calMD(vector <double>& arr1, vector <double>& arr2, vector <char>& arr,int n)
{
	int i = n;
	do
	{
		if (arr[i] == '*')
		{
			arr1[i + 1] = arr1[i] * arr1[i + 1];
		}
		else
		{
			arr1[i + 1] = arr1[i] / arr1[i + 1];
		}
		i++;
	} while (arr[i]=='*'|| arr[i] == '/');
	arr2.push_back(arr1[i]);
	return i - n;
}

int main()
{
	cout << "请输入表达式：";
	double i = 0;
	int num = 0;
	vector <double> arr1,arr2;
	char ch;
	vector <char> arr;
	do
	{
		cin >> i >> ch;
		arr1.push_back(i);
		arr.push_back(ch);
		num++;
	} while (arr[num-1] != '=');
	for(int j=0;j<num;j++)
	{
		if (arr[j] == '*' || arr[j] == '/')
		{
			j+=calMD(arr1,arr2,arr,j);
		}
		else
		{
			arr2.push_back(arr1[j]);
		}
	}
	double sum = 0;
	sum += arr2[0];
	i = 0;
	for (int j = 0; j < arr2.size() && i + 1 < arr2.size(); j++)
	{
		while (1)
		{
			if (arr[j] == '+')
			{
				sum += arr2[i + 1];
				i++;
				break;
			}
			else if (arr[j] == '-')
			{
				sum -= arr2[i + 1];
				i++;
				break;
			}
			else
			{
				j++;
			}
		}
	}
	cout << "结果为："<<sum;
	return 0;
}