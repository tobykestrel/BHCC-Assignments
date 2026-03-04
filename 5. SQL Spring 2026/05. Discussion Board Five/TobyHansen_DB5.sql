/*
Toby Hansen
March 3, 2026
SQL Programming
Discussion Board Five

We want to create a query that will let us see a new price list for the books 
written by the same author. We do not want to "key in" the entire name, just 
the first 4 letters of the last name and the first 2 letters of the first name. 
We want to calculate the new discounted price based on the current retail price 
minus 7%. For testing, discount the price of James Patterson books.
*/


/*v1*/
select 
    Fname || ' ' || Lname as "Author",
    Title as "Title",
    round(Retail*0.93, 2) as "New Price",
    Retail as "Old Price"
from BOOKS 
inner join BOOKAUTHOR using (Isbn)
inner join AUTHOR using (AuthorID)
where lower(Fname) like 'ja%'
    and lower(Lname) like 'patt%';

/*v2*/
select 
    Fname || ' ' || Lname as "Author",
    Title as "Title",
    round(Retail*0.93, 2) as "New Price",
    Retail as "Old Price"
from BOOKS 
inner join BOOKAUTHOR using (Isbn)
inner join AUTHOR using (AuthorID)
where lower(substr(Fname,1,2)) = 'ja'
    and lower(substr(Lname,1,4)) = 'patt';

/*v3*/
select 
    Fname || ' ' || Lname as "Author",
    Title as "Title",
    round(Retail*0.93, 2) as "New Price",
    Retail as "Old Price"
from BOOKS 
inner join BOOKAUTHOR using (Isbn)
inner join AUTHOR using (AuthorID)
where lower(substr(Fname,1,2)) = :firstName
    and lower(substr(Lname,1,4)) = :lastName;