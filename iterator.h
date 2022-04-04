#pragma once
#include <iostream>
#include "var.h"

using namespace std;

void outPut() {
    cout  << "Bang don hinh thu: " << count << endl;
    cout << "c" << "\t";
    for ( size_t i=0; i<x_num; ++i ){
    	cout << c[i] << "\t";
	}
    cout << z << endl;

    cout << " " << "\t";
    for ( size_t i=0; i<x_num; ++i ) {
        cout << "x" << i+1 << "\t";
    }
    cout << "b" << "\t" << endl;

    for ( size_t i=0; i<st_num; ++i ) {
        cout << "x[" << base_id[i] << "]\t";
        for( size_t j = 0 ; j < x_num ; ++j ){
        	cout << a[i][j] << "\t";
		}
        cout << b[i] << "\t" << endl;
    }

    cout << "Delta: " << "\t";
    for (size_t i=0; i<x_num; ++i) {
        cout << sga[i] << "\t" ;
    }
    cout << endl;
}

void _iterator() {
    size_t k_f, k_a;
    size_t mainElerow;
    double mainElevalue;

    //Delta
    sga.resize(x_num);
    for (size_t i=0; i<x_num; ++i) {
        sga[i] = c[i];
        for (size_t j=0; j<st_num; ++j){
        	sga[i] -= c[base_id[j]-1] * a[j][i];
		}
        for (size_t j=0; j<st_num; ++j){
        	if (i==base_id[j]-1){
        		sga[i] = 0;
			}
		}
    }

    z = 0;
    for (size_t j=0; j<st_num; ++j){
    	z -= c[base_id[j]-1] * b[j];
	}

    outPut();

    size_t k_ = 0;
    for (; k_<x_num; ++k_){
    	if (sga[k_] > 0){
    		break;
		}
	}
    if (k_ == x_num) {
        for (size_t i=0; i<x_num; ++i) {
            k_f = k_a = 0;
            for(size_t j=0; j<ar_num; ++j){
            	if(i==ar_id[j]) k_a=1;
			}
            if(sga[i]==0 && k_a!=1) {
                for(size_t j=0; j<st_num; ++j){
                	if(i==base_id[j]-1){
                		k_f=1;
					}
				}
                if(k_f==0) {
					status=-1; 
					return;
				}
            }
        }
        status = 1;
        return;
    }

    for(size_t i=0; i<x_num; ++i) {
        k_f = 0;
        if(sga[i] > 0) {
            for(size_t j=0; j<st_num; ++j){
            	if(a[j][i]>0){
            		k_f=1;
				}
			}
            if(k_f!=1) {
				status=0; 
				return;
			}
        }
    }


    //base in
    double sgaMax = -INT_MAX;
    for (size_t i=0; i<x_num; ++i) {
        if (sga[i]>0 && sgaMax<sga[i] ) {
            in = i;
            sgaMax = sga[i];
        }
    }

    //base out
    double staMin = INT_MAX;
    //size_t staMinrow = 0;
    for (size_t i=0; i<st_num; ++i) {
        if (b[i]/a[i][in]<=staMin && a[i][in]>0) {
            bool exc = false;
            if(b[i]/a[i][in] == staMin) {
//                for (size_t j=0; j<ar_num; ++j)
//                    if (base_id[i] == ar_id[j])
//                        exc = true;
                for (size_t j=0; j<x_num; ++j) {
                    if (j == in){
                    	continue;
					}
                    if (a[i][j]/a[i][in]<a[mainElerow][j]/a[mainElerow][in]) {
                        exc = true;
                        break;
                    }
                }

            } else exc = true;
            if (exc) {
                out = base_id[i];
                mainElerow = i;
                staMin = b[i]/a[i][in];
            }
        }
    }





    cout << "Vecto co so: (";
    for (size_t i=0; i<st_num; ++i){
    	cout << " x[" << base_id[i] << "]";
	}
    cout << ")\t\t";
    cout << "Hang xoay: x[" << out << "]\t\t";
    cout << "Cot xoay: x[" << in+1 << "]" << endl << endl;

    for (size_t i=0; i<st_num; ++i){
    	if (base_id[i]==out){
    		base_id[i]=in+1;
		}
	}

    mainElevalue = a[mainElerow][in];
    b[mainElerow] /= mainElevalue;
    for (size_t i=0; i<x_num; ++i){
    	a[mainElerow][i]/=mainElevalue;
	}
    for (size_t i=0; i<st_num; ++i) {
        if (i!=mainElerow) {
            b[i] -= b[mainElerow]*a[i][in];
            mainElevalue = a[i][in];
            for (size_t j=0; j<x_num; ++j){
            	a[i][j] -= a[mainElerow][j]*mainElevalue;
			}
        }
    }

    ++count;
    if (count > 200) {
        status = -2;
        return;
    }

    _iterator();




}

