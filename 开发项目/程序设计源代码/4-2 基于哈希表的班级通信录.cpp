#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
//������Ҫ�Ŀ⺯������Ҫ

//// ����ѧ����Ϣ�ṹ��
//struct Student {
//    int studentId;
//    std::string name;
//    std::string dormitory;
//    std::string phoneNumber;
//};

class Student {
public:
    std::string studentId; // ѧ��
    std::string name; // ����
    std::string dormitory; // ����
    std::string phoneNumber; // �绰����
    std::string username; // �û���
    std::string password; // ����
    std::string userType; // �û�����

    //���˲�д�û�Ȩ���ˡ���Ĭ�Ͼ��ǹ���Ա�����й���Ա��Ȩ�޵ġ�
    //���ڶ�һ���û�Ȩ����ʵ���ǻ������㣬����Ĵ��벻д

    // Ĭ�Ϲ��캯��
    Student() {}
//д��������ܹ������

    Student(const std::string& id, const std::string& n, const std::string& dorm, const std::string& phone, const std::string& uname, const std::string& pwd, const std::string& type, const std::string& permission)
        : studentId(id), name(n), dormitory(dorm), phoneNumber(phone), username(uname), password(pwd), userType(type) {}
};


class HashTable {
public:
    static const int TABLE_SIZE = 100; // ��ϣ���С

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

    // ��ϣ����������ȡ������
    int hashFunction(const std::string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % TABLE_SIZE;
    }

    // ����ѧ����Ϣ����ϣ��
    void insert(const Student& student) {
        int index = hashFunction(student.name);
        while (table[index] != nullptr) {
            index = (index + 1) % TABLE_SIZE; // ����̽�ⷨ�����ͻ
        }
        table[index] = new Student(student);
    }

    // ����ѧ����Ϣ
    void update(const std::string& name, const Student& student) {
        int index = findIndex(name);
        if (index != -1) {
            delete table[index];
            table[index] = new Student(student);
            std::cout << "ѧ����Ϣ���³ɹ���" << std::endl;
        }
        else {
            std::cout << "ѧ����Ϣ�����ڣ�" << std::endl;
        }
    }

    // ɾ��ѧ����Ϣ
    void remove(const std::string& name) {
        int index = findIndex(name);
        if (index != -1) {
            delete table[index];
            table[index] = nullptr;
        }
        else {
            std::cout << "ѧ����Ϣ�����ڣ�" << std::endl;
        }
    }

    // ����������ѯѧ����Ϣ
    void search(const std::string& name) {
        int index = findIndex(name);
        if (index != -1) {
            std::cout << "ѧ�ţ�" << table[index]->studentId << std::endl;
            std::cout << "������" << table[index]->name << std::endl;
            std::cout << "���᣺" << table[index]->dormitory << std::endl;
            std::cout << "�绰���룺" << table[index]->phoneNumber << std::endl;
        }
        else {
            std::cout << "ѧ����Ϣ�����ڣ�" << std::endl;
        }
    }

    // �����û�����
    void UserType(const std::string& name, const std::string& userType) {
        int index = findIndex(name);
        if (index != -1) {
            table[index]->userType = userType;
        }
        else {
            std::cout << "ѧ����Ϣ�����ڣ�" << std::endl;
        }
    }

    // ���õ�¼��Ϣ
    int  LoginInfo(const std::string& name, const std::string& username, const std::string& password) {
        int index = findIndex(name);
        if (index != -1) {
            table[index]->username = username;
            table[index]->password = password;
            return 1;
        }
        else {
            std::cout << "ѧ����Ϣ�����ڣ�" << std::endl;
            return -1;
        }
    }

    // ���ó�ʼ��Ϣ
    int  bulitInInfo(const std::string& name, const std::string& username, const std::string& password, const std::string& userType) {

        int index = hashFunction(name);//��ʼ��ʱ�򲻴��ڳ�ͻ���⣬�͸�������Ϣ��һ�������
        //����ʹ��hashFunction������findIndex
        if (index != -1) {
            table[index] = new Student();// ����һ�� Student ���󲢷���� table[index]
            //�������ڴ�ͻᱨ��
            table[index]->username = username;
            table[index]->password = password;
            table[index]->userType = userType;
            return 1;
        }
        else {
            std::cout << "ѧ����Ϣ�����ڣ�" << std::endl;
            return -1;
        }
    }
  
