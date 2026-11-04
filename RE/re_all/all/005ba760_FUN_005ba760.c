
undefined4 FUN_005ba760(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if (-1 < param_2) {
    if (0xf < param_2) {
      return 0xffffffff;
    }
    if ((((param_1 != (&DAT_00f076c8)[param_2 * 0xd]) || (param_1 != (&DAT_00f076cc)[param_2 * 0xd])
         ) || (param_1 != (&DAT_00f076d0)[param_2 * 0xd])) || (DAT_00ef7324 != 0)) {
      FUN_00568ca0(0);
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
      (&DAT_00f07684)[param_2] = 1;
      DAT_00f07680 = 1;
      (&DAT_00f076c8)[param_2 * 0xd] = param_1;
      (&DAT_00f076cc)[param_2 * 0xd] = param_1;
      (&DAT_00f076d0)[param_2 * 0xd] = param_1;
      DAT_00ef72cc = 1;
    }
    return 0;
  }
  if (DAT_00ef7324 == 0) {
    iVar5 = 0;
    piVar4 = &DAT_00f076d0;
    piVar2 = &DAT_00f076cc;
    piVar1 = &DAT_00f076c8;
    do {
      if (((param_1 != *piVar1) || (param_1 != *piVar2)) || (param_1 != *piVar4)) break;
      if (((param_1 != piVar1[0xd]) || (param_1 != piVar2[0xd])) || (param_1 != piVar4[0xd])) {
        iVar5 = iVar5 + 1;
        break;
      }
      if (((param_1 != piVar1[0x1a]) || (param_1 != piVar2[0x1a])) || (param_1 != piVar4[0x1a])) {
        iVar5 = iVar5 + 2;
        break;
      }
      if (((param_1 != piVar1[0x27]) || (param_1 != piVar2[0x27])) || (param_1 != piVar4[0x27])) {
        iVar5 = iVar5 + 3;
        break;
      }
      iVar5 = iVar5 + 4;
      piVar1 = piVar1 + 0x34;
      piVar2 = piVar2 + 0x34;
      piVar4 = piVar4 + 0x34;
    } while (iVar5 < 0x10);
    if (iVar5 == 0x10) {
      return 0;
    }
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  piVar1 = &DAT_00f076cc;
  puVar3 = &DAT_00f07684;
  do {
    if (((param_1 != piVar1[-1]) || (param_1 != *piVar1)) ||
       ((param_1 != piVar1[1] || (DAT_00ef7324 != 0)))) {
      *puVar3 = 1;
      DAT_00f07680 = 1;
      piVar1[-1] = param_1;
      *piVar1 = param_1;
      piVar1[1] = param_1;
    }
    puVar3 = puVar3 + 1;
    piVar1 = piVar1 + 0xd;
  } while ((int)puVar3 < 0xf076c4);
  DAT_00ef72cc = 1;
  return 0;
}

