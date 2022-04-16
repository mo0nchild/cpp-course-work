create table account_clients(
    id int primary key auto_increment,	
    account_guid varchar(36),
    username varchar(50),
    age varchar(50),
    gender varchar(50),
    bank_card varchar(50)
);

create table account_drivers(
    id int primary key auto_increment,	
    account_guid varchar(36),
    username varchar(50),
    age varchar(50),
    gender varchar(50),
    driver_licence varchar(36),
    driver_experience varchar(50)
);

create table account_admins(
    id int primary key auto_increment,	
    account_guid varchar(36),
    username varchar(50),
    age varchar(50),
    gender varchar(50),
    permissions varchar(50)
);