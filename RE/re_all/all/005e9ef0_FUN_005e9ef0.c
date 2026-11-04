
undefined4 FUN_005e9ef0(uint param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int local_10;
  int local_c;
  int local_8;
  
  if (((((DAT_00cc6b10 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc6b38)) ||
      ((DAT_00cc6b40 <= (int)(param_1 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc6b14 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0)))) ||
     ((*piVar1 * 0x10000 != (param_1 & 0x3ff0000) || (piVar1[4] != 0)))) {
    return 0xffffffff;
  }
  if (piVar1[0x78] == 0) {
    return 0;
  }
  piVar5 = piVar1 + 0xaf;
  local_8 = 3;
  do {
    local_c = 2;
    do {
      local_10 = 9;
      do {
        iVar4 = *piVar5;
        while (iVar4 != 0) {
          if (**(int **)(iVar4 + 0x14) != 0) {
            FUN_005d4d00(**(int **)(iVar4 + 0x14),0);
          }
          iVar2 = *(int *)(*(int *)(iVar4 + 0x14) + 4);
          if (iVar2 != 0) {
            FUN_005d4d00(iVar2,0);
          }
          iVar2 = *(int *)(iVar4 + 0x18);
          FUN_0056e1d0(iVar4);
          iVar4 = iVar2;
        }
        *piVar5 = 0;
        piVar5[0x36] = 0;
        piVar5[-0x36] = 0;
        piVar5 = piVar5 + 1;
        local_10 = local_10 + -1;
      } while (local_10 != 0);
      local_c = local_c + -1;
    } while (local_c != 0);
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  iVar4 = 0;
  piVar1[0x77] = 0;
  if (0 < piVar1[0x49]) {
    puVar3 = (undefined4 *)(piVar1[0x4a] + 0x128);
    do {
      puVar3[-1] = 0;
      *puVar3 = 0;
      puVar3[1] = 0;
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 0x4e;
    } while (iVar4 < piVar1[0x49]);
  }
  piVar1[0x78] = 0;
  if ((DAT_00cc6e00 != 0) && (iVar4 = DAT_00cc6e38, DAT_00cc6e38 <= DAT_00cc6e3c)) {
    do {
      iVar2 = *(int *)(DAT_00cc6e04 + iVar4 * 4);
      if ((iVar2 != 0) && ((*(int *)(iVar2 + 0x10) == 0 && (*(int **)(iVar2 + 0x40) == piVar1)))) {
        FUN_005db6d0(*(undefined4 *)(iVar2 + 4));
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 <= DAT_00cc6e3c);
  }
  return 0;
}

