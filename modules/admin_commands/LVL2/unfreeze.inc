CMD:unfreeze(playerid, params[])
{
	if(AI[playerid][aLevel] < 2) return 1;
	if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/unfreeze [id]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Игрок не на сервере!");
	if(GetPVarInt(params[0], "Freeze") == 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Игрок не заморожен!");
	new str[128];
	format(str, sizeof(str), ""NS" {FFFFFF}Админ {CCFF00}%s {FFFFFF}разморозил игрока {CCFF00}%s{FFFFFF}.", PlayerInfo[playerid][pName], PlayerInfo[params[0]][pName]);
	SendClientMessageToAll(COLOR_VIOLET, str);
	SetPVarInt(params[0], "Freeze", 0);
	TogglePlayerControllable(params[0], 1);
	return 1;
}