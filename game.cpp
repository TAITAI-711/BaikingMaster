// Q[{Ò

#define CONIOEX
#include "game.h"
#include "main.h"
#include "timer.h"
#include "food.h"
#include "SOUND.h"

// \¢ÌÏé¾
PLAYER Player;
PLAYER_POS Player_pos;
OTHER_POS UI_moji_pos[4];
OTHER_POS FOOD_moji;
OTHER_POS AA_count_pos[4];
AA_SIZE	AA_size[AA_SYURUI];
RYOURI_UKETORI Ryouri_uketori;

//---------------------------------------------------------
// LN^[ÌAA
//---------------------------------------------------------
// v[[(AAÌíÞ:0)
const char* AA_player_0[] = {
	" È,,È   ",
	"(*EÖE) ",
	"(ÂPPPO",
	" Z   Z  ",
	NULL
};
const char* AA_player_0_1[] = {
	"   È,,È ",
	" (EÖE*)",
	"OPPP¼)",
	"  Z   Z ",
	NULL
};
const char* AA_player_1[] = {
	" È,,È   ",
	"(*EÖ¡) ",
	"(ÂPPPO",
	" Z   Z  ",
	NULL
};
const char* AA_player_1_1[] = {
	"   È,,È ",
	" (¡ÖE*)",
	"OPPP¼)",
	"  Z   Z ",
	NULL
};
const char* AA_player_2[] = {
	" È,,È   ",
	"(*E¡¡) ",
	"(ÂPPPO",
	" Z   Z  ",
	NULL
};
const char* AA_player_2_1[] = {
	"   È,,È ",
	" (¡¡E*)",
	"OPPP¼)",
	"  Z   Z ",
	NULL
};
const char* AA_player_3[] = {
	" È,,¡   ",
	"(*E¡¡) ",
	"(ÂPPPO",
	" Z   Z  ",
	NULL
};
const char* AA_player_3_1[] = {
	"   ¡,,È ",
	" (¡¡E*)",
	"OPPP¼)",
	"  Z   Z ",
	NULL
};
const char* AA_player_4[] = {
	" È¡¡   ",
	"(*E¡¡) ",
	"(ÂPPPO",
	" Z   Z  ",
	NULL
};
const char* AA_player_4_1[] = {
	"   ¡¡È ",
	" (¡¡E*)",
	"OPPP¼)",
	"  Z   Z ",
	NULL
};
const char* AA_player_5[] = {
	" È¡¡   ",
	"(*¡¡) ",
	"(ÂPPPO",
	" Z   Z  ",
	NULL
};
const char* AA_player_5_1[] = {
	"   ¡¡È ",
	" (¡¡*)",
	"OPPP¼)",
	"  Z   Z ",
	NULL
};

// ¿Ìg(AAÌíÞ:1)
const char* AA_ryouri_0[] = {
	"||      ²Íñ      ||",
	"||    T_t«    ||",
	"||                  ||",
	"||      6000 ~     ||",
	"||        ||",
	"======================",
	NULL
};
const char* AA_ryouri_1[] = {
	"======================",
	"||      ²Íñ      ||",
	"||    T_t«    ||",
	"||                  ||",
	"||      6000 ~     ||",
	"||        ||",
	NULL
};
const char* AA_ryouri_2[] = {
	"======================",
	NULL
};

// UIÌg(AAÌíÞ:2)
const char* AA_UI_0[] = {
	"§ÀÔ",
	"ÁÄ¢é¿Ì",
	NULL
};
const char* AA_UI_1[] = {
	"                ",
	"     60  b     ",
	"                ",
	NULL
};
const char* AA_UI_2[] = {
	"                ",
	"      ",
	"                ",
	NULL
};
const char* AA_UI_2_1[] = {
	"                ",
	"      ",
	"                ",
	NULL
};
const char* AA_UI_2_2[] = {
	"                ",
	"      ",
	"                ",
	NULL
};
const char* AA_UI_2_3[] = {
	"                ",
	"      ",
	"                ",
	NULL
};
const char* AA_UI_2_4[] = {
	"                ",
	"      ",
	"                ",
	NULL
};
const char* AA_UI_2_5[] = {
	"                ",
	"      ",
	"                ",
	NULL
};

// H×éÆ±ë(AAÌíÞ:3)
const char* AA_EAT_0[] = {
	"||",
	NULL
};

// H×éÆ±ëÌ¶
const char* AA_EAT_MOJI[] = {
	"e",
	"  ",
	"b",
	"  ",
	"u",
	"  ",
	"",
	NULL
};

