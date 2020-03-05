#pragma once
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<string> split(string data)
{
	vector<string> results;
	istringstream memStream(data);
	string token;
	while (getline(memStream, token, ','))
	{
		results.push_back(token);
	}
	return results;
}

