#include <iostream>
using namespace std;

class NumHolder{
 public:
    int num;
    NumHolder(int x){
	num = x;
    };
    NumHolder(){
	num = 0;
    };
    NumHolder& operator=(NumHolder arg){
	num = arg.num;
	return *this;
    };
};

bool operator<(NumHolder const& a, NumHolder const& b){
    return a.num < b.num;
}
bool operator>(NumHolder const& a, NumHolder const& b){
    return a.num > b.num;
}
bool operator==(NumHolder const& a, NumHolder const& b){
    return a.num == b.num;
}

ostream& operator<<(ostream& strm, const NumHolder &nh){
    return strm << "{Num: " << nh.num << "}";
}
