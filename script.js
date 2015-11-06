/*******************************
* Author: Alicia Broederdorf
* Date: October 30, 2015
* Description: Gone Camping game
* Navigate through house, completing tasks and collecting
* the correct items for your backpack while solving number
* puzzles. Don't run out of time before your friends come to
* pick you up!
*******************************/

//10 esstential items
var essentials = ["Map", "Compass", "Sunglasses", "Jacket", "Headlamp", "First-aid", "Fire starter", "Matches", "Knife", "Candy Bar"];
var backpack = ["Empty", "Empty", "Empty"];
var winningItems = ["Empty", "Empty", "Empty"];

//Start time
var startTime, currentTime, timeDiff, timeRemaining, remainMin, remainSec;

//Room Object Constructor functions
function BoolRoom (cellID, room, type, status, statT, statF, prompt){
	this.cellID = cellID;
	this.room = room;
	this.type = type;
	this.status = status;
	this.statT = statT;
	this.statF = statF;
	this.prompt = prompt;
}

function ClueRoom (cellID, room, type, status, statT, statF, prompt, clue){
	this.cellID = cellID;
	this.room = room;
	this.type = type;
	this.status = status;
	this.statT = statT;
	this.statF = statF;
	this.prompt = prompt;
	this.clue = clue;
}

function PuzzleRoom (cellID, room, type, status, statT, statF, prompt, combination, items){
	this.cellID = cellID;
	this.room = room;
	this.type = type;
	this.status = status;
	this.statT = statT;
	this.statF = statF;
	this.prompt = prompt;
	this.combination = combination;
	this.items = items;
}

//Create rooms
var diningRoom = new BoolRoom("c22", "boolRoom", "cat", false, "fed", "hungry", "Would you like to feed your cat tiger?");
var porch = new BoolRoom("c14", "boolRoom", "garbage", false, "empty", "piled up", "Would you like to take the garbage out?");
var bathroom = new ClueRoom("c21", "clueRoom", "light", false, "off", "on", "Would you like to turn the light off?", "No clue");
var hallCloset = new ClueRoom("c12", "clueRoom", "light", false, "off", "on", "Would you like to turn the light off?", "No clue");
var entry = new ClueRoom("c23", "clueRoom", "light", false, "off", "on", "Would you like to turn the light off?", "No clue");
var livingRoom = new ClueRoom("c13", "clueRoom", "window", false, "closed", "open", "Would you like to close the window?", "No clue");
var study = new ClueRoom("c33", "clueRoom", "window", false, "closed", "open", "Would you like to close the window?", "No clue");
var bedroom1 = new PuzzleRoom("c31", "puzzleRoom", "cabinet", false, "unlocked", "locked", "Would you like to open the cabinet?", -1, ["Empty", "Empty", "Empty"]);
var bedroom2 = new PuzzleRoom("c11", "puzzleRoom", "cabinet", false, "unlocked", "locked", "Would you like to open the cabinet?", -1, ["Empty", "Empty", "Empty"]);
var kitchen = new PuzzleRoom("c32", "puzzleRoom", "cabinet", false, "unlocked", "locked", "Would you like to open the cabinet?", -1, ["Empty", "Empty", "Empty", "Empty"]);


