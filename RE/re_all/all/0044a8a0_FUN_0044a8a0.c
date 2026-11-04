
undefined4 __thiscall FUN_0044a8a0(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int local_c;
  int local_8;
  
  if (((*(char *)(param_1 + 0x1894) == '\0') &&
      (((int)param_2 < 0 || (iVar1 = FUN_0047a490(), iVar1 * 2 <= (int)param_2)))) ||
     ((*(char *)(param_1 + 0x1895) == '\0' &&
      (((int)param_3 < 0 || (iVar1 = FUN_0047a4b0(), iVar1 * 2 <= (int)param_3)))))) {
    return 0;
  }
  local_8 = 2;
  while( true ) {
    if (local_8 < 0) {
      return 1;
    }
    local_c = FUN_0047a4d0(param_2,param_3,local_8);
    while ((local_c == 0 && (0 < local_8))) {
      local_8 = local_8 + -1;
      local_c = FUN_0047a4d0(param_2,param_3,local_8);
    }
    if (local_c == -1) break;
    puVar2 = (uint *)FUN_004ce990(local_c);
    if ((*puVar2 & 0xf) == 0xf) {
      return 0;
    }
    puVar2 = (uint *)FUN_004ce990(local_c);
    if ((*puVar2 & 0x200) == 0) {
      puVar2 = (uint *)FUN_004ce990(local_c);
      if ((*puVar2 & 0x20) != 0) {
        uVar3 = param_2 & 0x80000001;
        if ((int)uVar3 < 0) {
          uVar3 = (uVar3 - 1 | 0xfffffffe) + 1;
        }
        if (uVar3 == 0) {
          uVar3 = param_3 & 0x80000001;
          if ((int)uVar3 < 0) {
            uVar3 = (uVar3 - 1 | 0xfffffffe) + 1;
          }
          if ((uVar3 == 1) && (puVar2 = (uint *)FUN_004ce990(local_c), (*puVar2 & 2) != 0)) {
            return 0;
          }
        }
        uVar3 = param_2 & 0x80000001;
        if ((int)uVar3 < 0) {
          uVar3 = (uVar3 - 1 | 0xfffffffe) + 1;
        }
        if (uVar3 == 1) {
          uVar3 = param_3 & 0x80000001;
          if ((int)uVar3 < 0) {
            uVar3 = (uVar3 - 1 | 0xfffffffe) + 1;
          }
          if ((uVar3 == 0) && (puVar2 = (uint *)FUN_004ce990(local_c), (*puVar2 & 4) != 0)) {
            return 0;
          }
        }
        uVar3 = param_2 & 0x80000001;
        if ((int)uVar3 < 0) {
          uVar3 = (uVar3 - 1 | 0xfffffffe) + 1;
        }
        if (uVar3 == 0) {
          uVar3 = param_3 & 0x80000001;
          if ((int)uVar3 < 0) {
            uVar3 = (uVar3 - 1 | 0xfffffffe) + 1;
          }
          if ((uVar3 == 0) && (puVar2 = (uint *)FUN_004ce990(local_c), (*puVar2 & 8) != 0)) {
            return 0;
          }
        }
        param_2 = param_2 & 0x80000001;
        if ((int)param_2 < 0) {
          param_2 = (param_2 - 1 | 0xfffffffe) + 1;
        }
        if (param_2 == 1) {
          param_3 = param_3 & 0x80000001;
          if ((int)param_3 < 0) {
            param_3 = (param_3 - 1 | 0xfffffffe) + 1;
          }
          if ((param_3 == 1) && (puVar2 = (uint *)FUN_004ce990(local_c), (*puVar2 & 1) != 0)) {
            return 0;
          }
        }
        return 1;
      }
      puVar2 = (uint *)FUN_004ce990(local_c);
      if ((*puVar2 & 0x10) == 0) {
        return 1;
      }
    }
    local_8 = local_8 + -1;
  }
  return 0;
}

