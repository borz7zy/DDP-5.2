stock PlayerDialogMenu(playerid){
	if(PlayerInfo[playerid][pSkin] < 0){
		return 1;
	}
	if(Prison[playerid] > gettime()){
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}В тюрьме меню не работает!");
		return 1;
	}
	if(Events[playerid][0]){
	    SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Меню недоступно в лабиринте! Для выхода с него введите {CCFF00}/exit");
	    return 1;
	}
	if((Events[playerid][1] || Events[playerid][2] || Events[playerid][3])){
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Меню недоступно в Трек Мании! Для выхода с него введите {CCFF00}/exit");
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Для прохождения уровня сначала, пропишите {CCFF00}/restart");
	    return 1;
	}
	if(Checkpoint[playerid] == 1) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFF00}На работе Дальнобойщика нельзя использовать меню!");
	if(Checkpoint[playerid] == 2) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFF00}На работе Дальнобойщика нельзя использовать меню!");
	if(Duel[playerid] == 1)
	{
		SendClientMessage(playerid, COLOR_VIOLET, "[DUEL]: {CCFF00}Вы не можете использовать команды в дуэли!");
		return 1;
	}
	if(AI[playerid][aSpectateID] != INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}В слежке меню недоступно!");
	return ShowPlayerDialog(playerid, 4, DIALOG_STYLE_LIST, "Игровое меню", "\
																		{8F30E4}• {FFFFFF}Транспортное средство\
																		\n{8F30E4}• {FFFFFF}Меню игрока\
																		\n{CCFF00}$ {FFFFFF}Работы\
																		\n{8F30E4}• {FFFFFF}Телепорты\
																		\n{8F30E4}• {FFFFFF}Радио\
																		\n{8F30E4}• {FFFFFF}Оружие и предметы\
																		\n{8F30E4}• {FFFFFF}DM зоны\
																		\n{FF0000}• {FFFFFF}Система клана\
																		\n{8F30E4}• {FFFFFF}Настройки аккаунта\
																		\n{FFFF33}• {FFFFFF}ТОП ИГРОКОВ & ДОСТИЖЕНИЯ", "Выбрать", "Выход");
}
stock PlayerDialogWeapon(playerid, casee){
	if(PlayerInfo[playerid][pSkin] < 0){
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Для начала заспавнись!");
		return 1;
	}
	if(AI[playerid][aSpectateID] != INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}В слежке оружие недоступно!");
	if(Prison[playerid] > gettime()){
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}В тюрьме меню не работает!");
		return 1;
	}
	if(job[playerid]>0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Увольтесь с работы!");
	if(dmzone[playerid] > 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Нельзя! Для начала нужно выйти с DM ( {CCFF00}/dmexit{FFFFFF} )");
	if(Checkpoint[playerid] != 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Увольтесь с работы!");
	if(AI[playerid][aSpectateID] != INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы в наблюдении!");
	switch(casee){
		case 0:ShowPlayerDialog(playerid,7500, DIALOG_STYLE_TABLIST_HEADERS, "Холодное оружие","{FFFFFF}Оружие\t{CCFF00}Цена\
																		\n{8F30E4}W {FFFFFF}Гольф клюшка\t{CCFF00}Бесплатно\
																		\n{8F30E4}W {FFFFFF}Нож обычный\t{CCFF00}Бесплатно\
																		\n{8F30E4}W {FFFFFF}Бейсбольная бита\t{CCFF00}Бесплатно\
																		\n{8F30E4}W {FFFFFF}Лопата\t{CCFF00}Бесплатно\
																		\n{8F30E4}W {FFFFFF}Бильярдный кий\t{CCFF00}Бесплатно\
																		\n{8F30E4}W {FFFFFF}Катана\t{CCFF00}Бесплатно","Купить","Назад");

		case 1:ShowPlayerDialog(playerid,7501, DIALOG_STYLE_TABLIST_HEADERS, "Пистолеты","{FFFFFF}Оружие\t{CCFF00}Цена\
																		\n{8F30E4}W {FFFFFF}Glock 17\t{CCFF00}$2000\
																		\n{8F30E4}W {FFFFFF}Пистолет с глушителем\t{CCFF00}$2000\
																		\n{8F30E4}W {FFFFFF}Пустынный орёл\t{CCFF00}$2500","Купить","Назад");

		case 2:ShowPlayerDialog(playerid,7502, DIALOG_STYLE_TABLIST_HEADERS, "Ручные пулемёты","{FFFFFF}Оружие\t{CCFF00}Цена\
																		\n{8F30E4}W {FFFFFF}Автомат MP5\t{CCFF00}$3000\
																		\n{8F30E4}W {FFFFFF}Ручной пулемёт TEC9\t{CCFF00}$4000\
																		\n{8F30E4}W {FFFFFF}Ручной пулемёт UZI\t{CCFF00}$2000","Купить","Назад");

		case 3:ShowPlayerDialog(playerid,7503, DIALOG_STYLE_TABLIST_HEADERS, "Дробовики","{FFFFFF}Оружие\t{CCFF00}Цена\
																		\n{8F30E4}W {FFFFFF}Обрезы\t{CCFF00}$5500\
																		\n{8F30E4}W {FFFFFF}Помповый дробовик\t{CCFF00}$6000\
																		\n{8F30E4}W {FFFFFF}Ружьё\t{CCFF00}$4000","Купить","Назад");

		case 4:ShowPlayerDialog(playerid,7504, DIALOG_STYLE_TABLIST_HEADERS, "Снайперки","{FFFFFF}Оружие\t{CCFF00}Цена\
																		\n{8F30E4}W {FFFFFF}Охотничий карабин\t{CCFF00}$1000\
																		\n{8F30E4}W {FFFFFF}Снайперская винтовка\t{CCFF00}$9000","Купить","Назад");

		case 5:ShowPlayerDialog(playerid,7505, DIALOG_STYLE_TABLIST_HEADERS, "Автоматы","{FFFFFF}Оружие\t{CCFF00}Цена\
																		\n{8F30E4}W {FFFFFF}Автомат AK-47\t{CCFF00}$4000\
																		\n{8F30E4}W {FFFFFF}Автомат M4\t{CCFF00}$9000","Купить","Назад");

		case 6:ShowPlayerDialog(playerid,7506, DIALOG_STYLE_TABLIST_HEADERS, "Предметы","{FFFFFF}Оружие\t{CCFF00}Цена\
																		\n{8F30E4}W {FFFFFF}Камера\t{CCFF00}Бесплатно\
																		\n{8F30E4}W {FFFFFF}Кастет\t{CCFF00}Бесплатно\
																		\n{8F30E4}W {FFFFFF}Бензопила\t{CCFF00}Бесплатно\
																		\n{8F30E4}W {FFFFFF}Фалос\t{CCFF00}Бесплатно\
																		\n{8F30E4}W {FFFFFF}Цветы\t{CCFF00}Бесплатно\
																		\n{8F30E4}W {FFFFFF}Балончик\t{CCFF00}Бесплатно\
																		\n{8F30E4}W {FFFFFF}Огнетушитель\t{CCFF00}Бесплатно\
																		\n{8F30E4}W {FFFFFF}Парашют\t{CCFF00}Бесплатно","Купить","Назад");
	}
	return 1;
}

stock PlayerDialogTeleport(playerid){
	if(PlayerInfo[playerid][pSkin] < 0){
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Для начала заспавнись!");
		return 1;
	}
	if(job[playerid]>0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Увольтесь с работы!");
	if(AI[playerid][aSpectateID] != INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}В слежке телепорты недоступны!");
	if(Prison[playerid] > gettime()){
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}В тюрьме меню не работает!");
		return 1;
	}
	if(GetPVarInt(playerid, "Freeze") == 1){
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы заморожены!");
		return 1;
	}
	if(Checkpoint[playerid] != 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Увольтесь с работы!");
	if(AI[playerid][aSpectateID] != INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы в наблюдении!");
	return ShowPlayerDialog(playerid, 45, DIALOG_STYLE_LIST, "Телепорты", "{FF0000}Дрифт {FFFFFF}зоны\nДраг\nРазвлекательные зоны\nРазное\nГорода\n{B13DFF}Интерьеры\n{B13DFF}DM ЗОНЫ\n{CCFF00}TrackMania", "Выбор", "Выход");
}

stock PlayerDialogDM(playerid){
	if(PlayerInfo[playerid][pSkin] < 0){
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Для начала заспавнись!");
		return 1;
	}
	if(job[playerid]>0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Увольтесь с работы!");
	if(AI[playerid][aSpectateID] != INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}В слежке телепорты недоступны!");
	if(Prison[playerid] > gettime()){
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}В тюрьме меню не работает!");
		return 1;
	}
	if(GetPVarInt(playerid, "Freeze") == 1){
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы заморожены!");
		return 1;
	}
	if(Checkpoint[playerid] != 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Увольтесь с работы!");
	if(AI[playerid][aSpectateID] != INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы в наблюдении!");
	
	new str[256];
	new ii[2]={0};
	for(new i=0; i < MAX_PLAYERS; i++){
	    if(dmzone[i] == 1) ii[0]++;
	    if(dmzone[i] == 2) ii[1]++;
	}
	format(str, sizeof(str), "{CCFF00}ДМ ЗОНА\t{FFFF00}Сейчас на ней\n{CCFF00}DeagleOnly DM\t{FFFF00}%d\n{CCFF00}DeagleOnly (Anti +C zone)\t{FFFF00}%d", ii[0], ii[1]);
	ShowPlayerDialog(playerid, 4507, DIALOG_STYLE_TABLIST_HEADERS, "DM ЗОНЫ", str, "OK", "Отмена");
	return 1;
}