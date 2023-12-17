CMD:explode(playerid, params[]){
	if(AI[playerid][aLevel] < 1) return 1;
	if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/explode [id]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Игрока с таким ID нет на сервере!");
	if(gPlayerLogged[params[0]] == 0 || gPlayerSpawned[params[0]] == 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Игрок ещё не заспавнился/залогинился!");
	if(AI[params[0]][aLevel] > AI[playerid][aLevel]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Админ стоит на уровень выше вас{FF0000}! {FFFFFF}Невозможно{FF0000}!");
	new Float:X, Float:Y, Float:Z;
	GetPlayerPos(params[0], X, Y, Z);
	CreateExplosion(X, Y, Z, 10, 10.0);
	CreateExplosion(X, Y, Z, 10, 10.0);
	new str[256];
	format(str, sizeof(str), ""NS" {FFFFFF}Админ {CCFF00}%s {FFFFFF}подорвал игрока {CCFF00}%s", PlayerInfo[playerid][pName], PlayerInfo[params[0]][pName]);
	SendAdminMessage(COLOR_VIOLET, str);
	format(str, sizeof(str), ""NS" {FFFFFF}Админ {CCFF00}%s {FFFFFF}подорвал Вас!", PlayerInfo[playerid][pName]);
	SendClientMessage(params[0], COLOR_VIOLET, str);
	return 1;
}