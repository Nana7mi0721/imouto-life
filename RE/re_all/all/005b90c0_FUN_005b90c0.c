
undefined4 FUN_005b90c0(int param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if (-1 < param_2) {
    if (param_2 < 0x10) {
      DAT_00f07678 = 0xffffffff;
      if (((&DAT_00f076c4)[param_2 * 0xd] != param_1) || (DAT_00ef7324 != 0)) {
        FUN_00568ca0(0);
        if (DAT_00dda46c != 0) {
          FUN_00584d70();
        }
        (&DAT_00f07684)[param_2] = 1;
        DAT_00f07680 = 1;
        (&DAT_00f076c4)[param_2 * 0xd] = param_1;
        DAT_00ef72cc = 1;
      }
    }
    return 0;
  }
  if (((param_1 == 0x15) || (param_1 == 0)) || (param_1 == 0x55)) {
    DAT_00f07678 = 0xffffffff;
  }
  if (DAT_00ef7324 == 0) {
    piVar1 = &DAT_00f076c4;
    iVar3 = 0;
    do {
      if (*piVar1 != param_1) break;
      if (piVar1[0xd] != param_1) {
        iVar3 = iVar3 + 1;
        break;
      }
      if (piVar1[0x1a] != param_1) {
        iVar3 = iVar3 + 2;
        break;
      }
      if (piVar1[0x27] != param_1) {
        iVar3 = iVar3 + 3;
        break;
      }
      iVar3 = iVar3 + 4;
      piVar1 = piVar1 + 0x34;
    } while (iVar3 < 0x10);
    if (iVar3 == 0x10) {
      return 0;
    }
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  puVar2 = &DAT_00f07684;
  piVar1 = &DAT_00f076c4;
  do {
    if ((*piVar1 != param_1) || (DAT_00ef7324 != 0)) {
      *puVar2 = 1;
      DAT_00f07680 = 1;
      *piVar1 = param_1;
    }
    puVar2 = puVar2 + 1;
    piVar1 = piVar1 + 0xd;
  } while ((int)puVar2 < 0xf076c4);
  DAT_00ef72cc = 1;
  return 0;
}

