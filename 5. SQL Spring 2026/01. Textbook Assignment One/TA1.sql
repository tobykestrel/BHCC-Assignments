/*
Toby Hansen
January 31, 2026
SQL Programming
Chapter One Textbook Assignment
*/

/*1*/
select Shipcost from ORDERS where Order# = 67;
select ISBN from ORDERITEMS where Order# = 67;

/*2*/
select * from BOOKS where Discount is null;

/*3*/
select count(*)
from ORDERS
inner join ORDERITEMS on ORDERS.Order# = ORDERITEMS.Order#
inner join BOOKS on ORDERITEMS.ISBN = BOOKS.ISBN
where Category = ‘computer’ and Shipdate >= '2009-03-01' and Shipdate < '2009-04-01';

/*4*/
select sum((Paideach-Cost)*Quantity)
from ORDERS
inner join ORDERITEMS on ORDERS.Order# = ORDERITEMS.Order#
inner join BOOKS on ORDERITEMS.ISBN = BOOKS.ISBN
where Shipdate >= '2009-10-01' and Shipdate < '2010-01-01';

/*5*/
select *
from BOOKS
inner join BOOKAUTHOR on BOOKS.ISBN = BOOKAUTHOR.ISBN
inner join AUTHOR on BOOKAUTHOR.ISBN = AUTHOR.ISBN
where Lname = ‘Robinson’ and Pubdate >= '2005-01-01' and Pubdate < '2006-01-01';