import java.io.*;
import java.util.*;

class Person implements Serializable 
{
	 protected String id;  //员工编号
	    protected String name;  //姓名
	    protected String gender;  //性别
	    protected int age;  //年龄
	    
	    Person(String id, String name, String gender, int age) {
	        this.id = id;
	        this.name = name;
	        this.gender = gender;
	        this.age = age;
	    }
	    
	    void display()
	    {
	    	
	    }

}

class Teacher extends Person implements Serializable {
	protected String department;  //所在系部
	protected String major;  //专业
	protected String title;  //职称

    Teacher(String id, String name, String gender, int age, String department, String major, String title) {
        super(id, name, gender, age);//调用父类构造方法的语句
        //就是为了插入前面的数据， 不调用就不能将信息插入到父类中使用
        this.department = department;
        this.major = major;
        this.title = title;
    }
    
    void display() {  //显示教师信息
        System.out.println("编号：" + id + "，姓名：" + name + "，性别：" + gender + "，年龄：" + age
            + "，所在系部：" + department + "，专业：" + major + "，职称：" + title);
    }

}

class LaboratoryStaff extends Person implements Serializable {
	protected String laboratory;  //所在实验室
	protected String duty;  //职务

    LaboratoryStaff(String id, String name, String gender, int age, String laboratory, String duty) {
        super(id, name, gender, age);
        this.laboratory = laboratory;
        this.duty = duty;
    }
    
    void display() {  //显示实验员信息
        System.out.println("编号：" + id + "，姓名：" + name + "，性别：" + gender + "，年龄：" + age
            + "，所在实验室：" + laboratory + "，职务：" + duty);
    }

    }

class Administrator extends Person implements Serializable  {
	protected String politicalStatus;  //政治面貌
	protected String title;  //职称

    Administrator(String id, String name, String gender, int age, String politicalStatus, String title) {
        super(id, name, gender, age);
        this.politicalStatus = politicalStatus;
        this.title = title;
    }
    
    void display() {  //显示行政人员信息
        System.out.println("编号：" + id + "，姓名：" + name + "，性别：" + gender + "，年龄：" + age
            + "，政治面貌：" + politicalStatus + "，职称：" + title);
    }

    }

class TeacherAdministrator extends Teacher implements Serializable 
{
	protected String politicalStatus;  //政治面貌

    TeacherAdministrator(String id, String name, String gender, int age, String department, String major, String title,String politicalStatus) {
        super(id, name, gender, age,department,major,title);//调用父类构造方法的语句
        //就是为了插入前面的数据， 不调用就不能将信息插入到父类中使用
        this.politicalStatus=politicalStatus;
      
    }
    
	void display() {  //显示教师兼行政人员信息
	    System.out.println("编号：" + id + "，姓名：" + name + "，性别：" + gender + "，年龄：" + age
	        + "，所在系部：" + department + "，专业：" + major + "，职称：" + title + "，政治面貌：" + politicalStatus);
	}

}


class PersonManager//信息管理系统
{
	private static Scanner input=new Scanner(System.in);
	private Person persons[]=new Person[1000];//人的个数
	private int count =0;//记录人的数量，也就是数据个数
	
	
	//用equals语句来判断是否存在重复id
	private boolean idExists(String id)//判断id是否存在的方法
	{
		for(int i=0;i<count;i++)
			if(persons[i].id.equals(id))
				return true;
		return false;
	}
	
	private int findIndexById(String id)//查找id的方法
	{
		for(int i=0;i<count;i++)
			if(persons[i].id.equals(id))
				return i;
		
		return -1;
	}
	
