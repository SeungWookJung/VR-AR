#include <iostream>  
#include <string> 
#include <Windows.h>  //현재시간을 받아오기 위한 윈도우 라이브러리
#include <cstdlib> //절댓값을 위한 라이브러리


using namespace std;


int NowTime(); //현재시간을 구하는 함수
int NowDay(); //현재 일을 구하는 함수
bool In(int CarNumber,int time,int day); // 차량들어옴 시 차량남바,시간 넣어주는 함수
void Out(int OutCarNumber,int time,int day); // 차량나감시 차량남바,시간 변수를 받아서 계산까지 처리 해주는 함수


struct CAR{
	int CarNumber;//차량넘버
	int InTime; //차량들어오는 시간
	int OutTime; //차량나가는 시간
	int price; //금액
	int Inday;//들어온 일
	int Outday;// 나간 일 
};
CAR car[100] = {0,};

//주차 관리 시스템 구현 #2019_07_02 
int main()
{
	
	string status;

	while (1) //반복문 시작
	{	
		int CarNumber = 0; //들어오는 차의 변수를 저장하는 번호
		int time = 0; //시간을 담기위한 변수
		int OutCarNumber = 0;//나가는 차를 검색하기위한 차번호를 임시로 저장하는 변수
		int day; //차량이 들어온 일을 저장
		string PayAgree; //결제를 동의하는지에 대한 변수

		cout << "------- 차량들어옴 \t 차량나감 \t 취소 \t중에 선택 하세요. ------- " << endl;
		cin >> status;

		if (status == "차량들어옴") 
		{
			cout << "차량번호를 입력하세요(4자리만) : " << endl;

			cin >> CarNumber;
			time = NowTime();
			day = NowDay();
			if (In(CarNumber, time, day))
			{
				cout << "작업 정상처리 됐습니다." << endl;

				time = 0; //초기화
				CarNumber = 0;//초기화
			}
			else
			{
				cout << "작업이 정상처리 되지 않았습니다." << endl;
			}
		}
		else if (status == "차량나감")
		{
			cout << "차량번호를 입력해 주세요 : ";
				cin >> OutCarNumber;

				time = NowTime();
				day = NowDay();
				Out(OutCarNumber, time, day);
				
		}
		else if (status == "취소") {
			exit(1);
		}
		else
			cout << "다시 입력해 주세요!!" << endl;

	}//반복문 끝

	return 0;
}

int NowTime() //현재시간을 구하는 함수
{
	int Now;

	SYSTEMTIME lst;
	GetLocalTime(&lst);

	Now = lst.wHour;

	return Now;
}

int NowDay()
{
	int Now;

	SYSTEMTIME lst;
	GetLocalTime(&lst);

	Now = lst.wDay;

	return Now;
}

bool In(int carNumber, int time,int day) //들어오는 차량번호, 들어온 시간을 구조체에 저장하는 함수
{
	for (int i = 0; i <= 9; i++)
	{
		if (car[i].CarNumber == NULL)
		{
			car[i].CarNumber = carNumber;
			car[i].Inday = day;
			car[i].InTime = time;

			return true;
		}
		else if (car[i + 1].CarNumber == NULL)
		{
			car[i + 1].CarNumber = carNumber;
			car[i + 1].Inday = day;
			car[i + 1].InTime = time;
			return true;
		}
		else
			return false;
	}
}

void Out(int OutCarNumber,int time,int day) // 나가는 차량의 번호,시간을 찾아 계산해주는 함수
{
	string PayAgree;
	for (int i = 0; i <= 9; i++)
	{
		if (car[i].CarNumber == OutCarNumber)
		{
			car[i].OutTime = time;
			if (car[i].Inday == car[i].Outday)
			{
				if (abs(car[i].InTime - car[i].OutTime) <= 2)
				{
					car[i].price = (abs(car[i].InTime - car[i].OutTime)) * 2000;
					cout << "차량번호 : " << OutCarNumber << " 님은 " << car[i].price << " 원 내셔야 합니다." << endl;

					cout << "결제 하시겠습니까?(예,아니오) " << endl;
					cin >> PayAgree;
					if (PayAgree == "예")
					{
						car[i].CarNumber = NULL;
						car[i].Inday = NULL;
						car[i].InTime = NULL;
						car[i].Outday = NULL;
						car[i].OutTime= NULL;
						car[i].price = NULL;
						cout << "결제 되었습니다" << endl;
						break;
					}
					else
					{
						cout << "결제 되지 않았습니다." << endl;
						break;
					}
				}
				else if (abs(car[i].InTime - car[i].OutTime) > 2)
				{
					car[i].price = (abs(car[i].InTime - car[i].OutTime)) * 6000;
					cout << "차량번호 : " << OutCarNumber << " 님은 " << car[i].price << " 원 내셔야 합니다." << endl;
					
					cout << "결제 하시겠습니까?(예,아니오) " << endl;
					cin >> PayAgree;
					if (PayAgree == "예")
					{
						car[i].CarNumber = NULL;
						car[i].Inday = NULL;
						car[i].InTime = NULL;
						car[i].Outday = NULL;
						car[i].OutTime = NULL;
						car[i].price = NULL;
						cout << "결제 되었습니다" << endl;
						break;
					}
					else
					{
						cout << "결제 되지 않았습니다." << endl;
						break;
					}
				}
			}
			else
			{
			
				
				if (car[i].price = (abs(car[i].InTime / 2 - car[i].OutTime) <= 2)) 
				{
					car[i].price = (abs(car[i].InTime - car[i].OutTime)) * 2000;
					cout << "차량번호 : " << OutCarNumber << " 님은 " << car[i].price << " 원 내셔야 합니다." << endl;

					cout << "결제 하시겠습니까?(예,아니오) " << endl;
					cin >> PayAgree;
					if (PayAgree == "예")
					{
						car[i].CarNumber = NULL;
						car[i].Inday = NULL;
						car[i].InTime = NULL;
						car[i].Outday = NULL;
						car[i].OutTime = NULL;
						car[i].price = NULL;
						cout << "결제 되었습니다" << endl;
						break;
					}
					else
					{
						cout << "결제 되지 않았습니다." << endl;
						break;
					}
					break;
				}
				else
				{
					car[i].price = (abs(car[i].InTime - car[i].OutTime)) * 6000;
					cout << "차량번호 : " << OutCarNumber << " 님은 " << car[i].price << " 원 내셔야 합니다." << endl;

					cout << "결제 하시겠습니까?(예,아니오) " << endl;
					cin >> PayAgree;
					if (PayAgree == "예")
					{
						car[i].CarNumber = NULL;
						car[i].Inday = NULL;
						car[i].InTime = NULL;
						car[i].Outday = NULL;
						car[i].OutTime = NULL;
						car[i].price = NULL;
						cout << "결제 되었습니다" << endl;
						break;
					}
					else
					{
						cout << "결제 되지 않았습니다." << endl;
						break;
					}

					break;
				}
				
			}
		
			
		}
		else
			cout << "차량이 없습니다" << endl;
		break;
	}
	
}