CREATE TABLE `account_admins` (
  `id` int NOT NULL AUTO_INCREMENT,
  `account_guid` varchar(36) DEFAULT NULL,
  `username` varchar(50) DEFAULT NULL,
  `age` varchar(50) DEFAULT NULL,
  `gender` varchar(50) DEFAULT NULL,
  `permissions` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`)
);

CREATE TABLE `account_authentication` (
  `id` int NOT NULL AUTO_INCREMENT,
  `account_guid` varchar(36) DEFAULT NULL,
  `account_login` varchar(50) DEFAULT NULL,
  `account_password` varchar(50) DEFAULT NULL,
  `account_type` varchar(50) DEFAULT NULL,
  `account_state` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`)
);

CREATE TABLE `account_clients` (
  `id` int NOT NULL AUTO_INCREMENT,
  `account_guid` varchar(36) DEFAULT NULL,
  `username` varchar(50) DEFAULT NULL,
  `age` varchar(50) DEFAULT NULL,
  `gender` varchar(50) DEFAULT NULL,
  `bank_card` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`)
);

CREATE TABLE `account_drivers` (
  `id` int NOT NULL AUTO_INCREMENT,
  `account_guid` varchar(36) DEFAULT NULL,
  `username` varchar(50) DEFAULT NULL,
  `age` varchar(50) DEFAULT NULL,
  `gender` varchar(50) DEFAULT NULL,
  `driver_licence` varchar(36) DEFAULT NULL,
  `bank_card` varchar(36) DEFAULT NULL,
  PRIMARY KEY (`id`)
);

CREATE TABLE `bank_accounts` (
  `id` int NOT NULL AUTO_INCREMENT,
  `account_guid` varchar(36) DEFAULT NULL,
  `account_money` varchar(50) DEFAULT NULL,
  `account_marker` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`)
);

CREATE TABLE `car_garage` (
  `id` int NOT NULL AUTO_INCREMENT,
  `group_guid` varchar(36) DEFAULT NULL,
  `car_type` varchar(50) DEFAULT NULL,
  `car_class` varchar(50) DEFAULT NULL,
  `car_speed` varchar(50) DEFAULT NULL,
  `car_color` varchar(50) DEFAULT NULL,
  `car_count` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`)
);

CREATE TABLE `drive_complex` (
  `id` int NOT NULL AUTO_INCREMENT,
  `driver_guid` varchar(36) DEFAULT NULL,
  `car_type` varchar(50) DEFAULT NULL,
  `car_class` varchar(50) DEFAULT NULL,
  `driver_status` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`)
);

CREATE TABLE `order_collection` (
  `id` int NOT NULL AUTO_INCREMENT,
  `client_guid` varchar(36) DEFAULT NULL,
  `driver_guid` varchar(36) DEFAULT NULL,
  `car_type` varchar(50) DEFAULT NULL,
  `car_class` varchar(50) DEFAULT NULL,
  `address` varchar(50) DEFAULT NULL,
  `date_time` varchar(50) DEFAULT NULL,
  `order_status` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`)
);