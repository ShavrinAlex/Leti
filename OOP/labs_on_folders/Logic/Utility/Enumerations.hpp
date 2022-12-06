#pragma once

enum GameControllCommands {Nothing, MovePlayerRight, MovePlayerLeft, MovePlayerUp, MovePlayerDown, PlayerShoot, SetErrorsLogLevel, SetProcessesLogLevel, SetGameStatesLogLevel, AddConsoleLogStream, AddFileLogStream, RemoveConsoleLogStream, RemoveFileLogStream, QuitGame};
enum Direction {Right, Left, Up, Down};
enum GameStatus {Continues, Win, Loose, Quit, Pause};
enum EventStatus {Delete, Leave};
enum LogLevels {Errors, Processes, GameStates};
enum LogCout {Console, File};
enum Events {EndGame, WinGame, SetWall, SetWinGame, SetHealth, SetArmor, SetEnergy};
enum Levels {One, Two};
