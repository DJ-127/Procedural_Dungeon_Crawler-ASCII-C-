#include <iostream>
#include <windows.h> //timer
#include <stdlib.h> //cleasrscreen
#include <thread>
#include <time.h>
#include <conio.h>
using namespace std;

#define WIN32_LEAN_AND_MEAN
#define NOSERVICE
#define NOMCX
#define NOIME
#define NOMINMAX
#define c cout<< 

float HealthPopUp = 800;

class Items {
public:

	string name;
	int id;
	Items(int id, string name)
	{
		this->id = id;this->name = name;
	}
	Items()
	{
		id = 0;name = "Default_Item";
	}
};

class Enemys {
public:
	int id, health, attack_1, attack_2, attack_3, attack_4, attack_5;
	string name;
	Enemys(int id, int health, string name, int attack_1, int attack_2, int attack_3, int attack_4, int attack_5) //Points to Stuff
	{
		this->id = id;this->health = health;this->name = name;this->attack_1 = attack_1;this->attack_2 = attack_2;
		this->attack_3 = attack_3;this->attack_4 = attack_4;this->attack_5 = attack_5;
	}
	Enemys() //Assigns Default Values//Constructor
	{
		id = 0;health = 50;name = "Default Mob";attack_1 = 10;attack_2 = 10;attack_3 = 10;attack_4 = 10;attack_5 = 10;
	}
};

Enemys E1, E2, E3, E4, E5, E6, E7, E8, E9, E10;                      //Hopefully this will let them be acc3ssed by every Function.
void GameLoop(Items, Items, Items, Items, Items, Items);

void EventChecker(int);
//Hope Eradicated,I have no idea what im doing,how does Operator Overloading work?,i want to make levels less a pain to make

void KeyInput()
{
	char PressedKey;
	srand(time(NULL));                                 //Will Generate Random Room

	int Room[5][5]= {0};
	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			int RanRoomID = (rand() % 8);
			if (RanRoomID == 1 || RanRoomID== 9)
			{
				Room[i][j] = 0;
			}
			else
			{
				Room[i][j] = RanRoomID;
			}
		}
	}
	Room[4][4] = 9;                                                //exit

	int J1 = 2;
	int I1 = 2;
	Room[I1][J1] = 1;

	while (Room[4][4] == 9)                                             //Displays Numbers and Symbols on Grid-Map
	{
		c "\n\n";

		for (int i = 0;i < 5;i++)
		{
			for (int j = 0;j < 5;j++)
			{
				switch (Room[i][j])
				{
				case 0:                                //Empty
				{
					c "[" << "     " << "]";
					break;
				}
				case 1:                              //Player
				{
					c"[" << "USER " << "]";
					break;
				}
				case 6:
				{
					c"[" << "ENEM " << "]";
					break;
				}
				case 7:                               //Item,Treasure
				{
					c"[" << "ITEM?" << "]";
					break;
				}
				case 9:
				{
					c"[" << " Exit" << "]";               //Will Always Point Towards An Exit
					break;
				}
				default:
				{
					c "[  " << Room[i][j] << "  ]";
					break;
				}

				}
			}
			c endl;
		}

		c "\n\n\nMovement:W(UP)    A(LEFT)    S(DOWN)    D(Right)....";
		c "\n\n\t...Navigate to the EXIT to Complete MAP-Tutorial.";
		c"\n\nYour Character Is represented by 'U' On The Map-Grid.";


		//system("pause");

		PressedKey = _getch();                        //This code Abomination deals with Input and 'COLLISION'.
		switch (PressedKey)
		{
		case 'a':
		{

			if (J1 - 1 < 0)
			{
				;
			}

			else {
				EventChecker(Room[I1][J1 - 1]);
				Room[I1][J1] = 0;
				Room[I1][J1 - 1] = 1;
				J1 -= 1;

			}
			break;
		}
		case 's':
		{
			if (I1 + 1 > 4)
			{
				;
			}
			else {
				EventChecker(Room[I1 + 1][J1]);
				Room[I1][J1] = 0;
				Room[I1 + 1][J1] = 1;
				I1 += 1;

			}

			break;
		}
		case 'd':
		{
			if (J1 + 1 > 4)
			{
				;
			}
			else
			{
				EventChecker(Room[I1][J1 + 1]);
				Room[I1][J1] = 0;
				Room[I1][J1 + 1] = 1;
				J1 += 1;
			}

			break;
		}
		case 'w':
		{
			if (I1 - 1 < 0)
			{
				;
			}
			else {
				EventChecker(Room[I1 - 1][J1]);
				Room[I1][J1] = 0;
				Room[I1 - 1][J1] = 1;
				I1 -= 1;
			}
			break;
		}
		default:
		{

			break;
		}


		}
		system("CLS");


	}//while





}// void KeyInput()

