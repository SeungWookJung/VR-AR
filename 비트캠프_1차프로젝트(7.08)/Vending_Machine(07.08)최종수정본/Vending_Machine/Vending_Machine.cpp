#include <iostream>
#include <string>

#include "Definition_Can.h"

//음료들의 정보를 정의하는 함수(이름,금액,수량)를 Can이라는 구조체로 정의
struct Can
{
	char name[5];
	int price;
	int count;
};

Can can[5]; //음료마다의 정보를 저장한 구조체 배열


//제작: A team(김규민,김완준,정승욱)  제작날짜: 2019.07.03 ~ 07.06
//자판기 시스템
int main()
{
	string menu; //사용자로부터 메뉴를 받는 변수

	while (1) //취소가 나올 때까지 반복
	{
		MenuPrint(); //메뉴판을 보여주는 함수


		cout << "메뉴를 선택해 주세요 : ";
		cin >> menu;

		Choice_Can(menu);
	}

	return 0;
}

//메뉴판 출력함수(메뉴 5개)
void MenuPrint()
{

	cout << "==============================================================" << endl;
	cout << "\t\t    메뉴를 선택하세요(종료 입력시 종료)" << endl;
	cout << "==============================================================" << endl;
	cout << "\t 메뉴 \t\t 금액 \t\t 수량 \t " << endl;
	cout << "==============================================================" << endl;
	cout << "\t" << can[0].name << "\t\t\t" << can[0].price << "\t\t\t" << can[0].count << "\n";
	cout << "\t" << can[1].name << "\t\t\t" << can[1].price << "\t\t\t" << can[1].count << "\n";
	cout << "\t" << can[2].name << "\t\t\t" << can[2].price << "\t\t\t" << can[2].count << "\n";
	cout << "\t" << can[3].name << "\t\t\t" << can[3].price << "\t\t\t" << can[3].count << "\n";
	cout << "\t" << can[4].name << "\t\t\t" << can[4].price << "\t\t\t" << can[4].count << "\n";
	cout << "==============================================================" << endl;

}//메뉴판 출력함수(메뉴 5개)

void Master_MenuPrint() //관리자 메뉴화면 표시
{
	cout << "==============================================================" << endl;
	cout << "\t\t 어떤 기능을 수행하시겠습니까?" << endl;
	cout << "==============================================================" << endl;
	cout << " 전체초기화  \t  개별초기화  \t 종료 \t" << endl;
	cout << "==============================================================" << endl;
}//관리자 메뉴화면 표시

void Choice_Can(string menu) //음료를 선택하는 함수
{
	int CanNum = 0; //음료의 번호

	while (1) //음료선택 시 종료가 나올때 까지 계속 받기위한 반복문
	{

		if (menu == can[0].name) //1번째 음료를 선택시
		{
			Pay(menu, CanNum);
			break;
		}
		else if (menu == can[1].name) //2번째 음료를 선택시
		{
			CanNum = 1;
			Pay(menu, CanNum);
			break;
		}
		else if (menu == can[2].name) //3번째 음료를 선택시
		{
			CanNum = 2;
			Pay(menu, CanNum);
			break;
		}
		else if (menu == can[3].name) //4번째 음료를 선택시
		{
			CanNum = 3;
			Pay(menu, CanNum);
			break;
		}
		else if (menu == can[4].name) //5번째 음료를 선택시
		{
			CanNum = 4;
			Pay(menu, CanNum);
			break;
		}
		else if (menu == "master") //관리자 모드를 선택시
		{
			Master_Data();
			break;
		}
		else if (menu == "종료") //종료를 선택시
		{
			cout << " 이용해 주셔서 감사합니다. " << endl;
			exit(1);
		}
		else
			cout << "잘못 입력 하셨습니다. 다시입력해 주세요" << endl;

	}//음료선택 시 종료가 나올때 까지 계속 받기위한 반복문 종료
}//음료를 선택하는 함수

