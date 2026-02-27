/*
Toby Hansen
February 13, 2026
SQL Programming
Chapter Eight Textbook Assignment
*/

/* 1. List all order numbers and their ship dates for orders shipped after March 15, 2012. */
select Order#, Shipdate 
from ORDERS
where Shipdate > date '2012-03-15';

/* 2. List all customers that live in Massachusetts or California. Show the first and last 
names together in the same column, then city, then state. Sort the results in ascending 
order by the last name within the state. Use appropriate column aliases for the headings.*/
select 
    Firstname || ' ' || Lastname as "Name",
    City as "City",
    State as "State"
from CUSTOMERS
where State in ('MA','CA')
order by State asc, Lastname asc;

/* 3. List the titles, retail price, and discount for all books 
that contain the word “cook” in the title. Sort by cost. */
select Title, Retail, Discount, Cost
from BOOKS
where lower(Title) like '%cook%'
order by Cost asc;

/* 4. Report all books published after Jan. 1st, 2015, as well as all books published in 2014 
that have retail price of $50 or less. Show the title, publisher's number, retail price, and 
date published. The list should sort the data first by publisher number, then by retail price 
within each publisher. So you will have two sets of data in the report: all books published after 
January 1st, 2015 as well as those books published in 2014 that have retail price of $50 or less. */
select Title, PubID, Retail, Pubdate
from BOOKS
where (Pubdate > date '2015-01-01')
    or (Pubdate >= date '2014-01-01' and Pubdate < date '2015-01-01' and Retail <= 50)  
order by PubID asc, Retail asc;
/* In case the question was using "publisher number" to refer to phone number instead of PubID: */
select Title, Phone, Retail, Pubdate
from BOOKS
inner join Publisher on BOOKS.PubID = PUBLISHER.PubID
where (Pubdate > date '2015-01-01')
    or (Pubdate >= date '2014-01-01' and Pubdate < date '2015-01-01' and Retail <= 50)  
order by Phone asc, Retail asc;

/* 5. List titles, cost, retail and profit margin for all books that have a profit margin under 55%. 
Make sure to assign a descriptive column name for the calculated field. PM=((retail–cost)/retail)*100 */
select 
    Title as "Title", 
    Cost as "Original Cost", 
    Retail as "Retail Sell Price",
    round(((Retail-Cost)/Retail)*100, 2) as "Profit Margin"
from BOOKS
where (((Retail-Cost)/Retail)*100) < 55
order by (((Retail-Cost)/Retail)*100) asc;


/* 6. List the title and publish date of any computer book published in 2005. 
Perform the task of searching for the publish date by using 3 different methods: */
/* a) a range operator, */
select Title, Pubdate
from BOOKS 
where lower(Category) = 'computer' 
    and Pubdate between date '2005-01-01' and date '2005-12-31';
/* b) a logical operator, */
select Title, Pubdate
from BOOKS 
where lower(Category) = 'computer' 
    and Pubdate >= date '2005-01-01' and Pubdate < date '2006-01-01';
/* c) a search pattern operation. */
select Title, Pubdate
from BOOKS 
where lower(Category) = 'computer' 
    and Pubdate like '%2005%';
/* Although the above version works, I was originally taught to convert the datatype from date to character like this: */
select Title, Pubdate
from BOOKS 
where lower(Category) = 'computer' 
    and to_char(Pubdate, 'YYYY') = '2005';
/* Or, if the like command is specifically expected for this question: */
select Title, Pubdate
from BOOKS 
where lower(Category) = 'computer' 
    and to_char(Pubdate, 'YYYY') like '2005';