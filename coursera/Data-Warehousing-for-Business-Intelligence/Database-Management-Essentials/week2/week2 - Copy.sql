CREATE TABLE Employee (
  empNo      CHAR(11)     NOT NULL,
  empName    VARCHAR(30)  NOT NULL,
  department VARCHAR(30)  NOT NULL,
  email      VARCHAR(255) NOT NULL,
  phone      VARCHAR(30)  NOT NULL,
  CONSTRAINT EmployeePK PRIMARY KEY (empNo)
);
INSERT INTO Employee (empNo, empName, department, email, phone) VALUES ('E100','Chuck Coordinator','Administration','chuck@colorado.edu','3-1111');

INSERT INTO Employee (empNo, empName, department, email, phone) VALUES ('E101','Mary Manager','Football','mary@colorado.edu','5-1111');

INSERT INTO Employee (empNo, empName, department, email, phone) VALUES ('E102','Sally Supervisor','Planning','sally@colorado.edu','3-2222');

INSERT INTO Employee (empNo, empName, department, email, phone) VALUES ('E103','Alan Administrator','Administration','alan@colorado.edu','3-3333');

SET FOREIGN_KEY_CHECKS = 0;
DROP TABLE EventPlan;
SET FOREIGN_KEY_CHECKS = 1;

CREATE TABLE EventPlan (
  planNo   CHAR(8)  NOT NULL,
  evntNo   CHAR(8)  NOT NULL,
  empNo    CHAR(8),
  workDate DATE     NOT NULL,
  notes    TEXT,
  activity CHAR(10) NOT NULL,
  CONSTRAINT PK_EventPlan PRIMARY KEY (planNo),
  CONSTRAINT FK_EventRequest FOREIGN KEY (evntNo) REFERENCES EventRequest (evntNo),
  CONSTRAINT FK_Employee FOREIGN KEY (empNo) REFERENCES Employee (empNo)
);

INSERT INTO EventPlan (planNo, evntNo, empNo, workDate, notes, activity)
VALUES ('P100', 'E100', 'E102', '2013-10-25', 'Standard operation', 'Operation');
#
INSERT INTO EventPlan (planNo, evntNo, empNo, workDate, notes, activity)
VALUES ('P101', 'E104', 'E100', '2013-12-03', 'Watch for gate crashers', 'Operation');
#
INSERT INTO EventPlan (planNo, evntNo, empNo, workDate, notes, activity)
VALUES ('P102', 'E105', 'E102', '2013-12-05', 'Standard operation', 'Operation');
#
INSERT INTO EventPlan (planNo, evntNo, empNo, workDate, notes, activity)
VALUES ('P103', 'E106', NULL, '2013-12-12', 'Watch for seat switching', 'Operation');
#
INSERT INTO EventPlan (planNo, evntNo, empNo, workDate, notes, activity)
VALUES ('P104', 'E101', 'E101', '2013-10-26', 'Standard cleanup', 'Cleanup');
#
INSERT INTO EventPlan (planNo, evntNo, empNo, workDate, notes, activity)
VALUES ('P105', 'E100', 'E101', '2013-10-25', 'Light cleanup', 'Cleanup');
#
INSERT INTO EventPlan (planNo, evntNo, empNo, workDate, notes, activity)
VALUES ('P199', 'E102', 'E101', '2013-12-10', 'Standard operation', 'Operation');
#
INSERT INTO EventPlan (planNo, evntNo, empNo, workDate, notes, activity)
VALUES ('P299', 'E101', 'E101', '2013-10-26', '', 'Operation');
#
INSERT INTO EventPlan (planNo, evntNo, empNo, workDate, notes, activity)
VALUES ('P349', 'E106', 'E101', '2013-12-12', '', 'Cleanup');
#
INSERT INTO EventPlan (planNo, evntNo, empNo, workDate, notes, activity)
VALUES ('P85', 'E100', 'E102', '2013-10-25', 'Standard operation', 'Setup');
#
INSERT INTO EventPlan (planNo, evntNo, empNo, workDate, notes, activity)
VALUES ('P95', 'E101', 'E102', '2013-10-26', 'Extra security', 'Setup');

