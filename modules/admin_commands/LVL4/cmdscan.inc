CMD:cmdscan(playerid){
	if(AI[playerid][aLevel] < 4) return 1;
	switch(AI[playerid][aReadCMD]){
		case 0:{
			AI[playerid][aReadCMD]=true;
			SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}�� �������� ������������ ������{CCFF00}!");
		}
		case 1:{
			AI[playerid][aReadCMD]=false;
			SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}�� ��������� ������������ ������{CCFF00}!");
		}
	}
	return 1;
}