//Name: startGame
//Description: Initializes game by assigning winning items, clue phrases,
// and items to rooms. Also removes event listener for start button
//Input: None
//Output: None, items assigned to winningItems, rooms, and clue phrases assigned
function startGame() {
	//Initialize items in game
	//Shuffle items in array
	var tempArray = randomSort(essentials);
	
	//Assign first three items to winnningItems array
	for (var i = 0; i < 3; i++)
		winningItems[i] = tempArray[i];
	
	//Assign clue phrases to rooms
	bathroom.clue = getClue(tempArray[3]);
	hallCloset.clue = getClue(tempArray[4]);
	livingRoom.clue = getClue(tempArray[5]);
	entry.clue = getClue(tempArray[6]);
	study.clue = getClue(tempArray[7]);
	
	//Shuffle items in array
	tempArray = randomSort(essentials);
	
	//Assign items to room
	bedroom1.items[0] = tempArray[0];
	bedroom1.items[1] = tempArray[1];
	bedroom1.items[2] = tempArray[2];
	bedroom2.items[0] = tempArray[3];
	bedroom2.items[1] = tempArray[4];
	bedroom2.items[2] = tempArray[5];
	kitchen.items[0] = tempArray[6];
	kitchen.items[1] = tempArray[7];
	kitchen.items[2] = tempArray[8];
	kitchen.items[3] = tempArray[9];
	
	//Set backpack items to empty
	for (var i = 0; i < 3; i++)
	{
		backpack[i] = "Empty";
		
		//Change status display
		var packID = "statSpan" + (i+1);
		var packStr = (i+1) + ". Empty";
		document.getElementById(packID).textContent = packStr;
	}
	
	//Set status of all rooms to false
	bedroom1.status = false;
	bathroom.status = false;
	bedroom2.status = false;
	kitchen.status = false;
	diningRoom.status = false;
	hallCloset.status = false;
	livingRoom.status = false;
	entry.status = false;
	study.status = false;
	porch.status = false;
	
	//Make all buttons visible
	document.getElementById("upButton").disabled = false;
	document.getElementById("dnButton").disabled = false;
	document.getElementById("rtButton").disabled = false;
	document.getElementById("lfButton").disabled = false;
	document.getElementById("actButton").disabled = false;
	document.getElementById("leaveButton").disabled = false;
	
	//Clear checkboxes
	clearBoxes();
	
	//Test to see items
	console.log("Winning items: " + winningItems);
	
	//Unselect current cell
	unSelectCell();
	
	//Set current coordinates to porch
	currentX = 1;
	currentY = 4;
	
	//Select cell
	selectCell();
		
	//Print status in current room
	getRoomStatus();
	
	//Set start time
	var d = new Date();
	startTime = d.getTime();
	document.getElementById("remainTime").textContent = "10:00";
}

//Name: randomSort
//Description: This will randomly sort the items in an array
//Input: Original array
//Output: New array with sorted values
//Source: http://stackoverflow.com/questions/2450954/how-to-randomize-shuffle-a-javascript-array
function randomSort(arr){
	var curInd = arr.length, temp, randInd;

	//Create new array to sort
	var newArray = [];

	for (var i = 0; i < arr.length; i++)
		newArray.push(arr[i]);

	//While there remain elements to shuffle
	while (0 != curInd)
	{
		//Pick a remaining element
		randInd = Math.floor(Math.random() * curInd);
		curInd--;
		
		//Swap it with current element
		temp = newArray[curInd];
		newArray[curInd] = newArray[randInd];
		newArray[randInd] = temp;
	}
	
	return newArray;
}

//Name: getClue
//Description: Function generates a clue phrase for a given item
//Input: Item
//Output: String for clue phrase
function getClue(item){
	//Return clue phrase for item
	if (item == "Map")
		return "CLUE!       I won't get lost with my map.";
	else if (item == "Compass")
		return "CLUE!       Compass, check. How do you use this thing again?";
	else if (item == "Sunglasses")
		return "CLUE!       I've got my sunglasses.";
	else if (item == "Jacket")
		return "CLUE!       I'll be warm with my new jacket packed.";
	else if (item == "Headlamp")
		return "CLUE!       The dark is less scary with my powerful headlamp packed.";
	else if (item == "First-aid")
		return "CLUE!       Don't fall, but just in case, the first aid kit is packed.";
	else if (item == "Fire starter")
		return "CLUE!       Roaring fires start with good fire starter, check.";
	else if (item == "Matches")
		return "CLUE!       Matches are packed.";
	else if (item == "Knife")
		return "CLUE!       My pocket knife is secured in the cap of my pack.";
	else
		return "CLUE!       Mmmm, my favorite camping treat. Is having 3 candy bars packed excessive?";
}

