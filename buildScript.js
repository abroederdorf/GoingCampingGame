/*******************************
* Author: Alicia Broederdorf
* Date: October 30, 2015
* Description: Gone Camping game - Document Elements
* Create and add elements to html for Gone Camping game
* including table, paragraphs, headers, divs, and buttons
*******************************/

//Name: buildTitle
//Description: Build div and header elements for game title
//Input: None
//Output: Div element with header element appended
function buildTitle(){
	//Create div
	var newDiv = document.createElement("div");
	newDiv.style.backgroundColor = "#43BFC7";
	newDiv.style.width = "500px";
	newDiv.id = "titleDiv";
	
	//Create header
	var newHead = document.createElement("h1");
	newHead.textContent = "Going Camping";
	newHead.style.textAlign = "center";
	newHead.id = "titleHead";
	newDiv.appendChild(newHead);
	
	return newDiv;
}

//Name: buildTable
//Description: Build 4x4 table and add text content
//Input: None
//Output: Table returned with 4x4 cells
function buildTable() {
	//Room names
	var roomNames = ["Bedroom 2", "Bathroom", "Bedroom 1", "Hall Closet", "Dining Room", 
		"Kitchen", "Living Room", "Entry", "Study", "Porch"];
		
	//Create table
	var newTable = document.createElement("table");
	newTable.style.borderSpacing = "0px";
	newTable.cellPadding = "10";
	newTable.style.marginLeft = "80px";
	newTable.style.marginTop = "20px";
	newTable.style.border = "solid 5px";
	newTable.style.borderColor = "brown";
	
	//Create body
	var tblBody = document.createElement("tbody");
	newTable.appendChild(tblBody);
	
	//Create body rows and cells
	for (var i = 0; i < 3; i++)
	{
		//Create row
		var newRow = document.createElement("tr");
		tblBody.appendChild(newRow);
		
		//Create cells with id and numbered text
		for (var j = 0; j < 3; j++)
		{
			var newCell = document.createElement("td");
			newCell.textContent = roomNames[i * 3 + j];
			idName = "c" + (j+1) + "" + (i+1);
			newCell.id = idName;
			newCell.style.border = "solid 1px";
			newCell.style.textAlign = "center";
			newRow.appendChild(newCell);
		}
	}
	
	//Create front porch
	newRow = document.createElement("tr");
	tblBody.appendChild(newRow);
	newCell = document.createElement("td");
	newCell.textContent = roomNames[9];
	newCell.id = "c14";
	newCell.style.border = "solid 1px";
	newCell.style.textAlign = "center";
	newCell.colSpan = "3";
	newRow.appendChild(newCell);
	
	return newTable;
}	

