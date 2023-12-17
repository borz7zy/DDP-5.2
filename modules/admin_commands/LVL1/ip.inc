CMD:ip(playerid, params[]){
	if(AI[playerid][aLevel] < 1) return 1;
	if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/ip [id]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Игрока с таким ID нет на сервере!");
	if(AI[params[0]][aLevel] > AI[playerid][aLevel]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Админ стоит на уровень выше вас{FF0000}! {FFFFFF}Невозможно{FF0000}!");
	new str[256];
	format(str, sizeof(str), ""NS" Админ {CCFF00}%s посмотрел IP адрес игрока {FFFFFF}%s", PlayerInfo[playerid][pName], PlayerInfo[params[0]][pName]);
	SendAdminMessage(COLOR_VIOLET, str);
	format(str, sizeof(str), "%s : IP: {99FF99}%s", PlayerInfo[params[0]][pName], PlayerInfo[params[0]][pIPAdr]);
	SendClientMessage(playerid, 0xCCFF00FF, str);
	return 1;
}