//Name: unSelectCell
//Description: This will set border of current cell to normal
//Input: None
//Output: None, cell border changes
function unSelectCell() {
	var cellID = "c" + currentX + "" + currentY;
	document.getElementById(cellID).style.border = "solid 1px";
}

//Name: selectCell
//Description: This will increase border thickness of current cell 
//Input: None
//Output: None, cell border changes
function selectCell() {
	var cellID = "c" + currentX + "" + currentY;
	document.getElementById(cellID).style.border = "solid 5px";
}

//Name: instructions
//Description: Alert will be created with game information
//Input: None
//Output: Alert box with game information
function instructions(){
	document.getElementById("instrDiv").style.display = "block";
}

//Name: instructionsClose
//Description: Alert will be created with game information
//Input: None
//Output: Alert box with game information
function instructionsClose(){
	document.getElementById("instrDiv").style.display = "none";
}

//Name: takeAction
//Description: This will set the background color of the cell to yellow
//Input: None
//Output: None, cell background color is changed
function takeAction() {
	//Determine type of room
	var room = getRoom();
	if (room.room != "puzzleRoom")
	{
		//Change status of room if false
		room.status = true;
		
		//If clue room, print clue in message otherwise print done
		if (room.room == "clueRoom")
			document.getElementById("msgPar").textContent = room.clue;
		else
			document.getElementById("msgPar").textContent = "Done!";
	}
	else
	{
		//Set feedback for combination guess and input to blank
		document.getElementById("puzFB").textContent = " ";
		document.getElementById("puzGuess").value = 0;
		
		//Show combination box
		document.getElementById("puzzleDiv").style.display = "block";
		
		//If puzzle room 1
		if (room.cellID == "c31")
		{
			//Set combination for cabinet
			puzzle1Comb();
			
			//Display instructions in message box
			document.getElementById("msgPar").textContent = "The combination for this cabinet is an integer between 1 and 100. When you guess the correct combination the cabinet will open. Good luck!";
		}
		else if (room.cellID == "c11")
		{
			//Set combination for cabinet
			puzzle2Comb();
			
			//Display instructions in message box for puzzle room 2
			document.getElementById("msgPar").textContent = "The combination for this cabinet is a random order of the digits 1, 2, and 3. Example: The combination might be 123 or 321. When you guess the correct combination the cabinet will open. Good luck!";
		}
		else if (room.cellID == "c32")
		{
			//Set combination for cabinet
			var combSum = puzzle3Comb();
			
			//Display instructions in message box for puzzle room 3
			var printStr = "The combination for this cabinet is a random order of three odd integers between 1 and 7. Example: If the combination is 117 or 711, the sum is nine. When you guess the correct combination the cabinet will open. Good luck!";
			document.getElementById("msgPar").textContent = printStr;
			document.getElementById("msgParCom").style.display = "block";
			document.getElementById("puz3Sum").textContent = combSum;
		}
		else
			alert("Error in take action");
	}
}

//Name:checkGuess 
//Description: Compares player's guess with combination of room
//Input: Room object
//Output: None, will show cabinet div
function checkGuess() {
	//Get player's guess
	var playerGuess = document.getElementById("puzGuess").value;
	
	//Get room
	var room = getRoom();
	
	//Check if bedroom 1, perform input validation
	if (room.cellID == "c31")
	{
		//Compare guess with combination of room
		if (playerGuess == room.combination)
		{
			//Update message that guess is correct
			document.getElementById("puzFB").textContent = "Correct, good work! Look at the items in the cabinet listed below.";
			
			//Open cabinet
			openCabinet();
		}
		else
		{
			//Guess is not correct, update message with feedback
			if (playerGuess > room.combination)
				document.getElementById("puzFB").textContent = playerGuess + " is too high. Try again";
			else if (playerGuess < room.combination)
				document.getElementById("puzFB").textContent = playerGuess + " is too low. Try again";
			else
				document.getElementById("puzFB").textContent = "Please enter a valid whole number between 1 and 100";
		}
	}
	else
	{
		//Compare guess with combination of room
		if (playerGuess == room.combination)
		{
			//Update message that guess is correct
			document.getElementById("puzFB").textContent = "Correct, good work! Look at the items in the cabinet listed below.";
			
			//Open cabinet
			openCabinet();
		}
		else
		{
			//Guess is not correct, update message with feedback
			document.getElementById("puzFB").textContent = playerGuess + " is incorrect, try again";
		}
	}
}

