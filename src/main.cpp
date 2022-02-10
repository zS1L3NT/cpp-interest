#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <math.h>
#include <cmath>
using namespace std;

bool strIsInt(string str);
bool in_arr(vector<string>, string item);

int main()
{
	cout << "Welcome to Interest calculator" << endl;
	cout << "What method of interest are you using?" << endl;
	cout << "	-> Simple Interest (s)" << endl;
	cout << "	-> Compound Interest (c)" << endl;

	bool cycle = true;
	vector<string> ok_methods = {"c", "s"};
	string method;
	do
	{
		cout << "Method: ";
		cin >> method;

		if (in_arr(ok_methods, method) == 0)
		{
			cout << "Invalid option" << endl;
		}
		else
		{
			cycle = false;
		}
	} while (cycle);
	cycle = true;
	cout << endl;

	if (method == "s")
	{
		// Get what you're finding
		vector<string> ok_findings = {"i", "p", "r", "t"};
		string finding;
		unordered_map<string, double> values;
		unordered_map<string, string> texts = {
			{"i", "Total Interest in $"},
			{"p", "Principal Sum in $"},
			{"r", "Rate of interest per annum in %"},
			{"t", "Time of loan in years"}};
		cout << "What are you finding?" << endl;
		cout << "	-> " << texts["i"] << ": $ (i)" << endl;
		cout << "	-> " << texts["p"] << ": $ (p)" << endl;
		cout << "	-> " << texts["r"] << ": % (r)" << endl;
		cout << "	-> " << texts["t"] << ": (t)" << endl;
		do
		{
			cout << "Finding: ";
			cin >> finding;

			if (in_arr(ok_findings, finding) == 0)
			{
				cout << "Invalid option" << endl;
			}
			else
			{
				cycle = false;
			}
		} while (cycle);
		cycle = true;
		cout << endl;

		// Acquire values
		for (int j = 0; j < ok_findings.size(); j++)
		{
			string i = ok_findings[j];
			if (finding != i)
			{
				string temp;
				do
				{
					cout << "Enter " << texts[i] << ": ";
					cin >> temp;

					if (!strIsInt(temp))
					{
						cout << "Input cannot contain letters" << endl;
					}
					else
					{
						values[i] = stod(temp);
						cycle = false;
					}
				} while (cycle);
				cycle = true;
			}
		}

		if (finding == "i")
		{
			cout << texts["i"] << ": $" << ((values["p"] * values["r"] * values["t"]) / 100);
		}
		else if (finding == "p")
		{
			cout << texts["p"] << ": $" << ((100 * values["i"]) / (values["r"] * values["t"]));
		}
		else if (finding == "r")
		{
			cout << texts["r"] << ": " << ((100 * values["i"]) / (values["p"] * values["t"])) << "%";
		}
		else if (finding == "t")
		{
			cout << texts["t"] << ": " << ((100 * values["i"]) / (values["p"] * values["r"]));
		}
	}
	else if (method == "c")
	{
		// Get what you're finding
		vector<string> ok_findings = {"a", "p", "r", "n"};
		string finding;
		unordered_map<string, double> values;
		unordered_map<string, string> texts = {
			{"a", "Total Amount"},
			{"p", "Principal Sum"},
			{"r", "Interest Rate per period"},
			{"n", "Number of years you are paying interest"}};
		cout << "What are you finding?" << endl;
		cout << "	-> " << texts["a"] << ": $ (a)" << endl;
		cout << "	-> " << texts["p"] << ": $ (p)" << endl;
		cout << "	-> " << texts["r"] << ": % (r)" << endl;
		cout << "	-> " << texts["n"] << ": (n)" << endl;
		do
		{
			cout << "Finding: ";
			cin >> finding;

			if (in_arr(ok_findings, finding) == 0)
			{
				cout << "Invalid option" << endl;
			}
			else
			{
				cycle = false;
			}
		} while (cycle);
		cycle = true;
		cout << endl;

		// Get Compounding Period
		string temp;
		double cp;
		do
		{
			cout << "Compounding period in number of times payment given per year" << endl;
			cout << "\te.g. If i pay every 6 months, put '2'" << endl
				 << "\te.g. If i pay every 2 years, put '0.5'" << endl;
			cout << ": ";

			cin >> temp;

			if (!strIsInt(temp))
			{
				cout << "Input cannot contain letters" << endl;
			}
			else
			{
				cp = stod(temp);
				cycle = false;
			}
		} while (cycle);
		cycle = true;

		// Acquire values
		for (int j = 0; j < ok_findings.size(); j++)
		{
			string i = ok_findings[j];
			if (finding != i)
			{
				do
				{
					cout << "Enter " << texts[i] << ": ";
					cin >> temp;

					if (!strIsInt(temp))
					{
						cout << "Input cannot contain letters" << endl;
					}
					else
					{
						values[i] = stod(temp);
						cycle = false;
					}
				} while (cycle);
				cycle = true;
			}
		}

		if (finding == "a")
		{
			double base = 1 + (values["r"] / (100 * cp));
			double expo = values["n"] * cp;
			cout << texts["a"] << ": $" << values["p"] * pow(base, expo);
		}
		else if (finding == "p")
		{
			double base = 1 + (values["r"] / (100 * cp));
			double expo = values["n"] * cp;
			cout << texts["p"] << ": $" << values["a"] / pow(base, expo);
		}
		else if (finding == "r")
		{
			double base = values["a"] / values["p"];
			double expo = 1 / (values["n"] * cp);
			cout << texts["r"] << ": " << round(100 * cp * (pow(base, expo) - 1));
		}
		else if (finding == "n")
		{
			double top = log10(values["a"] / values["p"]);
			double bottom = log10(1 + (values["r"] / (100 * cp)));
			cout << texts["n"] << ": " << round((top / bottom) / cp);
		}
	}
}

bool strIsInt(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]) && str[i] != '.')
		{
			return false;
		}
	}
	return true;
}
bool in_arr(vector<string> arr, string item)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == item)
		{
			return true;
		}
	}
	return false;
}