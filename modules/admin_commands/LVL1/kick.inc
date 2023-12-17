CMD:kick(playerid, params[]){
	if(AI[playerid][aLevel] < 2) return 1;
	new str[144];
	if(sscanf(params, "ds[64]",params[0],params[1]))return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/kick [id] [причина]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_VIOLET, ""NS"{99FF99} Вы ввели ID игрока, которого нет на сервере!");
	if(playerid == params[0]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS"{99FF99} Невозможно кикнуть самого себя!");
	if(AI[params[0]][aLevel] > AI[playerid][aLevel]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Админ стоит на уровень выше вас{FF0000}! {FFFFFF}Невозможно{FF0000}!");
	format(str, sizeof(str), ""NS" {FFFFFF}Админ {CCFF00}%s {FFFFFF}кикнул игрока {FF0000}%s{FFFFFF}. Причина: {FF0000}%s", PlayerInfo[playerid][pName], PlayerInfo[params[0]][pName], params[1]);
	SendClientMessageToAll(COLOR_VIOLET, str);
	Kick(params[0]);
	return 1;
}