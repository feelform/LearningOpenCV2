//
//  example_04-02.cpp
//  example_04-01
//
//  Created by KangYongseok on 29/06/2018.
//  Copyright © 2018 feelform Corp. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main(int argc, char** argv) {
    
    cout << "\nExample 4-2. Summation of two arrays using the N-ary operator"
        << "\nCall:\n"
        << argv[0] << endl;
    
    const int n_mat_size = 5;
    const int n_mat_sz[] = { n_mat_size, n_mat_size, n_mat_size };
    
    cv::Mat n_mat0(3, n_mat_sz, CV_32FC1);
    cv::Mat n_mat1(3, n_mat_sz, CV_32FC1);
    
    cv::RNG rng;
    rng.fill(n_mat0, cv::RNG::UNIFORM, 0.f, 1.f);
    rng.fill(n_mat1, cv::RNG::UNIFROM, 0.f, 1.f);
    
    const cv::Mat* arrays[] = { &n_mat0, &n_mat1, 0 };
    
    cv::Mat my_planes[2];
    cv::NAryMatIterator it(arrays, my_planes);
    
    double s = 0.f;
    int n = 0;
    for (std::size_t p = 0; p < it.nplanes; p++, ++it) {
        s += cv::sum(it.planes[0])[0];
        s += cv::sum(it.planes[1])[0];
        n++;
    }

    cout << "Total across both volumes: " << s << endl;
    return 0;
}
