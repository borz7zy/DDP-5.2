CMD:acread(playerid){
	if(AI[playerid][aLevel] < 1) return 1;
	switch(AI[playerid][aReadCheat]){
		case false:{
			AI[playerid][aReadCheat]=true;
			SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}�� �������� ����������� �� ��������{CCFF00}!");
		}
		case true:{
			AI[playerid][aReadCheat]=false;
			SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}�� ��������� ����������� �� ��������{CCFF00}!");
		}
	}
	return 1;
}