
-- #### 数据库表设计
-- 根据实体和联系图，定义各个表的结构。
-- 

-- 创建学生表

-- 不是直接把整张表删了，而是在后面维护的时候使用局部调整

CREATE TABLE IF NOT EXISTS Students (
    StudentID INT PRIMARY KEY,
    Name VARCHAR(100),
    Gender CHAR(1),
    BirthDate DATE
);

-- 创建消费卡表，包含外键约束

CREATE TABLE IF NOT EXISTS Cards (
    CardID INT PRIMARY KEY,
    StudentID INT,
    Balance DECIMAL(10, 2) DEFAULT 0.00,
    FOREIGN KEY (StudentID) REFERENCES Students(StudentID) ON DELETE CASCADE
);

-- 删除已存在的Transactions表
DROP TABLE IF EXISTS Transactions;

-- 创建Transactions表，包括新增的discount_amount列和DishID列，设置默认值为0
CREATE TABLE IF NOT EXISTS Transactions (
    TransactionID INT AUTO_INCREMENT PRIMARY KEY,
    CardID INT,
    TransactionType VARCHAR(20), -- "Recharge", "Consume"
    Amount DECIMAL(10, 2),
    TransactionDate DATETIME DEFAULT CURRENT_TIMESTAMP,
    IsProcessed TINYINT DEFAULT 0, -- 新增字段，用来标记是否已处理，默认为0（未处理）
    RestaurantType VARCHAR(50), -- 新增列，用于标记餐厅类型
    RestaurantID INT,
    DishID INT, -- 新增DishID列
    DiscountAmount DECIMAL(10, 2) DEFAULT 0, -- 新增折扣金额列，并设置默认值为0
    FOREIGN KEY (CardID) REFERENCES Cards(CardID),
    FOREIGN KEY (RestaurantID) REFERENCES Restaurants(RestaurantID),
    FOREIGN KEY (DishID) REFERENCES Dishes(DishID) -- 新增外键约束，引用Dishes表中的DishID
);



-- 餐厅表
DROP TABLE if EXISTS Restaurants
CREATE TABLE if not EXISTS Restaurants (
    RestaurantID INT PRIMARY KEY,
    Name VARCHAR(100)
);

-- 菜品类别表
CREATE TABLE if not EXISTS DishCategories (
    CategoryID INT PRIMARY KEY,
    CategoryName VARCHAR(100) UNIQUE
);

-- 菜品表
CREATE TABLE if not EXISTS Dishes (
    DishID INT PRIMARY KEY,
    DishName VARCHAR(100) UNIQUE,
    CategoryID INT,
    RestaurantID INT,
    Price DECIMAL(10, 2),
    FOREIGN KEY (CategoryID) REFERENCES DishCategories(CategoryID),
    FOREIGN KEY (RestaurantID) REFERENCES Restaurants(RestaurantID)
);

-- 修改菜品表
-- ALTER TABLE Dishes
-- ADD COLUMN IsActive BOOLEAN DEFAULT true; -- 用于标识菜品是否处于激活状态


-- 添加餐厅菜品类别关系表
CREATE TABLE if not EXISTS RestaurantDishCategories (
    RestaurantID INT,
    CategoryID INT,
    PRIMARY KEY (RestaurantID, CategoryID),
    FOREIGN KEY (RestaurantID) REFERENCES Restaurants(RestaurantID),
    FOREIGN KEY (CategoryID) REFERENCES DishCategories(CategoryID)
);

-- 创建就餐时间表
CREATE TABLE if not EXISTS DiningTimes (
    DiningTimeID INT PRIMARY KEY,
    DiningType VARCHAR(20) UNIQUE, -- 早餐、中餐、晚餐
    StartTime TIME,
    EndTime TIME
);

CREATE TABLE if not EXISTS DiscountRules (
    DiscountID INT PRIMARY KEY,
    Description VARCHAR(255),
    MinimumAmount DECIMAL(10, 2),
    DiscountAmount DECIMAL(10, 2),
    StartDate DATE,
    EndDate DATE,
    IsMandatory TINYINT
);

INSERT INTO DiscountRules (DiscountID, Description, MinimumAmount, DiscountAmount, StartDate, EndDate, IsMandatory)
VALUES (1, '满500减30', 500, 30, '2024-01-01', '2024-12-31', 1);






CALL Consume(2, 100.00, '2024-06-29 15:20:00');

CALL Recharge(2, 1000.00, '2024-06-29 15:30:00');


-- 直接打钱

-- 当前还没有插入符合条件的数据，当然执行对应操作的对应行为0。
-- 在维护和数据的增删改查的那部分写好就行了，
-- 写在哪里不重要，重要的是写了，然后你去那里执行就好
-- 顺序不重要，写好了跑到对应的地方执行即可。



-- 设置指定餐厅是否支持学生促销活动

-- 替换为实际的餐厅ID和期望的值（0或1）
SET @RestaurantID = 1; -- 替换为目标餐厅的ID
SET @SupportsPromotion = 1; -- 设置为1表示支持学生促销活动，设置为0表示不支持

UPDATE Restaurants
SET Supports_Student_Promotion = @SupportsPromotion
WHERE RestaurantID = @RestaurantID;


-- 更新消费卡余额，根据学生促销活动规则进行减免

-- 替换为具体的餐厅名
SET @RestaurantName = 'RestaurantA';

