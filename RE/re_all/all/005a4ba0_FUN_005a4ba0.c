
int FUN_005a4ba0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                uint param_5,int param_6)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  undefined1 *local_4c [3];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  
  if (param_6 != 0) {
    local_4c[0] = &LAB_0059ce40;
    local_40 = param_1;
    local_3c = param_2;
    local_38 = param_3;
    local_34 = param_4;
    local_30 = param_5;
    iVar1 = FUN_0057ffd0(local_4c);
    return iVar1;
  }
  puVar4 = (uint *)0x0;
  iVar5 = 0;
  iVar1 = 0;
  puVar2 = (uint *)&DAT_00ec3b18;
  if (0 < DAT_00ecfb18) {
    do {
      if ((char)*puVar2 == '\0') {
        if (puVar4 == (uint *)0x0) {
          puVar4 = puVar2;
        }
      }
      else {
        iVar1 = iVar1 + 1;
        if ((((*(char *)((int)puVar2 + 2) == (char)param_1) && ((short)puVar2[1] == (short)param_2))
            && (*(short *)((int)puVar2 + 6) == (short)param_3)) &&
           ((*(char *)((int)puVar2 + 3) == (char)param_4 && (puVar2[2] == param_5)))) {
          iVar5 = iVar5 + 1;
          if (*(char *)((int)puVar2 + 1) != '\x01') {
            puVar2[3] = puVar2[3] + 1;
            *(char *)((int)puVar2 + 1) = '\x01';
            return (int)(puVar2 + -0x3b0ec6) / 0x18;
          }
          if (iVar5 == 0x10) {
            return -1;
          }
        }
      }
      puVar2 = puVar2 + 6;
    } while (iVar1 < DAT_00ecfb18);
  }
  if (DAT_00ecfb18 == 0x800) {
    uVar3 = 0xffffffff;
    puVar4 = (uint *)0x0;
    puVar2 = &DAT_00ec3b24;
    iVar1 = 0x200;
    do {
      if ((*(char *)((int)puVar2 + -0xb) == '\0') && (*puVar2 <= uVar3)) {
        puVar4 = puVar2 + -3;
        uVar3 = *puVar2;
      }
      if ((*(char *)((int)puVar2 + 0xd) == '\0') && (puVar2[6] <= uVar3)) {
        puVar4 = puVar2 + 3;
        uVar3 = puVar2[6];
      }
      if ((*(char *)((int)puVar2 + 0x25) == '\0') && (puVar2[0xc] <= uVar3)) {
        puVar4 = puVar2 + 9;
        uVar3 = puVar2[0xc];
      }
      if ((*(char *)((int)puVar2 + 0x3d) == '\0') && (puVar2[0x12] <= uVar3)) {
        puVar4 = puVar2 + 0xf;
        uVar3 = puVar2[0x12];
      }
      puVar2 = puVar2 + 0x18;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    if (puVar4 == (uint *)0x0) {
      return -1;
    }
    FUN_005d3370(puVar4[5]);
    puVar4[5] = 0;
    *(char *)puVar4 = '\0';
    puVar4[3] = 0;
    *(char *)((int)puVar4 + 1) = '\0';
    DAT_00ecfb18 = DAT_00ecfb18 + -1;
  }
  else if (puVar4 == (uint *)0x0) {
    puVar4 = puVar2;
  }
  *(char *)((int)puVar4 + 2) = (char)param_1;
  *(char *)((int)puVar4 + 3) = (char)param_4;
  *(short *)(puVar4 + 1) = (short)param_2;
  *(short *)((int)puVar4 + 6) = (short)param_3;
  puVar4[2] = param_5;
  puVar4[3] = 1;
  iVar1 = FUN_0059ce90(puVar4);
  if (iVar1 < 0) {
    FUN_0059d240(1);
    iVar1 = FUN_0059ce90(puVar4);
    if (iVar1 < 0) {
      return -1;
    }
  }
  *(char *)puVar4 = '\x01';
  *(char *)((int)puVar4 + 1) = '\x01';
  DAT_00ecfb18 = DAT_00ecfb18 + 1;
  return (int)(puVar4 + -0x3b0ec6) / 0x18;
}

