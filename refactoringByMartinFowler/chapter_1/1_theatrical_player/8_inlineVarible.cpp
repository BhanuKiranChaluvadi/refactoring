/*
 * Now we are done with argument to "amountFor". We will look
 * back at where its called. Its being used to set a temporary
 * variable that's not update again.
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
	const format = new Intl.NumberFormat(
										"en-US", 
									{
										style : "currency", currency : "USD",
										minimumFractionDigits: 2
									}).format;

	for(auto & perf : invoice.performace){
		// add volume credits
		volumeCredits += max(perf.audience - 30, 0);
		// add extra credit for every 10 comedy attendees
		if ("comedy" == playFor(perf).type) {
			volumeCredits += floor(perf.audience / 5);
		} 

		// print line for this order
		result << playFor(perf).name << " : " << "$" << amountFor(perf) << "  (" << perf.audience << " seats )\n";
		totalAmount += amountFor(perf);
	}							
	result << "Amount owed is $" << totalAmount << "\n";
	result << "ypu earned $" << volumeCredits << "\n";
	std::cout << result.str();
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

