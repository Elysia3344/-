package re0;
public class type
{
	public static void main(String args[])
	{
		float a=3.25F,b=-2.5F;//�����˸����;ͱ���Ҫ����F���Ͳ������
				//����Ҳ��ͬ���﷨�涨
		int c;
		byte d;
		c=(int)(a*b);//
		d=(byte)257;
		// byte number = (byte)257; 257������byte��[-128,127]�ķ�Χ,
		//���Խ�257����byte�ķ�Χ256(-128��127�ķ�Χ)ȡ�����õ�1;
		//ֻҪ������Χ�ͻᱨ������ǿ��ת������ǿ��ִ��
		System.out.println("c="+c);
		System.out.println("d="+d);
	}
}