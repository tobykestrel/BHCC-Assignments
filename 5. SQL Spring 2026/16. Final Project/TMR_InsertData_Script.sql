/*
Toby Hansen
April 24, 2026
SQL Programming Final Project
TMR Insert Data Script
*/

insert into MOVIES values ('tt0816692', 'Interstellar', to_date('2014-10-26','YYYY-MM-DD'),'Science Fiction', 'PG-13', 169, 1.99, 9.99);
insert into MOVIES values ('tt12042730', 'Project Hail Mary', to_date('2026-03-20','YYYY-MM-DD'), 'Science Fiction', 'PG-13', 156, 2.99, 10.99);
insert into MOVIES values ('tt1375666', 'Inception', to_date('2010-07-16','YYYY-MM-DD'), 'Science Fiction', 'PG-13', 148, 1.99, 9.99);
insert into MOVIES values ('tt15398776', 'Oppenheimer', to_date('2023-07-21','YYYY-MM-DD'), 'Biographical Drama', 'PG-13', 180, 2.99, 10.99);
insert into MOVIES values ('tt1517268', 'Barbie', to_date('2023-07-21','YYYY-MM-DD'), 'Comedy', 'PG-13', 104, 2.99, 10.99);
insert into MOVIES values ('tt1232829', '21 Jump Street', to_date('2012-03-16','YYYY-MM-DD'), 'Comedy', 'R', 109, 1.99, 8.99);
insert into MOVIES values ('tt0068646', 'The Godfather', to_date('1972-03-24','YYYY-MM-DD'), 'Drama', 'R', 177, 0.99, 11.99);

insert into DIRECTORS values (1, 'Christopher', 'Nolan');
insert into DIRECTORS values (2, 'Christopher', 'Miller');
insert into DIRECTORS values (3, 'Phil', 'Lord');
insert into DIRECTORS values (4, 'Greta', 'Gerwig');
insert into DIRECTORS values (5, 'Francis', 'Coppola');

insert into MOVIESDIRECTORS values ('tt0816692', 1);
insert into MOVIESDIRECTORS values ('tt12042730', 2);
insert into MOVIESDIRECTORS values ('tt12042730', 3);
insert into MOVIESDIRECTORS values ('tt1375666', 1);
insert into MOVIESDIRECTORS values ('tt15398776', 1);
insert into MOVIESDIRECTORS values ('tt1517268', 4);
insert into MOVIESDIRECTORS values ('tt1232829', 2);
insert into MOVIESDIRECTORS values ('tt1232829', 3);
insert into MOVIESDIRECTORS values ('tt0068646', 5);

insert into CUSTOMERS values (1, 'Alice', 'Aurora', 'alicea@gmail.com', to_date('2000-10-25','YYYY-MM-DD'));
insert into CUSTOMERS values (2, 'Billy', 'Boeman', 'bboeman@gmail.com', to_date('2001-05-15','YYYY-MM-DD'));
insert into CUSTOMERS values (3, 'Charlie', 'Charm', 'charcharm@gmail.com', to_date('2008-01-02','YYYY-MM-DD'));
insert into CUSTOMERS values (4, 'David', 'Doherty', 'dohertydavid@gmail.com', to_date('2007-12-14','YYYY-MM-DD'));
insert into CUSTOMERS values (5, 'Evan', 'Earls', 'evanearls@gmail.com', to_date('2012-03-26','YYYY-MM-DD'));

insert into RENTALS values (1, 1, to_date('2026-01-25','YYYY-MM-DD'), to_date('2026-02-06','YYYY-MM-DD'), 21.98);
insert into RENTALS values (2, 3, to_date('2026-01-27','YYYY-MM-DD'), to_date('2026-02-07','YYYY-MM-DD'), 21.98);
insert into RENTALS values (3, 4, to_date('2026-01-28','YYYY-MM-DD'), to_date('2026-04-02','YYYY-MM-DD'), 0);
insert into RENTALS values (4, 2, to_date('2026-02-01','YYYY-MM-DD'), to_date('2026-02-10','YYYY-MM-DD'), 31.97);
insert into RENTALS values (5, 5, to_date('2026-02-06','YYYY-MM-DD'), to_date('2026-02-19','YYYY-MM-DD'), 21.98);
insert into RENTALS values (6, 3, to_date('2026-02-07','YYYY-MM-DD'), to_date('2026-02-20','YYYY-MM-DD'), 9.99);
insert into RENTALS values (7, 2, to_date('2026-03-29','YYYY-MM-DD'), to_date('2026-04-10','YYYY-MM-DD'), 10.99);
insert into RENTALS values (8, 5, to_date('2026-04-21','YYYY-MM-DD'), null, null);

insert into RENTALMOVIES values (1, 'tt0816692', 1);
insert into RENTALMOVIES values (1, 'tt0068646', 1);
insert into RENTALMOVIES values (2, 'tt15398776', 1);
insert into RENTALMOVIES values (2, 'tt1517268', 1);
insert into RENTALMOVIES values (3, 'tt1232829', 2);
insert into RENTALMOVIES values (4, 'tt0816692', 1);
insert into RENTALMOVIES values (4, 'tt1517268', 1);
insert into RENTALMOVIES values (4, 'tt15398776', 1);
insert into RENTALMOVIES values (5, 'tt1517268', 1);
insert into RENTALMOVIES values (5, 'tt15398776', 1);
insert into RENTALMOVIES values (6, 'tt0816692', 1);
insert into RENTALMOVIES values (7, 'tt12042730', 1);
insert into RENTALMOVIES values (8, 'tt12042730', 1);