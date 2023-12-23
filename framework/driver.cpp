//
// Created by Mr.david on 12/21/2023.
//

#include "../sorting/AllSort.cpp"
#include <fstream>
#include <iostream>
#include <random>
#include <map>

class Driver {
private:
    SortingAlgorithm *currentAlgorithm;
    vector<vector<int>> sampleData;

public:
    void generateRandomNumber() {
        auto superpool = new vector<int>();
        for (int i = 1; i <= 100000; i++) {
            superpool->push_back(i);
        }
        // size: 10, 100, 1000, 10e4, 10e5
        auto sizeList = {10, 100, 1000, 10000, 100000};
        for (auto size: sizeList) {
            auto newSample = new vector<int>();
            newSample->assign(superpool->begin(), superpool->begin() + size);
            //            shuffle

            shuffle(newSample->begin(), newSample->end(),
                    default_random_engine(1111));
            this->sampleData.push_back(*newSample);
        }
    }

    void setSortingAlgorithm(SortingAlgorithm *c) { currentAlgorithm = c; }

    void doSort() {
        this->currentAlgorithm->setSampleData(this->sampleData);
        this->currentAlgorithm->printFirstSample();
        this->currentAlgorithm->excute();
        this->currentAlgorithm->printFirstResult();
        this->currentAlgorithm->writeReport();
        cout << "=========" << endl;
    }

    void doAllSort() {
        map<string, vector<pair<int, int>>> timeMapping;
        SortingAlgorithm *all[] = {
                new StdSort(), new InsertSort(), new BubbleSort(), new QuickSort(),
                new HeapSort(), new MergeSort(), new HillSort(), new SelectSort(),
        };
        for (SortingAlgorithm *c: all) {
            this->currentAlgorithm = c;
            this->doSort();
            this->currentAlgorithm->writeReport();
            auto timRes = new vector<pair<int, int>>();
            for (auto item: this->currentAlgorithm->getTimeResult()) {
                timRes->push_back(item);
            }
            timeMapping.insert(make_pair(this->currentAlgorithm->getName(), *timRes));
        }

        // write all sort result to csv
        ofstream outCsv("report/timing.csv");
        outCsv << "name,10_time,100_time,1000_time,10000_time,100000_time" << endl;
        for (auto item: timeMapping) {
            outCsv << item.first << ",";
            for (auto time: item.second) {
                outCsv << time.second << ",";
            }
            outCsv << endl;
        }
        outCsv.close();
    }
};