/*
Toby Hansen
February 4, 2026
SQL Programming
Chapter Two Textbook Assignment
*/

/* 1. Create a report showing ALL data from the PUBLISHER table. */
select * from PUBLISHER;

/* 2. List contact names and phone numbers of publisher contacts from the PUBLISHER table. 
Show column heading for the publisher contacts as "Contact name" in the report. */
select 
    Contact as "Contact name", 
    Phone as "Phone"
from PUBLISHER;

/* 3. Create a mailing list for the customers, include both first and last names. 
The report should have the following headings: Name, Street Address, City, State, Zip Code */
select 
    Firstname || ' ' || Lastname as "Name", 
    Address as "Street Address", 
    City as "City", 
    State as "State", 
    Zip as "Zip Code" 
from CUSTOMERS;

/* 4. List ISBN and the title for each book in the BOOKS table, along with cost and retail price of each book. */
select ISBN, Title, Cost, Retail from BOOKS;

/* 5. List all publication dates. List each date only ONCE. */
select distinct Pubdate from BOOKS;

/* 6. Show the structure of the CUSTOMERS table. */
describe CUSTOMERS;

/* 7. Create a list of orders and the city and state they are shipping to. Show order numbers followed by city and state (separated by comma and space in one column). 
Your report will have two columns. Create appropriate alias names for your columns. */
/* Toby Note: Order# works in oracle as-is, but should be double quoted like "Order#" in most other cases because of the hashtag. */
select
    Order# as "Order ID",
    Shipcity || ', ' || Shipstate as "Ship Location"
from ORDERS;

/* 8. For JustLee planning purposes, provide a list of all the books with a 5% retail price increase. 
Show the ISBN, title, current, and increased price. Use appropriate headings for calculated fields in your report. */
/* Toby Note: This question is not phrased in a way that's easy to understand. I'm interpreting it as "list all the books that
have a price increase of 5% from cost to retail", but none of the books in the provided database meet that specification. */
select
    ISBN, 
    Title as "Title", 
    Cost as "Current Price",
    Retail as "Increased Retail Price"
from BOOKS
where Retail = 1.05*Cost;
/* To make sure I had this right, I queried for all of the price increase percentages outright: */
select
    ISBN, 
    Title as "Title", 
    Cost as "Current Price",
    Retail as "Increased Price",
    Round((100*Retail/Cost)-100, 2) || '%' as "Retail price increase"
from BOOKS;
/* And sure enough, none of the percentages were even close to 5%, so I thought maybe I was just reading it all wrong. Maybe there was a field that wasn't in the  
entity-relationship diagram we were given as a reference, something like "Futureretail" to suggest that JustLee tracks the price they plan on changing a book to. */
describe BOOKS;
/* Unfortunately, nothing relevant turned up. Although, I did notice a field titled QOH (that I'm presuming stands for "quantity on hand") which isn't included in
the entity-relationship reference diagram. I decided instead to interpret the question as if it were asking: "list all the books if the prices were 5% higher." */
select
    ISBN, 
    Title as "Title", 
    Retail as "Current Price",
    round(Retail*1.05, 2) as "5% Increased Price"
from BOOKS;