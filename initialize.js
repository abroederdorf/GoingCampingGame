/*******************************
* Author: Alicia Broederdorf
* Date: October 30, 2015
* Description: Gone Camping game - Document Elements
* Initialize game by hiding items
*******************************/

//Initialize game board by hiding various areas like messsages, puzzle, cabinet, instructions, and hints
document.getElementById("puzzleDiv").style.display = "none";
document.getElementById("itemDiv").style.display = "none";
document.getElementById("packDiv").style.display = "none";
document.getElementById("instrDiv").style.display = "none";
document.getElementById("hintDiv").style.display = "none";
document.getElementById("msgParCom").style.display = "none";


//Disable game buttons
document.getElementById("upButton").disabled = true;
document.getElementById("dnButton").disabled = true;
document.getElementById("rtButton").disabled = true;
document.getElementById("lfButton").disabled = true;
document.getElementById("actButton").disabled = true;
document.getElementById("leaveButton").disabled = true;