
int FUN_005a4db0(undefined4 param_1,undefined4 param_2,uint param_3,int param_4)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  undefined1 *local_4c [3];
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  
  if (param_4 != 0) {
    local_4c[0] = &LAB_0059ce70;
    local_40 = param_1;
    local_3c = param_2;
    local_38 = param_3;
    iVar1 = FUN_0057ffd0(local_4c);
    return iVar1;
  }
  puVar5 = (uint *)0x0;
  iVar4 = 0;
  iVar1 = 0;
  puVar2 = (uint *)&DAT_00ecfb1c;
  if (0 < DAT_00edbb1c) {
    do {
      if ((char)*puVar2 == '\0') {
        if (puVar5 == (uint *)0x0) {
          puVar5 = puVar2;
        }
      }
      else {
        iVar1 = iVar1 + 1;
        if (((*(short *)((int)puVar2 + 2) == (short)param_1) && ((short)puVar2[1] == (short)param_2)
            ) && (puVar2[2] == param_3)) {
          iVar4 = iVar4 + 1;
          if (*(char *)((int)puVar2 + 1) != '\x01') {
            puVar2[3] = puVar2[3] + 1;
            *(char *)((int)puVar2 + 1) = '\x01';
            return (int)(puVar2 + -0x3b3ec7) / 0x18;
          }
          if (iVar4 == 0x10) {
            return -1;
          }
        }
      }
      puVar2 = puVar2 + 6;
    } while (iVar1 < DAT_00edbb1c);
  }
  if (DAT_00edbb1c == 0x800) {
    uVar3 = 0xffffffff;
    puVar5 = (uint *)0x0;
    puVar2 = &DAT_00ecfb28;
    iVar1 = 0x200;
    do {
      if ((*(char *)((int)puVar2 + -0xb) == '\0') && (*puVar2 <= uVar3)) {
        puVar5 = puVar2 + -3;
        uVar3 = *puVar2;
      }
      if ((*(char *)((int)puVar2 + 0xd) == '\0') && (puVar2[6] <= uVar3)) {
        puVar5 = puVar2 + 3;
        uVar3 = puVar2[6];
      }
      if ((*(char *)((int)puVar2 + 0x25) == '\0') && (puVar2[0xc] <= uVar3)) {
        puVar5 = puVar2 + 9;
        uVar3 = puVar2[0xc];
      }
      if ((*(char *)((int)puVar2 + 0x3d) == '\0') && (puVar2[0x12] <= uVar3)) {
        puVar5 = puVar2 + 0xf;
        uVar3 = puVar2[0x12];
      }
      puVar2 = puVar2 + 0x18;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    if (puVar5 == (uint *)0x0) {
      return -1;
    }
    FUN_005d3370(puVar5[5]);
    puVar5[5] = 0;
    *(char *)puVar5 = '\0';
    puVar5[3] = 0;
    *(char *)((int)puVar5 + 1) = '\0';
    DAT_00edbb1c = DAT_00edbb1c + -1;
  }
  else if (puVar5 == (uint *)0x0) {
    puVar5 = puVar2;
  }
  *(short *)((int)puVar5 + 2) = (short)param_1;
  *(short *)(puVar5 + 1) = (short)param_2;
  puVar5[2] = param_3;
  puVar5[3] = 1;
  iVar1 = FUN_0059d030(puVar5);
  if (iVar1 < 0) {
    FUN_0059d2a0(1);
    iVar1 = FUN_0059d030(puVar5);
    if (iVar1 < 0) {
      return -1;
    }
  }
  *(char *)puVar5 = '\x01';
  *(char *)((int)puVar5 + 1) = '\x01';
  DAT_00edbb1c = DAT_00edbb1c + 1;
  return (int)(puVar5 + -0x3b3ec7) / 0x18;
}

