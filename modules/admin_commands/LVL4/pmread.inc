CMD:pmread(playerid){
	if(AI[playerid][aLevel] < 4) return 1;
	switch(AI[playerid][aReadPM]){
		case false:{
			AI[playerid][aReadPM]=true;
			SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы включили чтение /pm{CCFF00}!");
		}
		case true:{
			AI[playerid][aReadPM]=false;
			SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы отключили  чтение /pm{CCFF00}!");
		}
	}
	return 1;
}