
#include <iostream>
#include "normalize.h"
#include "input.h"
#include "iterator.h"

using namespace std;


void showOr() {
    cout << endl << "Bai toan: " << endl;
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

    //cout << a[0][1] << endl;

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
        switch (eql[i]) {
        case 1:
            cout << " == " << b[i];
            break;
        case 2:
            cout << " >= " << b[i];
            break;
        case 3:
            cout << " <= " << b[i];
            break;
        }
        cout << endl;
    }
    cout << " x[1]~x[" << x_num << "] >= 0" << endl << endl;



}



void showPr() {
    if (section == 1) {
        cout << "min z = x[" << ar_id[0] << "]";
        for (size_t i=1; i<ar_num; ++i) {
            cout << " + x[" << ar_id[i] << "]";
        }
    } else if (section == 2) {
        cout << "min z = ";
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
    } else cout << "Section wrong" << endl;


    cout << endl << "Cac rang buoc: " << endl;
    for (size_t i=0; i<st_num; ++i) {
        int k = 0;
        for (size_t j=0; j<x_num; ++j) {
            if (a[i][j] != 0) {
                if (a[i][j]==1 && k==0){
                	cout << " x[" << j+1 << "]";
				}
                else if (a[i][j]==1 && k!=0){
                	cout << " + x[" << j+1 << "]";
				}
                else if (a[i][j]==-1 && k==0){
                	cout << " -x[" << j+1 << "]";
				}
                else if (a[i][j]==-1 && k!=0){
                	cout << " - x[" << j+1 << "]";
				}
                else if (a[i][j]>0 && k==0){
                	cout << " " << a[i][j] << "x[" << j+1 << "]";
				}
                else if (a[i][j]>0 && k!=0){
                	cout << " + " << a[i][j] << "x[" << j+1 << "]";
				}
                else if (a[i][j]<0 && k==0){
                	cout << " " << a[i][j] << "x[" << j+1 << "]";
				}
                else if (a[i][j]<0 && k!=0){
                	cout << " - " << -a[i][j] << "x[" << j+1 << "]";
				}
                k = 1;
            }
        }
        cout << " = " << b[i] << endl;
    }
    cout << " x[1]~x[" << x_num << "] >= 0" << endl << endl;;
}



void _result() {
    x.resize(x_num);
    cout << " *x = (";
    for (size_t i=0; i<x_num; ++i) {
        for (size_t j=0; j<st_num; ++j) {
            if (i==base_id[j]-1) {
                x[i] = b[j];
                break;
            } 
			else{
				x[i] = 0;
			}
        }
        cout << "  " << x[i] ;
    }
    cout << ")\t";
    cout << " *f = " << z << endl << endl;
}


void dataClear() {
    a.clear();  b.clear();  c.clear();
    ct.clear(); sga.clear();    x.clear();
    eql.clear();
    ar_id.clear();  base_id.clear();
    add_num = 0;    ba_num = 0;     ar_num = 0;
    step = 1;       section = 1;    count = 1;
    z = 0;
}

int main()
{
    
		
		inPut();

        showOr();

        normalize();

        ct.resize(x_num);

        for (size_t i=0; i<x_num; ++i) {
            size_t j = 0;
            for (; j<ar_num; ++j){
            	if (ar_id[j]-1 == i) break;
			}
            if (j == ar_num){
            	ct[i] = 0;
			}
            else{
            	ct[i] = -1;
			}
        }
        swap(c, ct);
        cout << "Bien doi lan 1 : " << endl;
        cout << "Ket qua : " ;
        showPr();
        _iterator();
        if (status == -2) {
            cout << "Time out" << endl;
            exit(0);
        }
        _result();

        if (z != 0) {
            cout << "Bai toan khong co phuong an." << endl;
            exit(0);
        }

        swap(c, ct);
        x_num -= ar_num;
        ar_num = 0;
        cout << "Bien doi lan 2 : " << endl;
        showPr();
        ++step;
        _iterator();
        cout << endl;

        switch (status) {
        case 1:
            cout << "Phuong an toi uu cua bai toan : " << endl;
            _result();
            break;
        case 0:
            cout << "Bai toan co vo so phuong an." << endl;
            break;
        case -1:
            cout << "Phuong an thay the." << endl;
            _result();
            break;
        case -2:
            cout << "Iteration time out" << endl;
            break;
        }
      

    return 0;
}