    // �����ϣ���ļ�
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
            std::cout << "��ϣ���浽�ļ� '" << filename << "' �ɹ���" << std::endl;
        }
        else {
            std::cerr << "�޷����ļ� '" << filename << "' ���б��棡" << std::endl;
        }
    }

    // ���ļ����ع�ϣ��
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
            std::cout << "���ļ� '" << filename << "' ���ع�ϣ��ɹ���" << std::endl;
        }
        else {
            std::cerr << "�޷����ļ� '" << filename << "' ���м��أ�" << std::endl;
        }
    }



public:
    Student** table; // ��ϣ��

    // �ڹ�ϣ���в���������Ӧ������
    int findIndex(const std::string& name) {
        int index = hashFunction(name);
        int count = 0;
        while (table[index] != nullptr && table[index]->name != name) {//����������
            index = (index + 1) % TABLE_SIZE; // ����̽�ⷨ�����ͻ
            count++;
        }
        if (table[index] != nullptr && table[index]->name == name) {
            std::cout << "�Ƚϴ�����" << count + 1 << std::endl;
            return index;
        }
        else {
            return -1;
        }
    }

    // ���ݵ�¼��Ϣ���Ҷ�Ӧ������
    int findIndexByLoginInfo(const std::string& username, const std::string& password) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != nullptr && table[i]->username == username && table[i]->password == password) {
                return i;
            }
        }
        return -1;
    }


    bool checkUser(const std::string& username, const std::string& password, const std::string& userType) {
        int index = findIndexByLoginInfo(username, password);//Ȩ�޵�ֵͨ����������ó�
        //ͨ���û���������ȡ��Ψһ������ֵ���Ӷ�����һ��Ψһ��Ȩ��
        if (index != -1 && table[index]->userType == userType) {
            return true;
        }
        else {
            return false;
        }
    }




};

//table[index]->userType�����ڲ��趨��Ҳ����һ��ʼ����ϵͳ�ڲ���������ݻ�����Ӻõģ���Ȩ������
//���Լ������userType���Լ���ϵͳ�д����ѡ����û�Ȩ��
//Ҳ����ѡ����ʲô��ݵ�¼���������
//��ô������Ϊ�˺˶���ݣ����õ��û�Ȩ���Ƿ����ѡ����û�Ȩ�޶�Ӧ��
//������û�Ȩ�޲�ƥ����޷���½�����ƥ��ſɳɹ�


// ���˵�
void showMainMenu() {
    std::cout << "===== �༶ͨѶ¼ =====" << std::endl;
    std::cout << "1. ��ͨ�û���¼" << std::endl;
    std::cout << "2. ����Ա��¼" << std::endl;
    std::cout << "3. ���ļ����ع�ϣ��" << std::endl;
    std::cout << "4. �����ϣ���ļ�" << std::endl;
    std::cout << "0. �˳�" << std::endl;
    std::cout << "������ѡ�";
}

// ��ͨ�û��˵�
void showUserMenu() {
    std::cout << "===== ��ͨ�û��˵� =====" << std::endl;
    std::cout << "1. ��ѯѧ����Ϣ" << std::endl;
    std::cout << "0. �����ϼ��˵�" << std::endl;
    std::cout << "������ѡ�";
}

// ����Ա�˵�
void showAdminMenu() {
    std::cout << "===== ����Ա�˵� =====" << std::endl;
    std::cout << "1. �û�����" << std::endl;
    std::cout << "2. ͨ��¼����" << std::endl;
    std::cout << "0. �����ϼ��˵�" << std::endl;
    std::cout << "������ѡ�";
}

