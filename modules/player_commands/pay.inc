CMD:pay(playerid, params[]){
	if(sscanf(params, "dd", params[0], params[1])) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/pay [id игрока] [деньги]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Игрок не в сети!");
	if(!gPlayerLogged[params[0]] || gPlayerSpawned[params[0]])return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Игрок ещё не авторизовался!");
	if(params[1] <= 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы не можете указать 0 ли меньше!");
	if(playerid == params[0]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы указали свой ID");
	if(params[1] > GetPVarInt(playerid, "PlMon")) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы не имеете столько денег!");
	if(CheckFlood(playerid, "StopPay", 30) == 0)
	{
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Раз в 30 секунд{FF0000}!");
		return 1;
	}
	new string[144];
	format(string, sizeof(string), "Игрок {CCFF00}%s[%d] {FFFFFF}передал игроку {CCFF00}%s[%d] $%d", PlayerInfo[playerid][pName], playerid, PlayerInfo[params[0]][pName], params[0], params[1]);
	SendClientMessageToAll(-1, string);
	MoneyK(playerid, -params[1]);
	MoneyK(params[0], params[1]);
	return 1;
}