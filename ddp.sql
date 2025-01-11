-- phpMyAdmin SQL Dump
-- version 5.2.1deb1
-- https://www.phpmyadmin.net/
--
-- Хост: localhost:3306
-- Время создания: Дек 17 2023 г., 19:30
-- Версия сервера: 10.11.3-MariaDB-1
-- Версия PHP: 8.2.7

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База данных: `ddp`
--

-- --------------------------------------------------------

--
-- Структура таблицы `admins`
--

CREATE TABLE `admins` (
  `kicksplayers` int(11) NOT NULL,
  `banedplayers` int(11) NOT NULL,
  `loggedcount` int(11) NOT NULL,
  `loggedtime` int(11) NOT NULL DEFAULT 0,
  `id` int(11) NOT NULL,
  `aname` text NOT NULL,
  `apass` text NOT NULL,
  `hash` text NOT NULL,
  `alevel` int(11) NOT NULL,
  `dateget` int(11) NOT NULL,
  `setadmin` text NOT NULL,
  `dateend` int(11) NOT NULL,
  `setendadmin` text NOT NULL,
  `reasonend` text NOT NULL,
  `blocklogged` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=cp1251 COLLATE=cp1251_general_cs;


-- --------------------------------------------------------

--
-- Структура таблицы `bans`
--

CREATE TABLE `bans` (
  `NameBan` text CHARACTER SET cp1251 COLLATE cp1251_general_cs NOT NULL,
  `UnbanDate` int(11) NOT NULL,
  `BanDate` int(11) NOT NULL,
  `Who` text CHARACTER SET cp1251 COLLATE cp1251_general_cs NOT NULL,
  `Reason` text CHARACTER SET cp1251 COLLATE cp1251_general_cs NOT NULL,
  `IP` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=cp1251 COLLATE=cp1251_general_ci;

-- --------------------------------------------------------

--
-- Структура таблицы `bussines`
--

CREATE TABLE `bussines` (
  `ID` int(11) NOT NULL,
  `Type` int(11) NOT NULL,
  `Price` int(11) NOT NULL,
  `X` float NOT NULL,
  `Y` float NOT NULL,
  `Z` float NOT NULL,
  `BuyID` int(11) NOT NULL,
  `accumulation` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=cp1251 COLLATE=cp1251_general_ci;

-- --------------------------------------------------------

--
-- Структура таблицы `gangs`
--

CREATE TABLE `gangs` (
  `gID` int(11) NOT NULL,
  `gName` text CHARACTER SET cp1251 COLLATE cp1251_general_cs NOT NULL,
  `gColor` text CHARACTER SET cp1251 COLLATE cp1251_general_cs NOT NULL,
  `g_Glawa` text CHARACTER SET cp1251 COLLATE cp1251_general_cs NOT NULL,
  `gSpawnX` double NOT NULL,
  `gSpawnY` double NOT NULL,
  `gSpawnZ` double NOT NULL,
  `gSpawnInt` int(11) NOT NULL,
  `g_VW` int(11) NOT NULL,
  `g_Players` int(11) NOT NULL,
  `g_cDate` int(11) NOT NULL,
  `gSkin0` int(11) NOT NULL,
  `gSkin1` int(11) NOT NULL,
  `gSkin2` int(11) NOT NULL,
  `gSkin3` int(11) NOT NULL,
  `gSkin4` int(11) NOT NULL,
  `gSkin5` int(11) NOT NULL,
  `gVerifyCapt` int(11) NOT NULL,
  `gLastOneCapt` int(11) NOT NULL,
  `gLastTwoCapt` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=cp1251 COLLATE=cp1251_general_ci;

-- --------------------------------------------------------

--
-- Структура таблицы `houses`
--

CREATE TABLE `houses` (
  `id` int(11) NOT NULL,
  `owned` tinyint(1) NOT NULL,
  `owner` varchar(24) CHARACTER SET cp1251 COLLATE cp1251_general_cs NOT NULL DEFAULT 'The State',
  `lock` tinyint(1) NOT NULL DEFAULT 1,
  `cost` int(11) NOT NULL,
  `klass` int(11) NOT NULL,
  `int` int(11) NOT NULL,
  `enterx` double NOT NULL,
  `entery` double NOT NULL,
  `enterz` double NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=cp1251 COLLATE=cp1251_general_ci;

-- --------------------------------------------------------

--
-- Структура таблицы `mutedlist`
--

CREATE TABLE `mutedlist` (
  `IDDB` int(11) NOT NULL,
  `getmute` int(11) NOT NULL,
  `endmute` int(11) NOT NULL,
  `admin` text CHARACTER SET cp1251 COLLATE cp1251_general_cs NOT NULL,
  `reason` text CHARACTER SET cp1251 COLLATE cp1251_general_cs NOT NULL,
  `leavetime` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=cp1251 COLLATE=cp1251_general_ci;

-- --------------------------------------------------------

--
-- Структура таблицы `players`
--

CREATE TABLE `players` (
  `PID` int(11) NOT NULL,
  `PlayerName` varchar(24) CHARACTER SET cp1251 COLLATE cp1251_general_cs NOT NULL,
  `TDReg` int(11) NOT NULL DEFAULT 0,
  `Money` int(11) NOT NULL DEFAULT 50000,
  `DriftExp` int(11) NOT NULL DEFAULT 5,
  `ExpRecord` int(11) NOT NULL DEFAULT 0,
  `Kills` int(11) NOT NULL DEFAULT 0,
  `MinLog` int(11) NOT NULL DEFAULT 0,
  `Deaths` int(11) NOT NULL DEFAULT 0,
  `Combo` int(11) NOT NULL DEFAULT 1,
  `VIP` int(11) NOT NULL DEFAULT 0,
  `RecPM` int(11) NOT NULL DEFAULT 1,
  `houseid` int(11) NOT NULL DEFAULT 0,
  `IPAdr` varchar(17) CHARACTER SET cp1251 COLLATE cp1251_general_cs NOT NULL DEFAULT 'localhost',
  `keymenu` int(11) NOT NULL DEFAULT 1,
  `Pass` varchar(512) CHARACTER SET cp1251 COLLATE cp1251_general_cs NOT NULL,
  `HASH` varchar(512) CHARACTER SET cp1251 COLLATE cp1251_general_cs NOT NULL,
  `Skin` int(11) NOT NULL DEFAULT 0,
  `weapons` text NOT NULL DEFAULT '',
  `ColorPlayer` int(11) NOT NULL DEFAULT 0,
  `SpawnChange` int(11) NOT NULL DEFAULT 0,
  `Labirint1` int(11) NOT NULL DEFAULT 0,
  `TrackMania1` int(11) NOT NULL DEFAULT 0,
  `TrackMania2` int(11) NOT NULL DEFAULT 0,
  `TrackMania3` int(11) NOT NULL DEFAULT 0,
  `Warns` int(11) NOT NULL DEFAULT 0,
  `sex` int(11) NOT NULL DEFAULT 0,
  `Gang` int(11) NOT NULL DEFAULT 0,
  `GangLvl` int(11) NOT NULL DEFAULT 0,
  `vsx` float NOT NULL DEFAULT 0,
  `vsy` float NOT NULL DEFAULT 0,
  `vsz` float NOT NULL DEFAULT 0,
  `vsa` float NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=cp1251 COLLATE=cp1251_general_ci;

--
-- Структура таблицы `prisonlist`
--

CREATE TABLE `prisonlist` (
  `IDDB` int(11) NOT NULL,
  `getprison` int(11) NOT NULL,
  `endprison` int(11) NOT NULL,
  `admin` text CHARACTER SET cp1251 COLLATE cp1251_general_cs NOT NULL,
  `reason` text CHARACTER SET cp1251 COLLATE cp1251_general_cs NOT NULL,
  `leavetime` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=cp1251 COLLATE=cp1251_general_ci;

-- --------------------------------------------------------

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `admins`
--
ALTER TABLE `admins`
  ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `bans`
--
ALTER TABLE `bans`
  ADD KEY `UnbanDate` (`UnbanDate`),
  ADD KEY `BanDate` (`BanDate`);

--
-- Индексы таблицы `bussines`
--
ALTER TABLE `bussines`
  ADD PRIMARY KEY (`ID`);

--
-- Индексы таблицы `gangs`
--
ALTER TABLE `gangs`
  ADD PRIMARY KEY (`gID`);

--
-- Индексы таблицы `houses`
--
ALTER TABLE `houses`
  ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `players`
--
ALTER TABLE `players`
  ADD PRIMARY KEY (`PID`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
