#include "sys.h"
#include "lcd.h"
#include "gui.h"
#include "test.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ���������ɣ��������������κ���;
//����Ӳ������Ƭ��STC12LE5A60S2,����30M  ��Ƭ��������ѹ3.3V
//QDtech-TFTҺ������ for C51
//xiao��@ShenZhen QDtech co.,LTD
//��˾��վ:www.qdtech.net
//�Ա���վ��http://qdtech.taobao.com
//��˾�ṩ����֧�֣��κμ������⻶ӭ��ʱ����ѧϰ
//�̻�(����) :+86 0755-23594567 
//�ֻ�:15989313508���빤�� 
//����:QDtech2008@gmail.com 
//Skype:QDtech2008
//��������QQȺ:324828016
//��������:2013/5/13
//�汾��V1.1
//��Ȩ���У�����ؾ���
//Copyright(C) ������ȫ�����Ӽ������޹�˾ 2009-2019
//All rights reserved
//********************************************************************************

/****************************************************************************************************
//=========================================��Դ����================================================//
//5V��DC 5V��Դ
//3V3 ���ý�
//GND�ӵ�
//=======================================Һ���������߽���==========================================//
//��ģ��Ĭ��������������Ϊ8λ����ģʽ
//8λģʽ���ߣ�
//Һ����LCD_D0��Ӧ��Ƭ��P0.0
//Һ����LCD_D1��Ӧ��Ƭ��P0.1
//Һ����LCD_D2��Ӧ��Ƭ��P0.2
//Һ����LCD_D3��Ӧ��Ƭ��P0.3
//Һ����LCD_D4��Ӧ��Ƭ��P0.4
//Һ����LCD_D5��Ӧ��Ƭ��P0.5
//Һ����LCD_D6��Ӧ��Ƭ��P0.6
//Һ����LCD_D7��Ӧ��Ƭ��P0.7
//=======================================Һ���������߽���==========================================//
//LCD_RST	��P3.3	//��λ�ź�
//LCD_CS	��P1.3	//Ƭѡ�ź�
//LCD_RS	��P1.2	//�Ĵ���/����ѡ���ź�
//LCD_WR	��P1.1	//д�ź�
//LCD_RD	��P1.0	//���ź�
//=========================================������������=========================================//
//�����򲻽��д������ԡ�
//������Դ������ܣ���ʹ��Arduino���׳�����в���
**************************************************************************************************/	



//STC��Ƭ��IO����������ö���
//������ͨC51��Ƭ���޴����������������������
sfr P3M1  = 0xB1;	//P3M1.n,P3M0.n 	=00--->Standard,	01--->push-pull
sfr P3M0  = 0xB2;	//					=10--->pure input,	11--->open drain

sfr P1M0 = 0x92; // 0000,0000
sfr P1M1 = 0x91; // 0000,0000
sfr P0M0 = 0x94; // 0000,0000
sfr P0M1 = 0x93; // 0000,0000
//������
void main(void)
{ 
  u16 i=0;	
	//����STC_12LE5A60S2��Ƭ����P3.2Ϊ������������ڿ��Ʊ�������
	//������ͨC51��Ƭ���޴����������������������
	P3M1 &= ~(1<<2),P3M0 |=  (1<<2); 
	//P1�����ó��������
  P1M0=0xff;
	P1M1=0x00;
	//P0�����ó��������
	P0M0=0xff;
	P0M1=0x00;
	LCD_Init();	   //Һ������ʼ��

	while(1)
	{	LCD_direction(i%4);
		i++;		
		main_test(); 		//����������
		Test_Color();  		//��ˢ��������
		Test_FillRec();		//GUI���λ�ͼ����
		Test_Circle(); 		//GUI��Բ����
		English_Font_test();//Ӣ������ʾ������
		Chinese_Font_test();//��������ʾ������
		Pic_test();			//ͼƬ��ʾʾ������	
		delay_ms(1000);
		//Touch_Test();		//��������д����  
	}		
}