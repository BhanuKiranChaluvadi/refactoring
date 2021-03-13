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

	for(auto & perf : invoice.performace) {
		const auto play = plays[perf.playID];
		double thisAmount = 0;

		switch(play.type) {
			case "tragedy":
				thisAmount = 40000;
				if (perf.audience > 30) {
					thisAmount += 1000 * (perf.audience - 30);
				}
				break;
			case "comedy":
				thisAmount = 30000;
				if (perf.audience > 20) {
					thisAmount += 1000 + 500 * (perf.audience - 20);
				}	
				thisAmount += 300 * perf.audience;
				break;
			default:
				throw new Error("unknow type: ${play.type}");
		}

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