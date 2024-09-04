#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
//引用需要的库函数很重要

//// 定义学生信息结构体
//struct Student {
//    int studentId;
//    std::string name;
//    std::string dormitory;
//    std::string phoneNumber;
//};

class Student {
public:
    std::string studentId; // 学号
    std::string name; // 姓名
    std::string dormitory; // 宿舍
    std::string phoneNumber; // 电话号码
    std::string username; // 用户名
    std::string password; // 密码
    std::string userType; // 用户类型

    //算了不写用户权限了。我默认就是管理员就是有管理员的权限的。
    //你在多一个用户权限属实就是画蛇添足，多余的代码不写

    // 默认构造函数
    Student() {}
//写了这个才能构造对象

    Student(const std::string& id, const std::string& n, const std::string& dorm, const std::string& phone, const std::string& uname, const std::string& pwd, const std::string& type, const std::string& permission)
        : studentId(id), name(n), dormitory(dorm), phoneNumber(phone), username(uname), password(pwd), userType(type) {}
};


class HashTable {
public:
    static const int TABLE_SIZE = 100; // 哈希表大小

    HashTable() {
        table = new Student * [TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != nullptr) {
                delete table[i];
            }
        }
        delete[] table;
    }

    // 哈希函数：除留取余数法
    int hashFunction(const std::string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % TABLE_SIZE;
    }

    // 插入学生信息到哈希表
    void insert(const Student& student) {
        int index = hashFunction(student.name);
        while (table[index] != nullptr) {
            index = (index + 1) % TABLE_SIZE; // 线性探测法解决冲突
        }
        table[index] = new Student(student);
    }

    // 更新学生信息
    void update(const std::string& name, const Student& student) {
        int index = findIndex(name);
        if (index != -1) {
            delete table[index];
            table[index] = new Student(student);
            std::cout << "学生信息更新成功！" << std::endl;
        }
        else {
            std::cout << "学生信息不存在！" << std::endl;
        }
    }

    // 删除学生信息
    void remove(const std::string& name) {
        int index = findIndex(name);
        if (index != -1) {
            delete table[index];
            table[index] = nullptr;
        }
        else {
            std::cout << "学生信息不存在！" << std::endl;
        }
    }

    // 根据姓名查询学生信息
    void search(const std::string& name) {
        int index = findIndex(name);
        if (index != -1) {
            std::cout << "学号：" << table[index]->studentId << std::endl;
            std::cout << "姓名：" << table[index]->name << std::endl;
            std::cout << "宿舍：" << table[index]->dormitory << std::endl;
            std::cout << "电话号码：" << table[index]->phoneNumber << std::endl;
        }
        else {
            std::cout << "学生信息不存在！" << std::endl;
        }
    }

    // 设置用户类型
    void UserType(const std::string& name, const std::string& userType) {
        int index = findIndex(name);
        if (index != -1) {
            table[index]->userType = userType;
        }
        else {
            std::cout << "学生信息不存在！" << std::endl;
        }
    }

    // 设置登录信息
    int  LoginInfo(const std::string& name, const std::string& username, const std::string& password) {
        int index = findIndex(name);
        if (index != -1) {
            table[index]->username = username;
            table[index]->password = password;
            return 1;
        }
        else {
            std::cout << "学生信息不存在！" << std::endl;
            return -1;
        }
    }

    // 设置初始信息
    int  bulitInInfo(const std::string& name, const std::string& username, const std::string& password, const std::string& userType) {

        int index = hashFunction(name);//初始的时候不存在冲突问题，就跟插入信息是一个道理的
        //所以使用hashFunction而不是findIndex
        if (index != -1) {
            table[index] = new Student();// 创建一个 Student 对象并分配给 table[index]
            //不创建内存就会报错
            table[index]->username = username;
            table[index]->password = password;
            table[index]->userType = userType;
            return 1;
        }
        else {
            std::cout << "学生信息不存在！" << std::endl;
            return -1;
        }
    }
  
    // 保存哈希表到文件
    void saveToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (int i = 0; i < TABLE_SIZE; ++i) {
                if (table[i] != nullptr) {
                    file << table[i]->studentId << " "
                        << table[i]->name << " "
                        << table[i]->dormitory << " "
                        << table[i]->phoneNumber << " "
                        << table[i]->username << " "
                        << table[i]->password << " "
                        << table[i]->userType << "\n";
                }
            }
            file.close();
            std::cout << "哈希表保存到文件 '" << filename << "' 成功！" << std::endl;
        }
        else {
            std::cerr << "无法打开文件 '" << filename << "' 进行保存！" << std::endl;
        }
    }

    // 从文件加载哈希表
    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string id, name, dorm, phone, uname, pwd, type;
                iss >> id >> name >> dorm >> phone >> uname >> pwd >> type;
                Student student(id, name, dorm, phone, uname, pwd, type, "");
                insert(student);
            }
            file.close();
            std::cout << "从文件 '" << filename << "' 加载哈希表成功！" << std::endl;
        }
        else {
            std::cerr << "无法打开文件 '" << filename << "' 进行加载！" << std::endl;
        }
    }



