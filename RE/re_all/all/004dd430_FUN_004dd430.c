
/* WARNING: Removing unreachable block (ram,0x004dd476) */
/* WARNING: Removing unreachable block (ram,0x004dd4e8) */
/* WARNING: Removing unreachable block (ram,0x004dd55e) */
/* WARNING: Removing unreachable block (ram,0x004dd590) */
/* WARNING: Removing unreachable block (ram,0x004dd5cb) */
/* WARNING: Removing unreachable block (ram,0x004dd611) */
/* WARNING: Removing unreachable block (ram,0x004dd5ee) */
/* WARNING: Removing unreachable block (ram,0x004dd634) */
/* WARNING: Removing unreachable block (ram,0x004dd666) */
/* WARNING: Removing unreachable block (ram,0x004dd68f) */
/* WARNING: Removing unreachable block (ram,0x004dd6bd) */
/* WARNING: Removing unreachable block (ram,0x004dd703) */
/* WARNING: Removing unreachable block (ram,0x004dd6e0) */
/* WARNING: Removing unreachable block (ram,0x004dd504) */
/* WARNING: Removing unreachable block (ram,0x004dd534) */
/* WARNING: Removing unreachable block (ram,0x004dd559) */
/* WARNING: Removing unreachable block (ram,0x004dd492) */
/* WARNING: Removing unreachable block (ram,0x004dd4c0) */
/* WARNING: Removing unreachable block (ram,0x004dd4e3) */
/* WARNING: Removing unreachable block (ram,0x004dd726) */

undefined4 * __thiscall
FUN_004dd430(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined1 local_28 [8];
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18 [16];
  undefined4 local_8;
  
  FUN_004e9510();
  iVar2 = FUN_004cc130();
  if (iVar2 == 0) {
    FUN_004ddc10(param_2,1,*(undefined4 *)(param_1 + 4),param_4);
    return param_2;
  }
  uVar3 = FUN_004cc870(local_18);
  cVar1 = const_iterator__operator__(uVar3);
  if (cVar1 == '\0') {
    uVar3 = FUN_004ce060(local_1c);
    cVar1 = const_iterator__operator__(uVar3);
    if (cVar1 == '\0') {
      uVar3 = FUN_004e9610();
      uVar3 = FUN_004dd3d0(uVar3);
      uVar4 = FUN_004e8ab0(param_4,uVar3);
      cVar1 = FUN_004d59a0(uVar4,uVar3);
      if (cVar1 != '\0') {
        local_8 = param_3;
        uVar3 = FUN_004e8ab0(param_4);
        FUN_004dea10(uVar3);
        uVar4 = FUN_004e9610();
        uVar4 = FUN_004dd3d0(uVar4);
        cVar1 = FUN_004d59a0(uVar4,uVar3);
        if (cVar1 != '\0') {
          uVar3 = FUN_004e9610();
          puVar6 = (undefined4 *)FUN_004d6880(uVar3);
          pcVar5 = (char *)FUN_004dd3c0(*puVar6);
          if (*pcVar5 == '\0') {
            uVar3 = FUN_004e9610(param_4);
            FUN_004ddc10(param_2,1,uVar3,param_4);
            return param_2;
          }
          uVar3 = FUN_004e9610(param_4);
          FUN_004ddc10(param_2,0,uVar3,param_4);
          return param_2;
        }
      }
      uVar3 = FUN_004e8ab0(param_4);
      uVar4 = FUN_004e9610(uVar3);
      uVar4 = FUN_004dd3d0(uVar4);
      cVar1 = FUN_004d59a0(uVar4,uVar3);
      if (cVar1 != '\0') {
        local_8 = param_3;
        uVar3 = FUN_004ce060(local_20);
        FUN_004e8ac0(uVar3);
        cVar1 = const_iterator__operator__(uVar3);
        if (cVar1 == '\0') {
          uVar3 = FUN_004e9610();
          uVar3 = FUN_004dd3d0(uVar3);
          uVar4 = FUN_004e8ab0(param_4,uVar3);
          cVar1 = FUN_004d59a0(uVar4,uVar3);
          if (cVar1 == '\0') goto LAB_004dd9d5;
        }
        uVar3 = FUN_004e9610();
        puVar6 = (undefined4 *)FUN_004d6880(uVar3);
        pcVar5 = (char *)FUN_004dd3c0(*puVar6);
        if (*pcVar5 == '\0') {
          uVar3 = FUN_004e9610(param_4);
          FUN_004ddc10(param_2,1,uVar3,param_4);
          return param_2;
        }
        uVar3 = FUN_004e9610(param_4);
        FUN_004ddc10(param_2,0,uVar3,param_4);
        return param_2;
      }
    }
    else {
      uVar3 = FUN_004e8ab0(param_4);
      puVar6 = (undefined4 *)FUN_004e1fa0(uVar3);
      uVar4 = FUN_004dd3d0(*puVar6);
      cVar1 = FUN_004d59a0(uVar4,uVar3);
      if (cVar1 != '\0') {
        puVar6 = (undefined4 *)FUN_004e1fa0(param_4);
        FUN_004ddc10(param_2,0,*puVar6,param_4);
        return param_2;
      }
    }
  }
  else {
    uVar3 = FUN_004e9610();
    uVar3 = FUN_004dd3d0(uVar3);
    uVar4 = FUN_004e8ab0(param_4,uVar3);
    cVar1 = FUN_004d59a0(uVar4,uVar3);
    if (cVar1 != '\0') {
      uVar3 = FUN_004e9610(param_4);
      FUN_004ddc10(param_2,1,uVar3,param_4);
      return param_2;
    }
  }
LAB_004dd9d5:
  puVar6 = (undefined4 *)FUN_004d3720(local_28,param_4);
  *param_2 = *puVar6;
  return param_2;
}

