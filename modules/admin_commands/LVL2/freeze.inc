CMD:freeze(playerid, params[])
{
	if(AI[playerid][aLevel] < 2) return 1;
	if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/freeze [id]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}����� �� �� �������!");
	if(!gPlayerLogged[params[0]] || !gPlayerSpawned[params[0]]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}����� �� �������������/�����������!");
	if(Prison[params[0]] > gettime()) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}���� � ������!");
	if(GetPVarInt(params[0], "Freeze") == 1) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}����� ��� ���������!");
	if(AI[params[0]][aLevel] > AI[playerid][aLevel]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}����� ����� �� ������� ���� ���{FF0000}! {FFFFFF}����������{FF0000}!");
	new str[128];
	format(str, sizeof(str), ""NS" {FFFFFF}����� {CCFF00}%s {FFFFFF}��������� ������ {CCFF00}%s{FFFFFF}.", PlayerInfo[playerid][pName], PlayerInfo[params[0]][pName]);
	SendClientMessageToAll(COLOR_VIOLET, str);
	SetPVarInt(params[0], "Freeze", 1);
	TogglePlayerControllable(params[0], false);
	return 1;
}