// JEg(AAÌíÞ:4)
const char* AA_COUNT_NUM_1[] =
{
	"    ¡",
	"    ¡",
	"    ¡",
	"    ¡",
	"    ¡",
	NULL
};
const char* AA_COUNT_NUM_2[] =
{
	"¡¡¡",
	"    ¡",
	"¡¡¡",
	"¡    ",
	"¡¡¡",
	NULL
};
const char* AA_COUNT_NUM_3[] =
{
	"¡¡¡",
	"    ¡",
	"¡¡¡",
	"    ¡",
	"¡¡¡",
	NULL
};
// (AAÌíÞ:5)
const char* AA_COUNT_END[] =
{
	"    ¡  ¡      ¡          ¡    ¡",
	"¡¡¡¡  ¡  ¡¡¡¡¡    ¡    ¡",
	"  ¡¡¡        ¡¡  ¡    ¡¡  ¡",
	"¡  ¡  ¡    ¡¡    ¡          ¡",
	"¡¡¡  ¡      ¡  ¡        ¡¡¡",
	NULL
};
// (AAÌíÞ:6)
const char* AA_COUNT_WAKU_1[] =
{
	"==========================",
	"||                      ||",
	"||                      ||",
	"||                      ||",
	"||                      ||",
	"||                      ||",
	"||                      ||",
	"||                      ||",
	"==========================",
	NULL
};
const char* AA_COUNT_WAKU_1_KUHAKU[] =
{
	"                          ",
	"                          ",
	"                          ",
	"                          ",
	"                          ",
	"                          ",
	"                          ",
	"                          ",
	"                          ",
	NULL
};
// (AAÌíÞ:7)
const char* AA_COUNT_WAKU_2[] =
{
	"============================================",
	"||                                        ||",
	"||                                        ||",
	"||                                        ||",
	"||                                        ||",
	"||                                        ||",
	"||                                        ||",
	"||                                        ||",
	"============================================",
	NULL
};


//---------------------------------------------------------
// O[oÏé¾
//---------------------------------------------------------
static DWORD time;						// cèÔ
static int game_start_count = 4;		// Q[ÌJEg\¦p
static bool draw_one = true;			// ÅÌPñÌÝ\¦Ì»èp
static bool PK_SP_ET_on = false;		// Xy[X{^ª³êÄ¢é©»èp
static bool game_end_hantei = false;	// Q[ÌI¹»è
static bool game_start_hantei = false;	// Q[ÌJn»è

//---------------------------------------------------------
// Öè`
//---------------------------------------------------------

void game_Init(void)
{
	system("cls");
	// J[\ñ\¦
	setcursortype(NOCURSOR);
	// \¢Ìú»
	Player = {};
	Player_pos = {};
	FOOD_moji = {};
	Ryouri_uketori = {};
	// »èú»
	game_start_hantei = false;
	game_end_hantei = false;
	game_start_count = 4;
	draw_one = true;
	// ^C}[Zbg
	TimerInit();
	setTimerRemaining(GAME_TIME + COUNT_TIME);
	// AAÌîñüÍ
	AA_info_Init();
	// v[[ÌúÝè
	player_set_Init();
	// UIÌÀWÝè
	ui_waku_Init();
	// H×¨ÌîñüÍ
	food_Init(AA_size[1].tate, AA_size[1].yoko);	
}

void game_End(void)
{
	food_End();
	SoundStop(SOUND_GAME_BGM);
	scene_kirikae(3);
}

void game_Update(void)
{
	// ^C}[ÌcèÔ
	time = getTimerRemaining();
	if (!game_start_hantei && (time <= GAME_TIME))
	{
		// ¹y
		SoundPlayLoop(SOUND_GAME_BGM);
		game_start_hantei = true;
	}
	if (!game_end_hantei)
	{
		if (game_start_hantei)
		{
			// v[[Ú®
			player_move_Update();
			// v[[ÌcÁ·
			p_zanzou_kesu_Update();
		}
		// ¿Ì
		food_Update(time);
		// ¿ÌgÌó¯æèªXV
		ryouri_waku_uketori_Update();
		// vC[ÌÁÄ¢é¿Ì
		player_food_have_Update();
	}
	// I¹
	if (time == 0 && !game_end_hantei)
	{
		// ¹y
		SoundPlayOnce(SOUND_END);
		// ^C}[ÔZbg
		setTimerRemaining(2000);
		// Q[ÌI¹»èI
		game_end_hantei = true;
		// ÅÌ1ñÌÝ\¦Ì»èI
		draw_one = true;
	}
	else if (time == 0 && game_end_hantei)
	{
		scene_kirikae_hantei_on();
	}
}