SET FOREIGN_KEY_CHECKS = 0;
DROP TABLE EventPlanLine;
SET FOREIGN_KEY_CHECKS = 1;

CREATE TABLE EventPlanLine (
  planNo    CHAR(8)   NOT NULL,
  lineNo    CHAR(8)   NOT NULL,
  locNo     CHAR(8)   NOT NULL,
  resNo     CHAR(8)   NOT NULL,
  timeStart TIMESTAMP NOT NULL,
  timeEnd   TIMESTAMP NOT NULL,
  numberFLD INTEGER   NOT NULL,
  CONSTRAINT PK_EventPlanLine PRIMARY KEY (planNo, lineNo),
  CONSTRAINT FK_EventPlan FOREIGN KEY (planNo) REFERENCES EventPlan (planNo),
  CONSTRAINT FK_Location FOREIGN KEY (locNo) REFERENCES Location (locNo),
  CONSTRAINT FK_ResourceTbl FOREIGN KEY (resNo) REFERENCES ResourceTbl (resNo)
);
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P100', '1','L100','R100','2013-10-25 8:00','2013-10-25 17:00','2');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P100', '2','L101','R101','2013-10-25 12:00','2013-10-25 17:00','2');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P100', '3','L102','R102','2013-10-25 7:00','2013-10-25 16:30','1');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P100', '4','L100','R102','2013-10-25 18:00','2013-12-12 22:00','1');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P101', '1','L103','R100','2013-12-03 18:00','2013-12-03 20:00','2');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P101', '2','L105','R100','2013-12-03 18:30','2013-12-03 19:00','2');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P101', '3','L103','R103','2013-12-03 19:00','2013-12-03 20:00','4');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P102', '1','L103','R100','2013-12-05 18:00','2013-12-05 19:00','2');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P102', '2','L105','R100','2013-12-05 18:00','2013-12-05 21:00','2');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P102', '3','L103','R103','2013-12-05 19:00','2013-12-05 22:00','4');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P103', '1','L103','R100','2013-12-12 18:00','2013-12-12 21:00','2');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P103', '2','L105','R100','2013-12-12 18:00','2013-12-12 21:00','4');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P103', '3','L103','R103','2013-12-12 19:00','2013-12-12 22:00','2');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P104', '1','L101','R104','2013-10-26 18:00','2013-10-26 22:00','4');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P104', '2','L100','R104','2013-10-26 18:00','2013-10-26 22:00','4');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P105', '1','L101','R104','2013-10-25 18:00','2013-10-25 22:00','4');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P105', '2','L100','R104','2013-10-25 18:00','2013-10-25 22:00','4');
# #
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P199', '1','L100','R100','2013-12-10 8:00','2013-12-10 12:00','1');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P349', '1','L103','R100','2013-12-12 12:00','2013-12-12 15:30','1');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P85', '1','L100','R100','2013-10-25 9:00','2013-10-25 17:00','5');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P85', '2','L102','R101','2013-10-25 8:00','2013-10-25 17:00','2');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P85', '3','L104','R100','2013-10-25 10:00','2013-10-25 17:00','3');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P95', '1','L100','R100','2013-10-26 8:00','2013-10-26 17:00','4');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P95', '2','L102','R101','2013-10-26 9:00','2013-10-26 17:00','4');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P95', '3','L106','R100','2013-10-26 10:00','2013-10-26 15:00','4');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P95', '4','L100','R103','2013-10-26 13:00','2013-10-26 17:00','2');
#
INSERT INTO EventPlanLine(planNo, lineNo, locNo, resNo, timeStart, timeEnd, numberFLD) VALUES ('P95', '5','L101','R104','2013-10-26 13:00','2013-10-26 17:00','2');

SET FOREIGN_KEY_CHECKS = 0;
DROP TABLE EventRequest;
SET FOREIGN_KEY_CHECKS = 1;

