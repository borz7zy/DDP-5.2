CMD:setskin(playerid, params[]){
	if(AI[playerid][aLevel] < 2) return 1;
	if(sscanf(params, "dd", params[0], params[1])) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/setskin [id] [skinid (0-299)]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Игрока нет на сервере!");
	if(gPlayerLogged[params[0]] == 0 || gPlayerSpawned[params[0]] == 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Игрок не заспавнился/залогинился!");
	if(GetPlayerSkin(params[0]) == params[1]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}У Игрока уже этот скин!");
	if(AI[params[0]][aLevel] > AI[playerid][aLevel]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Админ стоит на уровень выше вас{FF0000}! {FFFFFF}Невозможно{FF0000}!");
	PlayerInfo[params[0]][pSkin] = params[1];
	SetPlayerSkin(params[0], params[1]);
	new str[256];
	format(str, sizeof(str), ""NS" {FFFFFF}Админ {CCFF00}%s {FFFFFF}сменил скин игроку {CCFF00}%s{FFFFFF}.", PlayerInfo[playerid][pName], PlayerInfo[params[0]][pName]);
	SendClientMessage(params[0], COLOR_VIOLET, str);
	SendAdminMessage(COLOR_VIOLET, str);
	return 1;
}