void Pay(string menu, int CanNum) //가격지불 함수
{
	int insert_Money = 0; //사용자가 넣는 돈
	int resultMoney = 0; //남은 돈 
	int moreMoney = 0; //필요한 돈 표시를 위해 담는 변수
	int addMoney = 0; //사용자로부터 필요한 돈을 담는 변수
	string buy;

	while (1) //가격이 맞을때 까지 돌리는 반복문
	{

		if (can[CanNum].count <= 0) //음료의 재고가 없을 때
		{
			cout << "음료가 없습니다. 다른 메뉴를 골라주세요" << endl;
			break;
		}
		else if (can[CanNum].count > 0) //음료의 재고가 있을 때
		{
			if (insert_Money == 0) //초기값 
			{
				MenuPrint();
				cout << "돈을 넣어주세요(취소는 -1)" << endl;
				cin >> insert_Money;
			}
			else if (insert_Money == -1) //돈을 넣는데 취소를 하고 싶은면 
			{
				cout << "취소 되었습니다." << endl;
				break;
			}
			else if (insert_Money == can[CanNum].price) //조건 1.사용자가 넣은 돈과 음료가격이 일치 한다면
			{
				cout << can[CanNum].name << " :  " << can[CanNum].price << " 원입니다." << endl;
				can[CanNum].count -= 1;
				cout << "음료수가 나왔습니다" << endl;
				insert_Money = 0;
				break;
			}//조건 1
			else if (insert_Money > can[CanNum].price) //조건 2.사용자가 넣은 돈이 음료가격 보다 크다면
			{
				can[CanNum].count -= 1; //음료 재고감소
				resultMoney = insert_Money - can[CanNum].price; //남은 돈 계산
				insert_Money = resultMoney;

				cout << "음료수가 나왔습니다" << endl;
				cout << "남은돈은 : " << resultMoney << "입니다" << endl;

				if (resultMoney >= can[CanNum].price) //조건 2.1 남은돈이 음료수 가격보다 클때
				{

					while (1) //추가 구매 판별을 위해 돌리는 반복문
					{
						if (resultMoney <= 0) //조건 2.1.1추가 구매 도중 금액이 0보다 작거나 0원이면
						{
							cout << "남은돈은 : " << resultMoney << "입니다." << endl;
							cout << "이용해 주셔서 감사합니다." << endl;
							insert_Money = 0;
							break;
						}
						cout << "계속해서 구입 하시겠습니까?( 예,아니오 로 대답해주세요. )" << endl;  //계속 구매를 물어보는 질문
						cin >> buy;

						if (buy == "예") //조건 2.1.2 추가구매를 하겠다면
						{


							if (resultMoney < can[CanNum].price) //조건 2.1.2 추가구매 도중 금액이 음료가격보다 낮을 때 
							{
								moreMoney = can[CanNum].price - resultMoney; //필요한 금액 계산
								cout << moreMoney << " 원의 돈을 더 넣어주세요" << endl;
								cin >> addMoney;

								resultMoney += addMoney; //사용자가 넣은돈으로 계산
							}
							else if (resultMoney == can[CanNum].price) //추가 구매 도중 남은 금액과 음료가격이 같을때
							{
								resultMoney -= can[CanNum].price;
								can[CanNum].count -= 1;
								cout << "음료수가 나왔습니다" << endl;
								cout << "남은돈은 : " << resultMoney << "입니다\n" << endl;
								cout << "이용해 주셔서 감사합니다." << endl;

								insert_Money = resultMoney;
								break;
							}

							cout << can[CanNum].name << " :  " << can[CanNum].price << "원입니다." << endl;
							can[CanNum].count -= 1;
							resultMoney -= can[CanNum].price;
							insert_Money = resultMoney;

							cout << "음료수가 나왔습니다" << endl;
							cout << "남은돈은 : " << resultMoney << "입니다\n" << endl;

						}//추가구매를 하겠다면

						else if (buy == "아니오") //조건 2.1.3추가구매를 하지 않겠다면
						{
							cout << "거스름돈은 : " << resultMoney << "입니다" << endl;
							cout << " 이용해 주셔서 감사합니다. " << endl;

							insert_Money = 0;
							resultMoney = 0;

							break;
						}//추가구매를 하지 않겠다면
						else
						{
							cout << " 잘못 입력했습니다. 다시 입력해주세요. " << endl;

						}

					}//추가 구매 판별을 위해 돌리는 반복문 종료

				}//남은돈이 음료수 가격보다 클때
				break;
			}//조건 2

			else if (insert_Money < can[CanNum].price) //조건 3.사용자가 넣은 돈이 음료의 가격보다 낮으면1
			{
				while (1) //모자란 금액을 계속 받기위한 반복문
				{

					if (can[CanNum].price == insert_Money) //조건 3.1.사용자가 총 넣은 금액과 음료의 가격이 같다면
					{
						can[CanNum].count -= 1;
						cout << "음료수가 나왔습니다" << endl;
						insert_Money = 0;
						break;
					}//조건 3.1
					
					else if (can[CanNum].price < insert_Money)//조건 3.2.사용자가 총 넣은 금액이 음료 금액보다 클경우
					{
						can[CanNum].count -= 1;
						cout << "음료수가 나왔습니다" << endl;
						insert_Money -= can[CanNum].price;
						resultMoney = insert_Money;
						cout << "남은 금액은 : " << resultMoney << " 원 입니다." << endl;

						while (1)//조건 3.2 안에 추가 구매를 위해 쓰는 반복문
						{

							if (resultMoney <= 0) //추가 구매 도중 금액이 0보다 작거나 0원이면
							{
								cout << "남은돈은 : " << resultMoney << "입니다." << endl;
								cout << "이용해 주셔서 감사합니다." << endl;
								insert_Money = 0;
								break;
							}

							cout << "계속해서 구입 하시겠습니까?( 예,아니오 로 대답해주세요. )" << endl;  //계속 구매를 물어보는 질문
							cin >> buy;

							if (buy == "예") //추가구매를 하겠다면
							{
								if (resultMoney < can[CanNum].price) //추가구매 도중 금액이 음료가격보다 낮을 때 
								{
									moreMoney = can[CanNum].price - resultMoney; //필요한 금액 계산
									cout << moreMoney << " 원의 돈을 더 넣어주세요" << endl;
									cin >> addMoney;

									resultMoney += addMoney; //사용자가 넣은돈으로 계산
								}
								else if (resultMoney == can[CanNum].price) //추가 구매 도중 남은 금액과 음료가격이 같을때
								{
									resultMoney -= can[CanNum].price;
									can[CanNum].count -= 1;
									cout << "음료수가 나왔습니다" << endl;
									cout << "남은돈은 : " << resultMoney << "입니다\n" << endl;
									cout << "이용해 주셔서 감사합니다." << endl;

									insert_Money = resultMoney;
									break;
								}

								cout << can[CanNum].name << " :  " << can[CanNum].price << "원입니다." << endl;
								can[CanNum].count -= 1;
								resultMoney -= can[CanNum].price;
								insert_Money = resultMoney;

								cout << "음료수가 나왔습니다" << endl;
								cout << "남은돈은 : " << resultMoney << "입니다\n" << endl;

							}//추가구매를 하겠다면

							else if (buy == "아니오") //추가구매를 하지 않겠다면
							{
								cout << "거스름돈은 : " << resultMoney << "입니다" << endl;
								cout << " 이용해 주셔서 감사합니다. " << endl;

								insert_Money = 0;
								resultMoney = 0;

								break;
							}//추가구매를 하지 않겠다면
							else
							{
								cout << " 잘못입력하셨습니다. 다시 입력해 주세요. " << endl;
							}

						}//조건 3.2 안에 추가 구매를 위해 쓰는 반복문 종료
						break;
					}//조건 3.2

					moreMoney = can[CanNum].price - insert_Money; //필요한 금액 계산
					cout << moreMoney << " 원의 돈을 더 넣어주세요4" << endl;
					cin >> addMoney;

					insert_Money += addMoney; //사용자가 넣은돈으로 계산

				}//모자란 금액을 계속 받기위한 반복문 종료
			}//조건 3

			else //조건 4
			{
				cout << "돈을 제대로 넣어주세요" << endl;
			}//조건 4

		}//음료의 재고가 있을 때

		else
		{
			cout << "돈을 제대로 넣어주세요" << endl;
		}

	}//가격이 맞을때 까지 돌리는 반복문 종료
}//가격지불 함수