public:
    Student** table; // 哈希表

    // 在哈希表中查找姓名对应的索引
    int findIndex(const std::string& name) {
        int index = hashFunction(name);
        int count = 0;
        while (table[index] != nullptr && table[index]->name != name) {//这里有问题
            index = (index + 1) % TABLE_SIZE; // 线性探测法解决冲突
            count++;
        }
        if (table[index] != nullptr && table[index]->name == name) {
            std::cout << "比较次数：" << count + 1 << std::endl;
            return index;
        }
        else {
            return -1;
        }
    }

    // 根据登录信息查找对应的索引
    int findIndexByLoginInfo(const std::string& username, const std::string& password) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != nullptr && table[i]->username == username && table[i]->password == password) {
                return i;
            }
        }
        return -1;
    }


    bool checkUser(const std::string& username, const std::string& password, const std::string& userType) {
        int index = findIndexByLoginInfo(username, password);//权限的值通过这个函数得出
        //通过用户名和密码取得唯一的索引值，从而导出一个唯一的权限
        if (index != -1 && table[index]->userType == userType) {
            return true;
        }
        else {
            return false;
        }
    }




};

//table[index]->userType这是内部设定的也就是一开始就在系统内部储存的数据或者添加好的，即权限设置
//而自己传入的userType是自己在系统中传入的选择的用户权限
//也就是选择以什么身份登录的这个操作
//这么做就是为了核对身份，内置的用户权限是否和你选择的用户权限对应。
//如果该用户权限不匹配就无法登陆，如果匹配才可成功


// 主菜单
void showMainMenu() {
    std::cout << "===== 班级通讯录 =====" << std::endl;
    std::cout << "1. 普通用户登录" << std::endl;
    std::cout << "2. 管理员登录" << std::endl;
    std::cout << "3. 从文件加载哈希表" << std::endl;
    std::cout << "4. 保存哈希表到文件" << std::endl;
    std::cout << "0. 退出" << std::endl;
    std::cout << "请输入选项：";
}

// 普通用户菜单
void showUserMenu() {
    std::cout << "===== 普通用户菜单 =====" << std::endl;
    std::cout << "1. 查询学生信息" << std::endl;
    std::cout << "0. 返回上级菜单" << std::endl;
    std::cout << "请输入选项：";
}

// 管理员菜单
void showAdminMenu() {
    std::cout << "===== 管理员菜单 =====" << std::endl;
    std::cout << "1. 用户管理" << std::endl;
    std::cout << "2. 通信录管理" << std::endl;
    std::cout << "0. 返回上级菜单" << std::endl;
    std::cout << "请输入选项：";
}

// 用户管理菜单
void showUserManageMenu() {
    std::cout << "===== 用户管理菜单 =====" << std::endl;
    std::cout << "1. 设置用户类别" << std::endl;
    std::cout << "2. 设置登录信息" << std::endl;
    std::cout << "0. 返回上级菜单" << std::endl;
    std::cout << "请输入选项：";
}

