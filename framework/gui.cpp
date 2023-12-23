//
// Created by Mr.david on 12/21/2023.
//

#include "driver.cpp"
#include <iostream>

class GUI {
 public:
  void init() {
    cout << "Ñ¡ÔñÅÅÐòËã·¨" << endl;
    cout << "1¡¢²åÈëÅÅÐò" << endl;
    cout << "2¡¢Ã°ÅÝÅÅÐò" << endl;
    cout << "3¡¢¿ìËÙÅÅÐò" << endl;
    cout << "4¡¢¶ÑÅÅÐò" << endl;
    cout << "5¡¢¹é²¢ÅÅÐò" << endl;
    cout << "6¡¢Ï£¶ûÅÅÐò" << endl;
    cout << "7¡¢Ñ¡ÔñÅÅÐò" << endl;
    cout << "8¡¢std::sort()" << endl;
    cout << "9¡¢È«²¿ÔËÐÐ" << endl;
    int choose;
    cin >> choose;
    auto driver = new Driver();

    switch (choose) {
      case 1: {
        auto insertSort = new InsertSort();
        driver->setSortingAlgorithm(insertSort);
        break;
      }
      case 2: {
        auto bubbleSort = new BubbleSort();
        driver->setSortingAlgorithm(bubbleSort);
        break;
      }
      case 3: {
        auto quickSort = new QuickSort();
        driver->setSortingAlgorithm(quickSort);
        break;
      }
      case 4: {
        auto heapSort = new HeapSort();
        driver->setSortingAlgorithm(heapSort);
        break;
      }
      case 5: {
        auto mergeSort = new MergeSort();
        driver->setSortingAlgorithm(mergeSort);
        break;
      }
      case 6: {
        auto hillSort = new HillSort();
        driver->setSortingAlgorithm(hillSort);
        break;
      }
      case 7: {
        auto selectSort = new SelectSort();
        driver->setSortingAlgorithm(selectSort);
        break;
      }
      case 8: {
        auto stdSort = new StdSort();
        driver->setSortingAlgorithm(stdSort);
        break;
      }
      case 9: {
        driver->generateRandomNumber();
        driver->doAllSort();
        return;
      }
    }
    driver->generateRandomNumber();
    driver->doSort();
  }
};