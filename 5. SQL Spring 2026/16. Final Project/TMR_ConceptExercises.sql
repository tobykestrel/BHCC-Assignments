/*
Toby Hansen
April 25, 2026
SQL Programming Final Project
TMR Concept Exercises 
*/

/*Q1 TMR wants to display a list of the five newest released 
movies to print posters of and hang outside their shop. 
Include the title and release date columns in the result.*/
select 
    MovieTitle,
    ReleaseDate
from MOVIES
order by ReleaseDate desc
fetch next 5 rows only;

/*Q2 A customer named Charlie Charm wants to know the history 
of what movies they have rented. Include the rental date, 
movie title and quantity of each movie they have rented.*/
select 
    RentalDate,
    MovieTitle,
    Quantity
from CUSTOMERS
join RENTALS using (CustomerId)
join RENTALMOVIES using (RentalId)
join MOVIES using (ImdbId)
where upper(FirstName) = 'CHARLIE'
    and upper(LastName) = 'CHARM'
order by RentalDate;

/*Q3 TMR wants to send an email to all of their customers who have 
rented something out within the past month, thanking them for their 
continued patronage. The first column should be their full name, 
and the second should be their email in all caps for visibility.*/
select distinct
    concat(concat(FirstName, ' '), LastName) 
        as "Customers Who Have Rented In The Past Month",
    upper(Email) as "Customer Email Address"
from CUSTOMERS join RENTALS using (CustomerId)
where months_between(sysdate, RentalDate) <= 1;

/*Q4 Generate a list of every movie title (with release year in parenthesis) in one 
column, with the director(s) of each movie aggregately listed in a second column.*/
select 
    MovieTitle || ' (' || to_char(ReleaseDate,'YYYY') || ')' as "Movie Titles",
    listagg(FirstName || ' ' || LastName, ', ') 
        within group (order by FirstName) as "Directors"
from MOVIES 
join MOVIESDIRECTORS using (ImdbId) 
join DIRECTORS using (DirectorId)
group by MovieTitle, ReleaseDate
order by "Movie Titles", "Directors";

/*Q5 In a single query result set, display the most and the least rented-out movie(s) side 
by side, with their number of rent-outs shown. Aggregate results if there are any ties.*/
select
    (
        select 
            listagg(MovieTitle || ' (' || to_char(ReleaseDate,'YYYY') || ')' || ' {x'
            || sum(nvl(Quantity, 0)) || '}', ', ') within group (order by MovieTitle)
        from MOVIES left join RENTALMOVIES using (ImdbId)
        group by ImdbId, MovieTitle, ReleaseDate
        having sum(nvl(Quantity, 0)) = (
            select max(sum(nvl(Quantity, 0)))
            from MOVIES left join RENTALMOVIES using (ImdbId)
            group by ImdbId)
    ) as "Most Rented-Out Movie(s)",
    (
        select 
            listagg(MovieTitle || ' (' || to_char(ReleaseDate,'YYYY') || ')' || ' {x' 
            || sum(nvl(Quantity, 0)) || '}', ', ') within group (order by MovieTitle)
        from MOVIES left join RENTALMOVIES using (ImdbId)
        group by ImdbId, MovieTitle, ReleaseDate
        having sum(nvl(Quantity, 0)) = (
            select min(sum(nvl(Quantity, 0)))
            from MOVIES left join RENTALMOVIES using (ImdbId)
            group by ImdbId)
    ) as "Least Rented-Out Movie(s)"
from DUAL;
