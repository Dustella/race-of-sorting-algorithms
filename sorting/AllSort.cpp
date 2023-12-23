//
// Created by Mr.david on 12/22/2023.
//
#include "interface.cpp"
#include <algorithm>
#include <ctime>
#include <iostream>
using namespace std;

class StdSort : public SortingAlgorithm {

public:
  StdSort() { this->name = "StdSort"; }

  void sort(vector<int> arr) override {
    std::sort(arr.begin(), arr.end());
    this->result.push_back(arr);
  }
};

class InsertSort : public SortingAlgorithm {

public:
  InsertSort() { this->name = "InsertSort"; }

  void sort(vector<int> arr) override {
    int len = arr.size();
    for (int i = 1; i < len; ++i) {
      int current = arr[i];
      int j = i - 1;
      while (j >= 0 && arr[j] > current) {
        arr[j + 1] = arr[j];
        j--;
      }
      arr[j + 1] = current;
    }
    this->result.push_back(arr);
  }
};

class BubbleSort : public SortingAlgorithm {
public:
  BubbleSort() { this->name = "BubbleSort"; }

  void sort(vector<int> arr) override {
    int len = arr.size();
    for (int i = 0; i < len - 1; ++i) {
      for (int j = 0; j < len - i - 1; ++j) {
        // just swap
        if (arr[j] > arr[j + 1]) {
          swap(arr[j], arr[j + 1]);
        }
      }
    }
    result.push_back(arr);
  }
};

class QuickSort : public SortingAlgorithm {
public:
  QuickSort() { this->name = "QuickSort"; }

  void sort(vector<int> arr) override {
    int len = arr.size();
    quickSort(arr, 0, len - 1);
    result.push_back(arr);
  }

  void quickSort(std::vector<int> &vec, int begin, int end) {
    if (begin < end) {
      int key = vec[begin];
      int i = begin;
      int j = end;
      while (i < j) {
        while (i < j && vec[j] > key) {
          j--;
        }
        if (i < j) {
          vec[i] = vec[j];
          i++;
        }
        while (i < j && vec[i] < key) {
          i++;
        }
        if (i < j) {
          vec[j] = vec[i];
          j--;
        }
      }
      vec[i] = key;
      quickSort(vec, begin, i - 1);
      quickSort(vec, i + 1, end);
    }
  }
};

class HillSort : public SortingAlgorithm {
public:
  HillSort() { this->name = "HillSort"; }

  void sort(vector<int> arr) override {
    int len = arr.size();
    for (int gap = len / 2; gap > 0; gap /= 2) {
      for (int i = gap; i < len; ++i) {
        int j = i;
        int current = arr[i];
        while (j - gap >= 0 && current < arr[j - gap]) {
          arr[j] = arr[j - gap];
          j -= gap;
        }
        arr[j] = current;
      }
    }
    result.push_back(arr);
  }
};

class HeapSort : public SortingAlgorithm {
public:
  HeapSort() { this->name = "HeapSort"; }
  void sort(vector<int> arr) override {
    int len = arr.size();
    heap_sort(arr, len);
    result.push_back(arr);
  }

  void sift_down(vector<int> &arr, int start, int end) {
    // ���㸸�����ӽ����±�
    int parent = start;
    int child = parent * 2 + 1;
    while (child <= end) { // �ӽ���±��ڷ�Χ�ڲ����Ƚ�
      // �ȱȽ������ӽ���С��ѡ������
      if (child + 1 <= end && arr[child] < arr[child + 1])
        child++;
      // ����������ӽ��󣬴���������ϣ�ֱ����������
      if (arr[parent] >= arr[child])
        return;
      else { // ���򽻻��������ݣ��ӽ���ٺ�����Ƚ�
        swap(arr[parent], arr[child]);
        parent = child;
        child = parent * 2 + 1;
      }
    }
  }

  void heap_sort(vector<int> &arr, int len) {
    // �����һ���ڵ�ĸ��ڵ㿪ʼ sift down ����ɶѻ� (heapify)
    for (int i = (len - 1 - 1) / 2; i >= 0; i--)
      sift_down(arr, i, len - 1);
    // �Ƚ���һ��Ԫ�غ��Ѿ��źõ�Ԫ��ǰһλ�������������µ������յ�����Ԫ��֮ǰ��Ԫ�أ���ֱ���������
    for (int i = len - 1; i > 0; i--) {
      swap(arr[0], arr[i]);
      sift_down(arr, 0, i - 1);
    }
  }
};

class MergeSort : public SortingAlgorithm {
public:
  MergeSort() { this->name = "MergeSort"; }

  void sort(vector<int> arr) override {
    int len = arr.size();
    mergeSort(arr, 0, len);
    result.push_back(arr);
  }

  void mergeSort(vector<int> &vec, int l, int r) {
    if (r - l <= 1)
      return;
    // �ֽ�
    int mid = l + (r - l) / 2;
    mergeSort(vec, l, mid);
    mergeSort(vec, mid, r);
    // �ϲ�
    vector<int> tmp(r - l);
    merge(vec.begin() + l, vec.begin() + mid, vec.begin() + mid,
          vec.begin() + r, tmp.begin());
    copy(tmp.begin(), tmp.end(), vec.begin() + l);
  }
};

class SelectSort : public SortingAlgorithm {
public:
  SelectSort() { this->name = "SelectSort"; }

  void sort(vector<int> arr) override {
    int len = arr.size();
    for (int i = 0; i < len - 1; ++i) {
      int minIndex = i;
      for (int j = i + 1; j < len; ++j) {
        if (arr[j] < arr[minIndex]) {
          minIndex = j;
        }
      }
      swap(arr[minIndex], arr[i]);
    }
    result.push_back(arr);
  }
};