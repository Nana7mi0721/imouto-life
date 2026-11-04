
undefined4 FUN_005a4f90(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  if ((DAT_00a37dc8 == 0) || (DAT_00f3a04c == 0)) {
    return 0xffffffff;
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  iVar3 = FUN_005d35f0();
  if ((iVar3 != 0) && (DAT_00e79688 != 0)) {
    FUN_005d3950();
    DAT_00e79688 = 0;
  }
  if (DAT_00f3a04c != 0) {
    if (DAT_00e39a4c == 0) {
      if (DAT_00e39a54 == 0) goto LAB_005a5034;
    }
    else if ((DAT_00e39a54 == 0) && (FUN_00568ca0(0), DAT_00dda46c != 0)) {
      FUN_00584d70();
    }
    DAT_00e39a1c = 1;
    if (DAT_00e39a4c != 0) {
      DAT_00e39a18 = 1;
    }
    DAT_00e39a4c = 0;
    DAT_00e39a00 = 1;
  }
LAB_005a5034:
  if (DAT_00cc47d0 != 0) {
    uVar1 = (&DAT_00a38120)[param_1];
    if ((((-1 < (int)uVar1) && ((uVar1 & 0x7c000000) == DAT_00cc47f8)) &&
        ((int)(uVar1 & 0xffff) < DAT_00cc4800)) &&
       (((piVar2 = *(int **)(DAT_00cc47d4 + (uVar1 & 0xffff) * 4), piVar2 != (int *)0x0 &&
         (*piVar2 * 0x10000 == (uVar1 & 0x3ff0000))) &&
        ((piVar2[4] == 0 && (*(int *)(*(int *)piVar2[0x40] + 0x1c) != 0)))))) {
      FUN_00598650((int *)piVar2[0x40],(&DAT_00a38140)[param_1]);
    }
    if ((((DAT_00cc47d0 != 0) && (-1 < (int)param_2)) &&
        (((param_2 & 0x7c000000) == DAT_00cc47f8 &&
         ((((int)(param_2 & 0xffff) < DAT_00cc4800 &&
           (piVar2 = *(int **)(DAT_00cc47d4 + (param_2 & 0xffff) * 4), piVar2 != (int *)0x0)) &&
          (*piVar2 * 0x10000 == (param_2 & 0x3ff0000))))))) && (piVar2[4] == 0)) {
      if (*(char *)(piVar2[0x13] + 0xb) == '\0') {
        return 0xffffffff;
      }
      iVar3 = *(int *)(*(int *)piVar2[0x40] + 0x1c);
      if (iVar3 == 0) {
        FUN_005a0bd0(*(undefined4 *)(*(int *)piVar2[0x40] + 4 + param_3 * 4),param_1);
        return 0;
      }
      FUN_005a0bd0(iVar3,param_1);
      return 0;
    }
  }
  (&DAT_00a38120)[param_1] = 0;
  (&DAT_00a38140)[param_1] = 0;
  FUN_005a0bd0(0,param_1);
  return 0;
}