// 通信录管理菜单
void showAddressBookManageMenu() {
    std::cout << "===== 通信录管理菜单 =====" << std::endl;
    std::cout << "1. 添加学生信息" << std::endl;
    std::cout << "2. 更新学生信息" << std::endl;
    std::cout << "3. 删除学生信息" << std::endl;
    std::cout << "0. 返回上级菜单" << std::endl;
    std::cout << "请输入选项：";
}




// 添加学生信息
void addStudentInfo(HashTable& hashTable) {
    Student student;
    std::cout << "请输入学号：";
    std::cin >> student.studentId;
    std::cout << "请输入姓名：";
    std::cin >> student.name;
    std::cout << "请输入宿舍：";
    std::cin >> student.dormitory;
    std::cout << "请输入电话号码：";
    std::cin >> student.phoneNumber;
    hashTable.insert(student);
    std::cout << "学生信息添加成功！" << std::endl;
}




// 更新学生信息
void updateStudentInfo(HashTable& hashTable) {
    //哦，我知道问题出在哪里了。我在更新学生信息的时候前面是已经删除了之前的table用新的table
    //来记录数据的。
    //你在更新数据的时候没有吧名字输入进Student对象中，自然在findIndex这个函数中
    //使得  while (table[index] != nullptr && table[index]->name != name)
    //    中的table[index]->name != name不相等了(因为你更新数据没有把名字重新添加回去)

    std::string name;
    std::cout << "请输入要更新信息的学生姓名：";
    std::cin >> name;
    int index = hashTable.findIndex(name);
    if (index != -1) {
        Student student;
       
        student.name = name;
        //记住，名字也要重新插入一次，
        // 不然索引寻找的时候找不到名字就直接失败输出错误数据了！
        std::cout << "请输入学号：";
        std::cin >> student.studentId;
        std::cout << "请输入宿舍：";
        std::cin >> student.dormitory;
        std::cout << "请输入电话号码：";
        std::cin >> student.phoneNumber;
    hashTable.update(name, student);
      
       
    }
    else
    {
        std::cout << "不存在该学生！" << std::endl;
    }
}
//终于改对了真的哭死，
// 果然问题就出在没有重新插入name的值导致索引丢失找不到数据了

// 删除学生信息
void removeStudentInfo(HashTable& hashTable) {
    std::string name;
    std::cout << "请输入要删除的学生姓名：";
    std::cin >> name;
    hashTable.remove(name);
    std::cout << "学生信息删除成功！" << std::endl;
}


// 设置用户类型
void setUserType(HashTable& hashTable) {
    std::string name;
    std::cout << "请输入要设置用户类型的学生姓名：";
    std::cin >> name;
   std::string userType;
   std::cout << "请输入要设置用户类型：1.普通用户权限 2.管理员权限";
   std::cin >> userType;
    hashTable.UserType(name,userType);
    std::cout << "学生用户类型设置成功！" << std::endl;
    
}

// 设置登录信息
//2. 登录信息（Login Information）：
//登录信息包括用户名和密码。
//可以将用户名和密码保存在用户对象中，
//用户登录时需要输入用户名和密码，
//程序通过匹配输入的用户名和密码
//与已有用户对象中的用户名和密码是否一致来判断是否登录成功。
void setLoginInfo(HashTable& hashTable) {
    std::string name;
    std::cout << "请输入你要更新登录信息的学生姓名：";
    std::cin >> name;
    std::string username;
    std::cout << "请输入新的用户名：";
    std::cin >> username;
    std::string password;
    std::cout << "请输入新的密码：";
    std::cin >> password;
    if(hashTable.LoginInfo(name, username, password)== 1)
    std::cout << "学生登录信息设置成功！" << std::endl;

}


//设置内置用户
void builtInUsers(HashTable& hashTable) {



    std::string name,username,password, userType;
    name = "K";
    username = "kurumi";
    password = "kurumi1314";
    userType = "2";
    hashTable.bulitInInfo(name, username, password, userType);

   

}