UPDATE Cards c
SET Balance = Balance - 10
WHERE EXISTS (
    -- 存在符合以下条件的交易记录
    SELECT 1
    FROM Transactions t1
    WHERE t1.CardID = c.CardID  -- 关联消费卡ID
    AND t1.TransactionType = 'Consume' -- 交易类型为消费
    AND t1.TransactionDate = DATE_SUB(CURDATE(), INTERVAL 11 DAY) -- 交易日期在11天之前
    AND (
        -- 存在至少10笔金额小于100的消费记录，回顾20到11天之前的交易
        SELECT COUNT(*)
        FROM Transactions t2
        WHERE t2.CardID = c.CardID
        AND t2.TransactionType = 'Consume'
        AND t2.TransactionDate BETWEEN DATE_SUB(CURDATE(), INTERVAL 20 DAY) AND DATE_SUB(CURDATE(), INTERVAL 11 DAY)
        AND t2.Amount < 100
    ) >= 10
    AND NOT EXISTS (
        -- 不存在前一天在其他餐厅的消费记录
        SELECT 1
        FROM Transactions t3
        WHERE t3.CardID = c.CardID
        AND t3.TransactionType = 'Consume'
        AND t3.TransactionDate = DATE_SUB(CURDATE(), INTERVAL 1 DAY)
        AND t3.TransactionID <> t1.TransactionID -- 排除与当前交易相同的交易记录
    )
    AND EXISTS (
        -- 存在支持学生促销活动的指定餐厅
        SELECT 1
        FROM Restaurants r
        WHERE r.Name = @RestaurantName
        AND r.Supports_Student_Promotion = TRUE
    )
);






### 存储过程一：按餐厅统计消费金额


DELIMITER //
DROP PROCEDURE IF EXISTS GenerateRestaurantConsumptionReport;
CREATE PROCEDURE GenerateRestaurantConsumptionReport()
BEGIN
    SELECT r.Name AS RestaurantName, SUM(t.Amount) AS TotalAmount
    FROM Transactions t
    JOIN Restaurants r ON t.RestaurantID = r.RestaurantID
    WHERE t.TransactionType = 'Consume'
    GROUP BY r.Name;
END //

DELIMITER ;


### 存储过程二：按学生统计消费次数和充值次数


DELIMITER //
DROP PROCEDURE IF EXISTS GenerateStudentTransactionCounts;
CREATE PROCEDURE GenerateStudentTransactionCounts()
BEGIN
    SELECT s.Name AS StudentName,
           COUNT(CASE WHEN t.TransactionType = 'Consume' THEN 1 END) AS ConsumeCount,
           COUNT(CASE WHEN t.TransactionType = 'Recharge' THEN 1 END) AS RechargeCount
    FROM Transactions t
    JOIN Cards c ON t.CardID = c.CardID
    JOIN Students s ON c.StudentID = s.StudentID
    GROUP BY s.Name;
END //

DELIMITER ;

-- 存储过程三：按菜品类别统计销售金额


DELIMITER //

DROP PROCEDURE IF EXISTS GenerateDishCategorySalesReport;
CREATE PROCEDURE GenerateDishCategorySalesReport()
BEGIN
    SELECT dc.CategoryName, SUM(t.Amount) AS TotalSales
    FROM Transactions t
    JOIN Dishes d ON t.RestaurantID = d.RestaurantID
    JOIN DishCategories dc ON d.CategoryID = dc.CategoryID
    WHERE t.TransactionType = 'Consume'
    GROUP BY dc.CategoryName;
END //

DELIMITER ;


### 示例存储过程四：按时间段统计消费额

DELIMITER //

DROP PROCEDURE IF EXISTS GenerateTransactionAmountByTime;
CREATE PROCEDURE GenerateTransactionAmountByTime()
BEGIN
    SELECT DATE_FORMAT(t.TransactionDate, '%Y-%m-%d') AS TransactionDate,
           SUM(t.Amount) AS TotalAmount
    FROM Transactions t
    WHERE t.TransactionType = 'Consume'
    GROUP BY DATE_FORMAT(t.TransactionDate, '%Y-%m-%d');
END //

DELIMITER ;


### 示例存储过程五：生成折扣使用统计报表

DELIMITER //

DROP PROCEDURE IF EXISTS GenerateDiscountUsageReport;
CREATE PROCEDURE GenerateDiscountUsageReport()
BEGIN
    SELECT dr.Description AS DiscountDescription,
           COUNT(t.DiscountID) AS UsageCount,
           SUM(t.Amount) AS TotalDiscountAmount
    FROM Transactions t
    JOIN DiscountRules dr ON t.DiscountID = dr.DiscountID
    WHERE t.DiscountID IS NOT NULL
    GROUP BY dr.Description;
END //

DELIMITER ;



--  2. 基础数据维护


### 学生表 (Students)

-- 插入学生数据
INSERT INTO Students (StudentID, Name, Gender, BirthDate)
VALUES (1, 'Alice', 'F', '2000-05-15');

INSERT INTO Students (StudentID, Name, Gender, BirthDate)
VALUES (2, 'Bob', 'M', '1999-09-20');

-- 插入第三条学生记录
INSERT INTO Students (StudentID, Name, Gender, BirthDate)
VALUES (3, 'Eva', 'F', '2001-03-10');

-- 插入第四条学生记录
INSERT INTO Students (StudentID, Name, Gender, BirthDate)
VALUES (4, 'David', 'M', '2002-11-25');

-- 更新学生的出生日期
UPDATE Students
SET BirthDate = '2001-02-28'
WHERE StudentID = 3;


-- 删除学生记录，并同时删除关联的消费卡记录（由于外键约束设置了 ON DELETE CASCADE）
DELETE FROM Students
WHERE StudentID = 3;


-- 查询学生表中的数据
SELECT * FROM Students;



### 消费卡表 (Cards)

-- 插入消费卡数据
INSERT INTO Cards (CardID, StudentID, Balance)
VALUES (1, 1, 500.00);

INSERT INTO Cards (CardID, StudentID, Balance)
VALUES (2, 2, 500.00);

-- 插入消费卡数据
INSERT INTO Cards (CardID, StudentID, Balance)
VALUES (3, 3, 500.00);

INSERT INTO Cards (CardID, StudentID, Balance)
VALUES (4, 4, 500.00);



-- 因为两个表是相关联的，所以说，前面的数据如果是空的话，消费卡的插入也是不可进行的，
-- 这就是外键的作用，绑定互相约束！所以说你前面删除了数据，那么消费卡的插入就无法完成
-- 因为学生卡是主键，嗯

       
-- 更新消费卡余额
UPDATE Cards
SET Balance = 120.00
WHERE CardID = 1;

-- 删除消费卡记录
DELETE FROM Cards
WHERE CardID = 3;

DELETE FROM Cards
WHERE CardID = 4;

-- 查询消费卡表中的数据
SELECT * FROM Cards;


### 餐厅表 (Restaurants)

