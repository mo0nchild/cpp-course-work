use test;
-- create table drive_complex(
-- 	id int primary key auto_increment,
--     driver_guid varchar(36),
--     car_type varchar(50),
--     car_class varchar(50),
--     driver_status varchar(50)
-- );

-- create table car_garage(
-- 	id int primary key auto_increment,	
--     group_guid varchar(36),
--     car_type varchar(50),
--     car_class varchar(50),
--     car_speed varchar(50),
--     car_color varchar(50),
--     car_count varchar(50)
-- );

-- create table account_authentication(
-- 	id int primary key auto_increment,	
--     	account_guid varchar(36),
--     	account_login varchar(50),
-- 		account_password varchar(50),
--         account_type varchar(50),
--         account_state varchar(50)
-- );

-- create table account_clients(
-- 	id int primary key auto_increment,	
--     account_guid varchar(36),
--     username varchar(50),
--     age varchar(50),
--     gender varchar(50),
--     bank_card varchar(50),
--     order_count varchar(50)
-- );

-- create table account_drivers(
-- 	id int primary key auto_increment,	
--     account_guid varchar(36),
--     username varchar(50),
--     age varchar(50),
--     gender varchar(50),
--     driver_licence varchar(36),
--     bank_card varchar(36)
-- );

-- create table account_admins(
-- 	id int primary key auto_increment,	
--     account_guid varchar(36),
--     username varchar(50),
--     age varchar(50),
--     gender varchar(50),
--     permissions varchar(50)
-- );

-- create table order_collection(
-- 	id int primary key auto_increment,	
--     client_guid varchar(36),
--     driver_guid varchar(36),
--     car_type varchar(50),
--     car_class varchar(50),
--     address varchar(50),
--     date_time varchar(50),
--     order_status varchar(50)
-- );

-- insert into car_garage(
-- 	group_guid,
-- 	car_type,
-- 	car_class,
-- 	car_speed,
-- 	car_color,
-- 	car_count
-- )
-- values (
-- 	"af228218-633f-489d-a48f-fad8f32f0b75", 
-- 	"CarTypeEconom", 
-- 	"CarLightModel", 
-- 	"10", 
-- 	"CarColorBlack",
-- 	"3"
-- );

create table bank_accounts(
	id int primary key auto_increment,
    account_guid varchar(36),
    account_money varchar(50)
);

-- select * from account_authentication;
-- select * from account_admins;
-- select * from account_clients;
-- select * from account_drivers;

-- select * from order_collection;

select * from car_garage;
select * from drive_complex;