CMD:pay(playerid, params[]){
	if(sscanf(params, "dd", params[0], params[1])) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/pay [id ������] [������]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}����� �� � ����!");
	if(!gPlayerLogged[params[0]] || gPlayerSpawned[params[0]])return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}����� ��� �� �������������!");
	if(params[1] <= 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}�� �� ������ ������� 0 �� ������!");
	if(playerid == params[0]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}�� ������� ���� ID");
	if(params[1] > GetPVarInt(playerid, "PlMon")) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}�� �� ������ ������� �����!");
	if(CheckFlood(playerid, "StopPay", 30) == 0)
	{
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}��� � 30 ������{FF0000}!");
		return 1;
	}
	new string[144];
	format(string, sizeof(string), "����� {CCFF00}%s[%d] {FFFFFF}������� ������ {CCFF00}%s[%d] $%d", PlayerInfo[playerid][pName], playerid, PlayerInfo[params[0]][pName], params[0], params[1]);
	SendClientMessageToAll(-1, string);
	MoneyK(playerid, -params[1]);
	MoneyK(params[0], params[1]);
	return 1;
}