void game_Draw(void)
{
	// JEg\¦
	AA_count_NUM_Draw();
	
	if (!game_end_hantei)
	{
		if (draw_one) // ÅÌ1ñÌÝ\¦
		{
			draw_one = false;
			// ¿Ìg\¦
			ryouri_waku_Draw();
			// UIÌg\¦
			ui_waku_Draw();
			// H×éÆ±ëÌ¶\¦
			print_x_y_all(4, 13, AA_EAT_MOJI, WHITE);
		}

		// v[[ÌcÁ·ó\¦
		p_zanzou_kesu_Draw();
		// v[[\¦
		player_Draw();
		// ¿ÌgÌó¯æèª\¦
		ryouri_waku_uketori_Draw();
		// H×éÆ±ëÌ\¦
		food_eat_Draw();
		// UI\¦
		ui_Draw();
		// ¿\¦
		food_Draw();
	}
	else
	{
		if (draw_one)
		{
			// IíèÌÊuüÍ
			AA_count_END_Draw();
			draw_one = false;
		}
	}
}

//---------------------------------------------------------
// v[[ÌÚ®
//---------------------------------------------------------
void player_move_Update(void)
{
	// {^üÍÅÚ®
	if (inport(PK_A) || inport(PK_LEFT))
	{
		Player_pos.x -= PLAYER_MOVE_X;
	}
	if (inport(PK_D) || inport(PK_RIGHT))
	{
		Player_pos.x += PLAYER_MOVE_X;
	}
	if (inport(PK_W) || inport(PK_UP))
	{
		Player_pos.y -= PLAYER_MOVE_Y;
	}
	if (inport(PK_S) || inport(PK_DOWN))
	{
		Player_pos.y += PLAYER_MOVE_Y;
	}

	// vC[ªÀEÀWð´¦½çß·
	if (Player_pos.x < Player_pos.limit_L)
	{
		Player_pos.x = Player_pos.limit_L;
	}
	if (Player_pos.x > Player_pos.limit_R)
	{
		Player_pos.x = Player_pos.limit_R;
	}
	if (Player_pos.y < Player_pos.limit_U)
	{
		Player_pos.y = Player_pos.limit_U;
	}
	if (Player_pos.y > Player_pos.limit_D)
	{
		Player_pos.y = Player_pos.limit_D;
	}
}

//---------------------------------------------------------
// ¿ðH×éÊuÉ¢é©»è
//---------------------------------------------------------
void food_eat_Update(void)
{
	// H×éÊuÉ¢é©»è
	if ((int)Player_pos.x <= Player_pos.limit_L)
	{
		Ryouri_uketori.eat_iti = true;
	}
	else
	{
		Ryouri_uketori.eat_iti = false;
	}
}

//---------------------------------------------------------
// vC[ÌÁÄ¢é¿Ì
//---------------------------------------------------------
void player_food_have_Update(void)
{
	//v[[ªó¯æèÂ\ÈÊu©»è
	player_uketori_iti();
	// ¿ðH×éÊuÉ¢é©»è
	food_eat_Update();

	if (!inport(PK_SP) && !inport(PK_ENTER))
	{
		PK_SP_ET_on = false;
	}
	else if (!(PK_SP_ET_on))
	{
		for (int i = 0; i < 6; i++)
		{
			if (Ryouri_uketori.iti == i && Ryouri_uketori.ok[i])
			{
				// ¹y
				SoundPlayOnce(SOUND_UKETORI);
				// ÁÄ¢é¿ÌÊXV
				Player.food_have += ryouri_amount(i);
				// ó¯æÁ½¿ÌÔæ¾
				Player.food_uketori_num[Player.uketori_num] = ryouri_uketori(i);
				Player.uketori_num += 1;
				
				PK_SP_ET_on = true;
			}
		}
	}
	// ¿ðH×é
	if ((Ryouri_uketori.eat_iti) && (Player.food_have > 0))
	{
		// ¹y
		SoundPlayOnce(SOUND_TABERU);
		// ÁÄ¢é¿ÌÊð0É·é
		Player.food_have = 0;
		// ó¯æÁ½¿ðH×½¿É·é
		for (int i = 0; i < Player.uketori_num; i++)
		{
			Player.food_eat_num[Player.eat_num] = Player.food_uketori_num[i];
			Player.eat_num += 1;
		}
		// ó¯æÁ½¿Ìð0É·é
		Player.uketori_num = 0;
	}
	// (eXg)¿ÌÄéÀE
	if (Player.food_have > 5)
	{
		Player.food_have = 5;
	}
}

