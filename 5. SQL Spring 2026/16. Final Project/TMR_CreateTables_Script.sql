/*
Toby Hansen
April 24, 2026
SQL Programming Final Project
TMR Create Tables Script
*/

drop table if exists RENTALMOVIES cascade constraints;  
drop table if exists RENTALS cascade constraints; 
drop table if exists CUSTOMERS cascade constraints; 
drop table if exists MOVIESDIRECTORS cascade constraints; 
drop table if exists DIRECTORS cascade constraints; 
drop table if exists MOVIES cascade constraints; 

create table MOVIES (
    ImdbId varchar2(12) not null,
    MovieTitle varchar2(128) not null,
    ReleaseDate date,
    Genre varchar2(32),
    AgeRating varchar2(16),
    LengthInMinutes number(4),
    RentalCost number(4,2) not null,
    PurchaseCost number(4,2) not null,
    constraint MOVIES_ImdbId_PK
        primary key (ImdbId),
    constraint MOVIES_LengthInMinutes_CK
        check (LengthInMinutes >= 0),
    constraint MOVIES_RentalCost_CK
        check (RentalCost >= 0),
    constraint MOVIES_PurchaseCost_CK
        check (PurchaseCost >= 0)
);

create table DIRECTORS (
    DirectorId number(8) not null,
    FirstName varchar2(32) not null,
    LastName varchar2(32) not null,
    constraint DIRECTORS_DirectorId_PK
        primary key (DirectorId)
);

create table MOVIESDIRECTORS (
    ImdbId varchar2(12) not null,
    DirectorId number(8) not null,
    constraint MOVIESDIRECTORS_PK
        primary key (ImdbId, DirectorId),
    constraint MOVIESDIRECTORS_ImdbId_FK
        foreign key (ImdbId)
        references MOVIES(ImdbId),
    constraint MOVIESDIRECTORS_DirectorId_FK
        foreign key (DirectorId)
        references DIRECTORS(DirectorId)
);

create table CUSTOMERS (
    CustomerId  number(8) not null,
    FirstName varchar2(32) not null,
    LastName varchar2(32) not null,
    Email varchar2(128) not null,
    DateOfBirth date not null, 
    constraint CUSTOMERS_CustomerId_PK 
        primary key (CustomerId),
    constraint CUSTOMERS_Email_UK 
        unique (Email)
);

create table RENTALS (
    RentalId number(8) not null,
    CustomerId number(8) not null,
    RentalDate date not null,
    ReturnDate date,
    constraint RENTALS_RentalId_PK 
        primary key (RentalId),
    constraint RENTALS_CustomerId_FK 
        foreign key (CustomerId) 
        references CUSTOMERS(CustomerId)
);

create table RENTALMOVIES (
    RentalId number(8) not null,
    ImdbId varchar2(12) not null,
    Quantity number(3) default 1 not null,
    constraint RENTALMOVIES_PK 
        primary key (RentalId, ImdbId),
    constraint RENTALMOVIES_RentalId_FK
        foreign key (RentalId)
        references RENTALS(RentalId),
    constraint RENTALMOVIES_ImdbId_FK
        foreign key (ImdbId)
        references MOVIES(ImdbId),
    constraint RENTALMOVIES_Quantity_CK
        check (Quantity > 0)
);