-- 1. **插入数据**：


INSERT INTO Restaurants (RestaurantID, Name,ParticipatesInDiscount)
VALUES (1, 'Restaurant A',1);

INSERT INTO Restaurants (RestaurantID, Name,ParticipatesInDiscount)
VALUES (2, 'Restaurant B',1);

INSERT INTO Restaurants (RestaurantID, Name,ParticipatesInDiscount)
VALUES (0, '无',0);

INSERT INTO Restaurants (RestaurantID, Name,ParticipatesInDiscount)
VALUES (3, 'Restaurant C',1);

-- 2. **更新数据**：


UPDATE Restaurants
SET Name = 'Restaurant Z'
WHERE RestaurantID = 2;


-- 3. **删除数据**：


DELETE FROM Restaurants
WHERE RestaurantID = 3;


-- 4. **查询数据**：


SELECT * FROM Restaurants;

ALTER TABLE dishes
DROP FOREIGN KEY dishes_ibfk_2;

ALTER TABLE dishes
ADD CONSTRAINT dishes_ibfk_2 FOREIGN KEY (RestaurantID)
REFERENCES Restaurants (RestaurantID)
ON DELETE CASCADE;



### 菜品类别表 (DishCategories)

-- 1. **插入数据**：


INSERT INTO DishCategories (CategoryID, CategoryName)
VALUES (1, 'Appetizers');

INSERT INTO DishCategories (CategoryID, CategoryName)
VALUES (2, 'Main Dishes');

INSERT INTO DishCategories (CategoryID, CategoryName)
VALUES (3, 'ert');

INSERT INTO DishCategories (CategoryID, CategoryName)
VALUES (4, 'proDishes');

-- 2. **更新数据**：


UPDATE DishCategories
SET CategoryName = 'Desserts'
WHERE CategoryID = 1;


-- 3. **删除数据**：


DELETE FROM DishCategories
WHERE CategoryID = 3;


-- 4. **查询数据**：


SELECT * FROM DishCategories;


### 菜品表 (Dishes)

-- 又忘记了又是因为数据不完整才会报错，
-- 给我记牢了！！！!!

-- 1. **插入数据**：


-- 假设 Restaurants 表中已经存在 RestaurantID 为 1 和 2 的记录

-- 插入数据到菜品表 Dishes
INSERT INTO Dishes (DishID, DishName, CategoryID, RestaurantID, Price)
VALUES (1, 'Salad', 1, 1, 10.00);

INSERT INTO Dishes (DishID, DishName, CategoryID, RestaurantID, Price)
VALUES (2, 'Steak', 2, 2, 25.00);

INSERT INTO Dishes (DishID, DishName, CategoryID, RestaurantID, Price)
VALUES (3, 'Pasta', 1, 1, 10.00);

INSERT INTO Dishes (DishID, DishName, CategoryID, RestaurantID, Price)
VALUES (4, 'Seafood', 2, 2, 25.00);



-- 更新数据
UPDATE Dishes
SET Price = 30.00
WHERE DishID = 2;

-- 删除数据
DELETE FROM Dishes
WHERE DishID = 4;

-- 查询数据
SELECT * FROM Dishes;



### 3. 折扣规则的维护

#### 增删改查操作示例

-- 插入折扣规则
INSERT INTO DiscountRules (DiscountID, Description, MinimumAmount, DiscountAmount, StartDate, EndDate, IsMandatory) 
VALUES (1, '满500减30', 500, 30, '2024-01-01', '2024-12-31', 1);

-- 更新折扣规则
UPDATE DiscountRules SET DiscountAmount = 50 WHERE DiscountID = 1;

-- 删除折扣规则
DELETE FROM DiscountRules WHERE DiscountID = 1;

-- 查询折扣规则
SELECT * FROM DiscountRules;



-- 需要一个演示功能，把触发器的作用发挥出来



### 4. 消费卡交易流水的维护

#### 触发器和存储过程


-- 触发器：阻止直接修改交易流水
-- 删除现有触发器
DROP TRIGGER IF EXISTS trg_PreventTransactionUpdate;

-- 重新创建触发器
CREATE TRIGGER trg_PreventTransactionUpdate
BEFORE UPDATE ON Transactions
FOR EACH ROW
BEGIN
    SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Transactions cannot be modified';
END;



-- 充值存储过程 Recharge
DROP PROCEDURE IF EXISTS Recharge;
DELIMITER //

CREATE PROCEDURE Recharge(
    IN p_CardID INT, 
    IN p_Amount DECIMAL(10, 2),
    IN p_TransactionDate TIMESTAMP
)
BEGIN
    -- 插入充值交易记录，并设置RestaurantID默认值为0
    INSERT INTO Transactions (CardID, TransactionType, Amount, TransactionDate, RestaurantID)
    VALUES (p_CardID, 'Recharge', p_Amount, p_TransactionDate, 0);
    
    -- 更新卡片余额
    UPDATE Cards SET Balance = Balance + p_Amount WHERE CardID = p_CardID;
    
    -- 返回充值后的余额，可选步骤
    SELECT Balance FROM Cards WHERE CardID = p_CardID;
END;

DELIMITER ;


CALL Recharge(2, 1000.00,'2024-06-29 11:30:00');

-- 充值回退存储过程 RechargeRollback
DROP PROCEDURE IF EXISTS RechargeRollback;
DELIMITER //

CREATE PROCEDURE RechargeRollback(
    IN TransactionID INT
)
BEGIN
    DECLARE RechargeAmount DECIMAL(10, 2);
    DECLARE RechargeCardID INT;
    
    -- 获取充值金额和卡片ID
    SELECT Amount, CardID INTO RechargeAmount, RechargeCardID
    FROM Transactions
    WHERE TransactionID = TransactionID AND TransactionType = 'Recharge'
    LIMIT 1;
    
    -- 如果找不到对应的充值记录，抛出错误
    IF RechargeAmount IS NULL THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Invalid transaction ID or type';
    ELSE
        -- 删除交易记录
        DELETE FROM Transactions WHERE TransactionID = TransactionID;
        -- 回退卡片余额
        UPDATE Cards SET Balance = Balance - RechargeAmount WHERE CardID = RechargeCardID;
    END IF;
