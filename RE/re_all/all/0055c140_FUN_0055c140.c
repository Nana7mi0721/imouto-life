
undefined4 FUN_0055c140(uint param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint local_8;
  undefined4 local_4;
  
  iVar3 = FUN_0057e0e0();
  if (iVar3 == 0) {
    return 0xffffffff;
  }
  if (param_3 == 0) {
    if (DAT_00cc4db0 == 0) {
      return 0xffffffff;
    }
    if ((int)param_1 < 0) {
      return 0xffffffff;
    }
    if ((param_1 & 0x7c000000) != DAT_00cc4dd8) {
      return 0xffffffff;
    }
    if (DAT_00cc4de0 <= (int)(param_1 & 0xffff)) {
      return 0xffffffff;
    }
    piVar4 = *(int **)(DAT_00cc4db4 + (param_1 & 0xffff) * 4);
    if (piVar4 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar4 * 0x10000 != (param_1 & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (piVar4[4] != 0) {
      return 0xffffffff;
    }
  }
  else if ((((DAT_00cc4db0 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc4dd8))
          || (((DAT_00cc4de0 <= (int)(param_1 & 0xffff) ||
               (piVar4 = *(int **)(DAT_00cc4db4 + (param_1 & 0xffff) * 4), piVar4 == (int *)0x0)) ||
              (*piVar4 * 0x10000 != (param_1 & 0x3ff0000))))) {
    return 0xffffffff;
  }
  if (piVar4[0x482] != 1) {
    return 0;
  }
  iVar3 = FUN_0055fa80(param_1,piVar4,&local_4,0);
  if (iVar3 == -1) {
    return 0;
  }
  if ((char)piVar4[0x935] == '\0') {
    return 0;
  }
  if (param_2 == 0xffffffff) {
    FUN_00551ca0(local_4,&local_8,0);
  }
  else {
    local_8 = param_2;
  }
  uVar1 = piVar4[0x934];
  if (uVar1 == local_8) {
    return 0;
  }
  if (*(char *)((int)piVar4 + 0x24d6) == '\x01') {
    uVar2 = piVar4[0x939];
    if (uVar1 < local_8) {
      if (uVar2 <= uVar1) goto LAB_0055c2c5;
    }
    else if (uVar1 < uVar2) {
      iVar3 = piVar4[0x936];
      piVar4[0x933] = (piVar4[0x489] - uVar2) + local_8;
      *(undefined1 *)((int)piVar4 + 0x24d6) = 0;
      goto LAB_0055c2ec;
    }
    if (uVar2 <= local_8) {
      iVar3 = piVar4[0x936];
      piVar4[0x933] = local_8 - uVar2;
      *(undefined1 *)((int)piVar4 + 0x24d6) = 0;
      goto LAB_0055c2ec;
    }
  }
LAB_0055c2c5:
  if (uVar1 < local_8) {
    piVar4[0x933] = piVar4[0x933] + (local_8 - uVar1);
    piVar4[0x934] = local_8;
    return 0;
  }
  iVar3 = (piVar4[0x489] - uVar1) + local_8;
LAB_0055c2ec:
  piVar4[0x933] = piVar4[0x933] + iVar3;
  piVar4[0x934] = local_8;
  return 0;
}

