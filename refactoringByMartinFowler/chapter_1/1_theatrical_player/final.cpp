#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include<algorithm>

using namespace std;

class PlayType {
public:
	PlayType(){}
	virtual double basePerformanceAmount() const = 0 ;
	virtual double VolumeCredit() const = 0 ;

};

class Tragedy : public PlayType {
public:
	Tragedy() : basePerformaceAmount(40000), minAudiance(30) {}
	double basePerformanceAmount() const override {
		return basePerformaceAmount;
	}
	
	double audianceVariableAmount(int audiance) {
		return 1000 * (audiance - minAudiance);
	}

	double VolumeCredit() const override {
		return 0.0;
	}	
private:
	const int minAudiance;
	const double basePerformaceAmount;
};

class comedy : public PlayType {
	double basePerformanceAmount() const override {
		double amount = 0;
	}
	double VolumeCredit() const override {
		
	}
};

int main() {

}