## What makes a bad code from testablity point of view

[Video](https://www.youtube.com/watch?v=XcT4yYu_TTs&list=WL&index=185&t=836s&ab_channel=GoogleTechTalks)
[misko.hevery](http://misko.hevery.com/code-reviewers-guide/)
[presentation](http://misko.hevery.com/presentations/)

<ul>
<li>Singleton class. Usually b/c getInstance is the method we involve inorder to instantiate the class. We dont have any choice of providing mockups and the class is tightly coupled(implementation details). Put global vaiables/states every where.</li>
<li>Rather than dependency injection. Having a new operator inside class implementation(Tighly coupled to implementaion than interface).Put new operators every where(or Hard code dependency).New operator fundamentally makes its impossible to test.</li>
<li>May if/else & Switch statements. Prefer Polymorphism based on the state of the variable.</li>
<li>Returning a null pointer and return errorcode rather than run time exception</li>
<li>Static Fields or Static methods</li>
<li>Lots of static methods with can't be overwritten.</li>
<li></li>
</ul>
