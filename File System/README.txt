Uses a tree where each layer is a linked list which maintains it's structure by using a lag variable within the list. Extensive commenting added.

Functions Contained in 𝐅𝐢𝐥𝐞𝐒𝐲𝐬𝐭𝐞𝐦.𝐜𝐩𝐩(which is in the header folder for some reason) for future reference:
•	compareString(string, comparison string)
  o	Comments: Creates a char array and through each char in og string to see if it matches the character in the comparison string
•	makeFunction(string dirname)
  o	Comments: Misleading name, doesn’t actually make functions. Manages tge file tree’s addDir function.
•	goToFuction(string command)
  o	Comments: Calls the file tree’s cd function, and changes filepath you’re in.
•	deleteFunction()
  o	Comments: What you’d expect, checks if parent doesn’t exist. Manages the delete fuction and moves you to parent, then creates a temp var = to the child then deletes
    it, after every child is deleted of course. Then set child = to null
•	mainDisplay() 
  o	calls functions based off user input
