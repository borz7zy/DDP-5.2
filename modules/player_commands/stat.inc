CMD:stat(playerid, params[]){
	if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/stat [id]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}���� ID �� �� �������!");
	if(!gPlayerLogged[params[0]]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}����� ��� �� �������������!");
	STATPlayer(playerid, params[0]);
	return 1;
}