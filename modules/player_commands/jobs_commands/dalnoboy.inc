CMD:off(playerid){
	if(Checkpoint[playerid] != 0){
		Checkpoint[playerid] = 0;
		DisablePlayerCheckpoint(playerid);
		SetVehicleToRespawn(GetVehicleTrailer(GetPlayerVehicleID(playerid)));
	}else SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}�� �� ��������� � ���������!");
	return 1;

}

CMD:start(playerid){
	if(IsPlayerConnected(playerid))
	{
	    if(IsPlayerInRangeOfPoint(playerid,200.0,-75.1052,-289.7339,6.4286))
	    {
            new model = GetVehicleModel(GetPlayerVehicleID(playerid));
			if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER && model==515 || GetPlayerState(playerid) != PLAYER_STATE_DRIVER && model==514 || GetPlayerState(playerid) != PLAYER_STATE_DRIVER && model==403)
			{
		    	SendClientMessage(playerid,COLOR_VIOLET,"[������������]:{FFFFFF} �� ������ ���� � ���� �� ����!");
		    	return true;
			}
			if(!IsTrailerAttachedToVehicle(GetPlayerVehicleID(playerid)))
			{
		    	SendClientMessage(playerid,COLOR_VIOLET,"[������������]:{FFFFFF} �� �� ��������� ������!");
		    	return true;
			}
			DisablePlayerCheckpoint(playerid);
//				SetPlayerVirtualWorld(playerid, 0);
		 	GameTextForPlayer(playerid, "~r~Goto redmarker", 2500, 1);
			Checkpoint[playerid] = 1;
			new traileid = GetVehicleTrailer(GetPlayerVehicleID(playerid));
			if(traileid == Pricep[5] || traileid == Pricep[6] || traileid == Pricep[7]) // �������
			{
 		    	new rand666=random(4);
		    	switch (rand666)
		    	{
					case 0:
					{
						SetPlayerCheckpoint(playerid,-2101.1555,208.4684,34.8973,8.0);
						SendClientMessage(playerid, COLOR_GREEN, "[���������]: {FFFFFF}����� ����� �� ����� � ������ SF � ��������� ���� ����");
        				SendClientMessage(playerid, COLOR_RED, "��������:{FFFFFF} ��� ��������� ����� ��� ������ ����� �������� �� ����.");
					}
			    	case 1:
					{
						SetPlayerCheckpoint(playerid,2560.7014,-2405.9651,13.6356,8.0);
						SendClientMessage(playerid, COLOR_GREEN, "[���������]: {FFFFFF}����� ����� �� ����� � ����� LS � ��������� ���� ����");
        				SendClientMessage(playerid, COLOR_RED, "��������:{FFFFFF} ��� ��������� ����� ��� ������ ����� �������� �� ����.");
					}
			    	case 2:
					{
						SetPlayerCheckpoint(playerid,2619.9587,833.6466,4.9254,8.0);
						SendClientMessage(playerid, COLOR_GREEN, "[���������]: {FFFFFF}����� ����� �� ����� � ������ LV � ��������� ���� ����");
        				SendClientMessage(playerid, COLOR_RED, "��������:{FFFFFF} ��� ��������� ����� ��� ������ ����� �������� �� ����.");
					}
			    	case 3:
					{
						SetPlayerCheckpoint(playerid,680.4613,896.6621,-40.3721,8.0);
						SendClientMessage(playerid, COLOR_GREEN, "[���������]: {FFFFFF}����� ����� �� ����� � ������� LV � ��������� ���� ����");
        				SendClientMessage(playerid, COLOR_RED, "��������:{FFFFFF} ��� ��������� ����� ��� ������ ����� �������� �� ����.");
					}
		    	}
			}
			if(traileid == Pricep[3] || traileid == Pricep[9]) // ��������
			{
 		    	new rand666=random(4);
		    	switch (rand666)
		    	{
					case 0:
					{
						SetPlayerCheckpoint(playerid,2193.5149,2476.3335,10.8203,8.0);
						SendClientMessage(playerid, COLOR_GREEN, "[���������]: {FFFFFF}����� ����� �� ����� � ������ LV � ��������� ���� ����");
        				SendClientMessage(playerid, COLOR_RED, "��������:{FFFFFF} ��� ��������� ����� ��� ������ ����� �������� �� ����.");
					}
			    	case 1:
					{
						SetPlayerCheckpoint(playerid,-2442.1062,953.0255,45.2969,8.0);
						SendClientMessage(playerid, COLOR_GREEN, "[���������]: {FFFFFF}����� ����� �� ����� � ������ SF � ��������� ���� ����");
        				SendClientMessage(playerid, COLOR_RED, "��������:{FFFFFF} ��� ��������� ����� ��� ������ ����� �������� �� ����.");
					}
			    	case 2:
					{
						SetPlayerCheckpoint(playerid,-1624.4644,-2697.6082,48.5391,8.0);
						SendClientMessage(playerid, COLOR_GREEN, "[���������]: {FFFFFF}����� ����� �� ����� ����� �������� � ��������� ���� ����");
        				SendClientMessage(playerid, COLOR_RED, "��������:{FFFFFF} ��� ��������� ����� ��� ������ ����� �������� �� ����.");
					}
			    	case 3:
					{
						SetPlayerCheckpoint(playerid,1918.5468,-1792.2303,13.3828,8.0);
						SendClientMessage(playerid, COLOR_GREEN, "[���������]: {FFFFFF}����� ����� �� ����� ����� �� LS � ��������� ���� ����");
        				SendClientMessage(playerid, COLOR_RED, "��������:{FFFFFF} ��� ��������� ����� ��� ������ ����� �������� �� ����.");
					}
		    	}
			}
			if(traileid == Pricep[8] || traileid == Pricep[4]) // ��������
			{
 		    	new rand666=random(4);
		    	switch (rand666)
		    	{
					case 0:
					{
						SetPlayerCheckpoint(playerid,2119.4260,-1826.5001,13.5549,8.0);
						SendClientMessage(playerid, COLOR_GREEN, "[���������]: {FFFFFF}����� ����� �� ����� � ����� LS � ��������� ���� ����");
        				SendClientMessage(playerid, COLOR_RED, "��������:{FFFFFF} ��� ��������� ����� ��� ������ ����� �������� �� ����.");
					}
			    	case 1:
					{
						SetPlayerCheckpoint(playerid,2073.7229,2225.8416,10.8203,8.0);
						SendClientMessage(playerid, COLOR_GREEN, "[���������]: {FFFFFF}����� ����� �� ����� ����� ������ LV � ��������� ���� ����");
        				SendClientMessage(playerid, COLOR_RED, "��������:{FFFFFF} ��� ��������� ����� ��� ������ ����� �������� �� ����.");
					}
			    	case 2:
					{
						SetPlayerCheckpoint(playerid,1383.9170,264.0096,19.5669,8.0);
						SendClientMessage(playerid, COLOR_GREEN, "[���������]: {FFFFFF}����� ����� �� ����� �� ������� �������� ��������� � LS ���� ����");
        				SendClientMessage(playerid, COLOR_RED, "��������:{FFFFFF} ��� ��������� ����� ��� ������ ����� �������� �� ����.");
					}
			    	case 3:
					{
						SetPlayerCheckpoint(playerid,-1802.8058,960.6457,24.8906,8.0);
						SendClientMessage(playerid, COLOR_GREEN, "[���������]: {FFFFFF}����� ����� �� ����� � ������ SF � ��������� ���� ����");
        				SendClientMessage(playerid, COLOR_RED, "��������:{FFFFFF} ��� ��������� ����� ��� ������ ����� �������� �� ����.");
					}
		    	}
			}
			if(traileid == Pricep[2]) // ������
			{
 		    	new rand666=random(4);
		    	switch (rand666)
		    	{
					case 0:
					{
						SetPlayerCheckpoint(playerid,505.3549,-1366.4999,16.1252,8.0);
						SendClientMessage(playerid, COLOR_GREEN, "[���������]: {FFFFFF}����� ����� �� ����� �� ������ �� ����� LS � ��������� ���� ����");
        				SendClientMessage(playerid, COLOR_RED, "��������:{FFFFFF} ��� ��������� ����� ��� ������ ����� �������� �� ����.");
					}
			    	case 1:
					{
						SetPlayerCheckpoint(playerid,2247.9878,-1663.3557,15.4690,8.0);
						SendClientMessage(playerid, COLOR_GREEN, "[���������]: {FFFFFF}����� ����� �� ����� ����� Grove Street � ��������� ���� ����");
        				SendClientMessage(playerid, COLOR_RED, "��������:{FFFFFF} ��� ��������� ����� ��� ������ ����� �������� �� ����.");
					}
			    	case 2:
					{
						SetPlayerCheckpoint(playerid,2105.0955,2248.5913,11.0234,8.0);
						SendClientMessage(playerid, COLOR_GREEN, "[���������]: {FFFFFF}����� ����� �� ����� ����� ������ LV � ��������� ���� ����");
        				SendClientMessage(playerid, COLOR_RED, "��������:{FFFFFF} ��� ��������� ����� ��� ������ ����� �������� �� ����.");
					}
			    	case 3:
					{
						SetPlayerCheckpoint(playerid,-1889.1820,874.3929,35.1719,8.0);
						SendClientMessage(playerid, COLOR_GREEN, "[���������]: {FFFFFF}����� ����� �� ����� � ������ SF � ��������� ���� ����");
        				SendClientMessage(playerid, COLOR_RED, "��������:{FFFFFF} ��� ��������� ����� ��� ������ ����� �������� �� ����.");
					}
		    	}
			}
			if(traileid == Pricep[1]) // ����� �������
			{
 		    	new rand666=random(4);
		    	switch (rand666)
		    	{
					case 0:
					{
						SetPlayerCheckpoint(playerid,2303.3145,-1635.1567,14.1720,8.0);
						SendClientMessage(playerid, COLOR_GREEN, "[���������]: {FFFFFF}����� ����� �� ����� ����� Grove Street � ��������� ���� ����");
        				SendClientMessage(playerid, COLOR_RED, "��������:{FFFFFF} ��� ��������� ����� ��� ������ ����� �������� �� ����.");
					}
			    	case 1:
					{
						SetPlayerCheckpoint(playerid,1830.3245,-1682.8469,13.1551,8.0);
						SendClientMessage(playerid, COLOR_GREEN, "[���������]: {FFFFFF}����� ����� �� ����� ����� �� LS � ��������� ���� ����");
        				SendClientMessage(playerid, COLOR_RED, "��������:{FFFFFF} ��� ��������� ����� ��� ������ ����� �������� �� ����.");
					}
			    	case 2:
					{
						SetPlayerCheckpoint(playerid,-2244.7861,-87.9356,34.9299,8.0);
						SendClientMessage(playerid, COLOR_GREEN, "[���������]: {FFFFFF}����� ����� �� ����� � ������ SF � ��������� ���� ����");
        				SendClientMessage(playerid, COLOR_RED, "��������:{FFFFFF} ��� ��������� ����� ��� ������ ����� �������� �� ����.");
					}
			    	case 3:
					{
						SetPlayerCheckpoint(playerid,-2555.2585,191.8923,5.7216,8.0);
						SendClientMessage(playerid, COLOR_GREEN, "[���������]: {FFFFFF}����� ����� �� ����� � ������ SF � ��������� ���� ����");
        				SendClientMessage(playerid, COLOR_RED, "��������:{FFFFFF} ��� ��������� ����� ��� ������ ����� �������� �� ����.");
					}
		    	}
			}
			if(traileid == Pricep[0]) // ��������
			{
 		    	new rand666=random(4);
		    	switch (rand666)
		    	{
					case 0:
					{
						SetPlayerCheckpoint(playerid,1363.6267,-1282.4384,13.5469,8.0);
						SendClientMessage(playerid, COLOR_GREEN, "[���������]: {FFFFFF}����� ����� �� ����� ����� �������� LS � ��������� ���� ����");
        				SendClientMessage(playerid, COLOR_RED, "��������:{FFFFFF} ��� ��������� ����� ��� ������ ����� �������� �� ����.");
					}
			    	case 1:
					{
						SetPlayerCheckpoint(playerid,2394.5999,-1978.2787,13.1115,8.0);
						SendClientMessage(playerid, COLOR_GREEN, "[���������]: {FFFFFF}����� ����� �� ����� ����� Grove Street � ��������� ���� ����");
        				SendClientMessage(playerid, COLOR_RED, "��������:{FFFFFF} ��� ��������� ����� ��� ������ ����� �������� �� ����.");
					}
			    	case 2:
					{
						SetPlayerCheckpoint(playerid,2156.1287,940.5781,10.4309,8.0);
						SendClientMessage(playerid, COLOR_GREEN, "[���������]: {FFFFFF}����� ����� �� ����� ������ 4 ������� � LV � ��������� ���� ����");
        				SendClientMessage(playerid, COLOR_RED, "��������:{FFFFFF} ��� ��������� ����� ��� ������ ����� �������� �� ����.");
					}
			    	case 3:
					{
						SetPlayerCheckpoint(playerid,-2626.6106,211.0776,4.2099,8.0);
						SendClientMessage(playerid, COLOR_GREEN, "[���������]: {FFFFFF}����� ����� �� ����� � ������ SF � ��������� ���� ����");
        				SendClientMessage(playerid, COLOR_RED, "��������:{FFFFFF} ��� ��������� ����� ��� ������ ����� �������� �� ����.");
					}
		    	}
			}
			MyPricep[playerid] = traileid;
		}
		else
		{
	    	SendClientMessage(playerid,COLOR_VIOLET,"[������������]:{FFFFFF} �� �� ���������� �� ��������� ��� � ��� ��� ���� ����!");
		}
	}
	return 1;
}