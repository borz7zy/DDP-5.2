CMD:banip(playerid, params[]){
	if(AI[playerid][aLevel] < 2) return 1;
	new str[512];
	if(sscanf(params, "s[17]",params[0]))return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/banip [IP]");
	
	mysql_format(ServerDB, str, sizeof(str), "INSERT INTO `ipbans` (`IP`, `ADMINBAN`, `DATEBAN`, `DATEUNBAN`, `REASON`) VALUES ('%s','%s','%d','%d','%s')", params[0], PlayerInfo[playerid][pName]);
	mysql_tquery(ServerDB, str, "", "");
	
	format(str, sizeof(str), "[A] {FFFFFF}����� {CCFF00}%s {FFFFFF}������� IP {FF0000}%s", PlayerInfo[playerid][pName], params[0]);
	SendAdminMessage(COLOR_RED, str);
	
	foreach(Player,i){
		if(strcmp(PlayerInfo[i][pIPAdr], params[0], true) == 0){
			format(str, sizeof(str), "{FF0000}��� IP {CCFF00}%s {FF0000}��� �������!\n\n{FFFFFF}�� ������ ������ ��������� �� ������� � ����������� ������\n{CCFF00}"VK_G"", params[0]);
			ShowPlayerDialog(i, DIALOG_ZERO, DIALOG_STYLE_MSGBOX, "{FF0000}>>[�� ��������!]<<", str, "��", "");
			Kick(i);
		}
	}
	return 1;
}