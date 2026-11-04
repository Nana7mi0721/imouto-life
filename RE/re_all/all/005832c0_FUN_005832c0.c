
undefined4 FUN_005832c0(uint param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = (uint)(param_3 != 0);
  uVar3 = (uint)(param_4 != 0);
  if (((((DAT_00cc6e00 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc6e28)) ||
      ((DAT_00cc6e30 <= (int)(param_1 & 0xffff) ||
       (piVar2 = *(int **)(DAT_00cc6e04 + (param_1 & 0xffff) * 4), piVar2 == (int *)0x0)))) ||
     ((*piVar2 * 0x10000 != (param_1 & 0x3ff0000) || (piVar2[4] != 0)))) {
    return 0xffffffff;
  }
  if (param_2 == -1) {
    iVar1 = uVar3 + 0x76 + uVar5 * 2;
    if (piVar2[iVar1] != 0) {
      FUN_0056e1d0(piVar2[iVar1]);
      piVar2[iVar1] = 0;
      *(undefined1 *)((int)piVar2 + uVar3 + uVar5 * 2 + 0x1d4) = 0;
      return 0;
    }
  }
  else {
    if ((param_2 < 0) || (*(int *)(piVar2[0x10] + 0x7c) <= param_2)) {
      return 0xffffffff;
    }
    iVar4 = param_2 * 0x2b8 + piVar2[0x5f];
    piVar2 = (int *)(iVar4 + (uVar3 + 0x7c + uVar5 * 2) * 4);
    iVar1 = *piVar2;
    if (iVar1 != 0) {
      FUN_0056e1d0(iVar1);
      *piVar2 = 0;
      *(undefined1 *)(iVar4 + 0x1ec + uVar5 * 2 + uVar3) = 0;
    }
  }
  return 0;
}

