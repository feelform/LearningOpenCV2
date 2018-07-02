//
//  example_04-03.cpp
//  example_04-01
//
//  Created by KangYongseok on 02/07/2018.
//  Copyright © 2018 feelform Corp. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main(int argc, char** argv) {
    cout << "\nExample 4-3. Printing all of the nonzero elements of a sparse array"
    << "\nCall:\n" << argv[0] << endl;
    
    int size[] = {10, 10};
    cv::SparseMat sm(2, size, CV_32F);
    for (int i = 0; i < 10; i++) {
        int idx[2];
        idx[0] = size[0] * rand();
        idx[1] = size[1] * rand();
        sm.ref<float>(idx) += 1.0f;
    }
    
    cv::SparseMatConstIterator_<float> it = sm.begin<float>();
    cv::SparseMatConstIterator_<float> it_end = sm.end<float>();
    
    for (; it != it_end; ++it) {
        const cv::SparseMat::Node* node = it.node();
        printf(" (%3d,%3d) %f\n", node->idx[0], node->idx[1], *it);
    }
    
    return 0;
}