//Name: openCabinet
//Description: This will display the cabinet and allow the player to add an item to their backpack
//Input: None
//Output: None, items in backpack may have changed
function openCabinet() {
	//Get room
	var room = getRoom();
	
	//Show cabinet
	document.getElementById("itemDiv").style.display = "block";
	
	//Change names of items to those in room and set radio buttons to unchecked
	var spanID, txtStr, radID;
	for (var i = 1; i < 4; i++)
	{
		spanID = "cabSpan" + i;
		txtStr = room.items[i-1];
		document.getElementById(spanID).textContent = txtStr;
		radID = "cabRad" + i;
		document.getElementById(radID).checked = false;
	}

	//If in kitchen change fourth item, otherwise hide fourth item
	if (room.cellID == "c32")
	{
		txtStr = room.items[3];
		document.getElementById("cabSpan4").textContent = txtStr;
		document.getElementById("cabLab4").style.display = "block";
		document.getElementById("cabRad4").checked = false;
	}
	else
		document.getElementById("cabLab4").style.display = "none";		
}

//Name: yesItem
//Description: This displays packDiv for player to add an item to pack
//Input: None
//Output: None, div shown
function yesItem() {
	//Show div
	document.getElementById("packDiv").style.display = "block";	
	
	//Set position radio buttons to unchecked
	var radID;
	for (var i = 1; i < 4; i++)
	{
		radID = "packRad" + i;
		document.getElementById(radID).checked = false;
	}
}

//Name: addItem
//Description: Changes name of backpack item to that of the item the player chooses
//Input: None
//Output: None, backpack span text content changed
function addItem(){
	var itemNum = 0, packNum = 0;
	var room = getRoom();
	
	//Determine which item is checked
	while (itemNum == 0 && packNum == 0)
	{
		if (document.getElementById("cabRad1").checked)
			itemNum = 1;
		else if (document.getElementById("cabRad2").checked)
			itemNum = 2;
		else if (document.getElementById("cabRad3").checked)
			itemNum = 3;
		else if (document.getElementById("cabRad4").checked)
			itemNum = 4;
		else
			alert("Please check the button next to one of the items in the cabinet");
		
		//Determine which pack position is checked
		if (document.getElementById("packRad1").checked)
			packNum = 1;
		else if (document.getElementById("packRad2").checked)
			packNum = 2;
		else if (document.getElementById("packRad3").checked)
			packNum = 3;
		else
			alert("Please check the button next to one of the backpack positions");
	}
	
	//Change item in backpack by changing span text content
	var itemStr = room.items[itemNum - 1];
	var packID = "statSpan" + packNum;
	var packStr = packNum + ". " + itemStr;
	document.getElementById(packID).textContent = packStr;
	
	//Add item to backpack array
	backpack[packNum - 1] = room.items[itemNum - 1];
	
	//Close cabinet
	closeCabinet();
}

//Name: closeCabinet
//Description: This hides itemDiv and puzDiv
//Input: None
//Output: None, divs hidden
function closeCabinet() {
	//Hide divs
	document.getElementById("itemDiv").style.display = "none";
	document.getElementById("puzzleDiv").style.display = "none";
	document.getElementById("packDiv").style.display = "none";
	document.getElementById("msgParCom").style.display = "none";
}

