/*
 *###############################################################################
 *#                                                                             #
 *# Copyright (C) 2022 Project Nighthold <https://github.com/ProjectNighthold>  #
 *#                                                                             #
 *# This file is free software; as a special exception the author gives         #
 *# unlimited permission to copy and/or distribute it, with or without          #
 *# modifications, as long as this notice is preserved.                         #
 *#                                                                             #
 *# This program is distributed in the hope that it will be useful, but         #
 *# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the      #
 *# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.    #
 *#                                                                             #
 *# Read the THANKS file on the source root directory for more info.            #
 *#                                                                             #
 *###############################################################################
 */

#ifndef _WORLDDATABASE_H
#define _WORLDDATABASE_H

#include "DatabaseWorkerPool.h"
#include "MySQLConnection.h"

class WorldDatabaseConnection : public MySQLConnection
{
    public:
        //- Constructors for sync and async connections
        WorldDatabaseConnection(MySQLConnectionInfo& connInfo) : MySQLConnection(connInfo) { }
        WorldDatabaseConnection(ProducerConsumerQueue<SQLOperation*>* q, MySQLConnectionInfo& connInfo) : MySQLConnection(q, connInfo) { }

        //- Loads database type specific prepared statements
        void DoPrepareStatements();
};

typedef DatabaseWorkerPool<WorldDatabaseConnection> WorldDatabaseWorkerPool;

enum WorldDatabaseStatements
{
    /*  Naming standard for defines:
        {DB}_{SEL/INS/UPD/DEL/REP}_{Summary of data changed}
        When updating more than one field, consider looking at the calling function
        name for a suiting suffix.
    */

    WORLD_SEL_QUEST_POOLS,
    WORLD_DEL_CRELINKED_RESPAWN,
    WORLD_REP_CREATURE_LINKED_RESPAWN,
    WORLD_SEL_SMART_SCRIPTS,
    WORLD_SEL_SMARTAI_WP,
    WORLD_DEL_GAMEOBJECT,
    WORLD_DEL_EVENT_GAMEOBJECT,
    WORLD_INS_GRAVEYARD_ZONE,
    WORLD_DEL_GRAVEYARD_ZONE,
    WORLD_INS_GAME_TELE,
    WORLD_DEL_GAME_TELE,
    WORLD_INS_NPC_VENDOR,
    WORLD_DEL_NPC_VENDOR,
    WORLD_SEL_NPC_VENDOR_REF,
    WORLD_UPD_CREATURE_MOVEMENT_TYPE,
    WORLD_UPD_CREATURE_FACTION,
    WORLD_UPD_CREATURE_NPCFLAG,
    WORLD_UPD_CREATURE_POSITION,
    WORLD_UPD_CREATURE_SPAWN_DISTANCE,
    WORLD_UPD_CREATURE_SPAWN_TIME_SECS,
    WORLD_INS_CREATURE_FORMATION,
    WORLD_INS_WAYPOINT_DATA,
    WORLD_DEL_WAYPOINT_DATA,
    WORLD_UPD_WAYPOINT_DATA_POINT,
    WORLD_UPD_WAYPOINT_DATA_POSITION,
    WORLD_UPD_WAYPOINT_DATA_WPGUID,
    WORLD_UPD_WAYPOINT_DATA_ALL_WPGUID,
    WORLD_SEL_WAYPOINT_DATA_MAX_ID,
    WORLD_SEL_WAYPOINT_DATA_BY_ID,
    WORLD_SEL_WAYPOINT_DATA_SCRIPT_BY_ID,
    WORLD_SEL_WAYPOINT_DATA_POS_BY_ID,
    WORLD_SEL_WAYPOINT_DATA_POS_FIRST_BY_ID,
    WORLD_SEL_WAYPOINT_DATA_POS_LAST_BY_ID,
    WORLD_SEL_WAYPOINT_DATA_BY_WPGUID,
    WORLD_SEL_WAYPOINT_DATA_ALL_BY_WPGUID,
    WORLD_SEL_WAYPOINT_DATA_MAX_POINT,
    WORLD_SEL_WAYPOINT_DATA_BY_POS,
    WORLD_SEL_WAYPOINT_DATA_WPGUID_BY_ID,
    WOLRD_SEL_WAYPOINT_DATA_ACTION,
    WORLD_SEL_WAYPOINT_SCRIPTS_MAX_ID,
    WORLD_UPD_CREATURE_ADDON_PATH,
    WORLD_INS_CREATURE_ADDON,
    WORLD_DEL_CREATURE_ADDON,
    WORLD_SEL_CREATURE_ADDON_BY_GUID,
    WORLD_INS_WAYPOINT_SCRIPT,
    WORLD_DEL_WAYPOINT_SCRIPT,
    WORLD_UPD_WAYPOINT_SCRIPT_ID,
    WORLD_UPD_WAYPOINT_SCRIPT_X,
    WORLD_UPD_WAYPOINT_SCRIPT_Y,
    WORLD_UPD_WAYPOINT_SCRIPT_Z,
    WORLD_UPD_WAYPOINT_SCRIPT_O,
    WORLD_SEL_WAYPOINT_SCRIPT_ID_BY_GUID,
    WORLD_DEL_CREATURE,
    WORLD_SEL_COMMANDS,
    WORLD_SEL_CREATURE_TEMPLATE,
    WORLD_SEL_WAYPOINT_SCRIPT_BY_ID,
    WORLD_SEL_IP2NATION_COUNTRY,
    WORLD_SEL_ITEM_TEMPLATE_BY_NAME,
    WORLD_SEL_CREATURE_BY_ID,
    WORLD_SEL_GAMEOBJECT_NEAREST,
    WORLD_SEL_GAMEOBJECT_TARGET,
    WORLD_SEL_CREATURE_NEAREST,
    WORLD_INS_CREATURE,
    WORLD_DEL_GAME_EVENT_CREATURE,
    WORLD_DEL_GAME_EVENT_MODEL_EQUIP,
    WORLD_INS_GAMEOBJECT,
    WORLD_SEL_DISABLES,
    WORLD_INS_DISABLES,
    WORLD_DEL_DISABLES,
    WORLD_SEL_BLACKMARKET_TEMPLATE,

    WORLD_SEL_CHARACTER_TEMPLATES,
    WORLD_SEL_CHARACTER_TEMPLATE_CLASSES,

    WORLD_DEL_EVENTOBJECT,
    WORLD_INS_EVENTOBJECT,
    WORLD_SEL_EVENTOBJECT_NEAREST,

    WORLD_UPD_QUEST_OBJECTIVE_BUGGED_STATE,

    WORLD_INS_CREATURE_ADDON_EMOTESTATE,
    WORLD_UPD_CREATURE_ADDON_EMOTESTATE,

    MAX_WORLDDATABASE_STATEMENTS,
};

#endif
