CMD:getv(playerid){
	if(job[playerid]>0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Увольтесь с работы!");
	if(dmzone[playerid] != 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Для начала уйдите с дм зоны! {CCFF00}( /dmexit )");
	if(playcar[playerid]==0)return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы еще не арендовали транспорт. Аренда транспорта в меню");
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid,x,y,z);
	SetVehicleVirtualWorld(playcar[playerid], GetPlayerVirtualWorld(playerid));
	SetVehiclePos(playcar[playerid],x+3,y,z);
	PutPlayerInVehicle(playerid, playcar[playerid], 0);
	SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Транспорт телепортирован к вам!");
	return 1;
}