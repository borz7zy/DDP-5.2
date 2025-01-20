new PLAYER_CAR_DIALOG_SELECTED[MAX_PLAYERS] = {-1};

enum car_list{
    modelid,
    name[32]
};

static const StreetRacerCars[][car_list] = {
    {562, "Elegy"},
    {565, "Flash"},
    {559, "Jester"},
    {561, "Stratum"},
    {560, "Sultan"},
    {558, "Uranus"}
};

static const RaceCars[][car_list] = {
    {429, "Banshee"},
    {541, "Bullet"},
    {415, "Cheetah"},
    {480, "Comet"},
    {434, "Hotknife"},
    {494, "Hotring"},
    {502, "Hotring A"},
    {503, "Hotring B"},
    {411, "Infernus"},
    {506, "Super GT"},
    {451, "Turismo"},
    {555, "Windsor"},
    {477, "ZR-350"}
};

static const LowriderCars[][car_list] = {
    {536, "Blade"},
    {575, "Broadway"},
    {534, "Remington"},
    {567, "Savanna"},
    {535, "Slamvan"},
    {576, "Tornado"},
    {412, "Voodoo"}
};

static const TwoDoorsSedans[][car_list] = {
    {602, "Alpha"},
    {496, "Blista"},
    {401, "Bravura"},
    {518, "Buccaneer"},
    {527, "Cadrona"},
    {589, "Club"},
    {419, "Esperanto"},
    {587, "Euros"},
    {533, "Feltzer"},
    {526, "Fortune"},
    {474, "Hermes"},
    {545, "Hustler"},
    {517, "Majestic"},
    {410, "Manana"},
    {600, "Picador"},
    {436, "Previon"},
    {439, "Stallion"},
    {549, "Tampa"},
    {491, "Virgo"}
};

static const FourDoorsSedans[][car_list] = {
    {445, "Admiral"},
    {507, "Elegant"},
    {585, "Emperor"},
    {466, "Glendale"},
    {492, "Greenwood"},
    {546, "Intruder"},
    {551, "Merit"},
    {516, "Nebula"},
    {467, "Oceanic"},
    {426, "Premier"},
    {547, "Primo"},
    {405, "Sentinal"},
    {580, "Stafford"},
    {409, "Stretch"},
    {550, "Sunrise"},
    {566, "Tahoma"},
    {540, "Vincent"},
    {421, "Washington"},
    {529, "Willard"}
};

static const Jeeps[][car_list] = {
    {579, "Huntley"},
    {400, "Landstalker"},
    {404, "Perrenial"},
    {489, "Rancher"},
    {479, "Regina"},
    {442, "Romero"},
    {458, "Solair"}
};

static const PowerCars[][car_list] = {
    {402, "Buffalo"},
    {542, "Clover"},
    {603, "Phoenix"},
    {475, "Sabre"}
};

static const WorkCars[][car_list] = {
    {499, "Benson"},
    {498, "Boxville"},
    {609, "Boxville-Black"},
    {524, "Cement Truck"},
    {532, "Combine Harvestor"},
    {578, "DFT-30"},
    {486, "Dozer"},
    {406, "Dumper"},
    {573, "Dune"},
    {455, "Flatbed"},
    {588, "Hotdog"},
    {403, "Linerunner"},
    {423, "Mr Woopee"},
    {414, "Mule"},
    {443, "Packer"},
    {515, "Roadtrain"},
    {514, "Tanker"},
    {531, "Tractor"},
    {456, "Yankee"}
};

static const VanCars[][car_list] = {
    {459, "Topfun"},
    {422, "Bobcat"},
    {482, "Burrito"},
    {530, "Forklift"},
    {418, "Moonbeam"},
    {572, "Mower"},
    {582, "Newsvan"},
    {413, "Pony"},
    {440, "Rumpo"},
    {543, "Sadler"},
    {583, "Tug"},
    {478, "Walton"},
    {554, "Yosemite"}
};

