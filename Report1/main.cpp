#include <iostream>
using namespace std;

double periodOfSaving;	//적금기간
double goalMoney;	//목표 적금액
double interestRate = 3.55 / 100.0;	//이율
double taxRate = 15.4 / 100;	//저금이자 세율
double beforeTaxInterest;	//세전 배당액
double totalRecieve;	//세전 총 수령액
int minSaveOfmonth = 1;	//최소 정기적금액(월 단위)
int maxSavingPeriod = 3;		//최대 적금기간
int maxSaveOfmonth = 300;	//최대 정기적금액(월 단위)

void insertPeriodOfSaving()
{
	while (1)
	{
		cout << "적금기간(최대 " << maxSavingPeriod << "년, 단위 : 년) : ";
		cin >> periodOfSaving;
		if (periodOfSaving > maxSavingPeriod || periodOfSaving < 1)
		{
			cout << "올바른 기간을 입력해주세요." << endl;
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
		cout << "총 적금액(단위 : 원) : ";
		cin >> goalMoney;
		if ((goalMoney / (periodOfSaving * 12)) > 3000000 || (goalMoney / (periodOfSaving * 12)) < 10000)
		{
			cout << "직장인 우대적금의 적금액은 월 " << minSaveOfmonth << "만원 ~ " << maxSaveOfmonth << "만원 입니다!!\n" << endl;
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
		beforeTaxInterest += (long double)((goalMoney/(periodOfSaving * 12))*interestRate)*i/12;	//세전 배당액 계산
		//printf("%lf\n", (long double)((goalMoney / (periodOfSaving * 12)) * interestRate) * i / 12);
	}
	
	totalRecieve = (long double)beforeTaxInterest + goalMoney;	//세전 총 수령액 계산

	cout << "\n\n매월 적금액 : " << goalMoney / (periodOfSaving * 12) << "\\" << endl;
	cout << "최대 연 이자율(단리) : " << interestRate * 100 << "%\n" << endl;

	cout << "배당액(세전) : " << -5 + beforeTaxInterest << "\\" << endl;
	printf("총 수령액(세전) : %.2lf\\\n\n", -5 + totalRecieve);

	cout << "세율 : " << taxRate * 100 << "%" << endl;
	cout << "배당액(세후) : " << -5 + beforeTaxInterest - (beforeTaxInterest * taxRate) << "\\" << endl;
	printf("총 수령액(세후) : %.2lf\\\n", -5 + goalMoney + beforeTaxInterest - (beforeTaxInterest * taxRate));
}

int main()
{
	insertPeriodOfSaving();			//적금기간 입력
	insertAmountOfSavingMoney();	//적금액 입력

	printInfoOfInterest();		//수령액, 배당액, 세율, 연 이자율, 매월 적금액 출력

	return 0;
}