
undefined4 FUN_00516df0(uint param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  if (((((int)param_1 < 0) || ((param_1 & 0x7c000000) != 0x2c000000)) ||
      (uVar3 = param_1 & 0xffff, 0xfff < uVar3)) ||
     ((piVar1 = (int *)(&DAT_00a38e44)[uVar3], piVar1 == (int *)0x0 ||
      (*piVar1 * 0x10000 != (param_1 & 0x3ff0000))))) {
    return 0xffffffff;
  }
  DAT_00a3ce44 = DAT_00a3ce44 + -1;
  if (uVar3 == DAT_00a3ce48 - 1U) {
    if (DAT_00a3ce44 == 0) {
      DAT_00a3ce48 = 0;
    }
    else {
      iVar2 = (&DAT_00a38e40)[DAT_00a3ce48];
      while (iVar2 == 0) {
        DAT_00a3ce48 = DAT_00a3ce48 + -1;
        iVar2 = (&DAT_00a38e40)[DAT_00a3ce48];
      }
    }
  }
  FUN_0056e1d0(piVar1);
  (&DAT_00a38e44)[uVar3] = 0;
  DAT_00a3d258 = 1;
  DAT_00a3d360 = 1;
  return 0;
}