int main() {
	KeyInput();
	Items I1, I2, I3, I4, I5, I6;                                                 //Initialising Items.
	I1 = { 1,"Stimpack" };

	I2 = { 2,"Magnum Ammo" };

	I3 = { 3,"Rotting Boot" };

	I4 = { 4,"Old Bread" };

	I5 = { 5,"Canned Water" };

	I6 = { 6,"Mystery Meat" };
	//Format={ Enemy Id   ,Health     ,"Name"               ,Atk1  ,Atk2  ,Atk3  ,Atk4   ,Atk5  };
	E1 = { 1,50,"Undead-Soldier",5,20,5,5,5 };                //Format={ 1          ,50         ,"Undead-Soldier"     ,5     ,20    ,5     ,5       ,5     };

	E2 = { 2,100,"Mob2",10,25,15,5,5 };
	E3;
	E4;
	E5;
	E6;
	E7;
	E8;
	E9;
	E10;
	system("Pause");
	GameLoop(I1, I2, I3, I4, I5, I6);
	return 0;

}
void Inventory(Items, Items, Items, Items, Items, Items, int&);





void GameLoop(Items I1, Items I2, Items I3, Items I4, Items I5, Items I6) {
Start:                                          //Extremely Shitty way to program but should work for now.
	system("CLS");
	int PlayerHealthMax = 100;
	int PlayerHealth = 100;
	int EnemHealth = E1.health;
	int Light_Atk = E1.attack_1;
	int Heavy_Atk = E1.attack_2;

	                                                 //Will create a system here that sets enemy amount,order,and stats.


	int Map[10][10] = { 0 };
	while (PlayerHealth > 0 && EnemHealth > 0)                  //Gameloop(BattleSystem) here.
	{
	StartInGame:
		int n;
		c "\nRecieve Damage(Testing)?\n1-Light Atk\n2-Heavy Atk\n\nDeal Damage(To Enemy)?\n3-Light Atk\n4-Heavy Atk\n\n5-Use Items\n6-Inspect \nChoice:";              ///////////Shows Main Menu////////
		cin >> n;
		switch (n)
		{
		case 1:
		{
			PlayerHealth -= Light_Atk;

			(PlayerHealth < 0) ? PlayerHealth = 0 : PlayerHealth = PlayerHealth;
			(PlayerHealth > 100) ? PlayerHealth = 0 : PlayerHealth = PlayerHealth;
			c "\nCurrent Health:" << PlayerHealth << "\n\n";
			Sleep(HealthPopUp * 2);
			system("CLS");
			break;
		}
		case 2:
		{

			PlayerHealth -= Heavy_Atk;
			(PlayerHealth < 0) ? PlayerHealth = 0 : PlayerHealth = PlayerHealth;
			(PlayerHealth > 100) ? PlayerHealth = 0 : PlayerHealth = PlayerHealth;
			c"\nCurrent Health:" << PlayerHealth << "\n\n";
			Sleep(HealthPopUp * 2);
			system("CLS");

			break;
		}
		case 3:

		{
			EnemHealth -= Light_Atk;
			(EnemHealth < 0) ? EnemHealth = 0 : EnemHealth = EnemHealth;
			c "\nFoe's Current Health:" << EnemHealth << "\n\n";
			Sleep(HealthPopUp * 1.5);
			system("CLS");
			break;
		}
		case 4:
		{
			EnemHealth -= Heavy_Atk;
			(EnemHealth < 0) ? EnemHealth = 0 : EnemHealth = EnemHealth;
			c"\nFoe's Current Health:" << EnemHealth << "\n\n";
			Sleep(HealthPopUp * 1.5);
			system("CLS");

			break;
		case 5:
		{

			c "\n\t\tUse Item....\n";
			c"\t1." << I1.name << "\t2." << I2.name << "\t3." << I3.name << '\n' << "\t4." << I4.name << "\t5." << I5.name << "\t6." << I6.name << "\n\t0.Nothing";
			Inventory(I1, I2, I3, I4, I5, I6, PlayerHealth);
			(PlayerHealth > 100) ? PlayerHealth = 100 : PlayerHealth = PlayerHealth;
			break;
		}
		case 6:
		{
			int InsCh;
			c "Inspect:\n\t1.Player" << "\n\t2.Enemy\n0.Back\nYour Choice:";
			cin >> InsCh;
			switch (InsCh)
			{
			case 1:
			{
				c"\nYour Health:" << PlayerHealth << '.';
				(PlayerHealth == 100) ? c"Fully Healed.You feel like you can take on anything!" : c"";
				(PlayerHealth >= 80 && PlayerHealth < 100) ? c"A few scratches but you should be fine." : c"";
				(PlayerHealth >= 45 && PlayerHealth < 79) ? c"Less than ideal.But not Hopeless" : c"";
				(PlayerHealth >= 20 && PlayerHealth < 44) ? c"Your chances of making out of this alive dwindle with each second." : c"";
				(PlayerHealth < 20 && PlayerHealth >= 1) ? c"......................" : c"";
				Sleep(HealthPopUp * 5);
				system("CLS");
				break;
			}
			case 2:
			{
				c"\nEnemy Health:" << EnemHealth << '.';
				Sleep(HealthPopUp * 5);
				system("CLS");
				break;
			}
			case 0:                               //Go Back;
			{
				system("CLS");
				goto StartInGame;

				break;
			}
			default:
			{
				c"\nNot The Sharpest Tool In The Shed Are You?\n";

				Sleep(HealthPopUp * 2);
				system("CLS");
				break;
			}



			//More Horrible code but necessary.
			}
		default:
		{
			c"\nNot The Sharpest Tool In The Shed Are You?\n";

			Sleep(HealthPopUp * 2);
			system("CLS");
			break;
		}

		}


		}
		}

	}
	if (PlayerHealth == 0)
	{


		c "Iminenent Death in " << "\n 3";
		Sleep(700);
		system("CLS");
		c "Iminenent Death in " << "\n 2";
		Sleep(700);
		system("CLS");
		c "Iminenent Death in " << "\n 1";
		Sleep(700);
		system("CLS");

		Sleep(700);
		system("CLS");
		c "\n\n\n";

		c"\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		c"\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		c"\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		c"\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		c"\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		c"\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		c"\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		c"\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		c"\t\t" << "$$$@*cc@$$$$Bvv&$8zzzzzcW$$$@WuuW$$$$@Mnz@$$$$%*uc**cuvM@$$$8cc%$8vnz*zn8B*uv**cuvM@$$$$$$\n";
		c"\t\t" << "$$$$$u/M$$$$Mf8@nnB$$$$$*j8$$$jj$$$$$$$/&$$$$$$W/M$$$$&nt#$$$xr$$$z/B$$W$$&/#$$$$&nt*$$$$$\n";
		c"\t\t" << "$$$$$$ct%$$Wr@$xj$$$$$$$$Mt%$$fr$$$$$$$/&$$$$$$W/M$$$$$$z/c$$xr$$$z/B$$$$$&/#$$$$$$#/v$$$$\n";
		c"\t\t" << "$$$$$$$cj@&x@$%/*$$$$$$$$$rn$$fr$$$$$$$/&$$$$$$W/M$$$$$$$x/@$xr$$$z/B$$B$$&/#$$$$$$$n/%$$$\n";
		c"\t\t" << "$$$$$$$$nrrB$$W/M$$$$$$$$$ct$$fx$$$$$$$/&$$$$$$W/M$$$$$$$*/8$xr$$$z/vcvf$$&/#$$$$$$$#/&$$$\n";
		c"\t\t" << "$$$$$$$$%/c$$$&/c$$$$$$$$$vt$$jx$$$$$$$/&$$$$$$W/M$$$$$$$*/@$xr$$$z/B$$8$$&/#$$$$$$$#/%$$$\n";
		c"\t\t" << "$$$$$$$$@/c$$$$ntB$$$$$$$$fz$$xr$$$$$$$/B$$$$$$W/M$$$$$$$rn$$xr$$$z/B$$$$$&/#$$$$$$$rx$$$$\n";
		c"\t\t" << "$$$$$$$$@/c$$$$$vrB$$$$$@nu$$$8tW$$$$$cc$$$$$$$W/M$$$$$Bnr@$$xr$$$z/%$$$B$&/*$$$$$@urB$$$$\n";
		c"\t\t" << "$$$$$$$$$$$$$$$$$$$$%8%$$$$$$$$$$$%8B$$$$$$$$$$$$@BBB@$$$$$$$$$$$$$$$$$@$$$$@BBB@$$$$$$$$$\n";
		c"\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		c"\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		c"\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		c"\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		c"\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		c"\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";

		c"\n\n\n\t\tLOADING.......";
		Sleep(HealthPopUp);
		c"You Died at:\n";
		for (int i = 1;i <= 10;i++)
		{
			for (int j = 1;j <= 10;j++)
			{
				c "[" << char(i + 64) << "-" << (j) << "]";
			}
			c  endl;
		}
		Sleep(HealthPopUp * 4);

		c "\n\n\n GIVE UP? :Y/N" << endl;
		char retry;
		cin >> retry;
		retry = toupper(retry);
		if (retry == 'N')
		{
			goto Start;
		}
		else
		{

		}
	}
	else if (EnemHealth == 0)
	{
		c "Foe's Iminenent Death in " << "\n 3";
		Sleep(700);
		system("CLS");
		c "Foe's Iminenent Death in " << "\n 2";
		Sleep(700);
		system("CLS");
		c "Foe's Iminenent Death in " << "\n 1";
		Sleep(700);
		system("CLS");

		Sleep(700);
		system("CLS");
		c "\n\n\n";
		c"VICTORY ACHIEVED!";


		Sleep(HealthPopUp * 4);
		c "\n\n\n\t\tYou Obtained an Item.....";
		srand(time(NULL));
		int id = (rand() % 5) + 1;
		int LootAmount = (rand() % 2) + 1;
		switch (id)                                                                                    //Loot-Generator
		{
		case 1:
			c I1.name << " X" << LootAmount;
			break;

		case 2:
			c I2.name << " X" << LootAmount;
			break;

		case 3:
			c I3.name << " X" << 1;
			break;

		case 4:
			c I4.name << " X" << LootAmount;
			break;

		case 5:
			c I5.name << " X" << LootAmount;
			break;
		case 6:
			c I6.name << " X" << LootAmount;
		default:
			c "hmmmm.....This shouldn't be possible.....how did you..?";
			break;
		}
		Sleep(HealthPopUp * 4.5);
		system("CLS");
		c "\n\n\n\n Try Again? :Y/N" << endl;
		char retry;
		cin >> retry;
		retry = toupper(retry);
		if (retry == 'Y')
		{
			goto Start;
		}
		else
		{

		}
	}
}




