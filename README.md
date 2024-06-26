# Linked-List-Update-Problem
Project 1 for my ECE 309 Data Structures and Algorithms class using C++. This project uses two different wasy to reorder a linked list. The goal is to read a text file and based on the number of times a specific value is called, it will reorganize the linked list to try to make the requests for each number require less steps since you must traverse the list until you find your desired value.

Move-to-front approach: in this approach, upon an access to an item, we want to assume that it is very likely it will be accessed again soon, and thus we move it to the front of the linked list.

![image](https://github.com/Tramanata/Linked-List-Update-Problem/assets/102120863/591423f5-f4b5-4162-9545-efcec4a25e5f)


Transpose: in this approach, upon an access to an item, we want to assume that it is very likely it will be accessed again soon, however instead of puttng it in the front we just advance its location by one position, i.e., we swap it with the one immediately preceding it (if any). In other words, we are conservatively moving it close to the front, but not immediately to the front position.

![image](https://github.com/Tramanata/Linked-List-Update-Problem/assets/102120863/c9eb7f36-28ef-43f1-be27-0e1542534fef)


The program that you will implement shall do the following:

    1- Parse the input parameters to know the heuristic to be used, input file, LinkedList file.
    2- For the above example, the program will parse the data.txt file to create the initial linked list. 
    Each line in the file represents an integer value to be stored in a linked-list item.
    3- Iterate over each item in request_x.txt to process the requests; each line is an independent request for a particular 
    item in the linked list, to be identified through the item value.
    4- After processing each request in (3), you will use the heuristic option (in this example Move-to-front) to decide how to 
    update the linked-list based on the request. For this example, you will move the accessed item to the front.
    5- Move to the next request
    6- Repeat 5-6 until the end of the request_x.txt file


Grading Format

    10 points: Files submieed with proper name.
    10 points: Program is complete. The program successfully takes three inputs and returns th integer as output.
    10 points: Proper coding style and comments.
    60 points: the program performs all funcAons correctly:
        (10 pts) Create a class named Linkedlist and store the data.txt in it.
        (10 pts) Correctly implement for Move-to-front.
        (10 pts) Correctly implement for transpose.
        (10 pts) Correct results for validaAon1.txt and validaAon2.txt for
        (20 pts) Correct results for request files.
    10 points: Report.
