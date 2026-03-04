/*
Toby Hansen
March 3, 2026
SQL Programming
Chapter Ten Textbook Assignment
*/

/*Q1*/
select
    initcap(Title) as "Title",
    Name as "Publisher",
    Contact as "Contact Name",
    trunc(months_between(current_date, Pubdate)) as "Book Age In Months"
from BOOKS 
inner join PUBLISHER using (PubID);

/*Q2*/
select 
    Isbn as "ISBN",
    initcap(Title) as "Title",
    Fname || ' ' || Lname as "Author",
    Retail as "Current Retail Price",
    round(Retail*.85, 2) as " Retail w/ 15% Discount"
from BOOKS 
inner join BOOKAUTHOR using (Isbn)
inner join AUTHOR using (AuthorID);

/*Q3 v1*/
select
    Order# as "Order#",
    initcap(Title) as "Titles",
    '$' || Quantity*(Paideach-Cost) as "Profit"
from ORDERS
inner join ORDERITEMS using (Order#)
inner join BOOKS using (Isbn)
where Order# = 1014;

/*Q3 v2, incase the individual items are expected to be aggregated*/
select
    listagg(initcap(Title), ', ')
        within group (order by Title) 
        as "Title(s) in Order 1014",
    '$' || sum(Quantity*(Paideach-Cost)) as "Profit"
from ORDERS
inner join ORDERITEMS using (Order#)
inner join BOOKS using (Isbn)
where Order# = 1014;

/*Q3 v3, with dynamic variables to check any Order#*/
select
    listagg(initcap(Title), ', ')
        within group (order by Title) 
        as "Title(s) in Order :order#",
    '$' || sum(Quantity*(Paideach-Cost)) as "Profit"
from ORDERS
inner join ORDERITEMS using (Order#)
inner join BOOKS using (Isbn)
where Order# = :order#;

/*Q4*/
select 
    to_char(current_timestamp at time zone 'America/New_York', 'YYYY-MON-DD') as "Current Date",
    to_char(current_timestamp at time zone 'America/New_York', 'DAY') as "Day Of The Week",
    to_char(current_timestamp at time zone 'America/New_York', 'HH24') as "Hours",
    to_char(current_timestamp at time zone 'America/New_York', 'MI') as "Minutes",
    to_char(current_timestamp at time zone 'America/New_York', 'SS') as "Seconds"
from DUAL;

/*Q5*/
select
    initcap(Title) as "Title",
    Isbn as "Full ISBN",
    substr(Isbn, 8, 1) as "8th Digit Of The ISBN",
    substr(Isbn, 9, 1) as "9th Digit Of The ISBN",
    instr(Isbn, '0', 1, 3) as "Position Of 3rd 0 In ISBN"
from BOOKS;

/*Q6*/
select distinct
    Name as "Publisher Name",
    length(Name) as "Name Length"
from PUBLISHER;

/*Q6 v2, incase the question was asking for distinct name lengths*/
select distinct
    length(Name) as "Name Length"
from PUBLISHER;

/*Q7*/
select 
    next_day(current_timestamp, 'THURSDAY') as "Date of next Thursday"
from DUAL;

/*Q8 NOTE: The intended effect does not work in APEX 
because the query results aren't in a monospace font*/
select
    Firstname || ' ' || Lastname as "Customer Name",
    lpad(' ' || Address, 25, '+ ') as "Street Address"
from CUSTOMERs;
