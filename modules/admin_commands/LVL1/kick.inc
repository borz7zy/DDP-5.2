CMD:kick(playerid, params[]){
	if(AI[playerid][aLevel] < 2) return 1;
	new str[144];
	if(sscanf(params, "ds[64]",params[0],params[1]))return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/kick [id] [�������]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_VIOLET, ""NS"{99FF99} �� ����� ID ������, �������� ��� �� �������!");
	if(playerid == params[0]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS"{99FF99} ���������� ������� ������ ����!");
	if(AI[params[0]][aLevel] > AI[playerid][aLevel]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}����� ����� �� ������� ���� ���{FF0000}! {FFFFFF}����������{FF0000}!");
	format(str, sizeof(str), ""NS" {FFFFFF}����� {CCFF00}%s {FFFFFF}������ ������ {FF0000}%s{FFFFFF}. �������: {FF0000}%s", PlayerInfo[playerid][pName], PlayerInfo[params[0]][pName], params[1]);
	SendClientMessageToAll(COLOR_VIOLET, str);
	Kick(params[0]);
	return 1;
}