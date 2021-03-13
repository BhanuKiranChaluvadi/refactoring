# Single Responsibility
[video](https://www.youtube.com/watch?v=Gt0M_OHKhQE&ab_channel=gnbitcom)

Single Responsibility is a simple ideas. It says things that change for the same reasons should be grouped together. Things that change for different reasons should be separeated. Any module/class should be responsible to only one person(not multiple roles). Hence class should be responsible for one and only one role.

SRP says if you are designing the software you consider who is using it. who are the roles that are using the software and how can you isolate the software when on guy asks for a change that change will not effect anybody else thats a very interesting question to ponder.

class Employee {
  calculatePay;
  Save;
  DescribeEmployee
  FindbyID;
};

How many responsibilities is the class Employee Handling ? How many roles the class is serving ?
We can think
<ul>
<li>Save & FindbyID deals with Database.</li>
<li>CalculatePay might deal with Business logic based on the employee role and responsilbilty.</li>
<li>DescribeEmployee might be need by some HR or clerk to read the report.</li>
</ul>

On an another note, we like the fact that the employee can save itself to the database. we like the fact that it can generate its own report isn't that after all the objects are supposed to do ?. Aren't you suppose to put all the methods in an object that object is supposed to know. Yeah you are right but that makes for a really coupled nasty system. It's one of the reasons that object-oriented systems gets so hard to maintain because we jam so much stuff into single class that wont belong there. How could we separate this whole bunch of different classes ?

There are bunch of ways.
<ul>
<li> Place Save & FindbyID - database related in EmployeeRepositoty class (repository pattern).</li>
<li> And DescibeEmployee into a separeate class b/c reports will all always expand to more methods in the future/.</li>
</ul>

Wait a Minute. If i do that ? that all my classes are gonna have one method in them !!!. Well not quite won't be one may be two or three or five and that not a bad thing. 

How many methods does a class have ? As small a number as possible.

<ul>
<li> </li>
</ul>