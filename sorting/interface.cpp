
#include <ctime>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <windows.h>

namespace fs = std::filesystem;

using namespace std;

#ifndef SORTINGALGORITHM_H
#define SORTINGALGORITHM_H

class SortingAlgorithm {
 protected:
  map<int, int> timeMapping;
  vector<vector<int>> sampleData;
  vector<vector<int>> result;
  string name;

 public:
  void excute() {
    auto target = this->sampleData;
    for (auto singleSample : target) {
      LARGE_INTEGER t1, t2;

      vector<int> res(singleSample.begin(), singleSample.end());
      QueryPerformanceCounter(&t1);
      this->sort(res);
      QueryPerformanceCounter(&t2);
      int duration = t2.QuadPart - t1.QuadPart;

      this->timeMapping.insert(make_pair(res.size(), duration));
      cout << this->name << ": " << res.size() << ", Time Used: " << duration
           << "s" << endl;
    }
  }

  virtual void sort(vector<int> arr) {};

  map<int, int> getTimeResult() { return this->timeMapping; };

  void printFirstSample() {
    if (this->sampleData.size() > 0) {
      cout << "First Sample: ";
      for (auto i : this->sampleData[0]) {
        cout << i << " ";
      }
      cout << endl;
    }
  }

  void printFirstResult() {
    if (this->result.size() > 0) {
      cout << "First Result: ";
      for (auto i : this->result[0]) {
        cout << i << " ";
      }
      cout << endl;
    }
  }

  void setSampleData(vector<vector<int>> res) { this->sampleData = res; }

  void setName(string name) { this->name = name; }

  string getName() { return this->name; }

  map<int, int> getTimeMapping() { return this->timeMapping; }

  void writeReport() {
//      if there is no report directory, create one
    if (!fs::exists("report")) {
      fs::create_directory("report");
    }
    string path = "report/";
    path.append(this->name);
    path.append(".txt");
    cout << "生成报告 位置 " << path << endl;

    ofstream out(path);

    out << "Sorting Result Report" << endl;
    out << "Size\tTime" << endl;
    for (auto item : this->timeMapping) {
      out << item.first << "\t" << item.second << endl;
    }
    out << "=========" << endl;
    out << "Sample Data" << endl;
    for (int i = 0; i < this->sampleData.size(); ++i) {
      out << "Sample " << i << ": " << endl;
      for (auto item : this->sampleData[i]) {
        out << item << " ";
      }
      out << endl;
      out << "Result " << i << ": " << endl;
      for (auto item : this->result[i]) {
        out << item << " ";
      }
      out << endl;
      out << "===========" << endl;
    }
    out.close();
  }
};

#endif //SORTINGALGORITHM_H