//---------------------------------------------------------
// vC[ÌúÝè
//---------------------------------------------------------
void player_set_Init(void)
{
	// úÀWÝè
	Player_pos.x = PLAYER_S_POS_X;
	Player_pos.y = PLAYER_S_POS_Y;
	Player_pos.previous_x = PLAYER_S_POS_X;
	Player_pos.previous_y = PLAYER_S_POS_Y;
	// úü«Ýè
	Player_pos.muki = 0;
	// ÀEÀWüÍ
	p_pos_limit_input();
}

//---------------------------------------------------------
// v[[ÌÀEÀWüÍ
//---------------------------------------------------------
void p_pos_limit_input(void)
{
	Player_pos.limit_L = (float)(FOOD_EAT_X + AA_size[3].yoko);	// ¶ÌÀE
	Player_pos.limit_R = (float)(UI_X - AA_size[0].yoko);		// EÌÀE
	Player_pos.limit_U = (float)(AA_size[1].tate + 1);			// ãÌÀE
	Player_pos.limit_D = (float)((SCREEN_Y + 1) -
		(AA_size[0].tate + AA_size[1].tate));					// ºÌÀE
}

//---------------------------------------------------------
// v[[ªó¯æèÂ\ÈÊu©»è
//---------------------------------------------------------
void player_uketori_iti(void)
{
	// ðÉÄÍÜçÈ©Á½çó¯æèsÂ
	Ryouri_uketori.iti = -1;

	if ((int)Player_pos.y <= (int)Player_pos.limit_U)
	{
		if (((int)Player_pos.x >= RYOURI_WAKU_1_4_POS_X) &&
			((int)Player_pos.x + (AA_size[0].yoko - 1) <=
				RYOURI_WAKU_1_4_POS_X + (AA_size[1].yoko - 1)))
		{
			Ryouri_uketori.iti = 0; // ¿PÌÊu
		}
		else if (((int)Player_pos.x >= RYOURI_WAKU_2_5_POS_X) &&
			((int)Player_pos.x + (AA_size[0].yoko - 1) <=
				RYOURI_WAKU_2_5_POS_X + (AA_size[1].yoko - 1)))
		{
			Ryouri_uketori.iti = 1; // ¿QÌÊu
		}
		else if (((int)Player_pos.x >= RYOURI_WAKU_3_6_POS_X) &&
			((int)Player_pos.x + (AA_size[0].yoko - 1) <=
				RYOURI_WAKU_3_6_POS_X + (AA_size[1].yoko - 1)))
		{
			Ryouri_uketori.iti = 2; // ¿RÌÊu
		}
	}
	else if ((int)Player_pos.y >= (int)Player_pos.limit_D)
	{
		if (((int)Player_pos.x >= RYOURI_WAKU_1_4_POS_X) &&
			((int)Player_pos.x + (AA_size[0].yoko - 1) <=
				RYOURI_WAKU_1_4_POS_X + (AA_size[1].yoko - 1)))
		{
			Ryouri_uketori.iti = 3; // ¿SÌÊu
		}
		else if (((int)Player_pos.x >= RYOURI_WAKU_2_5_POS_X) &&
			((int)Player_pos.x + (AA_size[0].yoko - 1) <=
				RYOURI_WAKU_2_5_POS_X + (AA_size[1].yoko - 1)))
		{
			Ryouri_uketori.iti = 4; // ¿TÌÊu
		}
		else if (((int)Player_pos.x >= RYOURI_WAKU_3_6_POS_X) &&
			((int)Player_pos.x + (AA_size[0].yoko - 1) <=
				RYOURI_WAKU_3_6_POS_X + (AA_size[1].yoko - 1)))
		{
			Ryouri_uketori.iti = 5; // ¿UÌÊu
		}
	}
}

