CMD:makevip(playerid, params[]){
	if(AI[playerid][aLevel] < 4) return 1;
	if(sscanf(params, "dd", params[0], params[1])) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/makevip [playerid] [0(отобрать)/1(дать)]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Игрока нет на сервере{FF0000}!");
	if(params[1] < 0 || params[1] > 1) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}0 - отнять / 1 - дать{FF0000}!");
	if(gPlayerLogged[params[0]] == false || gPlayerSpawned[params[0]] == false || PlayerInfo[params[0]][pSkin] < 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Игрок ещё не залогинился/заспавнился{FF0000}!");
	if(PlayerInfo[params[0]][pVIP] == params[1]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы ввели уже имеющееся у игрока значение{FF0000}!");
	PlayerInfo[params[0]][pVIP] = params[1];
	new str[256];
	format(str, sizeof(str), ""NS" {FFFFFF}Админ {CCFF00}%s {FFFFFF}дал игроку {CCFF00}%s[%d] {FFCC00}VIP{FFFFFF}!", PlayerInfo[playerid][pName], PlayerInfo[params[0]][pName], params[0]);
	SendClientMessageToAll(COLOR_VIOLET, str);
	return 1;
}