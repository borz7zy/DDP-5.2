CMD:gethere(playerid, params[]){
	if(AI[playerid][aLevel] < 2) return 1;
	if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/gethere [id]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}»грок не на сервере!");
	if(!gPlayerLogged[params[0]] || !gPlayerSpawned[params[0]]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}»грок не авторизовалс€/заспавнилс€!");
	if(Prison[params[0]] > gettime()) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}»гок в тюрьме!");
	if(GetPVarInt(params[0], "Freeze") == 1) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}»грок заморожен!");
	if(AI[params[0]][aLevel] > AI[playerid][aLevel]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Админ стоит на уровень выше вас{FF0000}! {FFFFFF}Невозможно{FF0000}!");
	new Float:X, Float:Y, Float:Z;
	GetPlayerPos(playerid, X, Y, Z);
	Teleport(params[0], X, Y, Z, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), false, 0.0000);
	new str[256];
	format(str, sizeof(str), "[A] {FFFFFF}јдмин {CCFF00}%s {FFFFFF}телепортировал к себе {CCFF00}%s", PlayerInfo[playerid][pName], PlayerInfo[params[0]][pName]);
	SendAdminMessage(COLOR_RED, str);
	return 1;
}