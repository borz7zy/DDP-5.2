CMD:ans(playerid,params[])
{
	if(AI[playerid][aLevel] < 1) return 1;
	if(sscanf(params,"is[128]",params[0],params[1])) return SendClientMessage(playerid,COLOR_VIOLET,""NS" {FFFFFF}/ans [�� ������] [�����]");
	new temp[256];
	format(temp, sizeof(temp), "[ANS] {FFFF00}����� {FF3F3F}%s[%d] {FFFF00}������� ���: {FFFFFF}%s", PlayerInfo[playerid][pName],playerid,params[1]);
	SendClientMessage(params[0], COLOR_RED, temp);
	PlayerPlaySound(params[0], 1085,0,0,0);
	format(temp, sizeof(temp), "[ANS] {FFFF00}����� {FF3F3F}%s[%d] {FFFF00}������� {FF3F3F}%s[%d]{FFFFFF}: %s", PlayerInfo[playerid][pName],playerid,PlayerInfo[params[0]][pName],params[0],params[1]);
	SendAdminMessage(COLOR_RED, temp);
	return 1;
}