//Name: exitPuzzle
//Description: This will hide the puzzle div
//Input: None
//Output: None, puzzle div hidden
function exitPuzzle() {
	//Hide combination box
	document.getElementById("puzzleDiv").style.display = "none";
	
	//Close cabinet
	closeCabinet();
}

//Name: getRoom
//Description: Returns the room object at the current location
//Input: None
//Output: Room object
function getRoom() {
	//Determine room based on coordinates and return object
	if (currentX == 1 && currentY == 4)
		return porch;
	else if (currentX == 1 && currentY == 3)
		return livingRoom;
	else if (currentX == 2 && currentY == 3)
		return entry;
	else if (currentX == 3 && currentY == 3)
		return study;
	else if (currentX == 1 && currentY == 2)
		return hallCloset;
	else if (currentX == 2 && currentY == 2)
		return diningRoom;
	else if (currentX == 3 && currentY == 2)
		return kitchen;
	else if (currentX == 1 && currentY == 1)
		return bedroom2;
	else if (currentX == 2 && currentY == 1)
		return bathroom;
	else
		return bedroom1;
}

//Name: leave
//Description: This determines if all the correct items are gathered
//and actions are completed and player is on porch, if not, status remains false
//Input: None
//Output: None
function leave(){
	var boolCount = 0, itemCount = 0;
	
	//Check player's location
	if (currentX ==1 && currentY == 4)
	{
		//Check if room status is all true
		//alert(bathroom.status);
		if (!(bathroom.status))
			boolCount++;
		if (!(hallCloset.status))
			boolCount++;
		if (!(livingRoom.status))
			boolCount++;
		if (!(entry.status))
			boolCount++;
		if (!(study.status))
			boolCount++;
		if (!(diningRoom.status))
			boolCount++;
		if (!(porch.status))
			boolCount++;

		//Check items
		for (var i = 0; i < backpack.length; i++)
		{
			for (var j = 0; j < winningItems.length; j++)
			{
				if (backpack[i] == winningItems[j])
					itemCount++;
			}
		}
		
		//Print message about status
		if (boolCount == 0)
		{
			if (itemCount == 3)
			{
				document.getElementById("msgPar").textContent = "Congratulations, you finished the house tasks and packed your three missing items. Have fun camping with your friends!";
				disableGameButtons();
				document.getElementById("startButton").focus();
			}
			//Determine how many items are incorrect
			else if (itemCount == 0)
				document.getElementById("msgPar").textContent = "You can't leave yet, all of your items are incorrect.";
			else if(itemCount == 1)
				document.getElementById("msgPar").textContent = "You can't leave yet, two of your items are incorrect.";
			else if(itemCount == 2)
				document.getElementById("msgPar").textContent = "You can't leave yet, one of your items is incorrect.";
		}
		else
		{
			var printStr = "You can't leave yet, you have unfinished house tasks";
			//Determine if items are correct
			if (itemCount == 0)
				printStr += " and all of your items are incorrect.";
			else if(itemCount == 1)
				printStr += " and two of your items are incorrect.";
			else if(itemCount == 2)
				printStr += " and one of your items is incorrect.";
			else
				printStr += "."
			
			//Print message
			document.getElementById("msgPar").textContent = printStr;
		}
	}
	else
		document.getElementById("msgPar").textContent = "You can't leave unless you are on the porch. Navigate to the porch and try again";
}