CREATE TABLE EventRequest (
  evntNo      CHAR(8)       NOT NULL,
  custNo      CHAR(8)       NOT NULL,
  facNo       CHAR(8)       NOT NULL,
  dateHeld    DATE          NOT NULL,
  dateReq     DATE          NOT NULL,
  dateAuth    DATE,
  status      CHAR(20)      NOT NULL,
  estCost     DECIMAL(8, 2) NOT NULL,
  estAudience INTEGER       NOT NULL,
  budNo       CHAR(30),
  CONSTRAINT EventRequestPK PRIMARY KEY (evntNo),
  CONSTRAINT FK_Facility FOREIGN KEY (facNo) REFERENCES Facility (facNo),
  CONSTRAINT FK_Customer FOREIGN KEY (custNo) REFERENCES Customer (custNo)

);
INSERT INTO EventRequest (evntNo, custNo, facNo, dateHeld, dateReq, dateAuth, status, estCost, estAudience, budNo)
VALUES ('E100', 'C100', 'F100', '2013-10-25', '2013-06-06', '2013-06-08', 'Approved', '5000.00', '80000', 'B1000');
#
INSERT INTO EventRequest (evntNo, custNo, facNo, dateHeld, dateReq, dateAuth, status, estCost, estAudience, budNo)
VALUES ('E101', 'C100', 'F100', '2013-10-26', '2013-07-28', NULL, 'Pending', '5000.00', '80000', 'B1000');
#
INSERT INTO EventRequest (evntNo, custNo, facNo, dateHeld, dateReq, dateAuth, status, estCost, estAudience, budNo)
VALUES ('E102', 'C100', 'F100', '2013-09-14', '2013-07-28', '2013-07-31', 'Approved', '5000.00', '80000', 'B1000');
#
INSERT INTO EventRequest (evntNo, custNo, facNo, dateHeld, dateReq, dateAuth, status, estCost, estAudience, budNo)
VALUES ('E103', 'C100', 'F100', '2013-09-21', '2013-07-28', '2013-08-01', 'Approved', '5000.00', '80000', 'B1000');
#
INSERT INTO EventRequest (evntNo, custNo, facNo, dateHeld, dateReq, dateAuth, status, estCost, estAudience, budNo)
VALUES ('E104', 'C101', 'F101', '2013-12-03', '2013-07-28', '2013-07-31', 'Approved', '2000.00', '12000', 'B1000');
#
INSERT INTO EventRequest (evntNo, custNo, facNo, dateHeld, dateReq, dateAuth, status, estCost, estAudience, budNo)
VALUES ('E105', 'C101', 'F101', '2013-12-05', '2013-07-28', '2013-08-01', 'Approved', '2000.00', '10000', 'B1000');
#
INSERT INTO EventRequest (evntNo, custNo, facNo, dateHeld, dateReq, dateAuth, status, estCost, estAudience, budNo)
VALUES ('E106', 'C101', 'F101', '2013-12-12', '2013-07-28', '2013-07-31', 'Approved', '2000.00', '10000', 'B1000');
#
INSERT INTO EventRequest (evntNo, custNo, facNo, dateHeld, dateReq, dateAuth, status, estCost, estAudience, budNo)
VALUES ('E107', 'C105', 'F100', '2013-11-23', '2013-07-28', '2013-07-31', 'Denied', '10000.00', '5000', NULL);

DROP TABLE ResourceTbl;

CREATE TABLE ResourceTbl (
  resNo   CHAR(8)       NOT NULL,
  resName VARCHAR(30)   NOT NULL,
  rate    DECIMAL(8, 2) NOT NULL,
  CONSTRAINT PK_ResourceTbl PRIMARY KEY (resNo)
);
INSERT INTO ResourceTbl (resNo, resName, rate) VALUES ('R100', 'attendant', '10.00');
INSERT INTO ResourceTbl (resNo, resName, rate) VALUES ('R101', 'police', '15.00');
INSERT INTO ResourceTbl (resNo, resName, rate) VALUES ('R102', 'usher', '10.00');
INSERT INTO ResourceTbl (resNo, resName, rate) VALUES ('R103', 'nurse', '20.00');
INSERT INTO ResourceTbl (resNo, resName, rate) VALUES ('R104', 'janitor', '15.00');
INSERT INTO ResourceTbl (resNo, resName, rate) VALUES ('R105', 'food service', '10.00');

