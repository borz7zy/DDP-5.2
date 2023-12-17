CMD:acread(playerid){
	if(AI[playerid][aLevel] < 1) return 1;
	switch(AI[playerid][aReadCheat]){
		case 0:{
			AI[playerid][aReadCheat]=true;
			SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы включили уведомления от античита{CCFF00}!");
		}
		case 1:{
			AI[playerid][aReadCheat]=false;
			SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы отключили уведомления от античита{CCFF00}!");
		}
	}
	return 1;
}