create table hostel(
hostel_id varchar(50)primary key,
hostel_name varchar(50),
phone_no varchar(10),
address varchar(100),
district varchar(30));


create table room(
roomNo varchar(50),
hostel_id varchar(20),
activate varchar(50),
roomStatus varchar(50),
primary key(roomNo,hostel_id),
foreign key(hostel_id)references hostel(hostel_id)on delete cascade);

create table student(
student_id varchar(50)primary key,
student_name varchar(50),
father varchar(50),
mobile_no varchar(10),
address varchar(50),
college varchar(50),
hostel_id varchar(50),
roomNo varchar(50),
status1 varchar(50),
foreign key(roomNo)references room(roomNo)on delete cascade,
foreign key(hostel_id)references hostel(hostel_id)on delete cascade,constraint HR unique(hostel_id,roomNo));

create table fees(
student_id varchar(50),
month1 varchar(50),
year1 varchar(20),
amount varchar(50),
primary key(student_id,month1,year1),
foreign key(student_id)references student(student_id)on delete cascade);

create table employee(
employee_id varchar(50)primary key,
employee_name varchar(50),
mobile_no varchar(10),
email varchar(50), 
address varchar(50),
hostel_id varchar(50),
designation varchar(50),
status1 varchar(50),
foreign key(hostel_id)references hostel(hostel_id)on delete cascade);

create table payment(
employee_id varchar(50),
month1 varchar(50),
year1 varchar(20),
amount varchar(50),
primary key(employee_id,month1,year1),
foreign key(employee_id)references employee(employee_id)on delete cascade);
