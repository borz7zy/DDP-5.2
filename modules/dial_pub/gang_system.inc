// Gang system
fpub:LoadGangs()
{
	new time = GetTickCount();
	for(new i=1; i <= cache_num_rows(); i++)
	{
	    new idgang;
        cache_get_value_int(i-1, "gID", idgang);
		if(idgang != i) continue;
	    GangInfo[i][gCreated] = true;
	    cache_get_value_int(i-1, "gID", GangInfo[i][gID]);
	    cache_get_value_name(i-1, "gName", GangInfo[i][gName], 31);
	    cache_get_value_name(i-1, "gColor", GangInfo[i][gColor], 10);

   		cache_get_value_float(i-1, "gSpawnX", GangInfo[i][gSpawns][0]);
		cache_get_value_float(i-1, "gSpawnY", GangInfo[i][gSpawns][1]);
		cache_get_value_float(i-1, "gSpawnZ", GangInfo[i][gSpawns][2]);
	    cache_get_value_int(i-1, "gSpawnInt", GangInfo[i][gSpawnInt]);
	    cache_get_value_int(i-1, "g_cDate", GangInfo[i][gCDate]);
		cache_get_value_int(i-1, "gVerifyCapt", GangInfo[i][gVerifyCapt]);
		cache_get_value_int(i-1, "gLastOneCapt", GangInfo[i][gLastOneCapt]);
		cache_get_value_int(i-1, "gLastTwoCapt", GangInfo[i][gLastTwoCapt]);

		cache_get_value_int(i-1, "gSkin0", GangInfo[i][gSkins][0]);
		cache_get_value_int(i-1, "gSkin1", GangInfo[i][gSkins][1]);
		cache_get_value_int(i-1, "gSkin2", GangInfo[i][gSkins][2]);
		cache_get_value_int(i-1, "gSkin3", GangInfo[i][gSkins][3]);
		cache_get_value_int(i-1, "gSkin4", GangInfo[i][gSkins][4]);
		cache_get_value_int(i-1, "gSkin5", GangInfo[i][gSkins][5]);
		
		cache_get_value_name(i-1, "g_Glawa", GangInfo[i][gGlawa], MAX_PLAYER_NAME);
	}
	printf("Кланы успешно загружены. Всего загружено %d кланов. Потрачено на загрузку: %i ms", cache_num_rows(), GetTickCount() - time);
	return 1;
}