void Inventory(Items I1, Items I2, Items I3, Items I4, Items I5, Items I6, int& PlayerHealth)
{
	int Choice;
	c "\n\tYour Choice:";
	cin >> Choice;
	switch (Choice)
	{
	case 1:
	{
		c"\nYou used " << I1.name << "....healed 50 HP!";                    //Stimpack
		PlayerHealth += 50;
		Sleep(HealthPopUp * 5);
		system("ClS");
		break;
	}
	case 2:
	{
		c"\nYou loaded your Magnum with " << I2.name;                  //Magnum Ammo
		Sleep(HealthPopUp * 5);
		system("ClS");
		break;
	}
	case 3:
	{
		c"\nYou used " << I3.name << ".Your Defense Increased!";              //Boot
		Sleep(HealthPopUp * 5);
		system("ClS");
		break;
	}
	case 4:
	{
		c"\nYou consumed " << I4.name << "...";                 //Bread
		Sleep(HealthPopUp);
		c".";
		Sleep(HealthPopUp);
		c".";
		Sleep(HealthPopUp);
		c".";
		Sleep(HealthPopUp);
		c"It's very old.....You healed 20HP!";
		PlayerHealth += 20;
		Sleep(HealthPopUp * 5);
		system("ClS");
		break;
	}
	case 5:
	{
		c"\nYou Drank " << I5.name << ".You healed 10 HP.";                 //Water
		PlayerHealth += 10;
		Sleep(HealthPopUp * 5);
		system("ClS");
		break;
	}
	case 6:
	{
		c"\nYou Ate " << I6.name << ".You healed 35 HP.";
		PlayerHealth += 35;
		Sleep(HealthPopUp * 5);
		system("CLS");
		break;
	}
	case 0:                                                              //Go Back
	{
		system("ClS");
		break;
	}
	default:
	{
		c"\nHmmmmm....doesn't seem to exist.....?";
		Sleep(HealthPopUp * 5);
		system("ClS");
		break;
	}
	}
}

void EventChecker(int EventCase)
{
	srand(time(NULL));
	int RandomTreasure = (rand() % 2) + 1;
	c EventCase;
	switch (EventCase)
	{
	case 0:
	{


		c "\nNothing here";
		Sleep(HealthPopUp / 8);
		break;
	}
	case 6:
	{
		c"\nYou Encountered Enemies";
		Sleep(HealthPopUp);

		break;

	}
	case 123123:
	{

	}
	case 7:
	{
		c "\nYou found an Item!";
		c "\nSome Item.";
		Sleep(HealthPopUp/1.5 );
		break;
	}
	default:
		break;
	}
}