CMD:a(playerid, params[]){
	if(AI[playerid][aLevel] <1) return 1;
	new str[144];
	if(sscanf(params, "s[144]",params[0])) return SendClientMessage(playerid, COLOR_VIOLET, "USE {FFFFFF}/a [сообщение]");
	format(str, sizeof(str), "[AC] {FBDF89}%s(%d) {FF3F3F}[LVL %d]: {FFFFFF}%s", AI[playerid][aName], playerid, AI[playerid][aLevel], params[0]);
	SendAdminMessage(0x99FF99FF, str);
	return 1;
}
