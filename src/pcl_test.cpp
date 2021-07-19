#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
vector<string> split(const string& _str, const string& _pattern) {
  // const char* convert to char*
  char* strc = new char[strlen(_str.c_str()) + 1];
  strcpy(strc, _str.c_str());
  vector<string> resultVec;
  char* tmpStr = strtok(strc, _pattern.c_str());
  while (tmpStr != NULL) {
    resultVec.push_back(string(tmpStr));
    tmpStr = strtok(NULL, _pattern.c_str());
  }

  delete[] strc;

  return resultVec;
}
vector<int> string2int_vector(const vector<string>& _str_vector) {
  vector<int> nums_vector;
  for (auto it = _str_vector.begin(); it != _str_vector.end(); it++) {
    int num;
    stringstream string_convert2int;
    string_convert2int << *it;
    string_convert2int >> num;
    nums_vector.push_back(num);
  }
  return nums_vector;
}
vector<int> read_pcd_muns(const vector<string>& _name_str_vector,
                          const vector<string>& _split_string_vector) {
  vector<string> name_out;
  vector<int> nums_vector;

  name_out = split(*_name_str_vector.begin(), _split_string_vector[0]);
  for (auto it = name_out.begin(); it != name_out.end(); it++) {
    std::cout << "name_out_1:" << *it << std::endl;
  }
  name_out = split(*name_out.rbegin(), _split_string_vector[1]);
  for (auto it = name_out.begin(); it != name_out.end(); it++)
    std::cout << "name_out_2:" << *it << std::endl;
  name_out = split(*name_out.begin(), _split_string_vector[2]);
  for (auto it = name_out.begin(); it != name_out.end(); it++)
    std::cout << "name_out_3:" << *it << std::endl;

  nums_vector = string2int_vector(name_out);
  return nums_vector;
}
int main(int argc, char** argv) {
  //创建了一个名为cloud的指针，储存XYZ类型的点云数据
  /// home/jz/map_save/10_0_0.pcd

  vector<string> name_out{"/home/jz/map_save/10_0_0.pcd",
                          "/home/jz/map_save/20_2_2.pcd"};
  vector<string> pattern{"/", ".", "_"};
  vector<int> num;
  for (auto it = pattern.begin(); it < pattern.end(); it++) {
    name_out = split(name_out[0], *it);
  }
  num = read_pcd_muns(name_out, pattern);
  // name_out = split(*name_out.begin(), pattern[0]);
  // name_out = split(*name_out.rbegin(), pattern[1]);
  // name_out = split(*name_out.begin(), pattern[2]);

  // for (auto it = pattern.begin(); it < pattern.end(); it++) {
  //   name_out = split(name_out[0], *it);
  // }

  for (auto it = name_out.begin(); it != name_out.end(); it++) {
    std::cout << *it << std::endl;
  }
  for (auto it = num.begin(); it != num.end(); it++) {
    std::cout << *it << std::endl;
  }
  // for (auto it = num.begin(); it != num.end(); it++) {
  //   std::cout << *it << std::endl;
  // }

  return 0;
}
// void part(string _str, vector<int>& _num, vector<char>& _op) {
//   int sum = 0;
//   unsigned int i = 0;

//   while (i < _str.length()) {
//     if ('0' <= _str.at(i) && _str.at(i) <= '9')
//       //还原连续的数字
//       sum = sum * 10 + (_str.at(i) - '0');
//     else {
//       _num.push_back(sum);
//       _op.push_back(_str.at(i));
//       sum = 0;
//     }
//     i++;
//   }

//   //判断最后一个字符是否是数字
//   if (0 != sum) _num.push_back(sum);
// }