	//添加人物的时候，只需要将数据插入到类中即可！
	void addPerson()//添加功能
	{
		   System.out.println("请选择要添加的人员类别：1.教师 2.实验员 3.行政人员 4.教师兼行政人员");
		   int choice=input.nextInt();
		   String id, name, gender;
	        int age;
	        System.out.println("请输入员工编号:");
	        id=input.next();
	        System.out.println("请输入姓名：");
	        name = input.next();
	        System.out.println("请输入性别：");
	        gender = input.next();
	        System.out.println("请输入年龄：");
	        age = input.nextInt();
		   
	        if(idExists(id))
	        {
	        	 System.out.println("编号已存在，无法添加！");
	        	 return;//返回去重新选择
	        }
		   
		   
		   switch(choice)
		   {
		   case 1:
			   String department, major, title;
               System.out.println("请输入所在系部：");
               department = input.next();
               System.out.println("请输入专业：");
               major = input.next();
               System.out.println("请输入职称：");
               title = input.next();
               persons[count++]=new Teacher(id, name, gender, age, department, major, title);
            		//使用persons开辟空间储存，调用teacher方法
            		   //不能使用teacher作为类，因为teacher没有开辟空间
               break;//不要漏写break!
               //不然会直接遍历到下一个case
		   case 2:
               String laboratory, duty;
               System.out.println("请输入所在实验室：");
               laboratory = input.next();
               System.out.println("请输入职务：");
               duty = input.next();
               persons[count++] = new LaboratoryStaff(id, name, gender, age, laboratory, duty);
               break;
           case 3:
               String politicalStatus, adminTitle;
               System.out.println("请输入政治面貌：");
               politicalStatus = input.next();
               System.out.println("请输入职称：");
               adminTitle = input.next();
               persons[count++] = new Administrator(id, name, gender, age, politicalStatus, adminTitle);
               break;	   
           case 4:
        	   //教师兼行政人员多了属性，因此要使用继承来更新使用新的类！
        	   //即在教师的基础上多个政治面貌
        	   //String department, major, title,politicalStatus;
        	   //switch中声明的变量都是共享的，只要在这里面都是公用的！
        	   System.out.println("请输入所在系部：");
               department = input.next();
               System.out.println("请输入专业：");
               major = input.next();
               System.out.println("请输入职称：");
               title = input.next();
               System.out.println("请输入政治面貌：");
               politicalStatus = input.next();
        	   persons[count++] = new TeacherAdministrator(id, name, gender, age,department,major,title,politicalStatus);
        	   break;	
        	   
        	   
            		   
               
		   }
		   System.out.println("数据添加成功！");//可读性
	}
	
	void searchPerson()//查询功能
	{
		System.out.println("请选择查询方式：1.编号 2.姓名");
		String keyword;
		int choice=input.nextInt();
		
		boolean found =false;
		 System.out.println("请输入查询关键字：");
	        keyword = input.next();
		for(int i=0;i<count;i++)
			//因为有可能姓名会同名，不同编号同名，所以不能输出数据直接break
		{
			if(choice==1&&persons[i].id.equals(keyword))
			{
					found=true;
			      persons[i].display();
			      //因为数据是在person的类中而不是系统中，所以要
			      //把display方法写在person的类中
			}
			
			else if(choice==2&&persons[i].name.equals(keyword))
			{
				found=true;
				 persons[i].display();
			}
				
			
		}
		if(!found)
		{
			System.out.println("未找到相应的记录！");
		}
		
	}
	
	void displayAll()//展示功能
	{
		if(count==0)
		{
		    System.out.println("记录为空！");
			return;
		}
		
		System.out.println("系统中共有" + count + "条记录，详情如下：");
		for(int i=0;i<count;i++)
		{
			persons[i].display();
		}
	}
	
