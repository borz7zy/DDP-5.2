CMD:veh(playerid, params[]){
	if(AI[playerid][aLevel] < 1) return 1;
	if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/veh [id ����������]");
	if(params[0] < 400 || params[0] > 611) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}�� ���������� �� 400 �� 611!");
	if(AI[playerid][aVehicle] !=0){
		DestroyVehicle(AI[playerid][aVehicle]);
		AI[playerid][aVehicle]=0;
	}
	new Float:X, Float:Y, Float:Z, Float:A;
	GetPlayerPos(playerid, X, Y, Z);
	GetPlayerFacingAngle(playerid, A);
	AI[playerid][aVehicle] = CreateVehicle(params[0], X, Y, Z, A, 0, 0, 0);
	LinkVehicleToInterior(AI[playerid][aVehicle], GetPlayerInterior(playerid));
	SetVehicleVirtualWorld(AI[playerid][aVehicle], GetPlayerVirtualWorld(playerid));
	PutPlayerInVehicle(playerid, AI[playerid][aVehicle], 0);
	SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}��� �������� ����� ���������� ����������� {CCFF00}/delveh");
	return 1;
}