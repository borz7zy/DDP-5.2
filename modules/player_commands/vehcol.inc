CMD:vehcol(playerid, params[]){
	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}�� ������ ���� �� ������������ �������!");
	if(sscanf(params, "dd", params[0], params[1])) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/vehcol [color1] [color2]");
	new VID = GetPlayerVehicleID(playerid);
	ChangeVehicleColor(VID, params[0], params[1]);
	SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}���� ���������� ������!");
	return 1;
}