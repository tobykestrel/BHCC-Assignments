alter table BIDDERS
add constraint UK_BIDDERS unique (BidderId),
add constraint PK_BIDDERS primary key (BidderId),
add constraint FK_BIDDERS_PARTIES foreign key (InPartyOf) references BIDDERS(BidderId);

alter table TICKETS
add constraint FK_TICKETS_BIDDERS foreign key (BidderId) references BIDDERS(BidderId);

alter table BIDS
add constraint FK_BIDS_ITEMS foreign key (ItemId) references ITEMS(ItemId),
add constraint FK_BIDS_BIDDERS foreign key (BidderId) references BIDDERS(BidderId);