static const FunnyCars[][car_list] = {
    {568, "Bandito"},
    {424, "BF Injection"},
    {504, "Bloodring Banger"},
    {457, "Caddy"},
    {483, "Camper"},
    {508, "Journey"},
    {571, "Kart"},
    {500, "Mesa"},
    {444, "Monster"},
    {556, "Monster A"},
    {557, "Monster B"},
    {471, "Quad"},
    {495, "Sandking"},
    {539, "Vortex"}
};

static const BicyclesMotorcycles[][car_list] = {
    {481, "BMX"},
    {509, "Bike"},
    {510, "Mountain Bike"},
    {581, "BF-400"},
    {462, "Faggio"},
    {521, "FCR-900"},
    {463, "Freeway"},
    {522, "NRG-500"},
    {461, "PCJ-600"},
    {448, "Pizzaboy"},
    {468, "Sanchez"},
    {586, "Wayfarer"}
};

static const TransportationCars[][car_list] = {
    {485, "Baggage"},
    {431, "Bus"},
    {438, "Cabbie"},
    {437, "Coach"},
    {574, "Sweeper"},
    {420, "Taxi"},
    {525, "Towtruck"},
    {408, "Trashmaster"},
    {552, "Utility Van"}
};

static const StateCars[][car_list] = {
    {416, "Ambulance"},
    {433, "Barracks"},
    {427, "Enforcer"},
    {490, "FBI Rancher"},
    {528, "FBI Truck"},
    {407, "Fire Truck"},
    {544, "Fire Truck A"},
    {523, "HPV-1000"},
    {470, "Patriot"},
    {596, "Police Los Santos"},
    {597, "Police San Fierro"},
    {598, "Police Las Venturas"},
    {599, "Police Ranger"},
    {428, "Securicar"},
    {601, "Swat Tank"}
};

static const AirCars[][car_list] = {
    {592, "Andromada"},
    {577, "AT-400"},
    {511, "Beagle"},
    {548, "Cargobob"},
    {512, "Cropduster"},
    {593, "Dodo"},
    {417, "Leviathan"},
    {487, "Maverick"},
    {553, "Nevada"},
    {488, "News Maverick"},
    {497, "Police Maverick"},
    {563, "Raindance"},
    {476, "Rustler"},
    {447, "Seasparrow"},
    {519, "Shamal"},
    {460, "Skimmer"},
    {469, "Sparrow"},
    {513, "Stunt Plane"}
};

static const WaterCars[][car_list] = {
    {472, "Coastguard"},
    {473, "Dingy"},
    {493, "Jetmax"},
    {595, "Launch"},
    {484, "Marquis"},
    {430, "Predator"},
    {453, "Reefer"},
    {452, "Speeder"},
    {446, "Squallo"},
    {454, "Tropic"}
};

