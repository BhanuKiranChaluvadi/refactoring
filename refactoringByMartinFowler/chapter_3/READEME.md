## Long Functions
  The programs that live best and longest are those with short function. You often fell that no computation ever takes place - that the program is endless sequence of delegation.
  
  Small functions and good naming. If you have a good name for a function, you mostly don't need to look at its body. The net effect is that you should much more aggressive about
  decomposing functions. A heuristic we follow is that when ever we feel that need to comment something, we write a function instead. Such a function contains the code that
  we want to comment but is named after the intention of the code rather than the way it works.
  
  How do you identify the clump of code to extract ?
    1. Look for comments:
      A good technique is to look for comments.  A block of code with a comment that tells you what it is doing can be replaced by a method whose name is based on the comment.
      Even a single line is worth extracting if it needs explanation.
    2. Conditions and loops:
      Use Decompose condition to deal with conditional expression. A big switch statement should have its legs turned into single calls with extract functiions.
      If there is more than one switch statement switching on the same condition, you should apply REPLACE CONDITION WITH POLYMORPHISM.
      With loops, extract the loop and the code within the loop into its own method, if you find hard to give an extracted loop a name, then may be because of its 
      doing two diffent things --- in which case don't be afraid to use SPLIT LOOP to break into separate task.
