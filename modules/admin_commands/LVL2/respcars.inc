CMD:respcars(playerid)
{
	if(AI[playerid][aLevel] < 2) return 1;
	for(new c=0; c<MAX_VEHICLES; c++)
	{
		if(!IsVehicleOccupiedCar(c))
		{
			SetVehicleToRespawn(c);
		}
	}
	new string[144];
	format(string, sizeof(string), ""NS" {FFFFFF}������������� {CCFF00}%s {FFFFFF}����������� ��� ��������� �����!", PlayerInfo[playerid][pName]);
	SendClientMessage(playerid, COLOR_VIOLET, string);
	return 1;
}