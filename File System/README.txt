Uses a tree where each layer is a linked list which maintains it's structure by using a lag variable within the list. Extensive commenting added.

Functions Contained in ππ’π₯πππ²π¬π­ππ¦.ππ©π©(which is in the header folder for some reason) for future reference:
β’	compareString(string, comparison string)
  o	Comments: Creates a char array and through each char in og string to see if it matches the character in the comparison string
β’	makeFunction(string dirname)
  o	Comments: Misleading name, doesnβt actually make functions. Manages tge file treeβs addDir function.
β’	goToFuction(string command)
  o	Comments: Calls the file treeβs cd function, and changes filepath youβre in.
β’	deleteFunction()
  o	Comments: What youβd expect, checks if parent doesnβt exist. Manages the delete fuction and moves you to parent, then creates a temp var = to the child then deletes it, after every child is deleted of course. Then set child = to null
β’	mainDisplay() 
  o	calls functions based off user input

ππ«ππππ’π¬π­.ππ©π© the linked list part:
β’	keeps track of a couple nodes
  o	first
  o	last
  o	current
  o	lag
β’	add(string dir)
  o	makes a node and tacks it onto the end of list
β’	goNext
  o	gets currents next and sets current = to it, and sets lag equal to where current just was. Not in that order.
β’	deleteCurrent()
  o	deletes the current in the list, with 300 conditions based on where current is in the list
β’	listOfOne()
  o	if first is last return true
β’	goTo() β overload for either a node or string as an argument
  o	Traverses list to look for argument while not at the end, then does final check when at end, and if it never returns true, return false.

ππ«ππ.ππ©π©
β’	addDir()
  o	Makes a new tree list or adds a node onto an list if it already exists
β’	displayChildren()
  o	while the list isnβt at the end it displays the contents of the list using getCurrentName from tree list
β’	deleteCurrx()
  o	Just look at the code for notes
β’	cd(string dirName)
  o	Sets current level as the specified arg. Has a lag variable to set to a childβs parent.
β’	goUp()
  o	Just moves current to currentβs parent
β’	doesExist(string dirName)
  o	Uses treeLists go to function and thatβs really it
