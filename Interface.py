import socket
import sys
#TODO: figure out how to "include" the c++ parser, if we even need to do that at all
exit = 0
print "      _                      _            ____                    _      " 
print "     / \      __ _    __ _  (_)   ___    | __ )    __ _   _ __   | | __  "
print "    / _ \    / _` |  / _` | | |  / _ \   |  _ \   / _` | | '_ \  | |/ /  " 
print "   / ___ \  | (_| | | (_| | | | |  __/   | |_) | | (_| | | | | | |   <   "
print "  /_/   \_\  \__, |  \__, | |_|  \___|   |____/   \__,_| |_| |_| |_|\_\  "
print "             |___/   |___/                                               "

print " "
print "Welcome to Aggie Bank"
print "Enter a command from the following list of commands."
print "Be sure to enter the right parameters!"
print "--------------------------------------------------------------"
print "Add User  <Account Number> <Account Name>"
print "Delete User <Account Number>"
print "Update Balance <Account Number> <Account(Savings or Checking)> <Money Amount>    (put money to subtract in parenthesis like this: '(12345)' "
#	TODO: make this look nicer 
print "Display User <Account Number>"
print "Tansfer Money <Account Number> <Account(Savings or Checking)> <Money Amount>" 
#	from input account to other option (savings to checking or vice versa)
print "Send Money <Source Account Number> <Account(Savings or Checking)> <Money Amount> <Recipient Account Number>"
print "Exit"

error_message = "We didn't quite understand that. Please check your inputs and try again."

#TODO: add socket functionality
#TODO: comment out all pass statements as the functions are implemented
#TODO: make read_in() return something after each inputted line

def read_in():
	instruction = raw_input()
	inputsplit = line.split(' ') #splits the input string by whitespace
	if(inputsplit[0] == "Add"):
		#modify and send instruction socket to parser
		instr = 'INSERT INTO Users VALUES FROM (' + inputsplit[2] + ', ' + inputsplit[3] + ', 0, 0);' 
		#					  (account number,        account name,   savings, checking)
		
		#read_in()
		
		pass #tells the compiler to "pass by" and ignore without doing anything
		     #with pass, you can work on a function without having to worry as much about unfinished code
		     #preventing you from compiling
	elif(inputsplit[0] == "Delete"):
		#modify and send instruction socket to parser

		instr = 'DELETE FROM Users WHERE (accountNumber == ' + inputsplit[2] + ');'

		pass
		#read_in()
	elif(inputsplit[0] == "Update"):
		#modify and send instructions socket to parser
		#inst1 = 'currentbal <- project (' + inputsplit[3] ') (select (accountNumber == ' + inputsplit[2] + ') Users);' #TODO: store this result in a variable
		#				    savings or checking				     account number
		
		#if('(' in inputsplit[4]):
		#	if(')' in inputsplit[4]):
		#		newNumber = number obtained from database - inputted amount (inputsplit[4])
		#	else:
		#		print error_message
		#elif(')' not in inputsplit[4]):
		#	newNumber = number obtained from database + inputted amount (inputsplit[4])
		#else:
		#	print error_message
		
		#instr = 'UPDATE Users SET (' + inputsplit[3] + ') (' + newNumber + ') WHERE (accountNumber = ' + inputsplit[2] + ');'
		#				account,		amount,						account number
		
		pass
		#read_in()
	elif(inputsplit[0] == "Display"):
		#modify and send instructions socket to parser
		instr1 = 'thisUser <- select(accountNumber == ' + inputsplit[2] ') Users;'	#INSERT is the only command that can handle query inputs
		instr2 = 'SHOW thisUser;'							#splitting Display into these three instructions gets around this issue
		instr3 = 'DROP TABLE thisUser;' #allows us to reuse thisUser			#without us having to restructure a significant amount of our code

		pass
		#read_in()
	elif(inputsplit[0] == "Transfer"):
		#modify and send instruction socket to parser
		
		#inst1 = 'currentbal <- project (' + inputsplit[3] ') (select (accountNumber == ' + inputsplit[2] + ') Users);' #TODO: store this result in a variable
                #                                   savings or checking                              account number

	        #if(inst1 < int(inputsplit[4])):
		#	print 'not enough funds in ' + inputsplit[3]	

		#if(inputsplit[3] == 'Savings'):
		#	otherAccount = 'Checking')
		#elif(inputsplit[3] == 'Checking'):
		#	otherAccount = 'Savings')
		#else:
		#	print error_message

		#inst2 = 'currentbal <- project (' + otherAccount ') (select (accountNumber == ' + inputsplit[2] + ') Users);' #TODO: store this result in a variable
                #                                                                                account number

		#subtraction = inst1 - int(inputsplit[4])
		#addition = inst2 + int(inputsplit[4])

		#instr3 = 'UPDATE Users SET (' + inputsplit[3] + ') (' + subtraction + ') WHERE (accountNumber = ' + inputsplit[2] + ');'
                #                               account,                 amount,                                         account number

		#instr4 = 'UPDATE Users SET (' + otherAccount + ') (' + addition + ') WHERE (accountNumber = ' + inputsplit[2] + ');'
                #                               account,               amount,                                  account number

		pass
		#read_in()
	elif(inputsplit[0] == "Send"):

		#inst1 = 'currentbal <- project (' + inputsplit[3] ') (select (accountNumber == ' + inputsplit[2] + ') Users);' #TODO: store this result in a variable
                #                                   savings or checking                              account number

		#if(inst1 < int(inputsplit[4])):
                #       print 'not enough funds in ' + inputsplit[3]   

		#inst2 = 'currentbal <- project (Checking) (select (accountNumber == ' + inputsplit[5] + ') Users);' #TODO: store this result in a variable
                #                               transfers go to checking by default       target account number

		#subtraction = inst1 - int(inputsplit[4])
                #addition = inst2 + int(inputsplit[4])

                #instr3 = 'UPDATE Users SET (' + inputsplit[3] + ') (' + subtraction + ') WHERE (accountNumber = ' + inputsplit[2] + ');'
                #                               account,                 amount,                                     account number

		#instr4 = 'UPDATE Users SET (Checking) (' + addition + ') WHERE (accountNumber = ' + inputsplit[5] + ');'
                #                            account,       amount,                                  target account number

		pass
		#read_in()
	elif(inputsplit[0] == "Exit"
		instr = 'EXIT;'
		pass
		#read_in()
	else:
		print error_message

=======
#TODO: make read_in() return something after each inputted line
initialInstruction = "CREATE TABLE Users (accountNumber INTEGER, accountName VARCHAR(30), savings INTEGER, checking INTEGER) PRIMARY KEY (accountName);"
#TODO: send this initial instruction
read_in()
