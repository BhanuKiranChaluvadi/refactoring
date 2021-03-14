/*
 * As we consider parameters for "amountFor", we look to see where they
 * come from. aPerformance come from loop varaible, so naturally change
 * with each iteration through the lopp. But the play is computed from 
 * performance. so no need to pass in "play" parameter at all. - we
 * can just recalculate it within "amountFor".
 * 
 * When we are breaking down a long function, we like to get rid of 
 * variables like play, because temporary variables create a lot of 
 * lot of locally scoped names that compliate extraction.
 * 
 * we bring the right hand side of the assignment into a function.
 * 
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
		double thisAmount = amountFor(perf, playFor(perf));

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
double amountFor(auto aPerformance, auto play) {
  double result = 0;
	switch(play.type) {
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
			throw new Error("unknow type: ${play.type}");
	}
	return result;
}