	void editPerson()//编辑功能
	{
		System.out.println("请输入要修改的人员信息编号：");
		String id=input.next();
		
	int	index=findIndexById(id);//寻找下标
		if(index==-1)
		{
			System.out.println("未找到相应的记录！");
			return;
		}
		
		  persons[index].display();
  	    System.out.println("请选择要修改的内容：1.姓名 2.性别 3.年龄");
//不改编号，因为编号是唯一的！
		
  	  if (persons[index] instanceof Teacher) {
	        System.out.println("4.所在系部 5.专业 6.职称");
	    } else if (persons[index] instanceof LaboratoryStaff) {
	        System.out.println("4.所在实验室 5.职务");
	    } else if (persons[index] instanceof Administrator) {
	        System.out.println("4.政治面貌 5.职称");
	    } else if (persons[index] instanceof TeacherAdministrator) {
	        System.out.println("4.所在系部 5.专业 6.职称 7.政治面貌");
	    }


  	  int choice = input.nextInt();
	    switch (choice) {
	        case 1:
	            System.out.println("请输入新的姓名：");
	            persons[index].name = input.next();
	            break;//记得写break;免得一直遍历下去
	        case 2:
	            System.out.println("请输入新的性别：");
	            persons[index].gender = input.next();
	            break;
	        case 3:
	            System.out.println("请输入新的年龄：");
	            persons[index].age = input.nextInt();
	            break;
		//职业的case
	            //判断是哪个类,因为职业的成员都是不同的
	        case 4:
	            if (persons[index] instanceof Teacher || persons[index] instanceof TeacherAdministrator) {
	                System.out.println("请输入新的所在系部：");
	                ((Teacher) persons[index]).department = input.next();
	            } else if (persons[index] instanceof LaboratoryStaff) {
	                System.out.println("请输入新的所在实验室：");
	                ((LaboratoryStaff) persons[index]).laboratory = input.next();
	            } else if (persons[index] instanceof Administrator) {
	                System.out.println("请输入新的政治面貌：");
	                ((Administrator) persons[index]).politicalStatus = input.next();
	            }
	            break;
	        case 5:
	            if (persons[index] instanceof Teacher || persons[index] instanceof TeacherAdministrator) {
	                System.out.println("请输入新的专业：");
	                ((Teacher) persons[index]).major = input.next();
	            } else if (persons[index] instanceof LaboratoryStaff) {
	                System.out.println("请输入新的职务：");
	                ((LaboratoryStaff) persons[index]).duty = input.next();
	            } else if (persons[index] instanceof Administrator) {
	                System.out.println("请输入新的职称：");
	                ((Administrator) persons[index]).title = input.next();
	            } else if (persons[index] instanceof TeacherAdministrator) {
	                System.out.println("请输入新的专业：");
	                ((TeacherAdministrator) persons[index]).major = input.next();
	            }
	            break;
	        case 6:
	            if (persons[index] instanceof Teacher || persons[index] instanceof TeacherAdministrator) {
	                System.out.println("请输入新的职称：");
	                ((Teacher) persons[index]).title = input.next();
	            } else if (persons[index] instanceof Administrator) {
	                System.out.println("请输入新的职称：");
	                ((Administrator) persons[index]).title = input.next();
	            } else if (persons[index] instanceof TeacherAdministrator) {
	                System.out.println("请输入新的职称：");
	                ((TeacherAdministrator) persons[index]).title = input.next();
	            }
	            break;
	        case 7:
	            if (persons[index] instanceof TeacherAdministrator) {
	                System.out.println("请输入新的政治面貌：");
	                ((TeacherAdministrator) persons[index]).politicalStatus = input.next();
	            }
	            break;
	        default:
	            System.out.println("请输入正确的选择！");
	            break;
	    }
		
	    System.out.println("修改成功！");
			
		}
		
		
		
		
			
	
	
	void deletePerson()//删除功能
	{
		  System.out.println("请输入要删除的人员信息编号：");
		  String id=input.next();
		  
		  int index=findIndexById(id);
		  if(index==-1)
		  {
			  System.out.println("未找到相应的记录！");
			  return;
		  }
		  
		  for(int i=index;i<count-1;i++)
		  {
			  persons[i]=persons[i+1];
		  }
		  
		  count--;
		  System.out.println("删除成功！");
	}
	
