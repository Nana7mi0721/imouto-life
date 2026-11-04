
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0053ea50(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_EAX;
  uint uVar4;
  undefined *puVar5;
  int local_88;
  int local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  
  FUN_00537710(0,0,0,0,0,1,0,0x3ff0000000000000,0x3ff0000000000000,0,0,0,0,param_3,0,0,0,0);
  uVar3 = _DAT_00a38114;
  if (((DAT_00a380cc == 0) && ((*(byte *)(in_EAX + 0x93184) & 2) == 0)) ||
     ((uVar4 = *(uint *)(in_EAX + 0x93184) & 2, uVar4 == 0 &&
      ((DAT_00a380cc == 1 && (DAT_00a380d0 == 0xff)))))) {
    FUN_00537710(1,param_1,param_2,(float)param_1,(float)param_2,1,0,0x3ff0000000000000,
                 0x3ff0000000000000,0,0,0,0,param_3,param_5,DAT_00a37e58,&DAT_00a38194,1);
    return 0;
  }
  puVar5 = &DAT_00a37e40;
  if (uVar4 == 0) {
    puVar5 = &DAT_00a37e28;
  }
  local_60 = DAT_00a38194;
  local_5c = DAT_00a38198;
  local_54 = DAT_00a381a0;
  local_58 = DAT_00a3819c;
  local_4c = 0;
  local_50 = 0;
  local_44 = DAT_00a37e64;
  local_80 = 0;
  local_7c = 0;
  local_48 = DAT_00a37e60;
  local_78 = local_88;
  local_74 = local_84;
  if (*(char *)(in_EAX + 0x93168) != '\0') {
    local_78 = (uint)(*(ushort *)(in_EAX + 0x9316a) >> 1) + local_88;
  }
  FUN_00514e10(&local_80,&local_50);
  DAT_00a38198 = local_7c;
  DAT_00a38194 = local_80;
  DAT_00a3819c = local_78;
  DAT_00a381a0 = local_74;
  FUN_005811b0(&local_80);
  if ((*(byte *)(in_EAX + 0x93184) & 2) == 0) {
    while( true ) {
      iVar2 = *(int *)(*(int *)(puVar5 + 0x14) + 0x1c);
      if ((param_5 != iVar2) && (param_6 != iVar2)) break;
      piVar1 = (int *)(*(int *)(puVar5 + 0x14) + 0x1c);
      *piVar1 = *piVar1 + 1;
    }
  }
  else {
    *(undefined4 *)(*(int *)(puVar5 + 0x14) + 0x1c) = 0;
  }
  FUN_00581fb0(puVar5,&local_80,*(undefined4 *)(*(int *)(puVar5 + 0x14) + 0x1c));
  FUN_00537710(1,0,0,0,0,1,0,0x3ff0000000000000,0x3ff0000000000000,0,0,0,0,param_3,param_5,puVar5,
               &local_80,1);
  local_68 = local_78 + param_1;
  local_64 = local_74 + param_2;
  _DAT_00a38114 = 0xffffff;
  local_70 = param_1;
  local_6c = param_2;
  FUN_00514e10(&local_70,&local_60);
  DAT_00a38198 = local_6c;
  DAT_00a38194 = local_70;
  DAT_00a3819c = local_68;
  DAT_00a381a0 = local_64;
  FUN_005811b0(&local_70);
  FUN_006c8cc0(DAT_00a37e58,puVar5,param_1,param_2,1,DAT_00a37e5c);
  DAT_00a38198 = local_5c;
  DAT_00a38194 = local_60;
  DAT_00a3819c = local_58;
  DAT_00a381a0 = local_54;
  FUN_005811b0(&local_60);
  _DAT_00a38114 = uVar3;
  return 0;
}

