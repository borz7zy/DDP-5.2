CMD:sw(playerid, params[]){
	if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "USE: {FFFFFF}/sw [id ������]");
	SetPlayerWeather(playerid, params[0]);
	SendClientMessage(playerid, COLOR_VIOLET, ""NS" {CCFF00}������ �����������!");
	return 1;
}