fpub:select_car_from_type(pid, dialogid, response, listitem, string:inputtext[]){
    if(!response) return SelectTypeCar(pid);
    new carid;
    new car_name[32];
    switch(PLAYER_CAR_DIALOG_SELECTED[pid]){
        case 0:{
            carid = StreetRacerCars[listitem][modelid];
            car_name = StreetRacerCars[listitem][name];
        }
        case 1:{
            carid = RaceCars[listitem][modelid];
            car_name = RaceCars[listitem][name];
        }
        case 2:{
            carid = LowriderCars[listitem][modelid];
            car_name = LowriderCars[listitem][name];
        }
        case 3:{
            carid = TwoDoorsSedans[listitem][modelid];
            car_name = TwoDoorsSedans[listitem][name];
        }
        case 4:{
            carid = FourDoorsSedans[listitem][modelid];
            car_name = FourDoorsSedans[listitem][name];
        }
        case 5:{
            carid = Jeeps[listitem][modelid];
            car_name = Jeeps[listitem][name];
        }
        case 6:{
            carid = PowerCars[listitem][modelid];
            car_name = PowerCars[listitem][name];
        }
        case 7:{
            carid = WorkCars[listitem][modelid];
            car_name = WorkCars[listitem][name];
        }
        case 8:{
            carid = VanCars[listitem][modelid];
            car_name = VanCars[listitem][name];
        }
        case 9:{
            carid = FunnyCars[listitem][modelid];
            car_name = FunnyCars[listitem][name];
        }
        case 10:{
            carid = BicyclesMotorcycles[listitem][modelid];
            car_name = BicyclesMotorcycles[listitem][name];
        }
        case 11:{
            carid = TransportationCars[listitem][modelid];
            car_name = TransportationCars[listitem][name];
        }
        case 12:{
            carid = StateCars[listitem][modelid];
            car_name = StateCars[listitem][name];
        }
        case 13:{
            carid = AirCars[listitem][modelid];
            car_name = AirCars[listitem][name];
        }
        case 14:{
            carid = WaterCars[listitem][modelid];
            car_name = WaterCars[listitem][name];
        }
    }
    SendClientMessage(pid, COLOR_VIOLET, "%s{FFFFFF} Вы выбрали {CCFF00}%s", NS, car_name);
    SendClientMessage(pid, COLOR_VIOLET, "%s{FFFFFF} Флипнуть тачку можно кнопкой {CCFF00}'N'", NS);
    SendClientMessage(pid, COLOR_VIOLET, "%s{FFFFFF} Телепортировать к себе транспорт при потере можно командой {CCFF00}/getv", NS);
    VehicSpawn(pid, carid, -1, -1);
    return 1;
}