END //

DELIMITER ;


CALL RechargeRollback(2);


-- 消费存储过程 Consume

DROP PROCEDURE IF EXISTS Consume;
DELIMITER //

CREATE PROCEDURE Consume(
    IN p_CardID INT, 
    IN p_Amount DECIMAL(10, 2),
    IN p_TransactionDate TIMESTAMP,
    IN p_RestaurantID INT,
    IN p_DishID INT
)
BEGIN
    DECLARE currentBalance DECIMAL(10, 2);
    
    -- 获取当前卡片余额
    SELECT Balance INTO currentBalance FROM Cards WHERE CardID = p_CardID;
    
    -- 如果余额足够消费
    IF currentBalance >= p_Amount THEN
        -- 插入消费交易记录，使用上传的时间戳和RestaurantID，并记录菜品的DishID
        INSERT INTO Transactions (CardID, TransactionType, Amount, TransactionDate, RestaurantID, DishID)
        VALUES (p_CardID, 'Consume', p_Amount, p_TransactionDate, p_RestaurantID, p_DishID);

        -- 更新卡片余额
        UPDATE Cards SET Balance = Balance - p_Amount WHERE CardID = p_CardID;
        
        -- 返回更新后的余额，可选步骤
        SELECT Balance FROM Cards WHERE CardID = p_CardID;
        
    ELSE
        -- 余额不足，抛出错误
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Insufficient balance';
    END IF;
END //

DELIMITER ;




-- 折扣判断

-- 更新卡片信息
UPDATE Cards c
JOIN (
    SELECT CardID,
           TotalConsumeAmount,
           FLOOR(TotalConsumeAmount / 500) * 30 AS RewardAmount
    FROM (
        SELECT CardID,
               SUM(CASE WHEN TransactionType = 'Consume' THEN Amount ELSE 0 END) AS TotalConsumeAmount
        FROM Transactions
        WHERE DATE(TransactionDate) = DATE_SUB(CURDATE(), INTERVAL 1 DAY)  -- 只考虑昨天的消费交易
          AND IsProcessed = 0  -- 确保交易记录未被处理过
        GROUP BY CardID
    ) AS t
) AS t ON c.CardID = t.CardID
SET c.Balance = c.Balance + t.RewardAmount,
    c.AccumulatedAmount = c.AccumulatedAmount + t.TotalConsumeAmount;

-- 更新交易信息及插入RewardAmount到DiscountAmount
UPDATE Transactions t
JOIN (
    SELECT TransactionID,
           FLOOR(TotalConsumeAmount / 500) * 30 AS RewardAmount
    FROM (
        SELECT TransactionID,
               SUM(CASE WHEN TransactionType = 'Consume' THEN Amount ELSE 0 END) AS TotalConsumeAmount
        FROM Transactions
        WHERE DATE(TransactionDate) = DATE_SUB(CURDATE(), INTERVAL 1 DAY)  -- 只考虑昨天的消费交易
          AND IsProcessed = 0  -- 确保交易记录未被处理过
        GROUP BY TransactionID
    ) AS t
) AS reward ON t.TransactionID = reward.TransactionID
SET t.DiscountAmount = reward.RewardAmount,
    t.IsProcessed = 1
WHERE DATE(t.TransactionDate) = DATE_SUB(CURDATE(), INTERVAL 1 DAY)
  AND t.IsProcessed = 0;



-- 标记交易为已处理
CREATE TEMPORARY TABLE temp_transactions_to_update (TransactionID INT);

INSERT INTO temp_transactions_to_update (TransactionID)
SELECT t.TransactionID
FROM Transactions t
JOIN (
    SELECT CardID
    FROM (
        SELECT CardID,
               SUM(CASE WHEN TransactionType = 'Consume' THEN Amount ELSE 0 END) AS TotalConsumeAmount
        FROM Transactions
        WHERE DATE(TransactionDate) = DATE_SUB(CURDATE(), INTERVAL 1 DAY)
          AND IsProcessed = 0
        GROUP BY CardID
    ) AS sub
    WHERE sub.TotalConsumeAmount >= 500
) AS sub ON t.CardID = sub.CardID
WHERE DATE(t.TransactionDate) = DATE_SUB(CURDATE(), INTERVAL 1 DAY)
  AND t.IsProcessed = 0;

UPDATE Transactions
SET IsProcessed = 1
WHERE TransactionID IN (SELECT TransactionID FROM temp_transactions_to_update);

DROP TEMPORARY TABLE IF EXISTS temp_transactions_to_update;

-- 记得卡号是要环环相扣的，如果不存在该卡号那也会插入失败！

-- CALL Consume(789, 25.00, '2024-06-28 15:30:00'); err

CALL Consume(2, 500.00, '2024-07-03 11:30:00',1,1);




-- 消费回退存储过程 ConsumeRollback
DROP PROCEDURE IF EXISTS ConsumeRollback;
DELIMITER //

CREATE PROCEDURE ConsumeRollback(
    IN TransactionID INT
)
BEGIN
    DECLARE ConsumeAmount DECIMAL(10, 2);
    DECLARE ConsumeCardID INT;
    
    -- 获取消费金额和卡片ID
    SELECT Amount, CardID INTO ConsumeAmount, ConsumeCardID
    FROM Transactions
    WHERE TransactionID = TransactionID AND TransactionType = 'Consume'
    LIMIT 1;  -- 限制只返回一条记录
    
    -- 如果找不到对应的消费记录，抛出错误
    IF ConsumeAmount IS NULL THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Invalid transaction ID or type';
    ELSE
        -- 删除消费交易记录
        DELETE FROM Transactions WHERE TransactionID = TransactionID;
        -- 回退卡片余额
        UPDATE Cards SET Balance = Balance + ConsumeAmount WHERE CardID = ConsumeCardID;
    END IF;
END //

DELIMITER ;

CALL ConsumeRollback(2);




DROP VIEW IF EXISTS TransactionView;
-- 交易流水查询视图
CREATE VIEW TransactionView AS
SELECT t.TransactionID, c.StudentID, t.TransactionType, t.Amount, t.TransactionDate
FROM Transactions t
JOIN Cards c ON t.CardID = c.CardID;

