
undefined4 FUN_005831d0(uint param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (((((DAT_00cc6e00 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc6e28)) ||
      ((DAT_00cc6e30 <= (int)(param_1 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc6e04 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0)))) ||
     ((*piVar1 * 0x10000 != (param_1 & 0x3ff0000) || (piVar1[4] != 0)))) {
    return 0xffffffff;
  }
  if (param_2 == -1) {
    iVar4 = piVar1[0x7b];
    piVar1[0x7b] = 0;
  }
  else {
    if ((param_2 < 0) || (*(int *)(piVar1[0x10] + 0x7c) <= param_2)) {
      return 0xffffffff;
    }
    iVar3 = param_2 * 0x2b8 + piVar1[0x5f];
    iVar4 = *(int *)(iVar3 + 0x204);
    *(undefined4 *)(iVar3 + 0x204) = 0;
  }
  if (iVar4 != 0) {
    iVar3 = *(int *)(*(int *)(iVar4 + 0x4c) + 0xc);
    while (iVar3 != 0) {
      iVar2 = *(int *)(iVar3 + 0xc);
      FUN_0056e1d0(iVar3);
      iVar3 = iVar2;
    }
    FUN_0056e1d0(iVar4);
  }
  return 0;
}

