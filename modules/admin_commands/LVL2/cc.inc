CMD:cc(playerid)
{
	if(AI[playerid][aLevel] < 2) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}������ � ������� ������!");
	for(new i;i< 60;i++) SendClientMessageToAll(-1, " ");
	new ii[144];
	format(ii, sizeof(ii), ""NS" {FFFFFF}����� {CCFF00}%s {FFFFFF}�������� ���������� ���!", PlayerInfo[playerid][pName]);
	SendClientMessageToAll(COLOR_VIOLET, ii);
	return 1;
}