// �û�����˵�
void showUserManageMenu() {
    std::cout << "===== �û�����˵� =====" << std::endl;
    std::cout << "1. �����û����" << std::endl;
    std::cout << "2. ���õ�¼��Ϣ" << std::endl;
    std::cout << "0. �����ϼ��˵�" << std::endl;
    std::cout << "������ѡ�";
}

// ͨ��¼����˵�
void showAddressBookManageMenu() {
    std::cout << "===== ͨ��¼����˵� =====" << std::endl;
    std::cout << "1. ���ѧ����Ϣ" << std::endl;
    std::cout << "2. ����ѧ����Ϣ" << std::endl;
    std::cout << "3. ɾ��ѧ����Ϣ" << std::endl;
    std::cout << "0. �����ϼ��˵�" << std::endl;
    std::cout << "������ѡ�";
}




// ���ѧ����Ϣ
void addStudentInfo(HashTable& hashTable) {
    Student student;
    std::cout << "������ѧ�ţ�";
    std::cin >> student.studentId;
    std::cout << "������������";
    std::cin >> student.name;
    std::cout << "���������᣺";
    std::cin >> student.dormitory;
    std::cout << "������绰���룺";
    std::cin >> student.phoneNumber;
    hashTable.insert(student);
    std::cout << "ѧ����Ϣ��ӳɹ���" << std::endl;
}




// ����ѧ����Ϣ
void updateStudentInfo(HashTable& hashTable) {
    //Ŷ����֪��������������ˡ����ڸ���ѧ����Ϣ��ʱ��ǰ�����Ѿ�ɾ����֮ǰ��table���µ�table
    //����¼���ݵġ�
    //���ڸ������ݵ�ʱ��û�а����������Student�����У���Ȼ��findIndex���������
    //ʹ��  while (table[index] != nullptr && table[index]->name != name)
    //    �е�table[index]->name != name�������(��Ϊ���������û�а�����������ӻ�ȥ)

    std::string name;
    std::cout << "������Ҫ������Ϣ��ѧ��������";
    std::cin >> name;
    int index = hashTable.findIndex(name);
    if (index != -1) {
        Student student;
       
        student.name = name;
        //��ס������ҲҪ���²���һ�Σ�
        // ��Ȼ����Ѱ�ҵ�ʱ���Ҳ������־�ֱ��ʧ��������������ˣ�
        std::cout << "������ѧ�ţ�";
        std::cin >> student.studentId;
        std::cout << "���������᣺";
        std::cin >> student.dormitory;
        std::cout << "������绰���룺";
        std::cin >> student.phoneNumber;
    hashTable.update(name, student);
      
       
    }
    else
    {
        std::cout << "�����ڸ�ѧ����" << std::endl;
    }
}
//���ڸĶ�����Ŀ�����
// ��Ȼ����ͳ���û�����²���name��ֵ����������ʧ�Ҳ���������

// ɾ��ѧ����Ϣ
void removeStudentInfo(HashTable& hashTable) {
    std::string name;
    std::cout << "������Ҫɾ����ѧ��������";
    std::cin >> name;
    hashTable.remove(name);
    std::cout << "ѧ����Ϣɾ���ɹ���" << std::endl;
}


// �����û�����
void setUserType(HashTable& hashTable) {
    std::string name;
    std::cout << "������Ҫ�����û����͵�ѧ��������";
    std::cin >> name;
   std::string userType;
   std::cout << "������Ҫ�����û����ͣ�1.��ͨ�û�Ȩ�� 2.����ԱȨ��";
   std::cin >> userType;
    hashTable.UserType(name,userType);
    std::cout << "ѧ���û��������óɹ���" << std::endl;
    
}

// ���õ�¼��Ϣ
//2. ��¼��Ϣ��Login Information����
//��¼��Ϣ�����û��������롣
//���Խ��û��������뱣�����û������У�
//�û���¼ʱ��Ҫ�����û��������룬
//����ͨ��ƥ��������û���������
//�������û������е��û����������Ƿ�һ�����ж��Ƿ��¼�ɹ���
void setLoginInfo(HashTable& hashTable) {
    std::string name;
    std::cout << "��������Ҫ���µ�¼��Ϣ��ѧ��������";
    std::cin >> name;
    std::string username;
    std::cout << "�������µ��û�����";
    std::cin >> username;
    std::string password;
    std::cout << "�������µ����룺";
    std::cin >> password;
    if(hashTable.LoginInfo(name, username, password)== 1)
    std::cout << "ѧ����¼��Ϣ���óɹ���" << std::endl;

}