-- 查询 TransactionView 视图的所有数据
SELECT * FROM TransactionView;


-- -------------------------------------------------------------------------------------------------------------------

-- 学校硬性要求的满500减30元，
-- 管理员可以统计指定时间段内因该项政策惠及了多少金额给多少学生，
-- 享受了该项政策的学生占全部学生的比例；

-- 查询指定时间段内政策受益金额和学生人数
SELECT
    COUNT(DISTINCT c.CardID) AS BenefitedStudents,
    SUM(t.RewardAmount) AS TotalBenefitAmount
FROM Cards c
JOIN (
    SELECT CardID,
           FLOOR(SUM(CASE WHEN TransactionType = 'Consume' THEN Amount ELSE 0 END) / 500) * 30 AS RewardAmount
    FROM Transactions
    WHERE TransactionDate BETWEEN '2024-06-01 00:00:00' AND '2024-08-30 23:30:00' -- 替换为实际的开始和结束日期
      AND IsProcessed = 1  -- 已处理的交易
    GROUP BY CardID
) AS t ON c.CardID = t.CardID;

-- 计算享受政策的学生比例
SELECT
    COUNT(DISTINCT c.CardID) / (SELECT COUNT(DISTINCT CardID) FROM Cards) AS BenefitedPercentage
FROM Cards c
JOIN (
    SELECT CardID
    FROM Transactions
    WHERE TransactionDate BETWEEN '2024-06-01 00:00:00' AND '2024-08-30 23:30:00'
      AND IsProcessed = 1
    GROUP BY CardID
) AS t ON c.CardID = t.CardID;

-- -------------------------------------------------------------------------------------------------------------------


ALTER TABLE Cards
ADD COLUMN LastTransactionDate DATE,
ADD COLUMN LastRestaurantID INT;

ALTER TABLE Restaurants
ADD COLUMN ParticipatesInDiscount TINYINT DEFAULT 0;

DELETE FROM DiscountRules WHERE DiscountID = 2;


INSERT INTO DiscountRules (DiscountID, Description, MinimumAmount, DiscountAmount, StartDate, EndDate, IsMandatory)
VALUES (2, '连续10天消费不足100元且第11天未在其他餐厅消费的折扣', 100.00, 10.00, '2024-06-01 11:30:00', NULL, 0);

-- 示例脚本，返还卡片余额并将返还金额插入DiscountAmount

-- 获取当前日期
SET @current_date := CURDATE();

-- 定义中餐时间范围
SET @lunch_start := '11:00:00';
SET @lunch_end := '14:00:00';

-- 创建临时表存储符合条件的交易ID和CardID，并且未被标记为已处理

CREATE TEMPORARY TABLE tmp_transactions_to_update
SELECT t.TransactionID, t.CardID
FROM Transactions t
JOIN Restaurants r ON t.RestaurantID = r.RestaurantID
WHERE t.TransactionType = 'Consume'
AND DATE(t.TransactionDate) >= '2024-06-01'
AND TIME(t.TransactionDate) BETWEEN @lunch_start AND @lunch_end
AND t.Amount < (SELECT MinimumAmount FROM DiscountRules WHERE DiscountID = 2)
AND (
    SELECT COUNT(DISTINCT t2.TransactionDate)
    FROM Transactions t2
    WHERE t2.CardID = t.CardID
    AND t2.TransactionDate BETWEEN @current_date - INTERVAL 10 DAY AND @current_date - INTERVAL 1 DAY
    AND t2.RestaurantID = t.RestaurantID
) = 9
AND NOT EXISTS (
    SELECT 1 FROM Transactions t3
    WHERE t3.CardID = t.CardID
    AND t3.TransactionDate = @current_date + INTERVAL 1 DAY
)
AND r.ParticipatesInDiscount = 1
AND t.IsProcessed = 0;  -- 确保未被标记为已处理


-- 更新符合条件的卡片余额，并标记已处理的交易记录
UPDATE Cards c
JOIN tmp_transactions_to_update tmp ON c.CardID = tmp.CardID
JOIN Transactions t ON tmp.TransactionID = t.TransactionID
SET 
    c.Balance = c.Balance + 10,  -- 卡片余额返还10元
    t.IsProcessed = 1;  -- 标记交易为已处理
		


UPDATE Transactions t
JOIN (
    SELECT TransactionID, CardID
    FROM Transactions
    WHERE IsProcessed = 1  -- 确保交易已被处理
    ORDER BY TransactionDate DESC  -- 按交易日期倒序排列，确保最后一条记录在顶部
    LIMIT 1  -- 只选择最后一条记录
) tmp ON t.TransactionID = tmp.TransactionID
SET t.DiscountAmount = t.DiscountAmount + 10;


-- 清理临时表
DROP TEMPORARY TABLE IF EXISTS tmp_transactions_to_update;





SELECT 
    @current_date AS CurrentDate,
    @current_date - INTERVAL 10 DAY AS StartDate,
    @current_date - INTERVAL 1 DAY AS EndDate;





SELECT * FROM tmp_transactions_to_update;


CALL Consume(2, 1.00, '2024-06-20 11:30:00', 1, 1);
CALL Consume(2, 1.00, '2024-06-21 11:30:00', 1, 1);
CALL Consume(2, 1.00, '2024-06-22 11:30:00', 1, 1);
CALL Consume(2, 1.00, '2024-06-23 11:30:00', 1, 1);
CALL Consume(2, 1.00, '2024-06-24 11:30:00', 1, 1);
CALL Consume(2, 1.00, '2024-06-25 11:30:00', 1, 1);
CALL Consume(2, 1.00, '2024-06-26 11:30:00', 1, 1);
CALL Consume(2, 1.00, '2024-06-27 11:30:00', 1, 1);
CALL Consume(2, 1.00, '2024-06-28 11:30:00', 1, 1);
CALL Consume(2, 1.00, '2024-06-29 11:30:00', 1, 1);
CALL Consume(2, 1.00, '2024-06-30 11:30:00', 1, 1);
CALL Consume(2, 1.00, '2024-07-01 11:30:00', 1, 1);
CALL Consume(2, 1.00, '2024-07-02 11:30:00', 1, 1);
CALL Consume(2, 1.00, '2024-07-03 11:30:00', 1, 1);