//Name: buildButtons
//Description: Create div and append five buttons to it.
// Create four navigational buttons and one mark cell button
//Input: None
//Output: 1 div and 5 buttons are created, div is returned
function buildButtons() {
	//Create div for buttons
	var butDiv = document.createElement("div");
	butDiv.id = "butDiv";
	butDiv.style.paddingTop = "10px";
	butDiv.style.marginLeft = "40px";

	//Create navigation buttons
	//Up button
	var upBut = document.createElement("button");
	upBut.textContent = "Up";
	upBut.style.textAlign = "center";
	upBut.style.marginLeft = "33px";
	upBut.id = "upButton";
	butDiv.appendChild(upBut);
	
	//Action Button
	var actBut = document.createElement("button");
	actBut.textContent = "Take Action!";
	actBut.style.textAlign = "center";
	actBut.style.marginLeft = "70px";
	actBut.id = "actButton";
	butDiv.appendChild(actBut);
	
	//Start Button
	var startBut = document.createElement("button");
	startBut.textContent = "Start Game";
	startBut.style.textAlign = "center";
	startBut.style.marginLeft = "75px";
	//startBut.style.backgroundColor = "lime";
	startBut.id = "startButton";
	butDiv.appendChild(startBut);
			
	//Left button
	var lnBrk = document.createElement("br");
	butDiv.appendChild(lnBrk);
	var lfBut = document.createElement("button");
	lfBut.textContent = "Left";
	lfBut.style.textAlign = "center";
	lfBut.style.marginTop = "5px";
	lfBut.id = "lfButton";
	butDiv.appendChild(lfBut);
	
	//Right button
	var rtBut = document.createElement("button");
	rtBut.textContent = "Right";
	rtBut.style.textAlign = "center";
	rtBut.style.marginLeft = "20px";
	rtBut.id = "rtButton";
	butDiv.appendChild(rtBut);
	
	//Instructions Button
	var instrBut = document.createElement("button");
	instrBut.textContent = "Instructions";
	instrBut.style.textAlign = "center";
	instrBut.style.marginLeft = "195px";
	instrBut.id = "instrButton";
	butDiv.appendChild(instrBut);
	
	//Down button
	lnBrk = document.createElement("br");
	butDiv.appendChild(lnBrk);
	var dnBut = document.createElement("button");
	dnBut.textContent = "Down";
	dnBut.style.textAlign = "center";
	dnBut.style.marginLeft = "23px";
	dnBut.style.marginTop = "5px";
	dnBut.id = "dnButton";
	butDiv.appendChild(dnBut);
	
	//Leave Button
	var lvBut = document.createElement("button");
	lvBut.textContent = "Meet Friends";
	lvBut.style.textAlign = "center";
	lvBut.style.marginLeft = "60px";
	lvBut.id = "leaveButton";
	butDiv.appendChild(lvBut);

	//Hints Button
	var hintBut = document.createElement("button");
	hintBut.textContent = "Hints";
	hintBut.style.textAlign = "center";
	hintBut.style.marginLeft = "92px";
	hintBut.id = "hintButton";
	butDiv.appendChild(hintBut);
	
	return butDiv;
}

//Name: buildInstructions
//Description: Div with paragraphs and headers to display instructions
//Input: None
//Output: Div element with appended paragraph and headers
function buildInstructions(){
	//Create div to hold instructions area
	var instrDiv = document.createElement("div");
	instrDiv.id = "instrDiv";
	instrDiv.style.marginTop = "10px";
	instrDiv.style.border = "dashed 1px";
	instrDiv.style.width = "500px";
	instrDiv.style.backgroundColor = "#E77471";
	
	//Create main header
	var hdr = document.createElement("h3");
	hdr.textContent = "Going Camping";
	hdr.id = "instrH3";
	hdr.style.paddingLeft = "5px";
	instrDiv.appendChild(hdr);
	
	//Create overview paragraph
	var par = document.createElement("p");
	par.textContent = "You are about to leave on a camping trip in the mountains, however, you forgot to pack three of the ten essentials and you need to get your house ready before your friends arrive in 10 minutes to pick you up.";
	par.style.paddingLeft = "5px";
	par.style.paddingRight = "5px";
	par.id = "instrOverview";
	instrDiv.appendChild(par);
	
	//Create objective header
	var hdr = document.createElement("h4");
	hdr.textContent = "Objective";
	hdr.id = "instrObjH";
	hdr.style.paddingLeft = "5px";
	instrDiv.appendChild(hdr);
	
	//Create objective paragraph
	var par = document.createElement("p");
	par.textContent = "You must pack the three remaining ten essentials in your backpack, close the windows, turn off all the lights, feed the cat, and take the garbage out before you can exit the porch to meet your friends.";
	par.style.paddingLeft = "5px";
	par.style.paddingRight = "5px";
	par.id = "instrObj";
	instrDiv.appendChild(par);
	
	//Create description header
	var hdr = document.createElement("h4");
	hdr.textContent = "Description";
	hdr.id = "instrDesH";
	hdr.style.paddingLeft = "5px";
	instrDiv.appendChild(hdr);
	
	//Create objective paragraph
	var par = document.createElement("p");
	par.textContent = "Navigate through the house to find which rooms have open windows to close and lights on that should be turned off. Find your cat Tiger and feed her, as well as take out the garbage. Three of the rooms contain a locked cabinet that your gear is stored in. You must choose the correct three items to be able to leave with your friends. You'll have to figure out the combination every time you want to open the cabinet. When you think you have the house prepared and the three missing items packed in your backpack, from the porch try to meet your friends. If you are correct you will successfully meet your friends, otherwise you'll have to go back and choose the correct item(s) or complete the unfinished house task(s). You are only allowed three items in your backpack at a time from the ten that are stored in the cabinets. Be on the lookout for clues along the the way!";
	par.style.paddingLeft = "5px";
	par.style.paddingRight = "5px";
	par.id = "instrDes";
	instrDiv.appendChild(par);
	
	//Create directions header
	var hdr = document.createElement("h4");
	hdr.textContent = "Directions";
	hdr.id = "instrDirH";
	hdr.style.paddingLeft = "5px";
	instrDiv.appendChild(hdr);
	
	//Create objective paragraph
	var par = document.createElement("p");
	par.textContent = "Use the direction buttons to navigate through the house. You may only reach the porch by exiting the entry. Messages will appear as you enter the rooms, if you'd like to take action - hit the button! If you want to meet your friends, click the meet friends button when you are on the porch. When you are ready to start, click the start game button. Good luck!";
	par.style.paddingLeft = "5px";
	par.style.paddingRight = "5px";
	par.id = "instrDir";
	instrDiv.appendChild(par);
	
	//Create instructions close button
	var instrClBut = document.createElement("button");
	instrClBut.textContent = "Close Instructions";
	instrClBut.style.textAlign = "center";
	instrClBut.style.marginLeft = "5px";
	instrClBut.style.marginBottom = "5px";
	instrClBut.id = "instrClButton";
	instrDiv.appendChild(instrClBut);

	return instrDiv;
}

