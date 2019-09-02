# Storing individual web pages from the log file into a linked list

### The Purpose of the Project :
This program 	stores individual web pages from the log file into a linked list and , it prints the most popular 10 web pages in a descending order.Then , it shows us to execution time of this program.

### Main Structure of the Project :

      List.h  :
      It contains the default contructor,the construction of struct Node, and there are 4 functions that have been implemented  in list.cpp class.These are nodegen,display,duprem and sorter functions.We will explain these funtions in list.cpp part.
      
      List.cpp :
      It contains the implementation of the default constructor and 4 functions.
           1)nodegen(string fileName) function :
           This public function stores web pages that reads from access_log file into a linked list.it has one parameter.
           2)duprem(node* head) function :
           This public function deletes all duplicated web pages and increases count by 1 before the process of the deletion.It has one parameter.
           3)sorter() function :
           This function sorts all web pages in a descending order.It has no parameter.
           4)display() function :
           This function displays the first  most visited 10 web pages.duprem and sorter functions have been executed in this function.It has no parameter.
           
     Source.cpp :
          It contains list.h,the main function and deleteChar function.
          In the main , it creates list object , opens the access_log  file and calculates the execution time .With the strlen function , the length of the access_log file will be equalized to n.Then ,
          With the for loop , it finds the string that is between GET and HTTP.Then ,this string value  will be assigned to temp string.After that , nodegen function will be called.Lastly , display function will be called.
         deleteChar(ifstream &in) :
            The access_log file encodes with UNICODE , but  Visual Studio deals with ASCII code. So,this function reads this type of file and ,deletes the first three characters.
            This is the screenshot of output(release) ; 
 
            NOTE : The execution time is approximately 26 seconds.The duprem function takes more than 20(more) seconds alone.We have worked to optimize our code.But ,linked list is too slow comparing to binary search or open hashing.We think our code has one of the fastest execution time between the other codes that implement the linked list.We have not used any extra library.
