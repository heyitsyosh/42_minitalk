<h1 align="center">
	minitalk
</h1>

*<p align="center">The purpose of this project is to code a small data exchange program using UNIX signals.</p>*

## Score: 125/100🎉

## Description:
Client converts message into binary data, then sends data to server process using the siganls SIGUSER1, SIGUSER2.  
Server signal handler reconstructs data and prints message.  
(In bonus implementation, server sends ack signal to client after recieving full message.)

## Set-up:
First, enter directory with `cd minitalk`.  
Then use any Makefile command.

#### Makefile Commands:
```C
make        //compile executables (./server, ./client)
make bonus  //compile executables (./server, ./client) for bonus implmentation 
make server //compile ./server for mandatory implementation
make client //compile ./client for mandatory implementation
make clean  //delete .o
make fclean //delete .o and executables
make re     //delete .o and executables, then recompile
```

## Usage:  
```
./server
./client <server_pid> <message_to_send>
```