//Name: buildHints
//Description: Div with paragraphs and headers to display instructions
//Input: None
//Output: Div element with appended paragraph and headers
function buildHints(){
	//Create div to hold instructions area
	var hintDiv = document.createElement("div");
	hintDiv.id = "hintDiv";
	hintDiv.style.marginTop = "10px";
	hintDiv.style.border = "dashed 1px";
	hintDiv.style.width = "500px";
	hintDiv.style.backgroundColor = "#C8A2C8";
	
	//Create main header
	var hdr = document.createElement("h3");
	hdr.textContent = "Hints";
	hdr.id = "hintH3";
	hdr.style.paddingLeft = "5px";
	hintDiv.appendChild(hdr);
	
	//Create overview paragraph
	var par = document.createElement("p");
	par.textContent = "Five rooms have clues as to the items already in your pack, leaving five of the 10 essentials as the potential missing items. The items are randomly stored in each cabinet so the three missing items could all be in one cabinet, could be stored between two cabinets, or there coule be one missing item in each cabinet. When you try to meet your friends, you'll learn how many of the items in your pack are correct.";
	par.style.paddingLeft = "5px";
	par.style.paddingRight = "5px";
	par.id = "hintContent";
	hintDiv.appendChild(par);
	
	//Create hintuctions close button
	var hintClBut = document.createElement("button");
	hintClBut.textContent = "Close Hints";
	hintClBut.style.textAlign = "center";
	hintClBut.style.marginLeft = "5px";
	hintClBut.style.marginBottom = "5px";
	hintClBut.id = "hintClButton";
	hintDiv.appendChild(hintClBut);
	
	return hintDiv;
}

