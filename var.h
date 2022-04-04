#pragma once
#include <iostream>
#include <iostream>
#include <vector>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>

#define size 100

using namespace std;


int status;  // xet dieu kien output
vector<vector<double>> a;  // vecto luu cac chi so
vector<double> b, c, ct, sga, x;
vector<int> eql;  // vecto luu dau cau bai toan
vector<size_t> ar_id, base_id;
size_t st_num, x_num, x_num_, min_max; // so rang buoc, so bien 'x', ..., lua chon output ham muc tieu
size_t add_num=0, ba_num=0, ar_num=0;
size_t step = 1, section = 1, count = 1;
size_t in, out, inputMathod;
string datapath = "../data.txt";
ifstream ifs;
double z=0;