//---------------------------------------------------------
// UIÌ\¦
//---------------------------------------------------------
void ui_Draw(void)
{
	int food_have_x = UI_moji_pos[3].x;// ÁÄ¢é¿Ì\¦XÀW
	int food_have_y = UI_moji_pos[3].y;// ÁÄ¢é¿Ì\¦YÀW

	// cèÔ\¦
	if (time / 1000 < 10)
	{
		print_x_y_one_num(UI_moji_pos[1].x + 5, UI_moji_pos[1].y + 1, 0, WHITE);
		print_x_y_one_num(UI_moji_pos[1].x + 6, UI_moji_pos[1].y + 1, time / 1000, WHITE);
	}
	else if (time / 1000 < 61)
	{
		print_x_y_one_num(UI_moji_pos[1].x + 5, UI_moji_pos[1].y + 1, time / 1000, WHITE);
	}
	else
	{
		print_x_y_one_num(UI_moji_pos[1].x + 5, UI_moji_pos[1].y + 1, 60, WHITE);
	}
	// ÁÄ¢é¿Ì\¦
	switch (Player.food_have)
	{
	case 0:
		print_x_y_all(food_have_x, food_have_y, AA_UI_2, RYOURI_HAVE_COLOR_2);
		break;
	case 1:
		print_x_y_all(food_have_x, food_have_y, AA_UI_2_1, RYOURI_HAVE_COLOR_2);
		break;
	case 2:
		print_x_y_all(food_have_x, food_have_y, AA_UI_2_2, RYOURI_HAVE_COLOR_2);
		break;
	case 3:
		print_x_y_all(food_have_x, food_have_y, AA_UI_2_3, RYOURI_HAVE_COLOR_2);
		break;
	case 4:
		print_x_y_all(food_have_x, food_have_y, AA_UI_2_4, RYOURI_HAVE_COLOR_2);
		break;
	case 5:
		print_x_y_all(food_have_x, food_have_y, AA_UI_2_5, RYOURI_HAVE_COLOR_2);
		break;
	default:
		break;
	}
}

//---------------------------------------------------------
// v[[Ì\¦
//---------------------------------------------------------
void player_Draw(void)
{
	const char* p;
	p = AA_player_0[0];
	switch (Player.food_have)
	{
	case 0:
		if (Player_pos.muki == 0)
		{
			print_x_y_all((int)Player_pos.x, (int)Player_pos.y, AA_player_0, WHITE);
		}
		else
		{
			print_x_y_all((int)Player_pos.x, (int)Player_pos.y, AA_player_0_1, WHITE);
		}
		break;
	case 1:
		if (Player_pos.muki == 0)
		{
			print_x_y_all((int)Player_pos.x, (int)Player_pos.y, AA_player_1, WHITE);
		}
		else
		{
			print_x_y_all((int)Player_pos.x, (int)Player_pos.y, AA_player_1_1, WHITE);
		}
		break;
	case 2:
		if (Player_pos.muki == 0)
		{
			print_x_y_all((int)Player_pos.x, (int)Player_pos.y, AA_player_2, WHITE);
		}
		else
		{
			print_x_y_all((int)Player_pos.x, (int)Player_pos.y, AA_player_2_1, WHITE);
		}
		break;
	case 3:
		if (Player_pos.muki == 0)
		{
			print_x_y_all((int)Player_pos.x, (int)Player_pos.y, AA_player_3, WHITE);
		}
		else
		{
			print_x_y_all((int)Player_pos.x, (int)Player_pos.y, AA_player_3_1, WHITE);
		}
		break;
	case 4:
		if (Player_pos.muki == 0)
		{
			print_x_y_all((int)Player_pos.x, (int)Player_pos.y, AA_player_4, WHITE);
		}
		else
		{
			print_x_y_all((int)Player_pos.x, (int)Player_pos.y, AA_player_4_1, WHITE);
		}
		break;
	case 5:
		if (Player_pos.muki == 0)
		{
			print_x_y_all((int)Player_pos.x, (int)Player_pos.y, AA_player_5, WHITE);
		}
		else
		{
			print_x_y_all((int)Player_pos.x, (int)Player_pos.y, AA_player_5_1, WHITE);
		}
		break;
	default:
		break;
	}
}

//---------------------------------------------------------
// ¿Ìg\¦
//---------------------------------------------------------
void ryouri_waku_Draw(void)
{
	print_x_y_all(RYOURI_WAKU_1_4_POS_X, 1, AA_ryouri_0, WHITE); //g1
	print_x_y_all(RYOURI_WAKU_2_5_POS_X, 1, AA_ryouri_0, WHITE); //g2
	print_x_y_all(RYOURI_WAKU_3_6_POS_X, 1, AA_ryouri_0, WHITE); //g3
	print_x_y_all(RYOURI_WAKU_1_4_POS_X,
		(SCREEN_Y + 1) - AA_size[1].tate, AA_ryouri_1, WHITE); //g4
	print_x_y_all(RYOURI_WAKU_2_5_POS_X,
		(SCREEN_Y + 1) - AA_size[1].tate, AA_ryouri_1, WHITE); //g5
	print_x_y_all(RYOURI_WAKU_3_6_POS_X,
		(SCREEN_Y + 1) - AA_size[1].tate, AA_ryouri_1, WHITE); //g6
}

