
/* WARNING: Removing unreachable block (ram,0x004de1a6) */
/* WARNING: Removing unreachable block (ram,0x004de218) */
/* WARNING: Removing unreachable block (ram,0x004de28e) */
/* WARNING: Removing unreachable block (ram,0x004de2c0) */
/* WARNING: Removing unreachable block (ram,0x004de2fb) */
/* WARNING: Removing unreachable block (ram,0x004de341) */
/* WARNING: Removing unreachable block (ram,0x004de31e) */
/* WARNING: Removing unreachable block (ram,0x004de364) */
/* WARNING: Removing unreachable block (ram,0x004de396) */
/* WARNING: Removing unreachable block (ram,0x004de3bf) */
/* WARNING: Removing unreachable block (ram,0x004de3ed) */
/* WARNING: Removing unreachable block (ram,0x004de433) */
/* WARNING: Removing unreachable block (ram,0x004de410) */
/* WARNING: Removing unreachable block (ram,0x004de234) */
/* WARNING: Removing unreachable block (ram,0x004de264) */
/* WARNING: Removing unreachable block (ram,0x004de289) */
/* WARNING: Removing unreachable block (ram,0x004de1c2) */
/* WARNING: Removing unreachable block (ram,0x004de1f0) */
/* WARNING: Removing unreachable block (ram,0x004de213) */
/* WARNING: Removing unreachable block (ram,0x004de456) */

undefined4 * __thiscall
FUN_004de160(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

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
    FUN_004e85d0(param_2,1,*(undefined4 *)(param_1 + 4),param_4);
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
      cVar1 = FUN_004d59a0(uVar4,uVar3);
      if (cVar1 != '\0') {
        local_8 = param_3;
        uVar3 = FUN_004e8ab0(param_4);
        FUN_004e9580(uVar3);
        uVar4 = FUN_004e9610();
        uVar4 = FUN_004d52c0(uVar4);
        cVar1 = FUN_004d59a0(uVar4,uVar3);
        if (cVar1 != '\0') {
          uVar3 = FUN_004e9610();
          puVar6 = (undefined4 *)FUN_004d6880(uVar3);
          pcVar5 = (char *)FUN_004d6860(*puVar6);
          if (*pcVar5 == '\0') {
            uVar3 = FUN_004e9610(param_4);
            FUN_004e85d0(param_2,1,uVar3,param_4);
            return param_2;
          }
          uVar3 = FUN_004e9610(param_4);
          FUN_004e85d0(param_2,0,uVar3,param_4);
          return param_2;
        }
      }
      uVar3 = FUN_004e8ab0(param_4);
      uVar4 = FUN_004e9610(uVar3);
      uVar4 = FUN_004d52c0(uVar4);
      cVar1 = FUN_004d59a0(uVar4,uVar3);
      if (cVar1 != '\0') {
        local_8 = param_3;
        uVar3 = FUN_004ce060(local_20);
        FUN_004e9530(uVar3);
        cVar1 = const_iterator__operator__(uVar3);
        if (cVar1 == '\0') {
          uVar3 = FUN_004e9610();
          uVar3 = FUN_004d52c0(uVar3);
          uVar4 = FUN_004e8ab0(param_4,uVar3);
          cVar1 = FUN_004d59a0(uVar4,uVar3);
          if (cVar1 == '\0') goto LAB_004de705;
        }
        uVar3 = FUN_004e9610();
        puVar6 = (undefined4 *)FUN_004d6880(uVar3);
        pcVar5 = (char *)FUN_004d6860(*puVar6);
        if (*pcVar5 == '\0') {
          uVar3 = FUN_004e9610(param_4);
          FUN_004e85d0(param_2,1,uVar3,param_4);
          return param_2;
        }
        uVar3 = FUN_004e9610(param_4);
        FUN_004e85d0(param_2,0,uVar3,param_4);
        return param_2;
      }
    }
    else {
      uVar3 = FUN_004e8ab0(param_4);
      puVar6 = (undefined4 *)FUN_004e1fa0(uVar3);
      uVar4 = FUN_004d52c0(*puVar6);
      cVar1 = FUN_004d59a0(uVar4,uVar3);
      if (cVar1 != '\0') {
        puVar6 = (undefined4 *)FUN_004e1fa0(param_4);
        FUN_004e85d0(param_2,0,*puVar6,param_4);
        return param_2;
      }
    }
  }
  else {
    uVar3 = FUN_004e9610();
    uVar3 = FUN_004d52c0(uVar3);
    uVar4 = FUN_004e8ab0(param_4,uVar3);
    cVar1 = FUN_004d59a0(uVar4,uVar3);
    if (cVar1 != '\0') {
      uVar3 = FUN_004e9610(param_4);
      FUN_004e85d0(param_2,1,uVar3,param_4);
      return param_2;
    }
  }
LAB_004de705:
  puVar6 = (undefined4 *)FUN_004e7b20(local_28,param_4);
  *param_2 = *puVar6;
  return param_2;
}

