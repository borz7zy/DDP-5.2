stock PlayerDialogMenu(playerid){
	if(PlayerInfo[playerid][pSkin] < 0){
		return 1;
	}
	if(Prison[playerid] > gettime()){
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}� ������ ���� �� ��������!");
		return 1;
	}
	if(Events[playerid][0] == 1){
	    SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}���� ���������� � ���������! ��� ������ � ���� ������� {CCFF00}/exit");
	    return 1;
	}
	if((Events[playerid][1] || Events[playerid][2] || Events[playerid][3]) == 1){
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

stock PlayerDialogCars(playerid, casee){
	if(PlayerInfo[playerid][pSkin] < 0){
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}��� ������ ����������!");
		return 1;
	}
	if(job[playerid]>0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}��������� � ������!");
	if(Prison[playerid] > gettime()){
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}� ������ ���� �� ��������!");
		return 1;
	}
	if(Checkpoint[playerid] != 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}��������� � ������!");
	if(AI[playerid][aSpectateID] != INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}� ������ ��������� ����������!");
	switch(casee){
		case 0:ShowPlayerDialog(playerid, 14000, DIALOG_STYLE_TABLIST_HEADERS, "��������������� ����", "���������\nElegy\nFlash\nJester\nStratum\nSultan\
				\nUranus", "OK", "������");
		case 1:ShowPlayerDialog(playerid, 22000, DIALOG_STYLE_TABLIST_HEADERS, "�������� ����", "���������\nBanshee\nBullet\nCheetah\nComet\nHotknife\
				\nHotring\nHotring A\nHotring B\nInfernus\nSuper GT\nTurismo\nWindsor\nZR-350", "OK", "������");
		case 2:ShowPlayerDialog(playerid, 23000, DIALOG_STYLE_TABLIST_HEADERS, "����������", "���������\nBlade\nBroadway\nRemington\nSavanna\nSlamvan\
				\nTornado\nVoodoo", "OK", "������");
		case 3:ShowPlayerDialog(playerid, 24000, DIALOG_STYLE_TABLIST_HEADERS, "����������� ������", "���������\nAlpha\nBlista\nBravura\nBuccaneer\nCadrona\
				\nClub\nEsperanto\nEuros\nFeltzer\nFortune\nHermes\nHustler\nMajestic\nManana\nPicador\nPrevion\nStallion\
				\nTampa\nVirgo", "OK", "������");
		case 4:ShowPlayerDialog(playerid, 25000, DIALOG_STYLE_TABLIST_HEADERS, "������������� ������", "���������\nAdmiral\nElegant\nEmperor\nGlendale\
				\nGreenwood\nIntruder\nMerit\nNebula\nOceanic\nPremier\nPrimo\nSentinal\nStafford\nStretch\nSunrise\nTahoma\
				\nVincent\nWashington\nWillard", "OK", "������");
		case 5:ShowPlayerDialog(playerid, 26000, DIALOG_STYLE_TABLIST_HEADERS, "�����", "���������\nHuntley\nLandstalker\nPerrenial\nRancher\nRegina\
				\nRomero\nSolair", "OK", "������");
		case 6:ShowPlayerDialog(playerid, 27000, DIALOG_STYLE_TABLIST_HEADERS, "������ ����", "���������\nBuffalo\nClover\nPhoenix\
				\nSabre", "OK", "������");
		case 7:ShowPlayerDialog(playerid, 28000, DIALOG_STYLE_TABLIST_HEADERS, "��������� � ������� ���������", "���������\nBenson\nBoxville\
				\nBoxville-Black\nCement Truck\nCombine Harvestor\nDFT-30\nDozer\nDumper\nDune\nFlatbed\nHotdog\
				\nLinerunner\nMr Woopee\nMule\nPacker\nRoadtrain\nTanker\nTractor\nYankee", "OK", "������");
		case 8:ShowPlayerDialog(playerid, 29000, DIALOG_STYLE_TABLIST_HEADERS, "˸���� ��������� � �������", "���������\nTopfun\nBobcat\nBurrito\
				\nForklift\nMoonbeam\nMower\nNewsvan\nPony\nRumpo\nSadler\nTug\nWalton\nYosemite", "OK", "������");
		case 9:ShowPlayerDialog(playerid, 30000, DIALOG_STYLE_TABLIST_HEADERS, "��������� ��� �����������", "���������\nBandito\nBF Injection\
				\nBloodring Banger\nCaddy\nCamper\nJourney\nKart\nMesa\nMonster\nMonster A\nMonster B\nQuad\nSandking\
				\nVortex\nJetPack   / �� ������ ���������� �� �����! /", "OK", "������");
		case 10:ShowPlayerDialog(playerid, 31000, DIALOG_STYLE_TABLIST_HEADERS, "���������� � ���������", "���������\nBMX\nBike\nMountain Bike\nBF-400\
				\nFaggio\nFCR-900\nFreeway\nNRG-500\nPCJ-600\nPizzaboy\nSanchez\nWayfarer", "OK", "������");
		case 11:ShowPlayerDialog(playerid, 32000, DIALOG_STYLE_TABLIST_HEADERS, "���� ��� ���������������", "���������\nBaggage\nBus\nCabbie\nCoach\
				\nSweeper\nTaxi\nTowtruck\nTrashmaster\nUtility Van", "OK", "������");
		case 12:ShowPlayerDialog(playerid, 3301, DIALOG_STYLE_TABLIST_HEADERS, "������������ � ��������������� ���������", "���������\nAmbulance\nBarracks\
				\nEnforcer\nFBI Rancher\nFBI Truck\nFire Truck\nFire Truck A\nHPV-1000\nPatriot\nPolice Los Santos\
				\nPolice San Fierro\nPolice Las Venturas\nPolice Ranger\nSecuricar\nSwat Tank", "OK", "������");
		case 13:ShowPlayerDialog(playerid, 3401, DIALOG_STYLE_TABLIST_HEADERS, "��������� ���������", "���������\nAndromada\nAT-400\nBeagle\nCargobob\
				\nCropduster\nDodo\nLeviathan\nMaverick\nNevada\nNews Maverick\nPolice Maverick\nRaindance\nRustler\
				\nSeasparrow\nShamal\nSkimmer\nSparrow\nStunt Plane", "OK", "������");
		case 14:ShowPlayerDialog(playerid, 3501, DIALOG_STYLE_TABLIST_HEADERS, "������ ���������", "���������\nCoastguard\nDingy\nJetmax\nLaunch\nMarquis\
				\nPredator\nReefer\nSpeeder\nSquallo\nTropic", "OK", "������");
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