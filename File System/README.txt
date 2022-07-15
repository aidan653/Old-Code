Uses a tree where each layer is a linked list which maintains it's structure by using a lag variable within the list. Extensive commenting added.

Functions Contained in 𝐅𝐢𝐥𝐞𝐒𝐲𝐬𝐭𝐞𝐦.𝐜𝐩𝐩(which is in the header folder for some reason) for future reference:
•	compareString(string, comparison string)
  o	Comments: Creates a char array and through each char in og string to see if it matches the character in the comparison string
•	makeFunction(string dirname)
  o	Comments: Misleading name, doesn’t actually make functions. Manages tge file tree’s addDir function.
•	goToFuction(string command)
  o	Comments: Calls the file tree’s cd function, and changes filepath you’re in.
•	deleteFunction()
  o	Comments: What you’d expect, checks if parent doesn’t exist. Manages the delete fuction and moves you to parent, then creates a temp var = to the child then deletes it, after every child is deleted of course. Then set child = to null
•	mainDisplay() 
  o	calls functions based off user input

𝐓𝐫𝐞𝐞𝐋𝐢𝐬𝐭.𝐜𝐩𝐩 the linked list part:
•	keeps track of a couple nodes
  o	first
  o	last
  o	current
  o	lag
•	add(string dir)
  o	makes a node and tacks it onto the end of list
•	goNext
  o	gets currents next and sets current = to it, and sets lag equal to where current just was. Not in that order.
•	deleteCurrent()
  o	deletes the current in the list, with 300 conditions based on where current is in the list
•	listOfOne()
  o	if first is last return true
•	goTo() – overload for either a node or string as an argument
  o	Traverses list to look for argument while not at the end, then does final check when at end, and if it never returns true, return false.

𝐓𝐫𝐞𝐞.𝐜𝐩𝐩
•	addDir()
  o	Makes a new tree list or adds a node onto an list if it already exists
•	displayChildren()
  o	while the list isn’t at the end it displays the contents of the list using getCurrentName from tree list
•	deleteCurrx()
  o	Just look at the code for notes
•	cd(string dirName)
  o	Sets current level as the specified arg. Has a lag variable to set to a child’s parent.
•	goUp()
  o	Just moves current to current’s parent
•	doesExist(string dirName)
  o	Uses treeLists go to function and that’s really it
