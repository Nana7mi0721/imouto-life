
uint FUN_0052f1d0(uint param_1)

{
  int *piVar1;
  uint uVar2;
  
  if ((((DAT_00cc5c60 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc5c88)) ||
     (((DAT_00cc5c90 <= (int)(param_1 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc5c64 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      ((*piVar1 * 0x10000 != (param_1 & 0x3ff0000) || (piVar1[4] != 0)))))) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = piVar1[0x24c5d];
    if (piVar1[0x24c5d] < 0) {
      if (*(ushort *)((int)piVar1 + 0x9316e) != 0xffff) {
        return (uint)*(ushort *)((int)piVar1 + 0x9316e);
      }
      uVar2 = DAT_00aba24c;
      if (DAT_00aba24c == 0) {
        FUN_0057a980();
        return DAT_00aba24c;
      }
    }
  }
  return uVar2;
}

