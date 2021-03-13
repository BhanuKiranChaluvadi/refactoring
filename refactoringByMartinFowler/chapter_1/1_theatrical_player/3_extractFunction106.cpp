/*
 * We mentally try ot identify parts that separate different parts of the over-all behaviour
 * The first chunk that leaps to my eye is the switch statement in the middle.
 *   Lets make it a function amounFor(aPerformance)
 *   first: we need to loolk in the fragments for any avaribles that will no longer 
 *   be in scope once we extracted the code into its own function. (perf, play, thisAmount)
 *   The first two(perf, play) are used by the extracted code , but not modified, so 
 *   i pass these two (perf, play) as parameters. Modified variable(thisAmount) needs
 *   more care. Here, there is only one, so i can return it. 
 *   I can bring its initialization inside the extracted code.
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

double amountFor(auto perf, auto play) {
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
	return thisAmount;
}