CALL Consume(1, 1.00, '2024-06-20 11:30:00', 1, 1);
CALL Consume(1, 1.00, '2024-06-21 11:30:00', 1, 1);
CALL Consume(1, 1.00, '2024-06-22 11:30:00', 1, 1);
CALL Consume(1, 1.00, '2024-06-23 11:30:00', 1, 1);
CALL Consume(1, 1.00, '2024-06-24 11:30:00', 1, 1);
CALL Consume(1, 1.00, '2024-06-25 11:30:00', 1, 1);
CALL Consume(1, 1.00, '2024-06-26 11:30:00', 1, 1);
CALL Consume(1, 1.00, '2024-06-27 11:30:00', 1, 1);
CALL Consume(1, 1.00, '2024-06-28 11:30:00', 1, 1);
CALL Consume(1, 1.00, '2024-06-29 11:30:00', 1, 1);
CALL Consume(1, 1.00, '2024-06-30 11:30:00', 1, 1);
CALL Consume(1, 1.00, '2024-07-01 11:30:00', 1, 1);




-- 删除已存在的Transactions表
DROP TABLE IF EXISTS Transactions;

-- 创建Transactions表，包括新增的discount_amount列和DishID列，设置默认值为0
CREATE TABLE IF NOT EXISTS Transactions (
    TransactionID INT AUTO_INCREMENT PRIMARY KEY,
    CardID INT,
    TransactionType VARCHAR(20), -- "Recharge", "Consume"
    Amount DECIMAL(10, 2),
    TransactionDate DATETIME DEFAULT CURRENT_TIMESTAMP,
    IsProcessed TINYINT DEFAULT 0, -- 新增字段，用来标记是否已处理，默认为0（未处理）
    RestaurantType VARCHAR(50), -- 新增列，用于标记餐厅类型
    RestaurantID INT,
    DishID INT, -- 新增DishID列
    DiscountAmount DECIMAL(10, 2) DEFAULT 0, -- 新增折扣金额列，并设置默认值为0
    FOREIGN KEY (CardID) REFERENCES Cards(CardID),
    FOREIGN KEY (RestaurantID) REFERENCES Restaurants(RestaurantID),
    FOREIGN KEY (DishID) REFERENCES Dishes(DishID) -- 新增外键约束，引用Dishes表中的DishID
);



-- -------------------------------------------------------------------------------------------------------------------


### 5. 按学生统计消费

#### 存储过程

DROP PROCEDURE IF EXISTS StudentMonthlyStats;
-- 按学生统计月度消费总额、每天平均消费额，享受的折扣总额
CREATE PROCEDURE StudentMonthlyStats(IN StudentID INT, IN MonthYear CHAR(7))
BEGIN
    -- 月度消费总额
    SELECT SUM(t.Amount) AS MonthlyTotal
    FROM Transactions t
    JOIN Cards c ON t.CardID = c.CardID
    WHERE c.StudentID = StudentID AND t.TransactionType = 'Consume' 
      AND DATE_FORMAT(t.TransactionDate, '%Y-%m') = MonthYear;

    -- 每天平均消费额
    SELECT AVG(daily.Total) AS DailyAverage
    FROM (
        SELECT DATE(t.TransactionDate) AS Date, SUM(t.Amount) AS Total
        FROM Transactions t
        JOIN Cards c ON t.CardID = c.CardID
        WHERE c.StudentID = StudentID AND t.TransactionType = 'Consume' 
          AND DATE_FORMAT(t.TransactionDate, '%Y-%m') = MonthYear
        GROUP BY DATE(t.TransactionDate)
    ) AS daily;

    -- 享受的折扣总额
    SELECT SUM(DiscountAmount) AS TotalDiscount
    FROM Transactions t
    WHERE StudentID = t.CardID AND DATE_FORMAT(DATE(t.TransactionDate), '%Y-%m') = MonthYear;
END;

-- 调用存储过程
CALL StudentMonthlyStats(2, '2024-07');


-- 6.按学生实时查询进行中的500减30元的进度情况。

DROP PROCEDURE IF EXISTS CheckDiscountProgress;

CREATE PROCEDURE CheckDiscountProgress(IN StudentID INT)
BEGIN
    DECLARE TotalConsumed DECIMAL(10, 2);
    DECLARE RemainingToNextDiscount DECIMAL(10, 2);

    -- 计算当前累计消费总额
    SELECT COALESCE(SUM(t.Amount), 0) INTO TotalConsumed
    FROM Transactions t
    JOIN Cards c ON t.CardID = c.CardID
    WHERE c.StudentID = StudentID 
      AND t.TransactionType = 'Consume';

    -- 计算已经满足的500元折扣条件后剩余的消费额
    SET TotalConsumed = TotalConsumed % 500;

    -- 计算还需消费多少金额才能达到下一个500元减30元的条件
    IF TotalConsumed >= 0 THEN
        SET RemainingToNextDiscount = 500 - TotalConsumed;
    ELSE
        SET RemainingToNextDiscount = 500;
    END IF;

    -- 输出结果
    SELECT TotalConsumed AS TotalConsumed, RemainingToNextDiscount AS RemainingToNextDiscount;
END;

CALL CheckDiscountProgress(2);


### 7. 实时查询10天中餐不足100减10元进度情况

DROP PROCEDURE IF EXISTS CheckContinuousConsumptionProgress;
#### 存储过程

CREATE PROCEDURE CheckContinuousConsumptionProgress(IN StudentID INT)
BEGIN
    SELECT COUNT(*) AS ConsecutiveDays
    FROM (
        SELECT DATE(t.TransactionDate) AS Date, SUM(t.Amount) AS Total
        FROM Transactions t
        JOIN Cards c ON t.CardID = c.CardID
        WHERE c.StudentID = StudentID AND t.TransactionType = 'Consume' 
          AND DATE_SUB(CURDATE(), INTERVAL 10 DAY) <= t.TransactionDate
        GROUP BY DATE(t.TransactionDate)
        HAVING Total < 100
    ) AS daily
    WHERE daily.Date > DATE_SUB(CURDATE(), INTERVAL 10 DAY);
