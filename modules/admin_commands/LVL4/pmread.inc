CMD:pmread(playerid){
	if(AI[playerid][aLevel] < 4) return 1;
	switch(AI[playerid][aReadPM]){
		case 0:{
			AI[playerid][aReadPM]=true;
			SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы включили чтение /pm{CCFF00}!");
		}
		case 1:{
			AI[playerid][aReadPM]=false;
			SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы отключили  чтение /pm{CCFF00}!");
		}
	}
	return 1;
}