//---------------------------------------------------------
// ¿ÌgÌó¯æèªXV
//---------------------------------------------------------
void ryouri_waku_uketori_Update(void)
{
	for (int i = 0; i < 6; i++)
	{
		if (((Player.food_have + ryouri_amount(i)) > 5) || 
			ryouri_kirikae_hantei(i)) // ó¯æèsÂ
		{
			Ryouri_uketori.waku_color[i] = RED;
			Ryouri_uketori.ok[i] = false;
		}
		else // ó¯æèÂ\
		{
			Ryouri_uketori.waku_color[i] = GREEN;
			Ryouri_uketori.ok[i] = true;
		}
	}
}

//---------------------------------------------------------
// ¿ÌgÌó¯æèª\¦
//---------------------------------------------------------
void ryouri_waku_uketori_Draw(void)
{	
	print_x_y_all(RYOURI_WAKU_1_4_POS_X, AA_size[1].tate, 
		AA_ryouri_2, Ryouri_uketori.waku_color[0]); //g1
	print_x_y_all(RYOURI_WAKU_2_5_POS_X, AA_size[1].tate, 
		AA_ryouri_2, Ryouri_uketori.waku_color[1]); //g2
	print_x_y_all(RYOURI_WAKU_3_6_POS_X, AA_size[1].tate, 
		AA_ryouri_2, Ryouri_uketori.waku_color[2]); //g3
	print_x_y_all(RYOURI_WAKU_1_4_POS_X, (SCREEN_Y + 1) - AA_size[1].tate, 
		AA_ryouri_2, Ryouri_uketori.waku_color[3]); //g4
	print_x_y_all(RYOURI_WAKU_2_5_POS_X, (SCREEN_Y + 1) - AA_size[1].tate, 
		AA_ryouri_2, Ryouri_uketori.waku_color[4]); //g5
	print_x_y_all(RYOURI_WAKU_3_6_POS_X, (SCREEN_Y + 1) - AA_size[1].tate,
		AA_ryouri_2, Ryouri_uketori.waku_color[5]); //g6
}

//---------------------------------------------------------
// H×éÆ±ëÌ\¦
//---------------------------------------------------------
void food_eat_Draw(void)
{
	int color; // F

	if (Player.food_have > 0)
	{
		color = GREEN;
	}
	else
	{
		color = RED;
	}
	for (int i = 0; i < SCREEN_Y; i++)
	{
		print_x_y_one(10, 1 + i, AA_EAT_0[0], color);
	}
}

//---------------------------------------------------------
// UIÌg\¦
//---------------------------------------------------------
void ui_waku_Draw(void)
{
	textbackground(LIGHTGRAY); // DFÉÏX
	// SÌðDFÉ·é
	for (int i = 1; i <= SCREEN_Y; i++)
	{
		for (int j = 0; j < (SCREEN_X + 1) - UI_X; j++)
		{
			gotoxy(UI_X + j, i);
			printf(" ");
		}
	}
	// §ÀÔÌ¶\¦
	print_x_y_one(UI_moji_pos[0].x, UI_moji_pos[0].y, AA_UI_0[0], BLACK);
	// ÁÄ¢é¿ÌÌ¶\¦
	print_x_y_one(UI_moji_pos[2].x, UI_moji_pos[2].y, AA_UI_0[1], RYOURI_HAVE_COLOR_1);
	textbackground(BLACK); // ÉÏX

	// §ÀÔ
	print_x_y_all(UI_moji_pos[1].x, UI_moji_pos[1].y, AA_UI_1, WHITE);
	// ÁÄ¢é¿Ì
	print_x_y_all(UI_moji_pos[3].x, UI_moji_pos[3].y, AA_UI_2, RYOURI_HAVE_COLOR_2);
}
//---------------------------------------------------------
// UIÌgÀWÝè
//---------------------------------------------------------
void ui_waku_Init(void)
{
	// §ÀÔÌ¶
	UI_moji_pos[0].x = UI_X + (((SCREEN_X + 1) - UI_X - strlen(AA_UI_0[0])) / 2);
	UI_moji_pos[0].y = UI_TIME_Y;
	// §ÀÔ
	UI_moji_pos[1].x = UI_X + (((SCREEN_X + 1) - UI_X - AA_size[2].yoko) / 2);
	UI_moji_pos[1].y = UI_TIME_Y + 2;
	// ÁÄ¢é¿ÌÌ¶
	UI_moji_pos[2].x = UI_X + (((SCREEN_X + 1) - UI_X - strlen(AA_UI_0[1])) / 2);
	UI_moji_pos[2].y = UI_RYOURI_Y;
	// ÁÄ¢é¿Ì
	UI_moji_pos[3].x = UI_X + (((SCREEN_X + 1) - UI_X - AA_size[2].yoko) / 2);
	UI_moji_pos[3].y = UI_RYOURI_Y + 2;
}

