CMD:setskin(playerid, params[]){
	if(AI[playerid][aLevel] < 2) return 1;
	if(sscanf(params, "dd", params[0], params[1])) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/setskin [id] [skinid (0-299)]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}������ ��� �� �������!");
	if(!gPlayerLogged[params[0]] || !gPlayerSpawned[params[0]]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}����� �� �����������/�����������!");
	if(GetPlayerSkin(params[0]) == params[1]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}� ������ ��� ���� ����!");
	if(AI[params[0]][aLevel] > AI[playerid][aLevel]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}����� ����� �� ������� ���� ���{FF0000}! {FFFFFF}����������{FF0000}!");
	PlayerInfo[params[0]][pSkin] = params[1];
	SetPlayerSkin(params[0], params[1]);
	new str[256];
	format(str, sizeof(str), ""NS" {FFFFFF}����� {CCFF00}%s {FFFFFF}������ ���� ������ {CCFF00}%s{FFFFFF}.", PlayerInfo[playerid][pName], PlayerInfo[params[0]][pName]);
	SendClientMessage(params[0], COLOR_VIOLET, str);
	SendAdminMessage(COLOR_VIOLET, str);
	return 1;
}