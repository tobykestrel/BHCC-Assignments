/*
Toby Hansen
April 12, 2026
SQL Programming
Chapter Five Textbook Assignment
*/

/*Q1 Add a new row in the ORDERS table with the following data: Order# is 2222, customer# is 2121, 
and the order date is January 22, 2016. Describe the error raised and explain what causes this 
error. Write another query with a change that allows it to succeed. You may use any valid data.*/
insert into ORDERS (Order#, Customer#, OrderDate)
values (2222, 2121, to_date('22-JAN-2016', 'DD-MON-YYYY'));
/*It causes a foreign key violation because the specified Customer# doesn't exist in the CUSTOMERS table*/
insert into ORDERS (Order#, Customer#, OrderDate)
values (2222, 1001, to_date('22-JAN-2016', 'DD-MON-YYYY'));

/*Q2 Create a script using  variables that allow the user to set a new retail price for a book 
based on ISBN. Run your script for the following values: ISBN = 1059831198, and retail = $99.99*/
update BOOKS 
set Retail = :NewRetailPrice 
where Isbn = :IsbnOfBookToModify;

/*Q3 Write a query to create a new price list for books written by the same author. Allow the user to 
enter only the first 4 letters of the last name and the first letter of the first name, they should be 
able to get the right author. Ask the user to input a percentage and calculate the new discounted price 
based on the current retail price minus this percentage. Round the result to cents (two decimals). 
For your example query, assume the user wants to discount the price of James Patterson books by 20%.*/
select
    Fname || ' ' || Lname as "Author",
    Title as "Book Title",
    round(Retail * (1 - (to_number(:DiscountPercentage) / 100)), 2) as "Discounted Price"
from BOOKS 
    inner join BOOKAUTHOR using (Isbn)
    inner join AUTHOR using (AuthorId)
where upper(substr(Lname, 1, 4)) = upper(substr(:FirstFourLettersAuthorLName, 1, 4))
    and upper(substr(Fname, 1, 1)) = upper(substr(:FirstLetterAuthorFName, 1, 1));

/*Q4 Add a new row in the ORDERS table with the following data: Order# = 1023 
and Customer# = 1009. Describe the error raised and what caused the error*/
insert into ORDERS (Order#, Customer#) 
values (1023, 1009);
/*It causes a not-null violation, because the OrderDate is a required field.*/
insert into ORDERS (Order#, Customer#, OrderDate) 
values (1023, 1009, to_date('22-JAN-2026', 'DD-MON-YYYY'));

/*Q5 Delete Order# 1005. You need to address both the master order record and the related detail records.*/
delete from ORDERITEMS where Order# = 1005;
delete from ORDERS where Order# = 1005;