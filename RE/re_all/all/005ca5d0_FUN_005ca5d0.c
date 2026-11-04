
undefined4 FUN_005ca5d0(int param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  int *piVar2;
  
  if ((DAT_00a37dc8 == 0) || (DAT_00f3a070 == 0)) {
    return 0xffffffff;
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  if (DAT_00f3a070 != 0) {
    if (DAT_00ef7314 == 0) {
      if (DAT_00ef7324 == 0) goto LAB_005ca65e;
    }
    else if ((DAT_00ef7324 == 0) && (FUN_00568ca0(0), DAT_00dda46c != 0)) {
      FUN_00584d70();
    }
    DAT_00ef72e8 = 1;
    if (DAT_00ef7314 != 0) {
      DAT_00ef72e4 = 1;
    }
    DAT_00ef7314 = 0;
    DAT_00ef7318 = 0;
    DAT_00ef72cc = 1;
  }
LAB_005ca65e:
  if (DAT_00cc47d0 != 0) {
    uVar1 = (&DAT_00a38120)[param_1];
    if ((((-1 < (int)uVar1) && ((uVar1 & 0x7c000000) == DAT_00cc47f8)) &&
        ((int)(uVar1 & 0xffff) < DAT_00cc4800)) &&
       (((piVar2 = *(int **)(DAT_00cc47d4 + (uVar1 & 0xffff) * 4), piVar2 != (int *)0x0 &&
         (*piVar2 * 0x10000 == (uVar1 & 0x3ff0000))) &&
        ((piVar2[4] == 0 && (**(int **)piVar2[0x40] != 0)))))) {
      FUN_005b8860((undefined4 *)piVar2[0x40],(&DAT_00a38140)[param_1],
                   *(undefined4 *)(&DAT_00ee9a58 + *(int *)(piVar2[0x13] + 4) * 4));
    }
    if ((((DAT_00cc47d0 != 0) && (-1 < (int)param_2)) &&
        (((param_2 & 0x7c000000) == DAT_00cc47f8 &&
         ((((int)(param_2 & 0xffff) < DAT_00cc4800 &&
           (piVar2 = *(int **)(DAT_00cc47d4 + (param_2 & 0xffff) * 4), piVar2 != (int *)0x0)) &&
          (*piVar2 * 0x10000 == (param_2 & 0x3ff0000))))))) && (piVar2[4] == 0)) {
      if (*(char *)(piVar2[0x13] + 0xb) == '\0') {
        return 0xffffffff;
      }
      FUN_005c2b20(*(undefined4 *)(*(int *)piVar2[0x40] + 4),
                   *(undefined4 *)
                    (*(int *)(*(int *)piVar2[0x40] + 0xc) +
                    (*(int *)(piVar2[0x13] + 0x34) * param_3 + param_4) * 4),param_1);
      if (param_1 == 0) {
        thunk_FUN_00567d80();
        return 0;
      }
      return 0;
    }
  }
  (&DAT_00a38120)[param_1] = 0;
  (&DAT_00a38140)[param_1] = 0;
  (&DAT_00a38160)[param_1] = 0;
  FUN_005c2b20(0,0,param_1);
  return 0;
}

