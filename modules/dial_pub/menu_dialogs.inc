stock PlayerDialogMenu(playerid){
	if(PlayerInfo[playerid][pSkin] < 0){
		return 1;
	}
	if(Prison[playerid] > gettime()){
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}� ������ ���� �� ��������!");
		return 1;
	}
	if(Events[playerid][0]){
	    SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}���� ���������� � ���������! ��� ������ � ���� ������� {CCFF00}/exit");
	    return 1;
	}
	if((Events[playerid][1] || Events[playerid][2] || Events[playerid][3])){
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}���� ���������� � ���� �����! ��� ������ � ���� ������� {CCFF00}/exit");
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}��� ����������� ������ �������, ��������� {CCFF00}/restart");
	    return 1;
	}
	if(Checkpoint[playerid] == 1) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFF00}�� ������ ������������� ������ ������������ ����!");
	if(Checkpoint[playerid] == 2) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFF00}�� ������ ������������� ������ ������������ ����!");
	if(Duel[playerid] == 1)
	{
		SendClientMessage(playerid, COLOR_VIOLET, "[DUEL]: {CCFF00}�� �� ������ ������������ ������� � �����!");
		return 1;
	}
	if(AI[playerid][aSpectateID] != INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}� ������ ���� ����������!");
	return ShowPlayerDialog(playerid, 4, DIALOG_STYLE_LIST, "������� ����", "\
																		{8F30E4}� {FFFFFF}������������ ��������\
																		\n{8F30E4}� {FFFFFF}���� ������\
																		\n{CCFF00}$ {FFFFFF}������\
																		\n{8F30E4}� {FFFFFF}���������\
																		\n{8F30E4}� {FFFFFF}�����\
																		\n{8F30E4}� {FFFFFF}������ � ��������\
																		\n{8F30E4}� {FFFFFF}DM ����\
																		\n{FF0000}� {FFFFFF}������� �����\
																		\n{8F30E4}� {FFFFFF}��������� ��������\
																		\n{FFFF33}� {FFFFFF}��� ������� & ����������", "�������", "�����");
}
stock PlayerDialogWeapon(playerid, casee){
	if(PlayerInfo[playerid][pSkin] < 0){
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}��� ������ ����������!");
		return 1;
	}
	if(AI[playerid][aSpectateID] != INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}� ������ ������ ����������!");
	if(Prison[playerid] > gettime()){
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}� ������ ���� �� ��������!");
		return 1;
	}
	if(job[playerid]>0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}��������� � ������!");
	if(dmzone[playerid] > 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}������! ��� ������ ����� ����� � DM ( {CCFF00}/dmexit{FFFFFF} )");
	if(Checkpoint[playerid] != 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}��������� � ������!");
	if(AI[playerid][aSpectateID] != INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}�� � ����������!");
	switch(casee){
		case 0:ShowPlayerDialog(playerid,7500, DIALOG_STYLE_TABLIST_HEADERS, "�������� ������","{FFFFFF}������\t{CCFF00}����\
																		\n{8F30E4}W {FFFFFF}����� ������\t{CCFF00}���������\
																		\n{8F30E4}W {FFFFFF}��� �������\t{CCFF00}���������\
																		\n{8F30E4}W {FFFFFF}����������� ����\t{CCFF00}���������\
																		\n{8F30E4}W {FFFFFF}������\t{CCFF00}���������\
																		\n{8F30E4}W {FFFFFF}���������� ���\t{CCFF00}���������\
																		\n{8F30E4}W {FFFFFF}������\t{CCFF00}���������","������","�����");

		case 1:ShowPlayerDialog(playerid,7501, DIALOG_STYLE_TABLIST_HEADERS, "���������","{FFFFFF}������\t{CCFF00}����\
																		\n{8F30E4}W {FFFFFF}Glock 17\t{CCFF00}$2000\
																		\n{8F30E4}W {FFFFFF}�������� � ����������\t{CCFF00}$2000\
																		\n{8F30E4}W {FFFFFF}��������� ���\t{CCFF00}$2500","������","�����");

		case 2:ShowPlayerDialog(playerid,7502, DIALOG_STYLE_TABLIST_HEADERS, "������ �������","{FFFFFF}������\t{CCFF00}����\
																		\n{8F30E4}W {FFFFFF}������� MP5\t{CCFF00}$3000\
																		\n{8F30E4}W {FFFFFF}������ ������ TEC9\t{CCFF00}$4000\
																		\n{8F30E4}W {FFFFFF}������ ������ UZI\t{CCFF00}$2000","������","�����");

		case 3:ShowPlayerDialog(playerid,7503, DIALOG_STYLE_TABLIST_HEADERS, "���������","{FFFFFF}������\t{CCFF00}����\
																		\n{8F30E4}W {FFFFFF}������\t{CCFF00}$5500\
																		\n{8F30E4}W {FFFFFF}�������� ��������\t{CCFF00}$6000\
																		\n{8F30E4}W {FFFFFF}�����\t{CCFF00}$4000","������","�����");

		case 4:ShowPlayerDialog(playerid,7504, DIALOG_STYLE_TABLIST_HEADERS, "���������","{FFFFFF}������\t{CCFF00}����\
																		\n{8F30E4}W {FFFFFF}��������� �������\t{CCFF00}$1000\
																		\n{8F30E4}W {FFFFFF}����������� ��������\t{CCFF00}$9000","������","�����");

		case 5:ShowPlayerDialog(playerid,7505, DIALOG_STYLE_TABLIST_HEADERS, "��������","{FFFFFF}������\t{CCFF00}����\
																		\n{8F30E4}W {FFFFFF}������� AK-47\t{CCFF00}$4000\
																		\n{8F30E4}W {FFFFFF}������� M4\t{CCFF00}$9000","������","�����");

		case 6:ShowPlayerDialog(playerid,7506, DIALOG_STYLE_TABLIST_HEADERS, "��������","{FFFFFF}������\t{CCFF00}����\
																		\n{8F30E4}W {FFFFFF}������\t{CCFF00}���������\
																		\n{8F30E4}W {FFFFFF}������\t{CCFF00}���������\
																		\n{8F30E4}W {FFFFFF}���������\t{CCFF00}���������\
																		\n{8F30E4}W {FFFFFF}�����\t{CCFF00}���������\
																		\n{8F30E4}W {FFFFFF}�����\t{CCFF00}���������\
																		\n{8F30E4}W {FFFFFF}��������\t{CCFF00}���������\
																		\n{8F30E4}W {FFFFFF}������������\t{CCFF00}���������\
																		\n{8F30E4}W {FFFFFF}�������\t{CCFF00}���������","������","�����");
	}
	return 1;
}

