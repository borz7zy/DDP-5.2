CMD:unjail(playerid, params[]){
	if(AI[playerid][aLevel] < 1) return 1;
	if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/unjail [id]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}����� �� �� �������!");
	if(!gPlayerLogged[params[0]] || !gPlayerSpawned[params[0]]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}����� �� �����������/�����������!");
	if(Prison[params[0]] < gettime()) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}����� �� � ������!");
	prisoncheck[params[0]] = false;
	Prison[params[0]] = 0;
	SpawnPlayer(params[0]);
	new str[256]; 
	format(str, sizeof(str), ""NS" {FFFFFF}����� {CCFF00}%s {FFFFFF}��������� ������ {CCFF00}%s.", PlayerInfo[playerid][pName], PlayerInfo[params[0]][pName]);
	SendClientMessageToAll(COLOR_VIOLET, str);
	return 1;
}