stock PlayerDialogCars(playerid, listitem){
    if(PlayerInfo[playerid][pSkin] < 0){
        SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Для начала заспавнись!");
        return 1;
    }
    if(job[playerid]>0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Увольтесь с работы!");
    if(Prison[playerid] > gettime()){
        SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}В тюрьме меню не работает!");
        return 1;
    }
    if(Checkpoint[playerid] != 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Увольтесь с работы!");
    if(AI[playerid][aSpectateID] != INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}В слежке транспорт недоступен!");
    new dialog_header[64];
    new str_dialog[1024];
    switch(listitem){
        case 0:{
            dialog_header = "Стритрейсерские авто";
            str_dialog = "Транспорт\nElegy\nFlash\nJester\nStratum\nSultan\nUranus";
        }
        case 1:{
            dialog_header = "Гоночные авто";
            str_dialog = "Транспорт\nBanshee\nBullet\nCheetah\nComet\nHotknife\nHotring\nHotring A\nHotring B\nInfernus\nSuper GT\nTurismo\nWindsor\nZR-350";
        }
        case 2:{
            dialog_header = "Лоурайдеры";
            str_dialog = "Транспорт\nBlade\nBroadway\nRemington\nSavanna\nSlamvan\nTornado\nVoodoo";
        }
        case 3:{
            dialog_header = "Двухдверные седаны";
            str_dialog = "Транспорт\nAlpha\nBlista\nBravura\nBuccaneer\nCadrona\
            \nClub\nEsperanto\nEuros\nFeltzer\nFortune\nHermes\nHustler\nMajestic\nManana\nPicador\nPrevion\nStallion\nTampa\nVirgo";
        }
        case 4:{
            dialog_header = "Четырёхдверные седаны";
            str_dialog = "Транспорт\nAdmiral\nElegant\nEmperor\nGlendale\
            \nGreenwood\nIntruder\nMerit\nNebula\nOceanic\nPremier\nPrimo\nSentinal\nStafford\nStretch\nSunrise\nTahoma\
            \nVincent\nWashington\nWillard";
        }
        case 5:{
            dialog_header = "Джипы";
            str_dialog = "Транспорт\nHuntley\nLandstalker\nPerrenial\nRancher\nRegina\
            \nRomero\nSolair";
        }
        case 6:{
            dialog_header = "Мощные авто";
            str_dialog = "Транспорт\nBuffalo\nClover\nPhoenix\nSabre";
        }
        case 7:{
            dialog_header = "Грузовики и рабочий транспорт";
            str_dialog = "Транспорт\nBenson\nBoxville\
            \nBoxville-Black\nCement Truck\nCombine Harvestor\nDFT-30\nDozer\nDumper\nDune\nFlatbed\nHotdog\
            \nLinerunner\nMr Woopee\nMule\nPacker\nRoadtrain\nTanker\nTractor\nYankee";
        }
        case 8:{
            dialog_header = "Лёгкие грузовики и фургоны";
            str_dialog = "Транспорт\nTopfun\nBobcat\nBurrito\
            \nForklift\nMoonbeam\nMower\nNewsvan\nPony\nRumpo\nSadler\nTug\nWalton\nYosemite";
        }
        case 9:{
            dialog_header = "Транспорт для развлечения";
            str_dialog = "Транспорт\nBandito\nBF Injection\
            \nBloodring Banger\nCaddy\nCamper\nJourney\nKart\nMesa\nMonster\nMonster A\nMonster B\nQuad\nSandking\nVortex";
        }
        case 10:{
            dialog_header = "Велосипеды и мотоциклы";
            str_dialog = "Транспорт\nBMX\nBike\nMountain Bike\nBF-400\
            \nFaggio\nFCR-900\nFreeway\nNRG-500\nPCJ-600\nPizzaboy\nSanchez\nWayfarer";
        }
        case 11:{
            dialog_header = "Авто для транспортировки";
            str_dialog = "Транспорт\nBaggage\nBus\nCabbie\nCoach\
            \nSweeper\nTaxi\nTowtruck\nTrashmaster\nUtility Van";
        }
        case 12:{
            dialog_header = "Коммерческий и государственный транспорт";
            str_dialog = "Транспорт\nAmbulance\nBarracks\
            \nEnforcer\nFBI Rancher\nFBI Truck\nFire Truck\nFire Truck A\nHPV-1000\nPatriot\nPolice Los Santos\
            \nPolice San Fierro\nPolice Las Venturas\nPolice Ranger\nSecuricar\nSwat Tank";
        }
        case 13:{
            dialog_header = "Воздушный транспорт";
            str_dialog = "Транспорт\nAndromada\nAT-400\nBeagle\nCargobob\
            \nCropduster\nDodo\nLeviathan\nMaverick\nNevada\nNews Maverick\nPolice Maverick\nRaindance\nRustler\
            \nSeasparrow\nShamal\nSkimmer\nSparrow\nStunt Plane";
        }
        case 14:{
            dialog_header = "Водный транспорт";
            str_dialog = "Транспорт\nCoastguard\nDingy\nJetmax\nLaunch\nMarquis\
            \nPredator\nReefer\nSpeeder\nSquallo\nTropic";
        }
    }
    PLAYER_CAR_DIALOG_SELECTED[playerid] = listitem;
    Dialog_ShowCallback(playerid, using public select_car_from_type<iiiis>, DIALOG_STYLE_TABLIST_HEADERS, dialog_header, str_dialog, "OK", "Отмена");
    return 1;
}

fpub:select_type_car(pid, dialogid, response, listitem, string:inputtext[]){
    if(response) PlayerDialogCars(pid, listitem);
    return 1;
}

stock SelectTypeCar(playerid){
    Dialog_ShowCallback(playerid, using public select_type_car<iiiis>, DIALOG_STYLE_LIST, 
    "Тип транспорта", "Стритрейсерские авто\nГоночные авто\
    \nЛоурайдеры\nДвухдверные седаны\nЧетырёхдверные седаны\nДжипы\nМощные авто\nГрузовики и рабочий транспорт\
    \nЛёгкие грузовики и фургоны\nТранспорт для развлечения\nВелосипеды и мотоциклы\nАвто для транспортировки\
    \nКоммерческий и государственный транспорт\nВоздушный транспорт\nВодный транспорт", "Выбор", "Отмена");
    return 1;
}