//
//  main.cpp
//  example_04-01
//
//  Created by Yongseok Kang on 27/06/2018.
//  Copyright © 2018 feelform Corp. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main(int argc, const char * argv[]) {
    
    cout << "\nExample 4-1. Summation of a multidimensional array, done plane by plane"
        << "\nCall:\n"
        << argv[0] << endl;
    
    const int n_mat_size = 5;
    const int n_mat_sz[] = { n_mat_size, n_mat_size, n_mat_size };
    cv::Mat n_mat(3, n_mat_sz, CV_32FC1);
    
    cv::RNG rng;
    rng.fill(n_mat, cv::RNG::UNIFORM, 0.1f, 1.f);
    
    const cv::Mat* arrays[] = { &n_mat, 0 };
    cv::Mat my_planes[1];
    cv::NAryMatIterator it(arrays, my_planes);
    
    float s = 0.f;
    int n = 0;
    for (int p = 0; p < it.nplanes; ++it) {
        s += cv::sum(it.planes[0])[0];
        n++;
    }
    
    cout << "Total across entire volume: " << s << endl;
    
    return 0;
}
