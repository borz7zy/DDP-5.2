CMD:setarmor(playerid, params[]){
	if(AI[playerid][aLevel] < 1) return 1;
	if(sscanf(params, "dd", params[0], params[1])) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/armor [id] [health]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_VIOLET,  ""NS" {FFFFFF}Ид игрока не в сети!");
	if(params[1] < 0 || params[1] > 250) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}От 0 до 250!");
	if(gPlayerLogged[params[0]] == 0 || gPlayerSpawned[params[0]] == 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Игрок ещё не авторизовался/заспавнился!");
	SetPlayerArmour(params[0], params[1]);
	new str[256];
	format(str, sizeof(str), ""NS" {FFFFFF}Админ {CCFF00}%s {FFFFFF}установил игроку {CCFF00}%s {FFFFFF}значение брони - {CCFF00}%d!", PlayerInfo[playerid][pName], PlayerInfo[params[0]][pName], params[1]);
	SendAdminMessage(COLOR_VIOLET, str);
	format(str, sizeof(str), ""NS" {FFFFFF}Админ {CCFF00}%s {FFFFFF}установил Вам {CCFF00}%d % брони!", PlayerInfo[playerid][pName], params[1]);
	SendClientMessage(params[0], COLOR_VIOLET, str);
	return 1;
}