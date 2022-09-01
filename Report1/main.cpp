#include <iostream>
using namespace std;

double periodOfSaving;	//���ݱⰣ
double goalMoney;	//��ǥ ���ݾ�
double interestRate = 3.55 / 100.0;	//����
double taxRate = 15.4 / 100;	//�������� ����
double beforeTaxInterest;	//���� ����
double totalRecieve;	//���� �� ���ɾ�
int minSaveOfmonth = 1;	//�ּ� �������ݾ�(�� ����)
int maxSavingPeriod = 3;		//�ִ� ���ݱⰣ
int maxSaveOfmonth = 300;	//�ִ� �������ݾ�(�� ����)

void insertPeriodOfSaving()
{
	while (1)
	{
		cout << "���ݱⰣ(�ִ� " << maxSavingPeriod << "��, ���� : ��) : ";
		cin >> periodOfSaving;
		if (periodOfSaving > maxSavingPeriod || periodOfSaving < 1)
		{
			cout << "�ùٸ� �Ⱓ�� �Է����ּ���." << endl;
		}
		else
		{
			break;
		}
	}
}

void insertAmountOfSavingMoney()
{
	while (1)
	{
		cout << "�� ���ݾ�(���� : ��) : ";
		cin >> goalMoney;
		if ((goalMoney / (periodOfSaving * 12)) > 3000000 || (goalMoney / (periodOfSaving * 12)) < 10000)
		{
			cout << "������ ��������� ���ݾ��� �� " << minSaveOfmonth << "���� ~ " << maxSaveOfmonth << "���� �Դϴ�!!\n" << endl;
		}
		else
		{
			break;
		}
	}
}

void printInfoOfInterest()
{
	for (int i = (periodOfSaving * 12); i > 0; i--)
	{
		beforeTaxInterest += (long double)((goalMoney/(periodOfSaving * 12))*interestRate)*i/12;	//���� ���� ���
		//printf("%lf\n", (long double)((goalMoney / (periodOfSaving * 12)) * interestRate) * i / 12);
	}
	
	totalRecieve = (long double)beforeTaxInterest + goalMoney;	//���� �� ���ɾ� ���

	cout << "\n\n�ſ� ���ݾ� : " << goalMoney / (periodOfSaving * 12) << "\\" << endl;
	cout << "�ִ� �� ������(�ܸ�) : " << interestRate * 100 << "%\n" << endl;

	cout << "����(����) : " << -5 + beforeTaxInterest << "\\" << endl;
	printf("�� ���ɾ�(����) : %.2lf\\\n\n", -5 + totalRecieve);

	cout << "���� : " << taxRate * 100 << "%" << endl;
	cout << "����(����) : " << -5 + beforeTaxInterest - (beforeTaxInterest * taxRate) << "\\" << endl;
	printf("�� ���ɾ�(����) : %.2lf\\\n", -5 + goalMoney + beforeTaxInterest - (beforeTaxInterest * taxRate));
}

int main()
{
	insertPeriodOfSaving();			//���ݱⰣ �Է�
	insertAmountOfSavingMoney();	//���ݾ� �Է�

	printInfoOfInterest();		//���ɾ�, ����, ����, �� ������, �ſ� ���ݾ� ���

	return 0;
}