//Name: build player status
//Description: Text area that displays items currently
// in backpack
//Input: None
//Output: Div with three paragraph elements 
function buildStatus() {
	//Create div to hold status
	var statDiv = document.createElement("div");
	statDiv.id = "statusDiv";
	statDiv.style.marginTop = "10px";
	statDiv.style.paddingBottom = "10px";
	statDiv.style.backgroundColor = "silver";
	statDiv.style.border = "dashed 2px";
	statDiv.style.width = "500px";
	
	//Create title
	var newHead = document.createElement("h3");
	newHead.textContent = "Items in Backpack";
	newHead.style.paddingLeft = "10px";
	newHead.id = "StatusTitle";
	statDiv.appendChild(newHead);
	
	//Create span elements to display items
	for (var i = 0; i < 3; i++)
	{
		//New span
		var newSpan = document.createElement("span");
		var idName = "statSpan" + (i+1);
		newSpan.id = idName;
		//newSpan.style.marginRight = "20px";
		newSpan.style.marginLeft = "10px";
		var str = (i + 1) + " Empty";
		newSpan.textContent = str;
		statDiv.appendChild(newSpan);
	}
	
	//Create time remaining
	var timeSpan = document.createElement("span");
	timeSpan.id = "timeTitle";
	timeSpan.textContent = "Time Remaining: ";
	timeSpan.style.marginLeft = "30px";
	statDiv.appendChild(timeSpan);
	
	//Remaining minutes
	var timeSpan = document.createElement("span");
	timeSpan.id = "remainTime";
	timeSpan.textContent = "10:00";
	timeSpan.style.marginLeft = "5px";
	statDiv.appendChild(timeSpan);
	
	//Create checklist div
	var clDiv = document.createElement("div");
	clDiv.style.width = "97%";
	clDiv.style.marginLeft = "5px";
	clDiv.style.marginTop = "10px";
	clDiv.style.border = "solid 1px";
	clDiv.id = "checkListDiv";
	statDiv.appendChild(clDiv);
	
	//Create checklist header
	var clHdr = document.createElement("p");
	clHdr.textContent = "10 Essentials Checklist";
	clHdr.style.marginLeft = "5px";
	clHdr.style.fontStyle = "italic";
	clHdr.style.fontWeight = "bold";
	clDiv.appendChild(clHdr);
	
	//Create checkboxes
	var itemNames = ["Sunglasses", "Headlamp ", "Matches", "First-aid", "Map", "Fire starter", "Candy Bar", "Compass", "Jacket", "Knife"];
	for (var i = 1; i < 11; i++)
	{
		//Create label
		var newLab = document.createElement("LABEL");
		var idName = "clLab" + i;
		newLab.id = idName;
		newLab.style.marginLeft = "15px";
		clDiv.appendChild(newLab);
	
		//Append radio button to label
		var clBox = document.createElement("INPUT");
		clBox.setAttribute("type", "checkbox"); 
		idName = "clBox" + i;
		clBox.id = idName;
		clBox.name = "checkList";
		newLab.appendChild(clBox);
		
		//New span
		var clSpan = document.createElement("span");
		var idName = "clSpan" + i;
		clSpan.id = idName;
		var str = itemNames[i - 1];
		clSpan.textContent = str;
		newLab.appendChild(clSpan);
	}
	
	//Create button to clear check marks
	var clBut = document.createElement("button");
	clBut.textContent = "Clear All Checkmarks";
	clBut.style.textAlign = "center";
	clBut.style.marginLeft = "160px";
	clBut.style.marginBottom = "5px";
	clBut.style.marginTop = "10px";
	clBut.id = "clClrButton";
	clDiv.appendChild(clBut);

	return statDiv;
}

//Name: buildMessage
//Description: Paragraph to update with messages for player
//Input: None
//Output: Div element with appended paragraph
function buildMessage(){
	//Create div to hold message area
	var msgDiv = document.createElement("div");
	msgDiv.id = "msgDiv";
	msgDiv.style.marginTop = "10px";
	msgDiv.style.border = "dotted 1px";
	msgDiv.style.width = "500px";
	msgDiv.style.backgroundColor = "#99C68E";
	
	//Create header
	var newHead = document.createElement("h3");
	newHead.textContent = "Messages:";
	newHead.id = "msgHead";
	newHead.style.marginLeft = "10px";
	msgDiv.appendChild(newHead);
	
	//Create paragraph element
	var newPar = document.createElement("p");
	newPar.style.width = "85%";
	newPar.style.align = "center";
	newPar.id = "msgPar";
	newPar.style.marginLeft = "10px";
	newPar.textContent = "Message goes here";
	msgDiv.appendChild(newPar);
	
	//Create paragraph element for combination
	var newPar = document.createElement("p");
	newPar.style.width = "85%";
	newPar.style.align = "center";
	newPar.id = "msgParCom";
	newPar.style.marginLeft = "10px";
	newPar.textContent = " ";
	msgDiv.appendChild(newPar);
	
	return msgDiv;
}