//Name: navigate
//Description: This will change the current coordinates as the
// user navigates around the table
//Input: String indicating navigation direction
//Output: None, coordinates will change and cell borders will change
function navigate(direction) {
	//Proceed if not edge condition
	if (!((direction == "up" && currentY == 1) || (direction == "dn" && currentY == 3 && currentX != 2) ||
		(direction == "lf" && currentX == 1) || (direction == "rt" && currentX == 3) || 
		(direction == "dn" && currentY == 4 && currentX == 1) || (direction == "rt" && currentY == 4)))
	{
		//Deselect current cell
		unSelectCell();
		
		//Close cabinet
		closeCabinet();
		
		//Update current coordinates
		if (direction == "up")
		{
			if (currentY == 4 && currentX == 1)
			{
				currentY--;
				currentX++;
			}
			else
				currentY--;
		}
		else if (direction == "dn")
		{
			if (currentY == 3 && currentX == 2)
			{
				currentY++;
				currentX--;
			}
			else
				currentY++;
		}
		else if (direction == "rt")
			currentX++;
		else if (direction == "lf")
			currentX--;
		else
			alert("Bug in navigation");
		
		//Select current cell
		selectCell();
		
		//Print status in current room
		getRoomStatus();
		
		//Check time and update
		var dC = new Date();
		currentTime = dC.getTime();
		timeDiff = (currentTime - startTime)/1000.0;
		timeRemaining = 10.0 - timeDiff/60.0;
		remainMin = Math.floor(timeRemaining);
		remainSecReal = (timeRemaining - remainMin) * 60.0;
		remainSec = remainSecReal.toFixed(0);
		
		//Update time
		if (remainSec < 10)
			var strSec = "0" + remainSec;
		else
			strSec = remainSec;
		var timeStr = remainMin + ":" + strSec;
		document.getElementById("remainTime").textContent = timeStr;
		
		//If over time
		if (timeRemaining < 0.0)
		{
			disableGameButtons();
			document.getElementById("msgPar").textContent = "I'm sorry but you ran out of time and missed your friends. Better luck next time!";
			document.getElementById("startButton").focus();
		}
		
	}
}

//Name: getRoomStatus
//Description: This updates the message as to the current status of the room
//Input: None 
//Output: None, msgPar is changed
function getRoomStatus() {
	//Get current room object
	var room = getRoom();
	
	//Create string of status of room
	var printStr = "The " + room.type + " is ";
	if (room.status)
		printStr += room.statT + ".";
	else
		printStr += room.statF + ". " + room.prompt;

	//Change message paragraph element to reflect new string
	document.getElementById("msgPar").textContent = printStr;
}

//Name: puzzle1Comb
//Description: Sets the combination for puzzle 1, a number between 1 and 100
//Input: None
//Output: None, combination of bedroom1 is changed
function puzzle1Comb() {
	//Generate random number between 1 and 100
	var comb = Math.floor(Math.random() * (100 - 1)) + 1;
	
	//Change combination of room object
	bedroom1.combination = comb;
	
	//Print answer to console for testing purposes
	console.log("Bedroom 1 combination: " + bedroom1.combination);
}

//Name: puzzle2Comb
//Description: Sets the combination for puzzle 2, random order of digits 1, 2, 3
//Input: None
//Output: None, combination of bedroom2 is changed
function puzzle2Comb() {
	//Sort array of 1, 2, and 3
	var sortedArr = randomSort([1, 2, 3]);
	
	//Concatenate string with combination
	var comb = sortedArr[0] + "" + sortedArr[1] + "" + sortedArr[2];
	
	//Change combination of room object
	bedroom2.combination = comb;
	
	//Print answer to console for testing purposes
	console.log("Bedroom 2 combination: " + bedroom2.combination);
}

//Name: puzzle3Comb
//Description: Sets the combination for puzzle 3, random order of digits 1, 3, 5, 7
//Input: None
//Output: Sum of combination digits is returned, combination of kitchen is changed
function puzzle3Comb() {
	var combArray = [];
	
	//Generate odd digit and add to combination
	for (var i = 0; i < 3; i++)
	{
		//Generate random number between 0 and 4
		var randNum = Math.floor(Math.random() * (3 - 0)) + 0;
		
		//Turn number into odd number and add to array
		combArray.push(2 * randNum + 1);
	}
	
	//Create combination value from digits
	var comb = combArray[0] * 100 + combArray[1] * 10 + combArray[2];
	
	//Change combination of room object
	kitchen.combination = comb;
	
	//Print answer to console for testing purposes
	console.log("Kitchen combination: " + kitchen.combination);
	
	//Return sum of digits
	return (combArray[0] + combArray[1] + combArray[2]);
}