stock PlayerDialogTeleport(playerid){
	if(PlayerInfo[playerid][pSkin] < 0){
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}��� ������ ����������!");
		return 1;
	}
	if(job[playerid]>0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}��������� � ������!");
	if(AI[playerid][aSpectateID] != INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}� ������ ��������� ����������!");
	if(Prison[playerid] > gettime()){
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}� ������ ���� �� ��������!");
		return 1;
	}
	if(GetPVarInt(playerid, "Freeze") == 1){
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}�� ����������!");
		return 1;
	}
	if(Checkpoint[playerid] != 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}��������� � ������!");
	if(AI[playerid][aSpectateID] != INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}�� � ����������!");
	return ShowPlayerDialog(playerid, 45, DIALOG_STYLE_LIST, "���������", "{FF0000}����� {FFFFFF}����\n����\n��������������� ����\n������\n������\n{B13DFF}���������\n{B13DFF}DM ����\n{CCFF00}TrackMania", "�����", "�����");
}

stock PlayerDialogDM(playerid){
	if(PlayerInfo[playerid][pSkin] < 0){
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}��� ������ ����������!");
		return 1;
	}
	if(job[playerid]>0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}��������� � ������!");
	if(AI[playerid][aSpectateID] != INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}� ������ ��������� ����������!");
	if(Prison[playerid] > gettime()){
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}� ������ ���� �� ��������!");
		return 1;
	}
	if(GetPVarInt(playerid, "Freeze") == 1){
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}�� ����������!");
		return 1;
	}
	if(Checkpoint[playerid] != 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}��������� � ������!");
	if(AI[playerid][aSpectateID] != INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}�� � ����������!");
	
	new str[256];
	new ii[2]={0};
	for(new i=0; i < MAX_PLAYERS; i++){
	    if(dmzone[i] == 1) ii[0]++;
	    if(dmzone[i] == 2) ii[1]++;
	}
	format(str, sizeof(str), "{CCFF00}�� ����\t{FFFF00}������ �� ���\n{CCFF00}DeagleOnly DM\t{FFFF00}%d\n{CCFF00}DeagleOnly (Anti +C zone)\t{FFFF00}%d", ii[0], ii[1]);
	ShowPlayerDialog(playerid, 4507, DIALOG_STYLE_TABLIST_HEADERS, "DM ����", str, "OK", "������");
	return 1;
}