/*
 * Now Lets take a look at what we have extractedto see if there are 
 * any quick and easy things we can do to clarify the extracted function.
 * Frist thing: We can do is rename the variables to make them clearer.
 *  thisAmount --> result (the role is clear for this variable name)
 *  perf --> aPerformance (default name for a parameter include the 
 * 						type name. I use indefinate article with it unless 
 * 						there is some specific role information to capture 
 * 						un the name)
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
		const auto play = plays[perf.playID];
		double thisAmount = amountFor(perf, play);

		// add volume credits
		volumeCredits += max(perf.audience - 30, 0);
		// add extra credit for every 10 comedy attendees
		if ("comedy" == play.type) {
			volumeCredits += floor(perf.audience / 5);
		} 

		// print line for this order
		result << play.name << " : " << "$" << thisAmount << "  (" << perf.audience << " seats )\n";
		totalAmount += thisAmount;
	}							
	result << "Amount owed is $" << totalAmount << "\n";
	result << "ypu earned $" << volumeCredits << "\n";
	std::cout << result.str();
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