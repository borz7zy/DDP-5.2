CMD:getv(playerid){
	if(job[playerid]>0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}��������� � ������!");
	if(dmzone[playerid] != 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}��� ������ ������ � �� ����! {CCFF00}( /dmexit )");
	if(playcar[playerid]==0)return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}�� ��� �� ���������� ���������. ������ ���������� � ����");
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid,x,y,z);
	SetVehicleVirtualWorld(playcar[playerid], GetPlayerVirtualWorld(playerid));
	SetVehiclePos(playcar[playerid],x+3,y,z);
	PutPlayerInVehicle(playerid, playcar[playerid], 0);
	SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}��������� �������������� � ���!");
	return 1;
}