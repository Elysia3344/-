

public class MyShape
{
private int shapeNum;

public void getArea(boolean type)
{
System.out.println("���ͼ������"); 

}



public static void main(String[] args)
{
 Circle myCircle=new Circle();//�½�һ������,��������µģ�����ԭ��д�õ��࣬���½���
 //����ʹ�õ���
RectAngle myRectAngle=new RectAngle();
myCircle.drawCircle(100,200,10.0);//�������е�����
myCircle.getArea(10);
myRectAngle.drawRectAngle(100,200,10.0,5.0);
myRectAngle.getArea(10,5);
} 

}
