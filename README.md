# Linked-List-Update-Problem
Project 1 for my ECE 309 Data Structures and Algorithms class using C++. This project uses two different wasy to reorder a linked list. The goal is to read a text file and based on the number of times a specific value is called, it will reorganize the linked list to try to make the requests for each number require less steps since you must traverse the list until you find your desired value.

Move-to-front approach: in this approach, upon an access to an item, we want to assume that it is very likely it will be accessed again soon, and thus we move it to the front of the linked list.

Transpose: in this approach, upon an access to an item, we want to assume that it is very likely it will be accessed again soon, however instead of puWng it in the front we just advance its locaAon by one posiAon, i.e., we swap it with the one immediately preceding it (if any). In other words, we are conservaAvely moving it close to the front, but not immediately to the front position.
