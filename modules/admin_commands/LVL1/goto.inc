CMD:goto(playerid, params[]){
	if(AI[playerid][aLevel] < 1) return 1;
	if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/goto [id]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Игрок с таким ID не в сети!");
	if(!gPlayerLogged[params[0]] || !gPlayerSpawned[params[0]]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Игрок ещё не заспавнился/авторизировался!");
	new vw, interior, Float:X, Float:Y, Float:Z;
	vw = GetPlayerVirtualWorld(params[0]);
	interior = GetPlayerInterior(params[0]);
	GetPlayerPos(params[0], X, Y, Z);
	Teleport(playerid, X+1.5, Y+1.5, Z, vw, interior, false, 0.0000);
	new str[256];
	format(str, sizeof(str), "[A] {FFFFFF}Админ {CCFF00}%s {FFFFFF}телепортировался к игроку {CCFF00}%s", PlayerInfo[playerid][pName], PlayerInfo[params[0]][pName]);
	SendAdminMessage(COLOR_RED, str);
	return 1;
}