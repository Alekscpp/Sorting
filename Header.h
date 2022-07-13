#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<List>
#include <ctime>
#include <vector>

using std::string;
using namespace std;

void Sort(vector<int>& v) {
	int n = v.size();
	for (int i = 1; i < n; i++)
	{
		int k = i;
		while (k > 0 && v[k - 1] > v[k]) {
			swap(v[k], v[k - 1]);
			k -= 1;
		}
	}
}
