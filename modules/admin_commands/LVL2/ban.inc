CMD:ban(playerid, params[]){
	if(AI[playerid][aLevel] < 2) return 1;
	new str[512];
	new id, day, reason[144];
	if(sscanf(params, "dds[144]",id, day, reason))return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/ban [id] [���(3-30)] [�������]");
	if(!IsPlayerConnected(id)) return SendClientMessage(playerid, COLOR_VIOLET, ""NS"{99FF99} �� ����� ID ������, �������� ��� �� �������!");
	if(playerid == id) return SendClientMessage(playerid, COLOR_VIOLET, ""NS"{99FF99} ���������� �������� ������ ����!");
	if(day > 30 || day < 3) return SendClientMessage(playerid, COLOR_RED, "������! ���� �� 3 �� 30!");
	if(AI[id][aLevel] > AI[playerid][aLevel]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}����� ����� �� ������� ���� ���{FF0000}! {FFFFFF}����������{FF0000}!");
	new unbandate=gettime() + day*86400;
	mysql_format(ServerDB, str, sizeof(str), "INSERT INTO `bans` (`NameBan`, `UnbanDate`, `BanDate`, `Who`, `Reason`, `IP`) VALUES ('%e','%d','%d','%e','%s','%s')", PlayerInfo[id][pName], unbandate, gettime(), PlayerInfo[playerid][pName], reason, PlayerInfo[id][pIPAdr]);
	mysql_tquery(ServerDB, str, "", "");
	
	format(str, sizeof(str), ""NS" {FFFFFF}����� {CCFF00}%s {FFFFFF}������� {FF0000}%s{FFFFFF} �� {CCFF00}%d{FFFFFF}����.", PlayerInfo[playerid][pName], PlayerInfo[id][pName], day);
	SendClientMessageToAll(COLOR_VIOLET, str);
	format(str, sizeof(str), ""NS" {FFFFFF}������� ����:{FF0000}%s", reason);
	SendClientMessageToAll(COLOR_VIOLET, str);

 	format(str, sizeof(str),"{FF0000}�� ���� ��������!!!\n{FFFFFF}���� ����: %s\n���� �������: %s\n�������: %s\n�������: %s\n\n{FFFFFF}�� ������ ������ ��������� �� ������� � ����������� ������\n{CCFF00}"VK_G"", date("%dd/%mm/%yyyy � %hh:%ii:%ss",gettime()), date("%dd/%mm/%yyyy � %hh:%ii:%ss",unbandate), PlayerInfo[playerid][pName], reason);
	ShowPlayerDialog(id, DIALOG_ZERO, DIALOG_STYLE_MSGBOX,"{CCFF00}>>[�� ��������!]<<",str,"Ok","");

	Kick(id);
	return 1;
}