END;

CALL CheckContinuousConsumptionProgress(2);




### 8. 菜品消费排行榜

#### 触发器、冗余表



-- 冗余表

DROP TABLE IF EXISTS DishPopularity;

CREATE TABLE IF NOT EXISTS DishPopularity (
    DishID INT,
    RestaurantID INT,
    MealType VARCHAR(20), -- "Lunch", "Dinner"
    ConsumptionCount INT,
    PRIMARY KEY (DishID, RestaurantID, MealType)
);


-- 更新冗余表的触发器
DROP TRIGGER IF EXISTS trg_UpdateDishPopularity;

DELIMITER //

CREATE TRIGGER trg_UpdateDishPopularity
AFTER INSERT ON Transactions
FOR EACH ROW
BEGIN
    DECLARE restaurant_id INT;
    DECLARE meal_type VARCHAR(50);
    
    -- 获取菜品对应的餐厅ID
    SELECT RestaurantID INTO restaurant_id FROM Dishes WHERE DishID = NEW.DishID;
    
    -- 根据时间判断是午餐还是晚餐消费
    IF TIME(NEW.TransactionDate) BETWEEN '11:00:00' AND '20:00:00' THEN
        SET meal_type = 'Lunch or Dinner';
    ELSE
        SET meal_type = 'Other';
    END IF;
    
    -- 更新冗余表 DishPopularity
    IF NEW.TransactionType = 'Consume' THEN
        INSERT INTO DishPopularity (DishID, RestaurantID, MealType, ConsumptionCount)
        VALUES (NEW.DishID, restaurant_id, meal_type, 1)
        ON DUPLICATE KEY UPDATE ConsumptionCount = ConsumptionCount + 1;
    END IF;
END//

DELIMITER ;




DROP VIEW IF EXISTS TopDishes;

-- 查询全校菜品中餐晚餐消费前10排行榜
CREATE VIEW TopDishes AS
SELECT d.DishName, dp.MealType, dp.ConsumptionCount
FROM DishPopularity dp
JOIN Dishes d ON dp.DishID = d.DishID
WHERE dp.MealType IN ('Lunch or Dinner')  -- 修改这里，合并中餐和晚餐的 MealType
ORDER BY dp.ConsumptionCount DESC
LIMIT 10;

SELECT * FROM TopDishes;



DROP VIEW IF EXISTS TopDishesForRestaurants;

-- 创建视图 TopDishesForRestaurants 用于查询各餐厅中餐和晚餐消费前三的菜品
CREATE VIEW TopDishesForRestaurants AS
SELECT d.RestaurantID, d.DishName, dp.MealType, dp.ConsumptionCount
FROM DishPopularity dp
JOIN Dishes d ON dp.DishID = d.DishID
WHERE dp.MealType IN ('Lunch or Dinner')  -- 修改这里，合并中餐和晚餐的 MealType
ORDER BY d.RestaurantID, dp.MealType, dp.ConsumptionCount DESC;

SELECT * FROM TopDishesForRestaurants;





### 9. 按餐厅统计月度消费总额、每天平均消费额

DROP PROCEDURE IF EXISTS RestaurantMonthlyStats;
#### 存储过程


CREATE PROCEDURE RestaurantMonthlyStats(IN RestaurantID INT, IN MonthYear CHAR(7))
BEGIN
    -- 月度消费总额
    SELECT SUM(t.Amount) AS MonthlyTotal
    FROM Transactions t
    JOIN Dishes d ON t.DishID = d.DishID
    WHERE d.RestaurantID = RestaurantID AND t.TransactionType = 'Consume' 
      AND DATE_FORMAT(t.TransactionDate, '%Y-%m') = MonthYear;

    -- 每天平均消费额
    SELECT AVG(daily.Total) AS DailyAverage
    FROM (
        SELECT DATE(t.TransactionDate) AS Date, SUM(t.Amount) AS Total
        FROM Transactions t
        JOIN Dishes d ON t.DishID = d.DishID
        WHERE d.RestaurantID = RestaurantID AND t.TransactionType = 'Consume' 
          AND DATE_FORMAT(t.TransactionDate, '%Y-%m') = MonthYear
        GROUP BY DATE(t.TransactionDate)
    ) AS daily;
END;

-- 调用存储过程 RestaurantMonthlyStats
CALL RestaurantMonthlyStats(1, '2024-06');

### 10. 统计指定时间段内满500减30政策的优惠总金额、受惠学生总人数、受惠学生总人数占全部学生的比率

-- 创建存储过程
DELIMITER //

CREATE PROCEDURE CalculatePolicyBenefitStats(IN StartDate DATETIME, IN EndDate DATETIME)
BEGIN
    DECLARE TotalBenefitAmount DECIMAL(10, 2);
    DECLARE BenefitedStudents INT;
    DECLARE BenefitedPercentage DECIMAL(5, 2);

    -- 查询政策受益金额和学生人数
    SELECT
        COUNT(DISTINCT c.CardID),
        SUM(t.RewardAmount)
    INTO
        BenefitedStudents,
        TotalBenefitAmount
    FROM Cards c
    JOIN (
        SELECT CardID,
               FLOOR(SUM(CASE WHEN TransactionType = 'Consume' THEN Amount ELSE 0 END) / 500) * 30 AS RewardAmount
        FROM Transactions
        WHERE TransactionDate BETWEEN StartDate AND EndDate
          AND IsProcessed = 1  -- 已处理的交易
        GROUP BY CardID
    ) AS t ON c.CardID = t.CardID;

    -- 计算享受政策的学生比例
    SELECT
        COUNT(DISTINCT c.CardID) / (SELECT COUNT(DISTINCT CardID) FROM Cards)
    INTO
        BenefitedPercentage
    FROM Cards c
    JOIN (
        SELECT CardID
        FROM Transactions
        WHERE TransactionDate BETWEEN StartDate AND EndDate
          AND IsProcessed = 1
        GROUP BY CardID
    ) AS t ON c.CardID = t.CardID;

    -- 输出结果
    SELECT BenefitedStudents AS BenefitedStudentsCount, TotalBenefitAmount AS TotalBenefitAmount;
    SELECT BenefitedPercentage AS BenefitedPercentage;