//Name: buildItems
//Description: This div will include radio buttons the player
//uses to add items to her backpack
//Input: None
//Output: Div element with radio buttons
function buildItems() {
	//Create div
	var itmDiv = document.createElement("div");
	itmDiv.style.width = "500px";
	itmDiv.style.border = "solid gray 1px";
	itmDiv.style.marginTop = "10px";
	itmDiv.style.backgroundColor = "#FFE5B4";
	itmDiv.id = "itemDiv";
	
	//------------------------------------------------------
	
	//Create header
	var newHead = document.createElement("h3");
	newHead.textContent = "Cabinet";
	newHead.id = "cabHead";
	newHead.style.marginLeft = "10px";
	itmDiv.appendChild(newHead);
	
	//------------------------------------------------------
	
	//Create message
	var newPar = document.createElement("p");
	newPar.textContent = "The cabinet contains the following items";
	newPar.id = "cabPar";
	newPar.style.marginLeft = "10px";
	itmDiv.appendChild(newPar);
	
	//------------------------------------------------------
	
	//Create cabinet radio buttons
	for (var i = 0; i < 4; i++)
	{
		//Create label
		var newLab = document.createElement("LABEL");
		var idName = "cabLab" + (i+1);
		newLab.id = idName;
		newLab.style.margin = "3px";
		itmDiv.appendChild(newLab);
	
		//Append radio button to label
		var cabRad = document.createElement("INPUT");
		cabRad.setAttribute("type", "radio"); 
		idName = "cabRad" + (i+1)
		cabRad.id = idName;
		cabRad.name = "cabinetItems";
		newLab.appendChild(cabRad);
		//document.getElementById("red").checked
		
		//New span
		var cabSpan = document.createElement("span");
		var idName = "cabSpan" + (i+1);
		cabSpan.id = idName;
		var str = (i + 1) + " Empty";
		cabSpan.textContent = str;
		newLab.appendChild(cabSpan);
	}
	
	//------------------------------------------------------
	
	//Create message
	newPar = document.createElement("p");
	newPar.textContent = "Would you like to pack one of the items from the cabinet in your backpack?";
	newPar.id = "questPar";
	newPar.style.marginLeft = "10px";
	itmDiv.appendChild(newPar);
	
	//------------------------------------------------------
		
	//Create yes cabinet close button
	var yesBut = document.createElement("button");
	yesBut.textContent = "Yes";
	yesBut.style.textAlign = "center";
	yesBut.style.marginLeft = "5px";
	yesBut.style.marginBottom = "5px";
	yesBut.id = "yesButton";
	itmDiv.appendChild(yesBut);
	
	//------------------------------------------------------
	
	//Create no cabinet close button
	var closeBut = document.createElement("button");
	closeBut.textContent = "No, Close Cabient";
	closeBut.style.textAlign = "center";
	closeBut.style.marginLeft = "20px";
	closeBut.style.marginBottom = "5px";
	closeBut.id = "closeButton";
	itmDiv.appendChild(closeBut);
	
	//------------------------------------------------------
	
	//Create div to hold all elements related to adding item to pack
	var packDiv = document.createElement("div");
	packDiv.id = "packDiv";
	itmDiv.appendChild(packDiv);
	
	//Create yes cabinet message
	newPar = document.createElement("p");
	newPar.textContent = "Select an item from the cabinet above, then select a position in your backpack to add it.";
	newPar.id = "addPar";
	newPar.style.marginLeft = "10px";
	packDiv.appendChild(newPar);
	
	//------------------------------------------------------
	
	//Create add item radio buttons
	for (var i = 0; i < 3; i++)
	{
		//Create label element
		newLab = document.createElement("LABEL");
		idName = "packLab" + (i+1);
		newLab.id = idName;
		newLab.style.margin = "3px";
		packDiv.appendChild(newLab);
	
		//Append radio button to label
		cabRad = document.createElement("INPUT");
		cabRad.setAttribute("type", "radio"); 
		idName = "packRad" + (i+1)
		cabRad.id = idName;
		cabRad.name = "packPos";
		newLab.appendChild(cabRad);
		
		//Append text node to label
		var packPos = i + 1;
		txtNd = document.createTextNode(packPos);
		idName = "packTxt" + (i+1);
		txtNd.id = idName;
		newLab.appendChild(txtNd);
	}
	
	//------------------------------------------------------
	
	//Create pack item button
	var packBut = document.createElement("button");
	packBut.textContent = "Add Item";
	packBut.style.textAlign = "center";
	packBut.style.marginLeft = "20px";
	packBut.style.marginBottom = "5px";
	packBut.id = "packButton";
	packDiv.appendChild(packBut);
	
	return itmDiv;
}

