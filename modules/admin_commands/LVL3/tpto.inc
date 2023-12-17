CMD:tpto(playerid, params[]){
	if(AI[playerid][aLevel] < 3) return 1;
	new Float:X, Float:Y, Float:Z;
	if(sscanf(params, "fff", X, Y, Z)) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/tpto [x] [y] [z]");
	SetPlayerPos(playerid, X, Y, Z);
	SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы телепортировались!");
	return 1;
}