#pragma once

enum NpcToServerPackets
{
    NpcToServerPacket_VersionPacket = 0,
    NpcToServerPacket_CreatePacket = 1,
    NpcToServerPacket_EnterWorldPacket = 2,
    NpcToServerPacket_MovePacket = 3,
    NpcToServerPacket_SayPacket = 4,
    NpcToServerPacket_AttackPacket = 5,
    NpcToServerPacket_ShowPagePacket = 6,
    NpcToServerPacket_RegisterTelPosListPacket = 7,
    NpcToServerPacket_TeleportPacket = 8,
    NpcToServerPacket_RegisterBuySellListPacket = 9,
    NpcToServerPacket_ShowBuyPagePacket = 10,
    NpcToServerPacket_ShowSellPagePacket = 11,
    NpcToServerPacket_GiveItemPacket = 12,
    NpcToServerPacket_ShowFHTML = 13,
    // no packet = 14,
    // no packet = 15,
    // no packet = 16,
    NpcToServerPacket_SetTaxRate = 17,
    NpcToServerPacket_RegisterAgit = 18,
    NpcToServerPacket_DeleteItemPacket = 19,
    NpcToServerPacket_ShowHTMLString = 20,
    NpcToServerPacket_ChangeMoveType = 21,
    NpcToServerPacket_EquipItem = 22,
    NpcToServerPacket_MoveToPawn = 23,
    NpcToServerPacket_ShowSkillList = 24,
    NpcToServerPacket_GrowSkillSuggestion = 25,
    // no packet = 26,
    // no packet = 27,
    NpcToServerPacket_GetItem = 28,
    NpcToServerPacket_ClassChange = 29,
    NpcToServerPacket_SetWeightPoint = 30,
    NpcToServerPacket_IncrementParam = 31,
    NpcToServerPacket_LeaveWorld = 32,
    NpcToServerPacket_UseSkill = 33,
    NpcToServerPacket_UseItem = 34,
    // no packet = 35,
    NpcToServerPacket_CreateOnePrivate = 36,
    NpcToServerPacket_EnableTimeEvent = 37,
    NpcToServerPacket_InstantTeleport = 38,
    NpcToServerPacket_InstantTeleportInMyTerritory = 39,
    NpcToServerPacket_KillMe = 40,
    NpcToServerPacket_PledgeLevelUp = 41,
    // no packet = 42,
    NpcToServerPacket_ViewSiegeList = 43,
    NpcToServerPacket_ApproveBattle = 44,
    NpcToServerPacket_CastleGateOpenClose_4A6310 = 45,
    NpcToServerPacket_ShowSystemMessage = 46,
    // no packet = 47,
    NpcToServerPacket_SocialAction = 48,
    NpcToServerPacket_Despawn = 49,
    NpcToServerPacket_PongForCastleSiege = 50,
    NpcToServerPacket_CastleSetCropPrice = 51,
    NpcToServerPacket_CastleSetCropDrop = 52,
    NpcToServerPacket_CastleDeleteCropDrfOPCODE_OP = 53,
    NpcToServerPacket_CastlePostCropPurchase = 54,
    NpcToServerPacket_Sound = 55,
    NpcToServerPacket_CastleBanishOthers = 56,
    NpcToServerPacket_CastleHpRegen = 57,
    NpcToServerPacket_CastleMpRegen = 58,
    NpcToServerPacket_ChangeStopType = 59,
    NpcToServerPacket_ShowTutorialPage = 60,
    NpcToServerPacket_ShowQuestionMark = 61,
    NpcToServerPacket_CloseTutorialHTML = 62,
    NpcToServerPacket_EnableTutorialEvent = 63,
    NpcToServerPacket_ShowRadar = 64,
    NpcToServerPacket_DeleteRadar = 65,
    NpcToServerPacket_CastleGateOpenClose = 66,
    NpcToServerPacket_CreatePet = 67,
    NpcToServerPacket_AtomicDelGiveItem = 68,
    NpcToServerPacket_Earthquake = 69,
    NpcToServerPacket_SpecialCamera = 70,
    NpcToServerPacket_SpecialCamera2 = 71,
    NpcToServerPacket_NormalCamera = 72,
    NpcToServerPacket_AgitAuction = 73,
    NpcToServerPacket_OpenSiegeInfo = 74,
    NpcToServerPacket_SetDoorHpLevel = 75,
    NpcToServerPacket_GetDoorHpLevel = 76,
    NpcToServerPacket_SetControlTowerLevel = 77,
    NpcToServerPacket_GetControlTowerLevel = 78,
    NpcToServerPacket_AgitTeleportLevel = 79,
    NpcToServerPacket_MusicEffect = 80,
    NpcToServerPacket_SetResidenceTaxRate = 81,
    NpcToServerPacket_MoveTaxToResidenceBank = 82,
    NpcToServerPacket_SetResidenceTaxRateEach = 83,
    NpcToServerPacket_SetVaultEmpty = 84,
    NpcToServerPacket_Dummy = 85
};