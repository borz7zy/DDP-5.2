CMD:spec(playerid, params[]){
	if(AI[playerid][aLevel] < 1) return 1;
	if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/spec [id]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Игрока нет на сервере!");
	if(gPlayerLogged[params[0]] == 0 || gPlayerSpawned[params[0]] == 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Игрок не заспавнился/авторизировался!");
	if(playerid == params[0]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Невозможно включить слежку за собой!");
	if(AI[params[0]][aSpectateID] != INVALID_PLAYER_ID && GetPlayerState(params[0]) == PLAYER_STATE_SPECTATING) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Этот админ в наблюдении!");
	StartSpectate(playerid, params[0]);
	new str[144];
	format(str, sizeof(str), "[SPEC]: {FFFFFF}Админ {CCFF00}%s[%d] {FFFFFF}начал слежку за игроком {CCFF00}%s[%d]", PlayerInfo[playerid][pName], playerid, PlayerInfo[params[0]][pName], params[0]);
	SendAdminMessage(COLOR_VIOLET, str);
	return 1;
}

stock StartSpectate(playerid, InvID2)
{
	if(IsPlayerInAnyVehicle(InvID2)) {
		if(AI[playerid][aSpectateOldINT] == -1 && AI[playerid][aSpectateOldVW] == -1){
			AI[playerid][aSpectateOldINT] = GetPlayerInterior(playerid);
			AI[playerid][aSpectateOldVW] = GetPlayerVirtualWorld(playerid);
			GetPlayerPos(playerid, AI[playerid][aSpecX], AI[playerid][aSpecY], AI[playerid][aSpecZ]);
			if(IsPlayerInAnyVehicle(playerid)) GetVehicleZAngle(GetPlayerVehicleID(playerid), AI[playerid][aSpecA]);
			else GetPlayerFacingAngle(playerid, AI[playerid][aSpecA]);
			if(IsPlayerInAnyVehicle(playerid)){
				PlayerTextDrawHide(playerid, VehicleSpeed[playerid]);
			}
		}
		SetPlayerInterior(playerid,GetPlayerInterior(InvID2));
		SetPlayerVirtualWorld(playerid,GetPlayerVirtualWorld(InvID2));
		TogglePlayerSpectating(playerid, 1);
		AI[playerid][aSpectateID] = InvID2;
		AI[playerid][aSpectateType] = ADMIN_SPEC_TYPE_VEHICLE;
		PlayerSpectateVehicle(playerid, GetPlayerVehicleID(InvID2), SPECTATE_MODE_NORMAL);
		
		if(AI[playerid][aSpectateType] == ADMIN_SPEC_TYPE_PLAYER || AI[playerid][aSpectateType] == ADMIN_SPEC_TYPE_NONE){
			new string[64];
			format(string, sizeof(string), "~r~Max Speed: ~y~%d", GetHMaxSpeed(GetPlayerVehicleID(InvID2)));
			PlayerTextDrawSetString(playerid, HMS44[playerid], string);
			PlayerTextDrawShow(playerid, HMS44[playerid]);

			format(string, sizeof(string), "~y~Speed: ~b~%d", GetPlayerSpeed(InvID2));
			PlayerTextDrawSetString(playerid, spec_TD[playerid], string);
			PlayerTextDrawShow(playerid, spec_TD[playerid]);
		}
		PlayerTextDrawShow(playerid, HMS44[playerid]);
		PlayerTextDrawShow(playerid, spec_TD[playerid]);
	}
	else {
		if(AI[playerid][aSpectateOldINT] == -1 && AI[playerid][aSpectateOldVW] == -1){
			AI[playerid][aSpectateOldINT] = GetPlayerInterior(playerid);
			AI[playerid][aSpectateOldVW] = GetPlayerVirtualWorld(playerid);
			GetPlayerPos(playerid, AI[playerid][aSpecX], AI[playerid][aSpecY], AI[playerid][aSpecZ]);
			if(IsPlayerInAnyVehicle(playerid)) GetVehicleZAngle(GetPlayerVehicleID(playerid), AI[playerid][aSpecA]);
			else GetPlayerFacingAngle(playerid, AI[playerid][aSpecA]);
			if(IsPlayerInAnyVehicle(playerid)){
				PlayerTextDrawHide(playerid, VehicleSpeed[playerid]);
			}
		}
		SetPlayerInterior(playerid,GetPlayerInterior(InvID2));
		SetPlayerVirtualWorld(playerid,GetPlayerVirtualWorld(InvID2));
		TogglePlayerSpectating(playerid, 1);
		if(AI[playerid][aSpectateType] == ADMIN_SPEC_TYPE_VEHICLE){
			PlayerTextDrawHide(playerid, HMS44[playerid]);
			PlayerTextDrawHide(playerid, spec_TD[playerid]);
		}
		AI[playerid][aSpectateID] = InvID2;
		AI[playerid][aSpectateType] = ADMIN_SPEC_TYPE_PLAYER;
		PlayerSpectatePlayer(playerid, InvID2, SPECTATE_MODE_NORMAL);
	}
	return 1;
}

stock StopSpectate(playerid)
{
	if(AI[playerid][aSpectateType] == ADMIN_SPEC_TYPE_VEHICLE){
		PlayerTextDrawHide(playerid, HMS44[playerid]);
		PlayerTextDrawHide(playerid, spec_TD[playerid]);
	}
	TogglePlayerSpectating(playerid, 0);
	AI[playerid][aSpectateID] = INVALID_PLAYER_ID;
	AI[playerid][aSpectateType] = ADMIN_SPEC_TYPE_NONE;
	
	//SetTimerEx("TeleportBackEndSpec", 500, false, "iffffii", playerid, AI[playerid][aSpecX], AI[playerid][aSpecY], AI[playerid][aSpecZ], AI[playerid][aSpecA], AI[playerid][aSpectateOldINT], AI[playerid][aSpectateOldVW]);
	
	//GameTextForPlayer(playerid,"~n~~n~~n~~n~~n~~n~~n~~n~~y~Spectate off",500,3);
	return 1;
}
/*
fpub:TeleportBackEndSpec(playerid, Float:X, Float:Y, Float:Z, Float:A, int, vw){

	SetPlayerInterior(playerid, int);
	SetPlayerVirtualWorld(playerid, vw);
	SetPlayerPos(playerid, X, Y, Z+2);
	SetPlayerFacingAngle(playerid, A);

	AI[playerid][aSpecX]=0;
	AI[playerid][aSpecY]=0;
	AI[playerid][aSpecZ]=0;
	AI[playerid][aSpecA]=0;

	AI[playerid][aSpectateOldINT] = -1;
	AI[playerid][aSpectateOldVW] = -1;
	return 1;
}*/