#pragma once

using namespace std;

void MenuPrint(); //메뉴 출력하는 함수
void Master_MenuPrint();//관리자 메뉴화면 표시
void Choice_Can(string menu); //메뉴를 골랐을 때 작동하는 함수
void Pay(string menu,int CanNum); //가격지불 함수
void Master_Data(); //관리자 모드 작업 함수
void Change_menu(); //관리자 모드에서 메뉴의 이름,가격,수량 등을 설정 할 수 있는 함수