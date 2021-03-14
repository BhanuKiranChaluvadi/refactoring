/*
 * Replacd Temp variable with Query
 * Step 1: Extract Function
 * Step 2: Inline Variable
 * 
 * Let pause a bit and talk about what we have done here. Firstly, I know 
 * readers will again be worry about performance with this changes, as many 
 * people are wary of repeating a loop. But most of the time running a loop
 * of this has a negligible effect on performance.
 * 
 * Here are the 4 step we followed for "volumeCredit"
 * 1. SPlit the loop - to isolate the accumulation
 * 2. Slide Statement - to bring the initialization code next to the accumulation
 * 3. Etract Function - to create a function
 * 4. Inline variable - to remove the variable completely.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include<algorithm>

using namespace std;

void statement(auto invoice, auto plays) {
	std::ostringstream result;
	result << "Statement for " << invoice.customer << "\n";
	for(auto & perf : invoice.performace){
		// print line for this order
		result << playFor(perf).name << " : " << "$" << usd(amountFor(perf)/100) << "  (" << perf.audience << " seats )\n";
	}
	result << "Amount owed is $" << usd(totalAmount()) << "\n";
	result << "you earned $" << totalVolumeCredits() << "\n";
	std::cout << result.str();
}

auto usd(double aNumber){   // format
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

double totalVolumeCredits(){
	double result = 0;
	for(auto & perf : invoice.performace){
		result += volumeCreditsFor(perf);
	}
	return result;
}

double totalAmount(){
	double result = 0;
	for(auto & perf : invoice.performace){
		result += amountFor(perf);
	}
	return result;
}

