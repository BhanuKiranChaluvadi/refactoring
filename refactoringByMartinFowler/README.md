

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
<ol>

## Extract a function
  
<ol>
   <li> Look into fragment for any variable that will no longer be in the scope once we extracted the code into new function. In our case, We have three: perf, play, thisAmount</li>
  <li> Categorize the varibles inside the function. The First two perf, play are used by the extracted code but not modified. So we can pass them as a parameter. </li> 
  <li> Categorize the varibles inside the function.  Modified vaiable needs more care. Here we have only one, so we can return the variable after modification. </li> 
  <li> Replace the code with function name in main code. </li>
  <li> After Extraction of function, take a look at what we have extracted to see if there are any quick and easy things we can do to clarifyt eh extracted function.</li>
<ol>
  
 ### Rename Varibles
  Rename some varibles to make them clear
<ol>
   <li> First argument rename (aPerformace)</li>
   <li> Second arguement rename if needed </li> 
   <li> Any other variables in the code  </li> 
<ol> 
  
 ### Look at passed Arguments
  Look into passed arguements where they come from. 
<ol>
   <li> Are all arguments independent OR Is one arguments is computed from another ? </li>
   <li> If arguments are dependent. Then we dont need to pass all of them. Just caluculate inside the function </li> 
<ol>
  
  
 
