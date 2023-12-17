CMD:specoff(playerid){
	if(AI[playerid][aLevel] < 1) return 1;
	if(AI[playerid][aSpectateID] == INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы ни за кем не следите!");
	StopSpectate(playerid);
	return 1;
}