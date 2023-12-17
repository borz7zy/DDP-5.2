CMD:cc(playerid)
{
	if(AI[playerid][aLevel] < 2) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Доступ к команде закрыт!");
	for(new i;i< 60;i++) SendClientMessageToAll(-1, " ");
	new ii[144];
	format(ii, sizeof(ii), ""NS" {FFFFFF}Админ {CCFF00}%s {FFFFFF}почистил глобальный чат!", PlayerInfo[playerid][pName]);
	SendClientMessageToAll(COLOR_VIOLET, ii);
	return 1;
}