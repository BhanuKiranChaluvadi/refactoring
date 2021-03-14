/*
 * As we suggested before, temporary variables can be a problem.
 * They are only useful with in their own routine, and therefore 
 * they encourage long, complex routine. 
 * 
 * Replace "format" variable. -- assign a function to a temp.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include<algorithm>

using namespace std;

void statement(auto invoice, auto plays) {
	double totalAmount = 0;
	double volumeCredits = 0;
	std::ostringstream result;
	result << "Statement for " << invoice.customer << "\n";
	for(auto & perf : invoice.performace){

        volumeCredits += volumeCreditsFor(perf);
		// print line for this order
		result << playFor(perf).name << " : " << "$" << usd(amountFor(perf)/100) << "  (" << perf.audience << " seats )\n";
		totalAmount += amountFor(perf);
	}							
	result << "Amount owed is $" << usd(totalAmount/100) << "\n";
	result << "you earned $" << volumeCredits << "\n";
	std::cout << result.str();
}

auto usd(aNumber){   // format
    return new Intl.NumberFormat(
										"en-US", 
									{
										style : "currency", currency : "USD",
										minimumFractionDigits: 2
									}).format(aNumber);
}

auto playFor(auto aPerformance) {
	return plays[aPerformance.playID];
}

double amountFor(auto aPerformance) {
  double result = 0;
	switch(playFor(aPerformance).type) {
		case "tragedy":
			result = 40000;
			if (aPerformance.audience > 30) {
				result += 1000 * (aPerformance.audience - 30);
			}
			break;
		case "comedy":
			result = 30000;
			if (aPerformance.audience > 20) {
				result += 1000 + 500 * (aPerformance.audience - 20);
			}	
			result += 300 * aPerformance.audience;
			break;
		default:
			throw new Error("unknow type: ${playFor(aPerformance).type}");
	}
	return result;
}

double volumeCreditsFor(auto aPerformance) {
	// add volume credits
    double result = 0;
	result += max(aPerformance.audience - 30, 0);
	// add extra credit for every 10 comedy attendees
	if ("comedy" == playFor(aPerformance).type) {
		result += floor(aPerformance.audience / 5);
	}
    return result;
}