//Name: buildPuzzle
//Description: This presents the interface for the player to enter a combination
// guess and get feedback about the guess
//Input: None
//Output: Div element with appended paragraphs, header, buttons, and text input
function buildPuzzle(){
	//Create div
	var puzDiv = document.createElement("div");
	puzDiv.style.width = "500px";
	puzDiv.style.border = "solid gray 1px";
	puzDiv.style.marginTop = "10px";
	puzDiv.style.backgroundColor = "#F9966B";
	puzDiv.id = "puzzleDiv";
	
	//Create header
	var newHead = document.createElement("h3");
	newHead.textContent = "Combination";
	newHead.id = "puzHead";
	newHead.style.marginLeft = "10px";
	puzDiv.appendChild(newHead);
	
	//Create message
	var newPar = document.createElement("p");
	newPar.textContent = "Enter your guess for the combination, you can type the numbers in:";
	newPar.id = "puzPar";
	newPar.style.marginLeft = "10px";
	puzDiv.appendChild(newPar);
		
	//Create combination text input
	var puzTxt = document.createElement("INPUT");
	puzTxt.setAttribute("type", "number"); 
	puzTxt.size = "10";
	puzTxt.id = "puzGuess";
	puzTxt.style.marginLeft = "10px";
	puzDiv.appendChild(puzTxt);
	
	//Create submit button for guess
	var subBut = document.createElement("button");
	subBut.textContent = "Guess";
	subBut.style.textAlign = "center";
	subBut.style.marginLeft = "20px";
	subBut.id = "submitButton";
	puzDiv.appendChild(subBut);
	
	//Create message
	newPar = document.createElement("p");
	newPar.id = "puzFB";
	newPar.textContent = " ";
	newPar.style.marginLeft = "10px";
	puzDiv.appendChild(newPar);
	
	//Create exit button to close cabinet
	var exitBut = document.createElement("button");
	exitBut.textContent = "Exit";
	exitBut.style.textAlign = "center";
	exitBut.style.marginLeft = "10px";
	exitBut.style.marginBottom = "5px";
	exitBut.id = "exitButton";
	puzDiv.appendChild(exitBut);
	
	return puzDiv;
}

//Create title, table, buttons, status, message, and items area and append to page
document.body.appendChild(buildTitle());
document.body.appendChild(buildTable());
document.body.appendChild(buildButtons());
document.body.appendChild(buildInstructions());
document.body.appendChild(buildHints());
document.body.appendChild(buildStatus());
document.body.appendChild(buildMessage());
document.body.appendChild(buildPuzzle());
document.body.appendChild(buildItems());

//Initialize game board
document.getElementById("puzzleDiv").style.display = "none";
document.getElementById("itemDiv").style.display = "none";
document.getElementById("packDiv").style.display = "none";
document.getElementById("instrDiv").style.display = "none";
document.getElementById("hintDiv").style.display = "none";
document.getElementById("msgParCom").style.display = "none";
document.getElementById("msgPar").textContent = "Welcome to the game! Click the instructions button for more information. When you are ready to start playing, click the start game button. Good luck!";