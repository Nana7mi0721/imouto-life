
int * FUN_00519300(uint param_1,int param_2)

{
  int *piVar1;
  bool bVar2;
  
  if (param_2 == 0) {
    if (DAT_00cc47d0 == 0) {
      return (int *)0x0;
    }
    if ((int)param_1 < 0) {
      return (int *)0x0;
    }
    if ((param_1 & 0x7c000000) != DAT_00cc47f8) {
      return (int *)0x0;
    }
    if (DAT_00cc4800 <= (int)(param_1 & 0xffff)) {
      return (int *)0x0;
    }
    piVar1 = *(int **)(DAT_00cc47d4 + (param_1 & 0xffff) * 4);
    if (piVar1 == (int *)0x0) {
      return (int *)0x0;
    }
    if (*piVar1 * 0x10000 != (param_1 & 0x3ff0000)) {
      return (int *)0x0;
    }
    bVar2 = piVar1[4] == 0;
  }
  else {
    if (DAT_00cc47d0 == 0) {
      return (int *)0x0;
    }
    if ((int)param_1 < 0) {
      return (int *)0x0;
    }
    if ((param_1 & 0x7c000000) != DAT_00cc47f8) {
      return (int *)0x0;
    }
    if (DAT_00cc4800 <= (int)(param_1 & 0xffff)) {
      return (int *)0x0;
    }
    piVar1 = *(int **)(DAT_00cc47d4 + (param_1 & 0xffff) * 4);
    if (piVar1 == (int *)0x0) {
      return (int *)0x0;
    }
    bVar2 = *piVar1 * 0x10000 == (param_1 & 0x3ff0000);
  }
  if (bVar2) {
    return piVar1;
  }
  return (int *)0x0;
}