void Master_Data() //관리자 모드 작업 함수
{
	string Master_Paswword = "9999";
	string password;


	while (1) //비밀번호를 받는 반복문
	{
		cout << " 비밀번호를 입력해 주세요  :  ";
		cin >> password;

		if (password == Master_Paswword) //비밀번호가 맞을경우
		{
			cout << "관리자 모드 접속" << endl;
			Change_menu();
			break;
		}
		else if (password == "종료") //종료를 입력했을 경우
		{
			cout << "관리자 모드가 종료되었습니다." << endl;
			break;
		}
		else //비밀번호가 틀렸을경우
		{
			cout << " 비밀번호가 틀렸습니다. 올바른 값을 넣어 주시거나 취소버튼을 통해 관리자 모드를 종료해 주세요." << endl;
			cin >> password;
			continue;
		}
	}//비밀번호를 받는 반복문 종료
}//관리자 모드 작업 함수 종료

//메뉴 수정 함수
void Change_menu() //관리자 모드에서 Change_menu 함수로 넘어가게 된다. 
{
	string func;

	while (1)
	{
		Master_MenuPrint();//관리자 메뉴화면 표시 화면 호출
		cin >> func;

		if (func == "전체초기화") //음료 전체의 이름,가격,수량을 설정 해주는 기능
		{
			for (int i = 0; i < 5; i++)
			{
				char all_name[5];
				int input_price;
				int input_count;

				cout << "메뉴이름을 입력해주세요 : ";
				cin >> all_name;
				strcpy(can[i].name, all_name);

				cout << "가격을 입력해주세요 : ";
				cin >> input_price;
				can[i].price = input_price;

				cout << "수량을 입력해주세요 : ";
				cin >> input_count;
				can[i].count = input_count;
				continue;
			}
		}
		else if (func == "개별초기화") //음료의 메뉴 각각의 이름,가격,수량을 설정해주는 기능
		{

			while (1)
			{
				int input_num;

				cout << "음료수 위치 번호를 입력하세요\t (0 ~ 4), 종료(5) " << endl;
				cin >> input_num;

				if (input_num == 0) //0번째 음료
				{
					char personal_name0[5];
					int inputprice;
					int inputcount;

					cout << " 음료수이름, 가격, 수량을 입력해주세요" << endl;
					cout << "음료수이름 : ";
					cin >> personal_name0;

					cout << " 가격 : ";
					cin >> inputprice;

					cout << " 수량 : ";
					cin >> inputcount;

					strcpy(can[0].name, personal_name0); //입력받은 음료의 이름을 배열안에 넣는 함수
					can[0].price = inputprice;
					can[0].count = inputcount;
				}

				else if (input_num == 1) //1번째 음료
				{
					char personal_name1[5];
					int inputprice;
					int inputcount;

					cout << " 음료수 이름, 가격, 수량을 입력해주세요." << endl;
					cout << "음료수 이름 : ";
					cin >> personal_name1;

					cout << "음료수 가격 : ";
					cin >> inputprice;

					cout << " 수량 : ";
					cin >> inputcount;

					strcpy(can[1].name, personal_name1);
					can[1].price = inputprice;
					can[1].count = inputcount;
				}

				else if (input_num == 2) //2번째 음료
				{
					char personal_name2[5];
					int inputprice;
					int inputcount;

					cout << " 음료수이름, 가격, 수량을 입력해주세요." << endl;
					cout << "음료수이름" << endl;
					cin >> personal_name2;

					cout << " 가격 " << endl;
					cin >> inputprice;

					cout << " 수량 " << endl;
					cin >> inputcount;

					strcpy(can[2].name, personal_name2);
					can[2].price = inputprice;
					can[2].count = inputcount;
				}

				else if (input_num == 3) //3번째 음료
				{
					char personal_name3[5];
					int inputprice;
					int inputcount;

					cout << " 음료수이름, 가격, 수량을 입력해주세요." << endl;
					cout << "음료수이름 : ";
					cin >> personal_name3;

					cout << " 가격 : ";
					cin >> inputprice;

					cout << " 수량 : ";
					cin >> inputcount;

					strcpy(can[3].name, personal_name3);
					can[3].price = inputprice;
					can[3].count = inputcount;
				}

				else if (input_num == 4) //4번째 음료
				{
					char personal_name4[5];
					int inputprice;
					int inputcount;

					cout << " 음료수이름, 가격, 수량을 입력해주세요." << endl;
					cout << "음료수이름 : ";
					cin >> personal_name4;

					cout << " 가격 : ";
					cin >> inputprice;

					cout << " 수량 : ";
					cin >> inputcount;

					strcpy(can[4].name, personal_name4);
					can[4].price = inputprice;
					can[4].count = inputcount;
				}
				else if (input_num == 5) //종료
				{
					break;
				}
				else
				{
					cout << "잘못 입력. 다시 입력하세요." << endl;
				}
			}
			break; // 음료, 가격, 수량 반복 종료
		}
		else if (func == "종료")
		{
			cout << "종료되었습니다" << endl;
			break;
		}
		else
		{
			cout << "잘못입력, 다시입력하세요. " << endl;
			continue;
		}
	}
}