//---------------------------------------------------------
// v[[ÌcÁ·
//---------------------------------------------------------
void p_zanzou_kesu_Update(void)
{
	Player_pos.zanzou = 0;

	if ((int)Player_pos.previous_x != (int)Player_pos.x ||
		(int)Player_pos.previous_y != (int)Player_pos.y)
	{
		if ((int)Player_pos.previous_y > (int)Player_pos.y) // ãÉÚ®
		{
			Player_pos.zanzou += 1;
		}
		if ((int)Player_pos.previous_y < (int)Player_pos.y) // ºÉÚ®
		{
			Player_pos.zanzou += 2;
		}
		if ((int)Player_pos.previous_x > (int)Player_pos.x) // ¶ÉÚ®
		{
			Player_pos.zanzou += 4;
			Player_pos.muki = 1; // ü«ð¶ÉÏX
		}
		if ((int)Player_pos.previous_x < (int)Player_pos.x) // EÉÚ®
		{
			Player_pos.zanzou += 8;
			Player_pos.muki = 0; // ü«ðEÉÏX
		}
	}
}

//---------------------------------------------------------
// v[[ÌcÁ·ó\¦
//---------------------------------------------------------
void p_zanzou_kesu_Draw(void)
{
	// ºðÁ·(ãÉÚ®)
	if (Player_pos.zanzou == 1 || Player_pos.zanzou == 5 || Player_pos.zanzou == 9)
	{
		for (int i = 0; i < AA_size[0].yoko; i++)
		{
			gotoxy((int)Player_pos.previous_x + i,
				(int)Player_pos.previous_y + (AA_size[0].tate - 1));
			printf(" ");
		}
	}
	// ãðÁ·(ºÉÚ®)
	if (Player_pos.zanzou == 2 || Player_pos.zanzou == 6 || Player_pos.zanzou == 10)
	{
		for (int i = 0; i < AA_size[0].yoko; i++)
		{
			gotoxy((int)Player_pos.previous_x + i, (int)Player_pos.previous_y);
			printf(" ");
		}
	}
	// EðÁ·(¶ÉÚ®)
	if (Player_pos.zanzou == 4 || Player_pos.zanzou == 5 || Player_pos.zanzou == 6)
	{
		for (int i = 0; i < AA_size[0].tate; i++)
		{
			gotoxy((int)Player_pos.previous_x + (AA_size[0].yoko - 1), 
				(int)Player_pos.previous_y + i);
			printf(" ");
		}
	}
	// ¶ðÁ·(EÉÚ®)
	if (Player_pos.zanzou == 8 || Player_pos.zanzou == 9 || Player_pos.zanzou == 10)
	{
		for (int i = 0; i < AA_size[0].tate; i++)
		{
			gotoxy((int)Player_pos.previous_x, (int)Player_pos.previous_y + i);
			printf(" ");
		}
	}
	// vC[ÌOÌÊuÉ»ÝnðüÍ
	Player_pos.previous_x = Player_pos.x;
	Player_pos.previous_y = Player_pos.y;
}

//---------------------------------------------------------
// AAÌîñüÍ
//---------------------------------------------------------
void AA_info_Init(void)
{
	// vC[Ì³Æ
	AA_size_input(AA_player_0, AA_size, 0);
	// ¿ÌgÌ³Æ
	AA_size_input(AA_ryouri_0, AA_size, 1);
	// UIÌ³Æ
	AA_size_input(AA_UI_1, AA_size, 2);
	// H×éÆ±ëÌ³Æ
	AA_size_input(AA_EAT_0, AA_size, 3);
	// JEgÌÌ³Æ
	AA_size_input(AA_COUNT_NUM_1, AA_size, 4);
	// JEgÌIíèÌ³Æ
	AA_size_input(AA_COUNT_END, AA_size, 5);
	// JEgÌg1Ì³Æ
	AA_size_input(AA_COUNT_WAKU_1, AA_size, 6);
	// JEgÌg2Ì³Æ
	AA_size_input(AA_COUNT_WAKU_2, AA_size, 7);
	// AAJEgÌ\¦ÀWüÍ
	// 
	AA_count_pos[0].x = ((SCREEN_X + 1) - AA_size[4].yoko) / 2;
	AA_count_pos[0].y = ((SCREEN_Y + 1) - AA_size[4].tate) / 2;
	// Iíè
	AA_count_pos[1].x = ((SCREEN_X + 1) - AA_size[5].yoko) / 2;
	AA_count_pos[1].y = ((SCREEN_Y + 1) - AA_size[5].tate) / 2;
	// g1
	AA_count_pos[2].x = ((SCREEN_X + 1) - AA_size[6].yoko) / 2;
	AA_count_pos[2].y = ((SCREEN_Y + 1) - AA_size[6].tate) / 2;
	// g2
	AA_count_pos[3].x = ((SCREEN_X + 1) - AA_size[7].yoko) / 2;
	AA_count_pos[3].y = ((SCREEN_Y + 1) - AA_size[7].tate) / 2;
}

