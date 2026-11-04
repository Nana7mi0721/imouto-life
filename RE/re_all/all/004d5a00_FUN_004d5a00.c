
/* WARNING: Removing unreachable block (ram,0x004d5a46) */
/* WARNING: Removing unreachable block (ram,0x004d5ab8) */
/* WARNING: Removing unreachable block (ram,0x004d5b2e) */
/* WARNING: Removing unreachable block (ram,0x004d5b60) */
/* WARNING: Removing unreachable block (ram,0x004d5b9b) */
/* WARNING: Removing unreachable block (ram,0x004d5be1) */
/* WARNING: Removing unreachable block (ram,0x004d5bbe) */
/* WARNING: Removing unreachable block (ram,0x004d5c04) */
/* WARNING: Removing unreachable block (ram,0x004d5c36) */
/* WARNING: Removing unreachable block (ram,0x004d5c5f) */
/* WARNING: Removing unreachable block (ram,0x004d5c8d) */
/* WARNING: Removing unreachable block (ram,0x004d5cd3) */
/* WARNING: Removing unreachable block (ram,0x004d5cb0) */
/* WARNING: Removing unreachable block (ram,0x004d5ad4) */
/* WARNING: Removing unreachable block (ram,0x004d5b04) */
/* WARNING: Removing unreachable block (ram,0x004d5b29) */
/* WARNING: Removing unreachable block (ram,0x004d5a62) */
/* WARNING: Removing unreachable block (ram,0x004d5a90) */
/* WARNING: Removing unreachable block (ram,0x004d5ab3) */
/* WARNING: Removing unreachable block (ram,0x004d5cf6) */

undefined4 * __thiscall
FUN_004d5a00(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

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
    FUN_004e1a10(param_2,1,*(undefined4 *)(param_1 + 4),param_4);
    return param_2;
  }
  uVar3 = FUN_004cc870(local_18);
  cVar1 = const_iterator__operator__(uVar3);
  if (cVar1 == '\0') {
    uVar3 = FUN_004ce060(local_1c);
    cVar1 = const_iterator__operator__(uVar3);
    if (cVar1 == '\0') {
      uVar3 = FUN_004e9610();
      uVar3 = FUN_004d52c0(uVar3);
      uVar4 = FUN_004e8ab0(param_4,uVar3);
      cVar1 = FUN_004d6210(uVar4,uVar3);
      if (cVar1 != '\0') {
        local_8 = param_3;
        uVar3 = FUN_004e8ab0(param_4);
        FUN_004e91e0(uVar3);
        uVar4 = FUN_004e9610();
        uVar4 = FUN_004d52c0(uVar4);
        cVar1 = FUN_004d6210(uVar4,uVar3);
        if (cVar1 != '\0') {
          uVar3 = FUN_004e9610();
          puVar6 = (undefined4 *)FUN_004d6880(uVar3);
          pcVar5 = (char *)FUN_004e0e80(*puVar6);
          if (*pcVar5 == '\0') {
            uVar3 = FUN_004e9610(param_4);
            FUN_004e1a10(param_2,1,uVar3,param_4);
            return param_2;
          }
          uVar3 = FUN_004e9610(param_4);
          FUN_004e1a10(param_2,0,uVar3,param_4);
          return param_2;
        }
      }
      uVar3 = FUN_004e8ab0(param_4);
      uVar4 = FUN_004e9610(uVar3);
      uVar4 = FUN_004d52c0(uVar4);
      cVar1 = FUN_004d6210(uVar4,uVar3);
      if (cVar1 != '\0') {
        local_8 = param_3;
        uVar3 = FUN_004ce060(local_20);
        FUN_004e9190(uVar3);
        cVar1 = const_iterator__operator__(uVar3);
        if (cVar1 == '\0') {
          uVar3 = FUN_004e9610();
          uVar3 = FUN_004d52c0(uVar3);
          uVar4 = FUN_004e8ab0(param_4,uVar3);
          cVar1 = FUN_004d6210(uVar4,uVar3);
          if (cVar1 == '\0') goto LAB_004d5fa5;
        }
        uVar3 = FUN_004e9610();
        puVar6 = (undefined4 *)FUN_004d6880(uVar3);
        pcVar5 = (char *)FUN_004e0e80(*puVar6);
        if (*pcVar5 == '\0') {
          uVar3 = FUN_004e9610(param_4);
          FUN_004e1a10(param_2,1,uVar3,param_4);
          return param_2;
        }
        uVar3 = FUN_004e9610(param_4);
        FUN_004e1a10(param_2,0,uVar3,param_4);
        return param_2;
      }
    }
    else {
      uVar3 = FUN_004e8ab0(param_4);
      puVar6 = (undefined4 *)FUN_004e1fa0(uVar3);
      uVar4 = FUN_004d52c0(*puVar6);
      cVar1 = FUN_004d6210(uVar4,uVar3);
      if (cVar1 != '\0') {
        puVar6 = (undefined4 *)FUN_004e1fa0(param_4);
        FUN_004e1a10(param_2,0,*puVar6,param_4);
        return param_2;
      }
    }
  }
  else {
    uVar3 = FUN_004e9610();
    uVar3 = FUN_004d52c0(uVar3);
    uVar4 = FUN_004e8ab0(param_4,uVar3);
    cVar1 = FUN_004d6210(uVar4,uVar3);
    if (cVar1 != '\0') {
      uVar3 = FUN_004e9610(param_4);
      FUN_004e1a10(param_2,1,uVar3,param_4);
      return param_2;
    }
  }
LAB_004d5fa5:
  puVar6 = (undefined4 *)FUN_004e0e90(local_28,param_4);
  *param_2 = *puVar6;
  return param_2;
}

