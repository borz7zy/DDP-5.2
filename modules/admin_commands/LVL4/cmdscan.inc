CMD:cmdscan(playerid){
	if(AI[playerid][aLevel] < 4) return 1;
	switch(AI[playerid][aReadCMD]){
		case false:{
			AI[playerid][aReadCMD]=true;
			SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}�� �������� ������������ ������{CCFF00}!");
		}
		case true:{
			AI[playerid][aReadCMD]=false;
			SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}�� ��������� ������������ ������{CCFF00}!");
		}
	}
	return 1;
}