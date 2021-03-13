/* 
 * Customer requests a few plays and the company charges Based
 * 1. Kind of play they perform
 * 2. Number of customers
 * 3. Also give a voucher/discount coupon for future
 */

/*
 * plays.json
 * {
 * 		"hamlet:" {"name": "Hamlet", "type": "tragedy"}
 *    "as-like:" {"name": "As you like it", "type": "comedy"}
 * 		"othello:" {"name": "othello", "type": "tragedy"}
 * }
 */

/*
 * invoices.json ...
 * [
 * {
 * 	"customer" : "BigCo",
 * 	"performances" : [
 * 		{
 * 			"playID" : "hamlet",
 * 			"audience" : 55
 * 		}
 * 		{
 * 			"playID" : "as-like",
 * 			"audience" : 35
 * 		}
 * 		{
 * 			"playID" : "othello",
 * 			"audience" : 40
 * 		}		
 * 	]
 * }
 * ]
 */

/*
 * Result
 * Statement for BigCo
 *  Hamlet: $650.00 (55 seats)
 *  As you like it: $580.00 (35 seats)
 *  Othello: $500.00 (40 seats)
 * Amount owed is $1,730.00
 * You earned 47 credits
 */