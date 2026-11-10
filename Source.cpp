#include <iostream>
#include <windows.h> //timer
#include <stdlib.h> //clearscreen
#include <thread>
using namespace std;


#define  WIN32_LEAN_AND_MEAN
#define NOSERVICE
#define NOMCX
#define NOIME
#define NOMINMAX

int Battle(int,int,int);
int HealthChecker(int, int, int);


int main() {
Start:                                          //Extremely Shitty way to program but should work for now.
	system("CLS");
	
	srand(time(NULL));
	
	         //Random Damage delivered to enemy,should be somewhere like 0.8x to 2x. Update:Settled Mod 3 +1.Update-Update using Addition System instead.
	int PlayerHealth = 100;
	int EnemHealth = 100;
	int Enem_Light_Atk =10 ;
	int Enem_Heavy_Atk = 25;
	
	int HealthPopUp = 800;
	int Map[10][10];
	


	//
	 Battle(EnemHealth,PlayerHealth,HealthPopUp);                           //Calling Battle Function.
	//
	 HealthChecker(EnemHealth, PlayerHealth, HealthPopUp);



	
	return 1;
}




int Battle(int EnemHealth, int PlayerHealth, int HealthPopUp)
{
	while (EnemHealth > 0 && PlayerHealth > 0)                  //Gameloop here.
	{
		float random = (rand() % 10) - (rand() % 10);
		float Player_Light_Atk = 15 + random;
		float Player_Heavy_Atk = 25 + random;
		int n;
		cout << "\nAttack?\n1-Light Atk\n2-Heavy Atk\nChoice:";
		cin >> n;
		switch (n)
		{
		case 1:
		{
			EnemHealth -= Player_Light_Atk;
			cout << "DAMAGE DEALT! :" << Player_Light_Atk << endl;
			(EnemHealth < 0) ? EnemHealth = 0 : EnemHealth = EnemHealth;
			cout << "\nEnemy Health:" << EnemHealth << "\n\n";
			Sleep(HealthPopUp);
			system("CLS");
			break;
		}
		case 2:
		{

			EnemHealth -= Player_Heavy_Atk;
			cout << "DAMAGE DEALT! :" << Player_Heavy_Atk << endl;
			(EnemHealth < 0) ? EnemHealth = 0 : EnemHealth = EnemHealth;
			cout << "\nEnemy Health:" << EnemHealth << "\n\n";
			Sleep(HealthPopUp);
			system("CLS");

			break;
		}
		case 99:
		{
			cout << "Suicide.";
			cout << "\nDAMAGE DEALT :" << PlayerHealth << endl;
			PlayerHealth -= PlayerHealth;
			cout << "PlayerHealth:" << PlayerHealth<<"\n\n";
			Sleep(HealthPopUp);
			system("CLS");

			break;
		}
		default:
		{
			cout << "\nNot The Sharpest Tool In The Shed Are You?\n";
			(EnemHealth < 0) ? EnemHealth = 0 : EnemHealth = EnemHealth;
			cout << "\nEnemy Health:" << EnemHealth << "\n\n";
			Sleep(HealthPopUp * 2);
			system("CLS");
			break;
		}

		}
	}
	HealthChecker(PlayerHealth,EnemHealth,10);
	return EnemHealth;
	
}

int HealthChecker(int PlayerHealth,int EnemHealth,int HealthPopUp)
{
	if (PlayerHealth <= 0) {
		cout << "Iminenent Death in " << "\n 3";
		Sleep(700);
		system("CLS");
		cout << "Iminenent Death in " << "\n 2";
		Sleep(700);
		system("CLS");
		cout << "Iminenent Death in " << "\n 1";
		Sleep(700);
		system("CLS");

		Sleep(700);
		system("CLS");
		cout << "\n\n\n";

		cout << "\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		cout << "\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		cout << "\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		cout << "\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		cout << "\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		cout << "\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		cout << "\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		cout << "\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		cout << "\t\t" << "$$$@*cc@$$$$Bvv&$8zzzzzcW$$$@WuuW$$$$@Mnz@$$$$%*uc**cuvM@$$$8cc%$8vnz*zn8B*uv**cuvM@$$$$$$\n";
		cout << "\t\t" << "$$$$$u/M$$$$Mf8@nnB$$$$$*j8$$$jj$$$$$$$/&$$$$$$W/M$$$$&nt#$$$xr$$$z/B$$W$$&/#$$$$&nt*$$$$$\n";
		cout << "\t\t" << "$$$$$$ct%$$Wr@$xj$$$$$$$$Mt%$$fr$$$$$$$/&$$$$$$W/M$$$$$$z/c$$xr$$$z/B$$$$$&/#$$$$$$#/v$$$$\n";
		cout << "\t\t" << "$$$$$$$cj@&x@$%/*$$$$$$$$$rn$$fr$$$$$$$/&$$$$$$W/M$$$$$$$x/@$xr$$$z/B$$B$$&/#$$$$$$$n/%$$$\n";
		cout << "\t\t" << "$$$$$$$$nrrB$$W/M$$$$$$$$$ct$$fx$$$$$$$/&$$$$$$W/M$$$$$$$*/8$xr$$$z/vcvf$$&/#$$$$$$$#/&$$$\n";
		cout << "\t\t" << "$$$$$$$$%/c$$$&/c$$$$$$$$$vt$$jx$$$$$$$/&$$$$$$W/M$$$$$$$*/@$xr$$$z/B$$8$$&/#$$$$$$$#/%$$$\n";
		cout << "\t\t" << "$$$$$$$$@/c$$$$ntB$$$$$$$$fz$$xr$$$$$$$/B$$$$$$W/M$$$$$$$rn$$xr$$$z/B$$$$$&/#$$$$$$$rx$$$$\n";
		cout << "\t\t" << "$$$$$$$$@/c$$$$$vrB$$$$$@nu$$$8tW$$$$$cc$$$$$$$W/M$$$$$Bnr@$$xr$$$z/%$$$B$&/*$$$$$@urB$$$$\n";
		cout << "\t\t" << "$$$$$$$$$$$$$$$$$$$$%8%$$$$$$$$$$$%8B$$$$$$$$$$$$@BBB@$$$$$$$$$$$$$$$$$@$$$$@BBB@$$$$$$$$$\n";
		cout << "\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		cout << "\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		cout << "\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		cout << "\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		cout << "\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		cout << "\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";

		cout << "\n\n\n\t\tLOADING.......";
		Sleep(HealthPopUp);
		cout << "You Died at:\n";
		for (int i = 1;i <= 10;i++)
		{
			for (int j = 1;j <= 10;j++)
			{
				cout << "[" << char(i + 64) << "-" << (j) << "]";
			}
			cout << endl;
		}
		Sleep(HealthPopUp * 4);

		cout << "\n\n\n GIVE UP? :Y/N" << endl;
		char retry;
		cin >> retry;
		retry = toupper(retry);
		if (retry == 'N')
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else if (EnemHealth == 0)
	{
		cout << "\n\n\n\n\t\t\tYOU WIN!\n";
		Sleep(HealthPopUp * 8);
		system("CLS");
		cout << "\n\n\n Try Again? :Y/N" << endl;
		char retry;
		cin >> retry;
		retry = toupper(retry);

		if (retry == 'Y')
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}