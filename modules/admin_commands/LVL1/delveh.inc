CMD:delveh(playerid, params[]){
	if(AI[playerid][aLevel] < 1) return 1;
	if(AI[playerid][aVehicle] == 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}�� �� �������� ���������!");
	
	DestroyVehicle(AI[playerid][aVehicle]);
	AI[playerid][aVehicle]=0;
	SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}��������� �����!");
	return 1;
}