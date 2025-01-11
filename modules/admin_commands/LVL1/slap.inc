CMD:slap(playerid, params[]){
	if(AI[playerid][aLevel] < 1) return 1;
	if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/slap [id]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Игрока нет на сервере!");
	if(!gPlayerLogged[params[0]] || !gPlayerSpawned[params[0]]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Игрок должен залогиниться и заспавниться{FF0000}!");
	if(AI[params[0]][aLevel] > AI[playerid][aLevel]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}У выбранного игрока админка выше{FF0000}! {FFFFFF}Вы можете использовать команду только равных вам админах или не на админах{FF0000}!");
	new Float:X, Float:Y, Float:Z;
	GetPlayerPos(params[0], X, Y, Z);
	SetPlayerPos(params[0], X, Y, Z+5);
	new str[256];
	format(str, sizeof(str), ""NS" {FFFFFF}Админ {CCFF00}%s {FFFFFF}пнул игрока {CCFF00}%s", PlayerInfo[playerid][pName], PlayerInfo[params[0]][pName]);
	SendAdminMessage(COLOR_VIOLET, str);
	format(str, sizeof(str), ""NS" {FFFFFF}Админ {CCFF00}%s {FFFFFF}пнул Вас!", PlayerInfo[playerid][pName]);
	SendClientMessage(params[0], COLOR_VIOLET, str);
	return 1;
}