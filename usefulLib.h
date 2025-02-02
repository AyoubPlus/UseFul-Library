#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

namespace UsefullLib
{
	static vector<string> SplitString(string Str, string Sep = "/")
	{
		vector<string> vStr;
		short Post = 0;
		string SubStr = "";

		while ((Post = Str.find(Sep)) != Str.npos)
		{
			SubStr = Str.substr(0, Post);
			vStr.push_back(SubStr);
			Str.erase(0, Post + Sep.length());
		}

		if (Str != "")
		{
			vStr.push_back(Str);
		}
		return vStr;

	}

	static void ReplaceStrInText(string& Str, string OldStr, string NewStr)
	{
		short Post;

		while ((Post = Str.find(OldStr)) != string::npos)
		{
			Str.replace(Post, OldStr.length(), NewStr);
		}
	}

	static string ReadString(string Message, short MaxCharNumber = 100)
	{
		string Str;
		cout << Message << ": ";
		getline(cin, Str);
		if (Str == "")
		{
			getline(cin, Str);
		}
		while (Str.length() > MaxCharNumber)
		{
			cout << Message << ": ";
			getline(cin, Str);
		}
		return Str;
	}

	static void PrintScreen(string Title, string SubTitle = "")
	{
		system("cls");
		cout << "\t\t\t{ " << Title << " }" << SubTitle << "\n\n";
	}

	static void PrintVectorOfStr(vector<string> vStr)
	{
		for (string Str : vStr)
		{
			cout << Str << endl;
		}
	}

	static void PromptMessage(string Message)
	{
		cout << Message << endl;
		system("pause>0");
	}

	static short ChoseOption(short From, short To, string Message = "")
	{
		short Op;
		do
		{
			cout << Message;
			cin >> Op;
		} while (Op > To || Op < From);
		return Op;
	}

	static short ChoseOption(short From, short To, vector<string> vStr, char Format = 'V')
	{
		short Op;

		if (Format == 'V')
			Format = '\t';
		else
			Format = '\n';

		for (short i = 0; i < vStr.size(); i++)
		{
			cout << "[" << i + 1 << "] " << vStr[i] << Format;
		}
		cout << endl;
		do
		{
			cin >> Op;
		} while (Op > To || Op < From);
		return Op;
	}

};

