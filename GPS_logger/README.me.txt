/////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////// 				 ///////////////////////////////////
///////////////////////      GPS Arduino Logger  	///////////////////////////////////
//////////////////////					//////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////



####################################################################################################################################################
##																		####
##    Source code creating csv file for logs, by the way can modifying source code to create txt file this is your choice.			####
##																		####
##	Let's talk little bit about hardware point, 												####
##	So this project need few components of sensors: GPS Module, Micdro SD card module, Microcontroller, Any wires and power 5-12(V).        ####  
##	I choose Arduino board this case you can choose raspberry pi, ESP32, ESP8266 and other controllers, this is your choice. 		####
##	Copy all data and insert in Google Map or other platform map										####
##	This projcet play's big role GPS module, In my case I chose the Ublox NEO-6M GPS Module. For logs files i use micro sd car module. 	####
##	OK let's talk about Arduino pins 													####
##																		####		
##	GPS Module pins:															####
##																		####	
##		TX : 2																####
##		RX : 3																####
##																		####			
##	SD micro module pins:															####
##																		####
##		cs 	:	4														####
##		sck 	: 	13														####
##		mosi	:	11														####
##		miso 	:	12														####
##		VCC/5V	:	5V														####
##		GND/gnd :	GND														####	
####################################################################################################################################################

Use this link:
	      
		https://www.google.com/maps


####################################################################################################################################################
##																		####
##	Creating you trajectory  trace :													####	
##																		####
##																		####
##		1) Convert csv file in kml format												####
##																		####	
##		2) Download Google Earth application 												####	
##																		####	
##		3) Import data in Google Earth after have two options, First, Download kml file from Google Earth and import in google map.	####	
##		   Second way is if Google Earth work's without bugs it's show trajectory of your traice 					####
##																		####
##		4) From Google map u can print map, make export kml file and 									####
##		   you have difference ways													####
##																		####	
##		5) Have fun with project! have a nice day 											####
##																		####
####################################################################################################################################################