//Name: hints
//Description: Show hints for playing the game
//Input: None
//Output: None, div shown
function hints(){
	document.getElementById("hintDiv").style.display = "block";
}

//Name: hintsClose
//Description: Hide hints for playing the game
//Input: None
//Output: None, div hidden
function hintsClose(){
	document.getElementById("hintDiv").style.display = "none";
}

//Name: clearBoxes
//Description: Clear checkmarks from boxes in check list
//Input: None
//Output: None, checked property of checkboxes set to false
function clearBoxes(){
	for (var i = 1; i < 11; i++)
	{
		var idStr = "clBox" + i;
		document.getElementById(idStr).checked = false;
	}		
}

//Name: disableGameButtons
//Description: This disables the navigation and game buttons
//Input: None
//Output: None, buttons disabled
function disableGameButtons(){
	document.getElementById("upButton").disabled = true;
	document.getElementById("dnButton").disabled = true;
	document.getElementById("rtButton").disabled = true;
	document.getElementById("lfButton").disabled = true;
	document.getElementById("actButton").disabled = true;
	document.getElementById("leaveButton").disabled = true;
}

//Run program
//-------------------------------------------------------------------------------
//Current location in table
var currentX = 1;
var currentY = 4;

//Select first cell
document.getElementById('c14').style.border = "solid 5px";

//Create event listeners for buttons and key press
//Navigation
document.getElementById("upButton").addEventListener("click", function() {navigate("up");});
document.getElementById("dnButton").addEventListener("click", function() {navigate("dn");});
document.getElementById("lfButton").addEventListener("click", function() {navigate("lf");});
document.getElementById("rtButton").addEventListener("click", function() {navigate("rt");});

//Keydown listener
document.addEventListener("keydown", function(event) {
	//Buttons to check against
	var actBut = document.getElementById("actButton");
	var guessBut = document.getElementById("submitButton");
	var guessInput = document.getElementById("puzGuess");
	var startBut = document.getElementById("startButton");
	
	//Determine key code and call function
	if (event.keyCode == 38)
	{
		navigate("up");
		document.getElementById("actButton").focus();
	}
	else if (event.keyCode == 40)
	{
		navigate("dn");
		document.getElementById("actButton").focus();
	}
	else if (event.keyCode == 37)
	{
		navigate("lf");
		document.getElementById("actButton").focus();
	}
	else if (event.keyCode == 39)
	{
		navigate("rt");
		document.getElementById("actButton").focus();
	}
	else if (event.keyCode == 13 && document.activeElement == actBut)
		takeAction();
	else if (event.keyCode == 13 && document.activeElement == guessInput)
		checkGuess();
	else if (event.keyCode == 13 && document.activeElement == startBut)
		startGame();
});

//Other actions
document.getElementById("actButton").addEventListener("click", takeAction);
document.getElementById("startButton").addEventListener("click", startGame);
document.getElementById("instrButton").addEventListener("click", instructions);
document.getElementById("instrClButton").addEventListener("click", instructionsClose);
document.getElementById("leaveButton").addEventListener("click", leave);
document.getElementById("submitButton").addEventListener("click", checkGuess);
document.getElementById("exitButton").addEventListener("click", exitPuzzle);
document.getElementById("yesButton").addEventListener("click", yesItem);
document.getElementById("closeButton").addEventListener("click", closeCabinet);
document.getElementById("packButton").addEventListener("click", addItem);
document.getElementById("hintButton").addEventListener("click", hints);
document.getElementById("hintClButton").addEventListener("click", hintsClose);
document.getElementById("clClrButton").addEventListener("click", clearBoxes);

//Name: 
//Description: 
//Input: 
//Output: 