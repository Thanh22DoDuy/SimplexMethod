#pragma once
#include <iostream>
#include <vector>
#include <cstdio>
#include "var.h"
using namespace std;


void normalize() {
    x_num_ = x_num;
    for (size_t i=0; i<st_num; ++i) {
        switch (eql[i]) {
        case 1:
        case 3:
            x_num++;
            break;
        case 2:
            x_num += 2;
            break;
        }
    }
    c.resize(x_num);
    for (size_t i=0; i<st_num; ++i) {
        a[i].resize(x_num);
    }

    if (min_max == 2)
        for (size_t i=0; i<x_num_; ++i){
        	c[i] *= -1;
		}

    for (size_t i=0; i<st_num; ++i) {
        switch (eql[i]) {
        case 1:
            break;
        case 2:
            add_num++;
            c[x_num_+add_num-1]=0;
            for(size_t j=x_num_; j<x_num; j++){
            	if(j==x_num_+add_num-1){
            		a[i][x_num_+add_num-1]=-1;
				}
			}
            break;
        case 3:
            add_num++;
            ba_num++;
            c[x_num_+add_num-1]=0;
            base_id[ba_num-1] = x_num_ + add_num;
            for(size_t j=x_num_; j<x_num; j++){
            	if(j==x_num_+add_num-1){
            		a[i][j]=1;
				}
			}
            break;
        }
    }

    for (size_t i=0; i<st_num; ++i) {
        switch (eql[i]) {
        case 1:
            add_num++;
            ba_num++;
            ar_num++;
            c[x_num_+add_num-1] = 0;
            base_id[ba_num-1] = ar_id[ar_num-1] = x_num_ + add_num;
            for(size_t j=x_num_; j<x_num; j++){
            	if(j==x_num_+add_num-1){
            		a[i][j] = 1;
				}
			}
            break;
        case 2:
            add_num++;
            ba_num++;
            ar_num++;
            c[x_num_+add_num-1]=0;
            base_id[ba_num-1] = ar_id[ar_num-1] = x_num_ + add_num;
            for(size_t j=x_num_;j<x_num;j++){
            	if(j==x_num_+add_num-1){
            		a[i][j] = 1;
				}
			}
            break;
        case 3:
            break;
        }

        vector<size_t> base_id_;
        for (size_t i=0; i<st_num; ++i) {
            for (size_t j=0; j<ba_num; ++j){
            	if (a[i][base_id[j]-1] == 1){
            		base_id_.push_back(base_id[j]);
				}
			}
        }
        base_id = base_id_;
    }

    cout << "Bai toan phu: " << endl;
    if (min_max == 1){
    	cout << "max z = ";
	}
    else{
    	cout << "min z = ";
	}
    if (c[0]==1){
    	cout << "x[1]";
	}
    else if(c[0]==-1){
    	cout << "-x[1]";
	}
    else if(c[0]!=0){
    	cout << " " << c[0] << "x[1]";
	}
    for (size_t i=1; i<x_num; ++i) {
        if(c[i]==1){
        	cout << " + x[" << i+1 << "]";
		}
        else if (c[i]==-1){
        	cout << " - x[" << i+1 << "]";
		}
        else if (c[i]>0){
        	cout << " + " << c[i] << "x[" << i+1 << "]";
		}
        else if (c[i]<0){
        	cout << " - " << -c[i] << "x[" << i+1 << "]";
		}
    }

    cout << endl << "Cac rang buoc: " << endl;
    for (size_t i=0; i<st_num; ++i) {
        for (size_t j=0; j<x_num; ++j) {
            if (a[i][j] != 0) {
                if (a[i][j]==1 && j==0){
                	cout << " x[" << j+1 << "]";
				}
                else if (a[i][j]==1 && j!=0){
                	cout << " + x[" << j+1 << "]";
				}
                else if (a[i][j]==-1 && j==0){
                	cout << " -x[" << j+1 << "]";
				}
                else if (a[i][j]==-1 && j!=0){
                	cout << " - x[" << j+1 << "]";
				}
                else if (a[i][j]>0 && j==0){
                	cout << " " << a[i][j] << "x[" << j+1 << "]";
				}
                else if (a[i][j]>0 && j!=0){
                	cout << " + " << a[i][j] << "x[" << j+1 << "]";
				}
                else if (a[i][j]<0 && j==0){
                	cout << " " << a[i][j] << "x[" << j+1 << "]";
				}
                else if (a[i][j]<0 && j!=0){
                	cout << " - " << -a[i][j] << "x[" << j+1 << "]";
				}
            }
        }
        cout << " = " << b[i] << endl;
    }
    cout << " x[1]~x[" << x_num << "] >= 0" << endl << endl;
}