// 程序入口函数


int main() {
    HashTable hashTable;

    //开始必须要内置一个管理员用户，不然无法实现插入用户的功能
    //所以一开始必须要建立一个默认的管理员账户，普通用户可以不用
//内置用户
    builtInUsers(hashTable);
//kurumi kurumi1314


    while (true) {
        showMainMenu();
        int option;
        std::cin >> option;
        //开局输入选择，
        // 作为选中的当前的权限，为了与后面的用户权限作对比
        std::string userType = std::to_string(option);//将整型的值导入进userType中调用
        //to_string转换类型，不能直接赋值，不然字符输出结果不同不匹配登录失败！

        switch (option) {
        case 1: {
            // 普通用户登录
            std::string username, password;
            std::cout << "请输入用户名：";
            std::cin >> username;
            std::cout << "请输入密码：";
            std::cin >> password;

            // 在哈希表中查找用户名和密码是否匹配
            if (hashTable.checkUser(username, password, userType)) {
                std::cout << "登录成功！" << std::endl;
                //这个userType是用来检测用户权限的。是用来判断用户到底是什么身份的
                //就是为了区分普通用户和管理员用户的区别

             /*   用户名和密码对应唯一的一个索引，那我跟什么比较值呢？*/


                bool loggedIn = true; // 登录成功
                if (loggedIn) {
                    while (true) {
                        showUserMenu();
                        std::cin >> option;
                        if (option == 1) {
                            std::string name;
                            std::cout << "请输入要查询的学生姓名：";
                            std::cin >> name;
                            hashTable.search(name);
                        }
                        else if (option == 0) {
                            break;
                        }
                        else {
                            std::cout << "无效选项！" << std::endl;
                        }
                    }
                }
            }
            else {
                std::cout << "用户名或密码错误，登录失败！" << std::endl;
            }

            break;
        }
        case 2: {
            // 管理员登录
            std::string username, password;
            std::cout << "请输入用户名：";
            std::cin >> username;
            std::cout << "请输入密码：";
            std::cin >> password;

            if (hashTable.checkUser(username, password, userType)) {
                std::cout << "登录成功！" << std::endl;
                bool loggedIn = true; // 假设登录成功
                if (loggedIn) {
                    while (true) {
                        showAdminMenu();
                        std::cin >> option;
                        if (option == 1) {
                            while (true) {
                                showUserManageMenu();
                                std::cin >> option;
                                if (option == 1) {
                                    setUserType(hashTable);
                                }
                                else if (option == 2) {
                                    setLoginInfo(hashTable);
                                }
                              
                                else if (option == 0) {
                                    break;
                                }
                                else {
                                    std::cout << "无效选项！" << std::endl;
                                }
                            }
                        }
                        else if (option == 2) {
                            while (true) {
                                showAddressBookManageMenu();
                                std::cin >> option;
                                if (option == 1) {
                                    addStudentInfo(hashTable);
                                }
                                else if (option == 2) {
                                    updateStudentInfo(hashTable);
                                }
                                else if (option == 3) {
                                    removeStudentInfo(hashTable);
                                }
                                else if (option == 0) {
                                    break;
                                }
                                else {
                                    std::cout << "无效选项！" << std::endl;
                                }
                            }
                        }
                        else if (option == 0) {
                            break;
                        }
                        else {
                            std::cout << "无效选项！" << std::endl;
                        }
                    }
                }
            }

            else {
                std::cout << "用户名或密码错误，登录失败！" << std::endl;
            }
            break;
        }
              case 3:
                  // 从文件加载哈希表
                  hashTable.loadFromFile("students.txt");
                  break;
              case 4:
  // 保存哈希表到文件
                  hashTable.saveToFile("students.txt");
                  break;
        case 0:
            // 退出程序
            return 0;
        default:
            std::cout << "无效选项！" << std::endl;
        }
    }

    return 0;
}

 