END //

DELIMITER ;


-- 调用存储过程 CalculatePolicyBenefitStats
CALL CalculatePolicyBenefitStats('2024-06-01 00:00:00', '2024-08-30 23:30:00');


### 11. 运维需求变更案例

#### 存储过程

-- 修改折扣规则为满500减50
UPDATE DiscountRules SET DiscountAmount = 50 WHERE DiscountID = 1;

-- 更新卡片信息
UPDATE Cards c
JOIN (
    SELECT CardID,
           TotalConsumeAmount,
           FLOOR(TotalConsumeAmount / 500) * 50 AS RewardAmount  -- 每满500元返还50元
    FROM (
        SELECT CardID,
               SUM(CASE WHEN TransactionType = 'Consume' THEN Amount ELSE 0 END) AS TotalConsumeAmount
        FROM Transactions
        WHERE DATE(TransactionDate) = DATE_SUB(CURDATE(), INTERVAL 1 DAY)  -- 只考虑昨天的消费交易
          AND IsProcessed = 0  -- 确保交易记录未被处理过
        GROUP BY CardID
    ) AS t
) AS t ON c.CardID = t.CardID
SET c.Balance = c.Balance + t.RewardAmount,
    c.AccumulatedAmount = c.AccumulatedAmount + t.TotalConsumeAmount;

-- 更新交易信息及插入RewardAmount到DiscountAmount
UPDATE Transactions t
JOIN (
    SELECT TransactionID,
           FLOOR(TotalConsumeAmount / 500) * 50 AS RewardAmount  -- 每满500元返还50元
    FROM (
        SELECT TransactionID,
               SUM(CASE WHEN TransactionType = 'Consume' THEN Amount ELSE 0 END) AS TotalConsumeAmount
        FROM Transactions
        WHERE DATE(TransactionDate) = DATE_SUB(CURDATE(), INTERVAL 1 DAY)  -- 只考虑昨天的消费交易
          AND IsProcessed = 0  -- 确保交易记录未被处理过
        GROUP BY TransactionID
    ) AS t
) AS reward ON t.TransactionID = reward.TransactionID
SET t.DiscountAmount = reward.RewardAmount,
    t.IsProcessed = 1
WHERE DATE(t.TransactionDate) = DATE_SUB(CURDATE(), INTERVAL 1 DAY)
  AND t.IsProcessed = 0;

-- 标记交易为已处理
CREATE TEMPORARY TABLE temp_transactions_to_update (TransactionID INT);

INSERT INTO temp_transactions_to_update (TransactionID)
SELECT t.TransactionID
FROM Transactions t
JOIN (
    SELECT CardID
    FROM (
        SELECT CardID,
               SUM(CASE WHEN TransactionType = 'Consume' THEN Amount ELSE 0 END) AS TotalConsumeAmount
        FROM Transactions
        WHERE DATE(TransactionDate) = DATE_SUB(CURDATE(), INTERVAL 1 DAY)
          AND IsProcessed = 0
        GROUP BY CardID
    ) AS sub
    WHERE sub.TotalConsumeAmount >= 500
) AS sub ON t.CardID = sub.CardID
WHERE DATE(t.TransactionDate) = DATE_SUB(CURDATE(), INTERVAL 1 DAY)
  AND t.IsProcessed = 0;

UPDATE Transactions
SET IsProcessed = 1
WHERE TransactionID IN (SELECT TransactionID FROM temp_transactions_to_update);

DROP TEMPORARY TABLE IF EXISTS temp_transactions_to_update;



-- 减免明细及补贴金额相关表
DROP TABLE SubsidyDetails;
CREATE TABLE SubsidyDetails (
    SubsidyID INT PRIMARY KEY AUTO_INCREMENT,
    RestaurantID INT NOT NULL,
    DiscountID INT NOT NULL,
    DiscountAmount DECIMAL(10, 2) NOT NULL,
    SubsidyAmount DECIMAL(10, 2) NOT NULL,
    FOREIGN KEY (RestaurantID) REFERENCES Restaurants(RestaurantID),
    FOREIGN KEY (DiscountID) REFERENCES DiscountRules(DiscountID)
);



DROP PROCEDURE IF EXISTS ProvideSubsidy;

DELIMITER $$

CREATE PROCEDURE ProvideSubsidy()
BEGIN
    INSERT INTO SubsidyDetails (RestaurantID, DiscountID, DiscountAmount, SubsidyAmount)
    SELECT 
        tr.RestaurantID,
        1 AS DiscountID, -- 假设DiscountID为1
        SUM(CASE WHEN tr.TransactionType = 'Consume' THEN tr.Amount ELSE 0 END) DIV 500 * 30 AS DiscountAmount,
        SUM(CASE WHEN tr.TransactionType = 'Consume' THEN tr.Amount ELSE 0 END) DIV 500 * 10 AS SubsidyAmount
    FROM Transactions tr
    GROUP BY tr.RestaurantID;
-- 这是多此一举的，因为前面选择的条件就已经把其他没有的都不会选到了，
-- 即前面选择数据的时候已经是一个判断条件的过程了
END$$

DELIMITER ;

CALL ProvideSubsidy();


DROP PROCEDURE IF EXISTS OldDiscountDetails;

DELIMITER $$

CREATE PROCEDURE OldDiscountDetails()
BEGIN
    SELECT 
        tr.RestaurantID,
        SUM(CASE WHEN tr.TransactionType = 'Consume' THEN tr.Amount ELSE 0 END) DIV 500 * 30 AS DiscountAmount,
        SUM(CASE WHEN tr.TransactionType = 'Consume' THEN tr.Amount ELSE 0 END) DIV 500 * 10 AS SubsidyAmount,
        SUM(CASE WHEN tr.TransactionType = 'Consume' THEN tr.Amount ELSE 0 END) DIV 500 * (30 + 10) AS TotalAmount
    FROM Transactions tr
    GROUP BY tr.RestaurantID;
END$$

DELIMITER ;

CALL OldDiscountDetails();