	void statistic()//统计人数
	{
		  int teacherCount = 0;           // 教师数量
  	    int labStaffCount = 0;          // 实验室人员数量
  	    int adminCount = 0;             // 管理员数量
  	    int teacherAdminCount = 0;      // 教师兼行政人员数量
  	    int maleCount = 0;              // 男性数量
  	    int femaleCount = 0;            // 女性数量

  	    for (int i = 0; i < count; i++) {
  	        if (persons[i] instanceof Teacher) {
  	            teacherCount++;
  	        } else if (persons[i] instanceof LaboratoryStaff) {
  	            labStaffCount++;
  	        } else if (persons[i] instanceof Administrator) {
  	            adminCount++;
  	        } else if (persons[i] instanceof TeacherAdministrator) {
  	            teacherAdminCount++;
  	        }

  	        if (persons[i].gender.equals("男")) {
  	            maleCount++;
  	        } else if (persons[i].gender.equals("女")) {
  	            femaleCount++;
  	        }
  	    }

  	    System.out.println("教师数量：" + teacherCount);
  	    System.out.println("实验室人员数量：" + labStaffCount);
  	    System.out.println("管理员数量：" + adminCount);
  	    System.out.println("教师兼行政人员数量：" + teacherAdminCount);
  	    System.out.println("男性数量：" + maleCount);
  	    System.out.println("女性数量：" + femaleCount);
	}
  

    	//将人员信息写入文件
    	void writeToFile() {
    	    try {
    	    	File file=new File("person.dat");
    	    	if(!file.exists())
    	    	{
    	    		file.createNewFile();
    	    	}
    	    	
    	        FileOutputStream fos = new FileOutputStream(file);
    	        ObjectOutputStream oos = new ObjectOutputStream(fos);
    	        oos.writeObject(persons);
    	        oos.writeInt(count);
    	        oos.close();
    	        fos.close();
    	        System.out.println("保存数据成功!");
    	    } catch (IOException e) {
    	        e.printStackTrace();
    	    }
    	}
    	
     	//从文件中读取人员信息
        void readFromFile() {
        	    try {
        	        File file = new File("person.dat");
        	        //给文件在编译器中申请空间
        	        if (file.exists()) {
        	            FileInputStream fis = new FileInputStream(file);
        	            ObjectInputStream ois = new ObjectInputStream(fis);
        	            persons = (Person[]) ois.readObject();
        	            //写(Person[]) 是为了安全转换成Person[]的类型
        	            count = ois.readInt();
        	            ois.close();
        	            fis.close();
        	            
        	            System.out.println("读取数据成功!");
        	        }
        	    } catch (FileNotFoundException e) {
        	        System.out.println("文件不存在！");
        	    } catch (IOException e) {
        	        e.printStackTrace();
        	    } catch (ClassNotFoundException e) {
        	        e.printStackTrace();
        	    }
        	}
	
}
public class Test {
	public static void main(String args[])
	{
    	PersonManager pm=new PersonManager();
    	Scanner input=new Scanner(System.in);
    	
    	while(true)//一直循环就是为了程序一直运行，就可以一直使用功能！所以要死循环，
    		//当然可以设置一个出口，直接退出程序
    	{
    		System.out.println("==============================");
            System.out.println("       人员信息管理系统");
            System.out.println("==============================");
            System.out.println("1. 添加人员信息");
            System.out.println("2. 查询人员信息");
            System.out.println("3. 显示全部人员信息");
            System.out.println("4. 编辑人员信息");
            System.out.println("5. 删除人员信息");
            System.out.println("6. 统计人员信息");
            System.out.println("7. 保存人员信息到文件");
            System.out.println("8. 从文件读取人员信息");
            System.out.println("0. 退出程序");
             System.out.print("请输入您的选择： ");
           
    		int choice=input.nextInt();
    		
    		switch(choice)
    		{
    		case 1:
    			   pm.addPerson();
	                break;
    		 case 2:
	                pm.searchPerson();
	                break;
    		 case 3:
	                pm.displayAll();
	                break;
	            case 4:
	                pm.editPerson();
	                break;
	            case 5:
	                pm.deletePerson();
	                break;     
	            case 6:
	            	pm.statistic();
	            	break;
	            case 7:
	            	pm.writeToFile();
	            	break;
	            case 8:
	            	pm.readFromFile();
	            	break;
	            case 0: 
	            	System.out.println("登出成功！");
	            	System.exit(0);
	            	 break;
	               default:
	                System.out.println("请输入正确的选择！");
	                break;
	         	
	         
    			
    		}
    	}
    	
    	
	}
}