//---------------------------------------------------------
// AA¨íèÌ\¦
//---------------------------------------------------------
void AA_count_END_Draw(void)
{
	textbackground(GREEN);
	// g2\¦
	print_x_y_all(AA_count_pos[3].x, AA_count_pos[3].y, AA_COUNT_WAKU_2, YELLOW);
	// Iíè\¦
	print_x_y_all(AA_count_pos[1].x, AA_count_pos[1].y, AA_COUNT_END, WHITE);
	textbackground(BLACK);
}

//---------------------------------------------------------
// AAJEgÌ\¦
//---------------------------------------------------------
void AA_count_NUM_Draw(void)
{
	if (!game_start_hantei)
	{
		if (time <= GAME_TIME + 1000 && game_start_count == 2)
		{
			// ¹y
			SoundPlayOnce(SOUND_COUNT);
			//g1\¦
			print_x_y_all(AA_count_pos[2].x, AA_count_pos[2].y, AA_COUNT_WAKU_1, RED);
			// 1\¦
			print_x_y_all(AA_count_pos[0].x, AA_count_pos[0].y, AA_COUNT_NUM_1, LIGHTRED);
			// JEg»èð1É·é
			game_start_count = 1;
		}
		else if (time <= GAME_TIME + 2000 && game_start_count == 3)
		{
			// ¹y
			SoundPlayOnce(SOUND_COUNT);
			//g1\¦
			print_x_y_all(AA_count_pos[2].x, AA_count_pos[2].y, AA_COUNT_WAKU_1, BROWN);
			// 2\¦
			print_x_y_all(AA_count_pos[0].x, AA_count_pos[0].y, AA_COUNT_NUM_2, YELLOW);
			// JEg»èð2É·é
			game_start_count = 2;
		}
		else if (game_start_count == 4)
		{
			// ¹y
			SoundPlayOnce(SOUND_COUNT);
			//g1\¦
			print_x_y_all(AA_count_pos[2].x, AA_count_pos[2].y, AA_COUNT_WAKU_1, BLUE);
			// 3\¦
			print_x_y_all(AA_count_pos[0].x, AA_count_pos[0].y, AA_COUNT_NUM_3, LIGHTBLUE);
			// JEg»èð3É·é
			game_start_count = 3;
		}
	}
	else if (game_start_count == 1)
	{
		// ¹y
		//SoundPlayOnce(SOUND_START);
		// JEgÁ·
		print_x_y_all(AA_count_pos[2].x, AA_count_pos[2].y, AA_COUNT_WAKU_1_KUHAKU, WHITE);
		// Q[ÌJEg»èð0É·é
		game_start_count = 0;
	}
}


//---------------------------------------------------------
// AAÌ³Æðªé
//---------------------------------------------------------
void AA_size_input(const char* p[], AA_SIZE AA_size[], int AA_num)
{
	AA_size[AA_num].tate = AA_size_tate(p);
	AA_size[AA_num].yoko = AA_size_yoko(p);
}

//---------------------------------------------------------
// H×½¿ÌðÔ·
//---------------------------------------------------------
const int eat_ryouri_num(void)
{
	return Player.eat_num;
}

//---------------------------------------------------------
// H×½¿Ì¼OðÔ·
//---------------------------------------------------------
const char* eat_ryouri_name(int i)
{
	return ryouri_name(Player.food_eat_num[i]);
}

//---------------------------------------------------------
// H×½¿ÌliðÔ·
//---------------------------------------------------------
const int eat_ryouri_nedan(int i)
{
	return ryouri_nedan(Player.food_eat_num[i]);
}

//---------------------------------------------------------
// H×½¿Ì¼OÌFðÔ·
//---------------------------------------------------------
const int eat_ryouri_color(int i)
{
	return ryouri_color(Player.food_eat_num[i]);
}