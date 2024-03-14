/*
* The Product relation gives the manufacturer, model number and type (PC, laptop, or printer) of various products. 
* We assume for convenience that model numbers are unique over all manufacturers and product types; that assumption 
* is not realistic, and a real database would include a code for the manufacturer as part of the model number. The 
* PC relation gives for each model number that is a PC the speed (of the processor, in gigahertz), the amount of RAM 
* (in megabytes), the size of the hard disk (in gigabytes), and the price. The Laptop relation is similar, except that 
* the screen size (in inches) is also included. The Printer relation records for each printer model whether the printer 
* produces color output (true, if so), the process type (laser or ink-jet, typically), and the price.
*/


-- Table: lab.product
-- DROP TABLE IF EXISTS lab.product;
CREATE TABLE IF NOT EXISTS lab.product
(
    maker varchar(30),
    model integer NOT NULL,
    type varchar(30),
    CONSTRAINT product_pkey PRIMARY KEY (model)
)

TABLESPACE pg_default;


-- Table: lab.pc
-- DROP TABLE IF EXISTS lab.pc;
CREATE TABLE IF NOT EXISTS lab.pc
(
    model integer NOT NULL,
    speed real,
    ram smallint,
    hd smallint,
    --hd real, --smallint
    price real,
    CONSTRAINT pc_pkey PRIMARY KEY (model),
    CONSTRAINT pc_model_fkey FOREIGN KEY (model)
        REFERENCES lab.product (model) MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION
)

TABLESPACE pg_default;


-- Table: lab.laptop
-- DROP TABLE IF EXISTS lab.laptop;
CREATE TABLE IF NOT EXISTS lab.laptop
(
    model integer NOT NULL,
    speed real,
    ram smallint,
    hd smallint,
    --hd real,
    screen real,
    --screen smallint, --float
    price real,
    CONSTRAINT laptop_pkey PRIMARY KEY (model),
    CONSTRAINT laptop_model_fkey FOREIGN KEY (model)
        REFERENCES lab.product (model) MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION
)

TABLESPACE pg_default;


-- Table: lab.printer
-- DROP TABLE IF EXISTS lab.printer;
CREATE TABLE IF NOT EXISTS lab.printer
(
    model integer NOT NULL,
    color boolean,
    type varchar(10),
    price real,
    CONSTRAINT printer_pkey PRIMARY KEY (model),
    CONSTRAINT printer_model_fkey FOREIGN KEY (model)
        REFERENCES lab.product (model) MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION
)

TABLESPACE pg_default;


--INSERT INTO lab.product
--pc
INSERT INTO lab.product VALUES('Asus',1100,'pc');
INSERT INTO lab.product VALUES('MSI',1233,'pc');
INSERT INTO lab.product VALUES('Acer',1276,'pc');
INSERT INTO lab.product VALUES('Apple',1298,'pc');
INSERT INTO lab.product VALUES('HP',1401,'pc');
INSERT INTO lab.product VALUES('Dell',1408,'pc');
INSERT INTO lab.product VALUES('Asus',1752,'pc');
INSERT INTO lab.product VALUES('Dell',1121,'pc');
INSERT INTO lab.product VALUES('Apple',1321,'pc');
INSERT INTO lab.product VALUES('Asus',1288,'pc');
--laptop
INSERT INTO lab.product VALUES('Apple',1433,'laptop');
INSERT INTO lab.product VALUES('Dell',1260,'laptop');
INSERT INTO lab.product VALUES('Asus',1434,'laptop');
INSERT INTO lab.product VALUES('Lenovo',2112,'laptop');
INSERT INTO lab.product VALUES('Microsoft',2113,'laptop');
INSERT INTO lab.product VALUES('Microsoft',9999,'laptop');
INSERT INTO lab.product VALUES('Lenovo',9876,'laptop');
--printer
INSERT INTO lab.product VALUES('HP',3433,'printer');
INSERT INTO lab.product VALUES('Samsung',2974,'printer');
INSERT INTO lab.product VALUES('Oki',4837,'printer');
INSERT INTO lab.product VALUES('Epson',9374,'printer');
INSERT INTO lab.product VALUES('HP',8493,'printer');
INSERT INTO lab.product VALUES('Oki',6574,'printer');

--INSERT INTO pc
INSERT INTO lab.pc VALUES(1100,500,64,5,600.00);
INSERT INTO lab.pc VALUES(1233,500,32,10,350.00);
INSERT INTO lab.pc VALUES(1276,900,64,40,980.60);
INSERT INTO lab.pc VALUES(1298,800,64,20,970.40);
INSERT INTO lab.pc VALUES(1401,750,128,20,1050.70);
INSERT INTO lab.pc VALUES(1408,450,32,10,450.30);
INSERT INTO lab.pc VALUES(1752,500,32,10,480.60);
INSERT INTO lab.pc VALUES(1121,600,128,8,850.90);
INSERT INTO lab.pc VALUES(1321,600,128,14,880.00);
INSERT INTO lab.pc VALUES(1288,900,128,40,1090.90);

--INSERT INTO laptop
INSERT INTO lab.laptop VALUES(1433,350,32,4,13,700.95);
INSERT INTO lab.laptop VALUES(1260,500,64,8,13,970.70);
INSERT INTO lab.laptop VALUES(1434,750,64,12,15,1200.00);
INSERT INTO lab.laptop VALUES(2112,600,64,10,15,1050.80);
INSERT INTO lab.laptop VALUES(2113,750,32,10,17,1150.09);
INSERT INTO lab.laptop VALUES(9999,450,64,10,15,950.00);
INSERT INTO lab.laptop VALUES(9876,350,32,10,17,1200.90);

--INSERT INTO printer
INSERT INTO lab.printer VALUES(3433,TRUE,'LASER',400.90);
INSERT INTO lab.printer VALUES(2974,TRUE,'JET',270.60);
INSERT INTO lab.printer VALUES(4837,FALSE,'JET',290.50);
INSERT INTO lab.printer VALUES(9374,FALSE,'MATRIX',150.00);
INSERT INTO lab.printer VALUES(8493,FALSE,'MATRIX',270.80);
INSERT INTO lab.printer VALUES(6574,TRUE,'LASER',400.90);


/*
DROP TABLE IF EXISTS lab.printer;
DROP TABLE IF EXISTS lab.laptop;
DROP TABLE IF EXISTS lab.pc;
DROP TABLE IF EXISTS lab.product;
*/



