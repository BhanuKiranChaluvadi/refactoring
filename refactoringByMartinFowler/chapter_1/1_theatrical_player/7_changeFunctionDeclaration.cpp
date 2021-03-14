/*
 * Change Function Decleration to "amountFor" to remove the
 * "play parameter". We will do it in two steps
 * 1. First, we use the new function "inside" "amountFor" 
 * 		compile and run tests
 * 2. Second , we remove arguement from function.
 * 
 * This refactoring alarms some programers. Previously, the code
 * to look for "play" was executed once in each loop iteration.
 * now it executes "thrice". We will talk about it later.
 * 
 * The great benifit of removing local varibles is that it makes
 * it much easier to do extraction, since there is less local 
 * scope to deal with. Indeed, usually we will take out local
 * variables before i do any extraction.
 * 
 * play - temporary varaible that is not update again.
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
		double thisAmount = amountFor(perf);

		// add volume credits
		volumeCredits += max(perf.audience - 30, 0);
		// add extra credit for every 10 comedy attendees
		if ("comedy" == playFor(perf).type) {
			volumeCredits += floor(perf.audience / 5);
		} 

		// print line for this order
		result << playFor(perf).name << " : " << "$" << thisAmount << "  (" << perf.audience << " seats )\n";
		totalAmount += thisAmount;
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