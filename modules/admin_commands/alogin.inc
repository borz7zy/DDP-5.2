/*CMD:alogin(playerid, params[]){//gettime() + days*86400
	new pass[200];
	if(sscanf(params, "s[200]", pass)) return SendClientMessage(playerid, COLOR_VIOLET, ""NS"{FFFFFF} USE: /alogin [������ �������]");
	new str[128];
	mysql_format(ServerDB, str, sizeof(str), "SELECT * FROM `admins` WHERE `aname` = '%e' LIMIT 1", PlayerInfo[playerid][pName]);
	mysql_tquery(ServerDB, str, "aLogin", "ds", playerid, pass);
	return 1;
}*/

fpub:aLogin(playerid,pass[]){
	if(cache_num_rows() > 0)
	{
		cache_get_value_name(0, "apass", AI[playerid][aPass], 65);
		cache_get_value_name(0, "hash", AI[playerid][aHASH], 17);
		new hashed_pass[65];
		new str[1024];
		SHA256_Hash(pass, AI[playerid][aHASH], hashed_pass, 65);
		if(strcmp(AI[playerid][aPass], hashed_pass) == 0){

			cache_get_value_int(0, "id", AI[playerid][db_ID]);
			cache_get_value_name(0, "aname", AI[playerid][aName], MAX_PLAYER_NAME);
			cache_get_value_int(0, "dateget", AI[playerid][aDGet]);
			cache_get_value_int(0, "alevel", AI[playerid][aLevel]);
			cache_get_value_name(0, "setendadmin", AI[playerid][aMakeAdminEnd], MAX_PLAYER_NAME);
			cache_get_value_name(0, "setadmin", AI[playerid][aMakeAdmin], MAX_PLAYER_NAME);
			cache_get_value_int(0, "dateend", AI[playerid][aDEnd]);
   			cache_get_value_int(0, "blocklogged", AI[playerid][aBlock]);
			cache_get_value_name(0, "reasonend", AI[playerid][aReasonEnd], 144);
			cache_get_value_int(0, "kicksplayers", AI[playerid][aKickPlayers]);
			cache_get_value_int(0, "banedplayers", AI[playerid][aBanPlayers]);
			cache_get_value_int(0, "loggedcount", AI[playerid][aLogCount]);
			cache_get_value_int(0, "loggedtime", AI[playerid][aLogCount]);
			if(AI[playerid][aBlock] == 1){
			    format(str, sizeof(str), "{FF0000}�� ����������� � ����� ������ ����� ����!!!\n\
				\n{FFFFFF}����� �������: {99ff99}%s\
				\n{FFFFFF}�����-����� �����: {99ff99}%s\
				\n{FFFFFF}�����-����� ����: {99FF99}%s\
				\n{FFFFFF}������� ������ �����-����: {99FF99}%s\n\
				\n{FFFFFF}���� ������ ������� �������, �������� �������� ��������������, ��������� ��� �������� ����� ���� � �������� ������.",
				AI[playerid][aName],
				AI[playerid][aMakeAdmin],
				AI[playerid][aMakeAdminEnd],
				AI[playerid][aReasonEnd]);
			    ShowPlayerDialog(playerid, DIALOG_ZERO, DIALOG_STYLE_MSGBOX, "����������� ������� �������������!", str, "��", "");
				AI[playerid][db_ID] = 0;
				AI[playerid][aHASH][0] = EOS;
				AI[playerid][aPass][0] = EOS;
				AI[playerid][aName][0] = EOS;
				AI[playerid][aDGet] = 0;
				AI[playerid][aDEnd] = 0;
				AI[playerid][aMakeAdmin][0] = EOS;
				AI[playerid][aMakeAdminEnd][0] = EOS;
				AI[playerid][aReasonEnd][0] = EOS;
				AI[playerid][aBlock] = 0;
				AI[playerid][aKickPlayers] = 0;
				AI[playerid][aBanPlayers] = 0;
				AI[playerid][aLogCount] = 0;
				AI[playerid][aLevel] = 0;
				AI[playerid][aResPlayer] = 0;
				AI[playerid][aTimeOnline] = 0;
				AI[playerid][aGod] = 0;
				return 1;
			}else if(AI[playerid][aDEnd] <= gettime() && AI[playerid][aDEnd] != 0){
				SendClientMessage(playerid, COLOR_VIOLET, ""NS"{FFFFFF} �������� �� ������� �����������!");
				SendClientMessage(playerid, COLOR_VIOLET, ""NS"{FFFFFF} ���� ������� ��������, �������� �������� ��������������!");
				mysql_format(ServerDB, str, sizeof(str), "UPDATE `admins` SET `reasonend`='%s', `blocklogged`='1', `setendadmin`='%e' WHERE `aname`='%e' LIMIT 1", "��������� ��������", "SYSTEM", AI[playerid][aName]);
				mysql_tquery(ServerDB, str, "", "");
				format(str, sizeof(str), "%s{FFFFFF} ������������� %s[%d] ��������� ���� �����������������. ����!", NS, AI[playerid][aName], playerid);
				SendAdminMessage(COLOR_VIOLET, str);
				AI[playerid][db_ID] = 0;
				AI[playerid][aHASH][0] = EOS;
				AI[playerid][aPass][0] = EOS;
				AI[playerid][aName][0] = EOS;
				AI[playerid][aDGet] = 0;
				AI[playerid][aDEnd] = 0;
				AI[playerid][aMakeAdmin][0] = EOS;
				AI[playerid][aMakeAdminEnd][0] = EOS;
				AI[playerid][aReasonEnd][0] = EOS;
				AI[playerid][aBlock] = 0;
				AI[playerid][aKickPlayers] = 0;
				AI[playerid][aBanPlayers] = 0;
				AI[playerid][aLogCount] = 0;
				AI[playerid][aLevel] = 0;
				AI[playerid][aResPlayer] = 0;
				AI[playerid][aTimeOnline] = 0;
				AI[playerid][aGod] = 0;
				return 1;
			}else{
				format(str, sizeof(str), "{99FF99}������� ���������!\n\n{FFFFFF}�������: {99FF99}%d\n{FFFFFF}���� ������: {99FF99}%s\n{FFFFFF}���� ���������: {99FF99}%s\n\n{FFFFFF}��������� ���������� ������� �� ������ ���������� �� ������� {99FF99}/ainfo",
				AI[playerid][aLevel],date("%dd/%mm/%yyyy � %hh:%ii:%ss",AI[playerid][aDGet]),date("%dd/%mm/%yyyy � %hh:%ii:%ss",AI[playerid][aDEnd]));//
				ShowPlayerDialog(playerid, DIALOG_ZERO, DIALOG_STYLE_MSGBOX, "�������� �������", str, "��", "");
				AI[playerid][aLogCount]++;
				format(str, sizeof(str), "<A> {CCFF00}%s {FF0000}alogin {FFFFFF}| IP:{CCFF00} %s {FFFFFF}| {FF0000}%d LVL", PlayerInfo[playerid][pName], PlayerInfo[playerid][pIPAdr], AI[playerid][aLevel]);
				SendAdminMessage(COLOR_VIOLET, str);
			}
		}else{
			SendClientMessage(playerid, COLOR_VIOLET, ""NS"{FFFFFF} �������� ������!");
		}
	}
	else{
		SendClientMessage(playerid, COLOR_VIOLET, ""NS"{FFFFFF} �� �� �������������!");
	}
	return 1;
}