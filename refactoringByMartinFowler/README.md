

<ul>
<li> Move a field from one class on another.</li>
<li> Pull some code out of the class to make it into its own method.</li>
<li> Push some code up or down a hierarchy.</li>
</ul>


1. SPlit the loop - to isolate the accumulation
2. Slide Statement - to bring the initialization code next to the accumulation
3. Etract Function - to create a function
4. Inline variable - to remove the variable completely.


<ol>
   <li> </li>
   <li> </li> 
</ol>

## Extract a function
  
<ol>
   <li> Look into fragment for any variable that will no longer be in the scope once we extracted the code into new function. In our case, We have three: perf, play, thisAmount</li>
  <li> Categorize the varibles inside the function - The First two perf, play are used by the extracted code but not modified. So we can pass them as a parameter. </li> 
  <li> Categorize the varibles inside the function -  Modified vaiable needs more care. Here we have only one, so we can return the variable after modification. </li> 
  <li> Replace the code with function name in main code. </li>
  <li> After Extraction of function, take a look at what we have extracted to see if there are any quick and easy things we can do to clarify the extracted function.</li>
<ol>
  
   
### Rename Varibles
  Rename some varibles to make them clear
<ol>
   <li> First argument rename (aPerformace)</li>
   <li> Second arguement rename if needed </li> 
   <li> Any other variables in the code e.g result </li> 
</ol> 
  
### Look at passed Arguments
  Look into passed arguements where they come from. 
<ol>
   <li> Are all arguments independent OR Is one arguments is computed from another ? </li>
   <li> If arguments are dependent. Then we dont need to pass all of them. Just caluculate inside the function </li> 
</ol>
 

 ### Removing a dependent variable
   play in this case. As we consider the function paramters, we should looks into where they come from. Variable aPerformace come from loop, so changes in eash iteration. But      variable play is computed from the performance. so no need to pass into the function.
   
   When we break down a long function, We should get rid of the variables like play, b/c temporary variables create a lot of locally scoped names that complicate the extraction.
 
 ###  Replace temp with Query 
<ol>
   <li> Create a function for temporary variable </li>
</ol>
   
 ###  Inline Variable
   eg: before
   const play = playFor(perf);
   let thisAmount = amountFor(pef, play)
   
   eg: after
   let thisAmount = amountFor(pef, playFor(perf))
<ol>
   <li> Perform this replacement at all the places. </li>
</ol>
   
The great benifit of removing a local variable is that it makes it much easier to do extraction, since there is less local scope to deal with. Usually we take out local variables before we do any extraction.
   
 
 ### Inline Variable - 2
   
 We look back at where the extracted function is called from ? It is being used to set a temporary variable that's not updated again. So we apply inline variable again.
   
 Temporary varaibles can be problem. They are only useful with in their own routine and therefore they encourage long, complex routines. We have to replace some of them atleast.
   
 ### Naming
   Naming is both important and tricky. Breaking a large function into smaller ones only adds value if the names are good. But its hard to get names right the first time.
   
 ### Next target
   Out next target variable is volumeCredits
   
### Splitting volume credits
<ol>
   <li> Split the loop - to isolate the accumulation. </li>
   <li> Slide Statement - to bring the initialization code next to the accumulation. </li> 
   <li> Etract Function - to create a function. </li> 
   <li> Inline variable - to remove the variable completely. </li> 
</ol>
 
 
   
 
