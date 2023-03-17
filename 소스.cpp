//private 상속의 경우, 상속 대상의 모든 멤버에 접근이 불가능하기 때문에, 상속의 의미가 없다.
//protected 멤버는 어차피 연계된 클래스 안에서는 공개되기 때문에, 따로 protected 상속의 의미가 있지는 않다.
//따라서 거의 public 상속만 쓰인다.

//상속은 기존 클래스에 속성을 더하고 싶을 때 유용하다.
//상속 대상과 상속 받는 자는 IS-A 관계에 있다.
//무선전화기 is a 전화
//class 무선전화기:public 전화
//이와 같은 관계가 아니라면 잘못된 상속일 가능성이 높다.

#include<iostream>
#include<cstring>
using namespace std;

class Computer
{
	char owner[50];
public:
	Computer(const char* name) { strcpy(owner, name); }
	void Calculate() { cout << "요청 내용을 계산합니다." << endl; }
};

class NotebookComp :public Computer
{
	int Battery;
public:
	NotebookComp(const char*name,int initChag):Computer(name),Battery(initChag){}
	void Charging() { Battery += 5; }
	void UseBattery() { Battery -= 1; }
	void MovingCal()
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "충전이 필요합니다." << endl;
			return;
		}
		cout << "이동하면서 ";
		Calculate();
		UseBattery();
	}
	int GetBatteryInfo() { return Battery; }
};

class TabletNotebook :public NotebookComp
{
	char regstPenModel[50];
public:
	TabletNotebook(const char* name, int initChag, const char* pen) :NotebookComp(name, initChag) { strcpy(regstPenModel, pen); }
	void Write(const char* penInfo)
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "충전이 필요합니다." << endl;
			return;
		}
		if (strcmp(regstPenModel, penInfo) != 0)
		{
			cout << "등록된 펜이 아닙니다.";
			return;
		}
		cout << "필기 내용을 처리합니다." << endl;
		UseBattery();
	}
};

int main()
{
	NotebookComp nc("LEE", 5);
	TabletNotebook tn("JUNG", 5, "ISE");
	nc.MovingCal();
	tn.Write("ISE");
	return 0;
}