ShowGangDialog(playerid, page = g_NonePage)
{
	switch(page)
	{
		case g_NonePage: ShowPlayerDialog(playerid, 10011, DIALOG_STYLE_LIST, ">>[МЕНЮ КЛАНОВ]<<", "Создать клан\nНазначить скины\nНазначить место спавна\nНазначить уровень\nПригласить в клан\nКикнуть из клана\nИзменить цвет клана\nУйти из клана\nУдалить клан", "ВЫБОР", "НАЗАД");
		case g_SetNamePage:
		{
			if(PlayerInfo[playerid][pGang] == 0 && PlayerInfo[playerid][pDriftExp] >= 5000 && GetPVarInt(playerid, "PlMon") >= 1000000) ShowPlayerDialog(playerid, 2002, DIALOG_STYLE_INPUT, ">>[СОЗДАНИЕ КЛАНА]<<", "{CCFF00}Введите название клана в нижнее поле:", "ВВОД", "ОТМЕНА");
			else SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы должны выйти из своей клане, и у вас должно быть как минимум {FF0000}5000 Score и $1.000.000");
		}
		case g_SetSkinPage:
		{
			if(PlayerInfo[playerid][pGang] != 0 && PlayerInfo[playerid][pGangLvl] == 6) ShowPlayerDialog(playerid, 8001, DIALOG_STYLE_LIST, ">>[НАЗНАЧЕНИЕ СКИНОВ КЛАНА]<<", "Нуб\nИгрок\nПро игрок\nЭлита\nЗам лидера\nЛидер", "ВЫБОР", "ОТМЕНА");
			else SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы должны состоять в клане, и у вас должен быть {CCFF00}уровень лидера.");
		}
		case g_SetSpawnPage:
		{
			if(PlayerInfo[playerid][pGang] != 0 && PlayerInfo[playerid][pGangLvl] == 6) ShowPlayerDialog(playerid, 7001, DIALOG_STYLE_MSGBOX, ">>[НАЗНАЧЕНИЕ СПАВНА КЛАНА]<<", "Вы точно хотите назначить место спавна на этом месте?", "ПРИНЯТЬ", "ОТМЕНА");
			else SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы должны состоять в клане, и у вас должен быть {CCFF00}уровень лидера.");
		}
		case g_SetPlayerLevelPage:
		{
			if(PlayerInfo[playerid][pGang] != 0 && PlayerInfo[playerid][pGangLvl] == 6) ShowPlayerDialog(playerid, 9001, DIALOG_STYLE_INPUT, ">>[НАЗНАЧЕНИЕ УРОВНЯ]<<", "Введите id игрока, которому хотите назначит уровень:", "ПРИНЯТЬ", "ОТМЕНА");
			else SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы должны состоять в клане, и у вас должен быть {CCFF00}уровень лидера.");
		}
		case g_InvitePage:
		{
			if(PlayerInfo[playerid][pGang] != 0 && PlayerInfo[playerid][pGangLvl] >= 4) ShowPlayerDialog(playerid, 3001, DIALOG_STYLE_INPUT, ">>[ПРИГЛАШЕНИЕ В КЛАН]<<", "Введите id игрока, которого хотите пригласить:", "ПРИНЯТЬ", "ОТМЕНА");
			else SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы должны состоять в клане, и у вас должен быть как минимум {CCFF00}4 уровень.");
		}
		case g_UnInvitePage:
		{
			if(PlayerInfo[playerid][pGang] != 0 && PlayerInfo[playerid][pGangLvl] >= 5) ShowPlayerDialog(playerid, 4001, DIALOG_STYLE_INPUT, ">>[КИК ИЗ КЛАНА]<<", "Введите id игрока, которого хотите кикнуть:", "ПРИНЯТЬ", "ОТМЕНА");
			else SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы должны состоять в клане, и у вас должен быть как минимум {CCFF00}5 уровень.");
		}
		case g_SetColorPage:
		{
			if(PlayerInfo[playerid][pGang] != 0 && PlayerInfo[playerid][pGangLvl] == 6) ShowPlayerDialog(playerid, 5001, DIALOG_STYLE_INPUT, ">>[СМЕНА ЦВЕТА КЛАНА]<<", "Введите 6 символов формата RRGGBB:", "ПРИНЯТЬ", "ОТМЕНА");
			else SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы должны состоять в клане, и у вас должен быть {CCFF00}уровень лидера.");
		}
		case g_ExitPlayerPage:
		{
			if(PlayerInfo[playerid][pGang] > 0 && PlayerInfo[playerid][pGangLvl] < 6) ShowPlayerDialog(playerid, 6001, DIALOG_STYLE_MSGBOX, ">>[УХОД ИЗ КЛАНА]<<", "Вы точно хотите выйти из клана?", "ДА", "ОТМЕНА");
			else SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы должны состоять в клане, и у Вас не должно быть {CCFF00}Уровня лидера{FFFF00}!");
		}
	    case g_DestroyGangPage:
		{
			if(PlayerInfo[playerid][pGang] != 0 && PlayerInfo[playerid][pGangLvl] == 6) ShowPlayerDialog(playerid, 9510, DIALOG_STYLE_MSGBOX, ">>[УХОД ИЗ КЛАНА]<<", "Вы точно хотите удалить клан?", "УДАЛИТЬ", "ОТМЕНА");
			else SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы должны состоять в клане, и у вас должен быть {CCFF00}уровень лидера.");
		}
		case g_cSetColorPage:
		{
			if(PlayerInfo[playerid][pGang] == 0 && PlayerInfo[playerid][pDriftExp] >= 5000 && GetPVarInt(playerid, "PlMon") >= 1000000) ShowPlayerDialog(playerid, 2003, DIALOG_STYLE_INPUT, ">>[СОЗДАНИЕ КЛАНА]<<", "Введите цвет клана:", "ПРИНЯТЬ", "ОТМЕНА");
			else SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы должны выйти из своего клана, и у вас должно быть как минимум {FF0000}5000 Score и $1.000.000");
		}
	    case g_SetSkinTwoPage:
		{
			if(PlayerInfo[playerid][pGang] != 0 && PlayerInfo[playerid][pGangLvl] == 6) ShowPlayerDialog(playerid, 8002, DIALOG_STYLE_INPUT, ">>[НАЗНАЧЕНИЕ СКИНОВ КЛАНУ]<<", "Введите в окошко ID скина, который хотите назначить:", "ПРИНЯТЬ", "ОТМЕНА");
			else SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы должны состоять в клане, и у вас должен быть {CCFF00}уровень лидера.");
		}
	    case g_SetPlayerLevelTwoPage:
		{
			if(PlayerInfo[playerid][pGang] != 0 && PlayerInfo[playerid][pGangLvl] == 6) ShowPlayerDialog(playerid, 9002, DIALOG_STYLE_LIST, ">>[НАЗНАЧЕНИЕ УРОВНЯ]<<", "Нуб\nИгрок\nПро игрок\nЭлита\nЗам лидера\nЛидер", "ПРИНЯТЬ", "ОТМЕНА");
			else SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы должны состоять в клане, и у вас должен быть {CCFF00}уровень лидера.");
		}
	}
	return 1;
}
// The end Gang System