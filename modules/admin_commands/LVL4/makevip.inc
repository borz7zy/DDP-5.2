CMD:makevip(playerid, params[]){
	if(AI[playerid][aLevel] < 4) return 1;
	if(sscanf(params, "dd", params[0], params[1])) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/makevip [playerid] [0(��������)/1(����)]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}������ ��� �� �������{FF0000}!");
	if(params[1] < 0 || params[1] > 1) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}0 - ������ / 1 - ����{FF0000}!");
	if(gPlayerLogged[params[0]] == false || gPlayerSpawned[params[0]] == false || PlayerInfo[params[0]][pSkin] < 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}����� ��� �� �����������/�����������{FF0000}!");
	if(PlayerInfo[params[0]][pVIP] == params[1]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}�� ����� ��� ��������� � ������ ��������{FF0000}!");
	PlayerInfo[params[0]][pVIP] = params[1];
	new str[256];
	format(str, sizeof(str), ""NS" {FFFFFF}����� {CCFF00}%s {FFFFFF}��� ������ {CCFF00}%s[%d] {FFCC00}VIP{FFFFFF}!", PlayerInfo[playerid][pName], PlayerInfo[params[0]][pName], params[0]);
	SendClientMessageToAll(COLOR_VIOLET, str);
	return 1;
}