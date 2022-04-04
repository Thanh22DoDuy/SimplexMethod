#include <iostream>
#include "var.h"

using namespace std;

void inPut() {

    while(1) {
        cout << "Ban lua chon: 1->max, 2->min - (1/2): ";
        cin >> min_max;
        if (min_max!=1 && min_max!=2){
            cout << "Dau vao sai! Vui long chon lai." << endl;
        }
        else break;
    }

    while(1) {
        cout << "\n***So bien x:";
        cin >> x_num;
        cout << "--Nhap c[1]~c[" << x_num << "]: " << endl;
        for (size_t i=0; i<x_num; ++i) {
            cout << "\tc" << i+1 << " = ";
            double c_;
            cin >> c_;
            c.push_back(c_);  // them gia tri vao c
        }

        if (min_max==1){
        	cout << "**Max z = ";
		}
        else{
        	cout << "**Min z = ";
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
        cout << "\t";
        
		a1: cout << "\tKet qua nhap chinh xac? - (y/n): ";
		
        char yn;
        cin >> yn;
        if (yn == 'y'){
        	break;
		}
        else if (yn == 'n'){
        	continue;
		}
        else {
            cout << "\tDau vao loi!" << endl;
            goto a1;
        }
    }

    cout << "\n***So rang buoc: ";
    cin  >> st_num;
    // reset kich thuoc cac vecto
    eql.resize(size);
    b.resize(size);
    base_id.resize(size);
    ar_id.resize(size);
    
    // lua chon dau cho rang buoc
    for (size_t i=0; i<st_num; ++i) {
        cout << "--Rang buoc thu: " << i+1 << ":" << endl;
        while (1) {
            cout << "+++Chon dau: 1: ==; 2: >=, 3: <=.  --- (1/2/3): ";
            cin >> eql[i];
            if(eql[i]!=1 && eql[i]!=2 && eql[i]!=3){
            	cout << "Dau vao sai! Vui long chon lai." << endl;
			}
            else break;
        }

		// nhap he so rang buoc
        cout << "--Input a: " << endl;
        vector<double> a_(x_num);
        for (size_t j=0; j<x_num; ++j) {
            cout << "\ta" << j+1 << " = ";
            cin >> a_[j];
        }
        a.push_back(a_);
		
		// nhap gia tri rang buoc
        cout << "--Input b: " << endl;
        cout << "\tb" << i+1 << " = ";
        cin >> b[i];
        cout << "St." << i+1 << ": ";
        if (a[i][0]==1){
        	cout << "x[1]";
		}
        else if(a[i][0]==-1){
        	cout << "-x[1]";
		}
        else if(a[i][0]!=0){
        	cout << " " << a[i][0] << "x[1]";
		}
        for (size_t j=1; j<x_num; ++j) {
            if(a[i][j]==1){
            	cout << " + x[" << j+1 << "]";
			}
            else if (a[i][j]==-1){
            	cout << " - x[" << j+1 << "]";
			}
            else if (a[i][j]>0){
            	cout << " + " << a[i][j] << "x[" << j+1 << "]";
			}
            else if (a[i][j]<0){
            	cout << " - " << -a[i][j] << "x[" << j+1 << "]";
			}
        }
        switch (eql[i]) {
	        case 1:{
	        	cout << " == " << b[i];
				break;
			}
	        case 2:{
	        	cout << " >= " << b[i];
				break;
			}
	        case 3:{
	        	cout << " <= " << b[i];
				break;
			}
        }

        while (1) {
            cout << "\t" ;
            cout << "*** Du lieu nhap chinh xac? - (y/n): ";
            char yn;
            cin >> yn;
            if (yn == 'y'){
            	break;
			}
            else if(yn == 'n') {
				--i; 
				a.pop_back();
				break;
			}
        }
        cout << endl;
    }

    c.resize(size);
    a.resize(size);



}