//���������û�
void builtInUsers(HashTable& hashTable) {



    std::string name,username,password, userType;
    name = "K";
    username = "kurumi";
    password = "kurumi1314";
    userType = "2";
    hashTable.bulitInInfo(name, username, password, userType);

   

}




// ������ں���


int main() {
    HashTable hashTable;

    //��ʼ����Ҫ����һ������Ա�û�����Ȼ�޷�ʵ�ֲ����û��Ĺ���
    //����һ��ʼ����Ҫ����һ��Ĭ�ϵĹ���Ա�˻�����ͨ�û����Բ���
//�����û�
    builtInUsers(hashTable);
//kurumi kurumi1314


    while (true) {
        showMainMenu();
        int option;
        std::cin >> option;
        //��������ѡ��
        // ��Ϊѡ�еĵ�ǰ��Ȩ�ޣ�Ϊ���������û�Ȩ�����Ա�
        std::string userType = std::to_string(option);//�����͵�ֵ�����userType�е���
        //to_stringת�����ͣ�����ֱ�Ӹ�ֵ����Ȼ�ַ���������ͬ��ƥ���¼ʧ�ܣ�

        switch (option) {
        case 1: {
            // ��ͨ�û���¼
            std::string username, password;
            std::cout << "�������û�����";
            std::cin >> username;
            std::cout << "���������룺";
            std::cin >> password;

            // �ڹ�ϣ���в����û����������Ƿ�ƥ��
            if (hashTable.checkUser(username, password, userType)) {
                std::cout << "��¼�ɹ���" << std::endl;
                //���userType����������û�Ȩ�޵ġ��������ж��û�������ʲô��ݵ�
                //����Ϊ��������ͨ�û��͹���Ա�û�������

             /*   �û����������ӦΨһ��һ�����������Ҹ�ʲô�Ƚ�ֵ�أ�*/


                bool loggedIn = true; // ��¼�ɹ�
                if (loggedIn) {
                    while (true) {
                        showUserMenu();
                        std::cin >> option;
                        if (option == 1) {
                            std::string name;
                            std::cout << "������Ҫ��ѯ��ѧ��������";
                            std::cin >> name;
                            hashTable.search(name);
                        }
                        else if (option == 0) {
                            break;
                        }
                        else {
                            std::cout << "��Чѡ�" << std::endl;
                        }
                    }
                }
            }
            else {
                std::cout << "�û�����������󣬵�¼ʧ�ܣ�" << std::endl;
            }

            break;
        }
        case 2: {
            // ����Ա��¼
            std::string username, password;
            std::cout << "�������û�����";
            std::cin >> username;
            std::cout << "���������룺";
            std::cin >> password;

            if (hashTable.checkUser(username, password, userType)) {
                std::cout << "��¼�ɹ���" << std::endl;
                bool loggedIn = true; // �����¼�ɹ�
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
                                    std::cout << "��Чѡ�" << std::endl;
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
                                    std::cout << "��Чѡ�" << std::endl;
                                }
                            }
                        }
                        else if (option == 0) {
                            break;
                        }
                        else {
                            std::cout << "��Чѡ�" << std::endl;
                        }
                    }
                }
            }

            else {
                std::cout << "�û�����������󣬵�¼ʧ�ܣ�" << std::endl;
            }
            break;
        }
              case 3:
                  // ���ļ����ع�ϣ��
                  hashTable.loadFromFile("students.txt");
                  break;
              case 4:
  // �����ϣ���ļ�
                  hashTable.saveToFile("students.txt");
                  break;
        case 0:
            // �˳�����
            return 0;
        default:
            std::cout << "��Чѡ�" << std::endl;
        }
    }

    return 0;
}

 

