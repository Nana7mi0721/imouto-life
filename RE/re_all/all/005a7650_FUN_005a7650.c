
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005a7650(uint param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 local_a4;
  uint local_a0;
  undefined4 local_9c;
  float local_98;
  float local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  float local_84;
  undefined4 local_80;
  uint local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  float local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  undefined1 local_10 [4];
  undefined1 local_c [12];
  
  if (DAT_00f3a04c == 0) {
    return 0;
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  if (param_1 < 0x100) {
    piVar3 = param_2;
    piVar4 = &DAT_00e79ca0 + param_1 * 0x1a;
    for (iVar2 = 0x1a; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar4 = *piVar3;
      piVar3 = piVar3 + 1;
      piVar4 = piVar4 + 1;
    }
  }
  if ((int)param_1 < 6) {
    puVar1 = (undefined4 *)FUN_00514db0(&local_a4,param_2 + 0x10,&DAT_00a383d8);
    local_90 = *puVar1;
    local_8c = puVar1[1];
    local_88 = puVar1[2];
    puVar1 = (undefined4 *)FUN_00514d50(local_c,param_2 + 0xd,&DAT_00a383d8);
    local_a4 = *puVar1;
    local_a0 = puVar1[1];
    local_9c = puVar1[2];
    local_74 = 0x3f800000;
    local_70 = local_90;
    local_6c = local_8c;
    local_68 = local_88;
    local_64 = 0;
    local_60 = param_2[1];
    local_5c = param_2[2];
    local_58 = param_2[3];
    local_54 = param_2[4];
    local_50 = param_2[5];
    local_4c = param_2[6];
    local_48 = param_2[7];
    local_44 = param_2[8];
    local_40 = param_2[9];
    local_3c = param_2[10];
    local_38 = param_2[0xb];
    local_34 = param_2[0xc];
    local_30 = (float)param_2[0x13] * (float)param_2[0x13];
    local_2c = param_2[0x14];
    local_28 = param_2[0x15];
    local_24 = param_2[0x16];
    local_20 = param_2[0x17];
    local_98 = (float)param_2[0x18] * (float)_DAT_00804a60;
    local_80 = local_a4;
    local_7c = local_a0;
    local_78 = local_9c;
    FUN_0056d4d0(local_98,local_10,&local_94);
    local_98 = (float)param_2[0x19] * (float)_DAT_00804a60;
    FUN_0056d4d0(local_98,&local_a4,&local_84);
    local_1c = local_84;
    local_18 = 1.0 / (local_94 - local_84);
    local_14 = 0;
    if ((int)param_1 < 4) {
      FUN_0059cb80(&DAT_00ddb600,0,0,(param_1 + 2) * 7,&local_80,7,1);
      FUN_0059cb80(&DAT_00ddb600,3,0,param_1 * 3 + 9,&local_60,3,1);
    }
    FUN_0059cb80(&DAT_00ddb600,3,0,param_1 * 7 + 0x20,&local_80,7,1);
    FUN_005a2cb0();
  }
  if ((int)param_1 < 4) {
    iVar2 = *param_2;
    if ((iVar2 == 2) || (local_a4 = 0, iVar2 == 1)) {
      local_a4 = 1;
    }
    local_a0 = (uint)(iVar2 == 2);
    FUN_0059cb80(&DAT_00ddb600,2,0,param_1 * 3 + 5,&local_a4,2,1);
  }
  FUN_00597e70();
  iVar2 = FUN_005d3a30(param_1,param_2);
  return -(uint)(iVar2 != 0);
}

