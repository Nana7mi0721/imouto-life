
undefined4 FUN_005526a0(uint param_1,uint *param_2,uint *param_3,int *param_4,uint *param_5)

{
  int *piVar1;
  
  if (((((DAT_00cc50a0 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc50c8)) ||
      ((DAT_00cc50d0 <= (int)(param_1 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc50a4 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0)))) ||
     ((*piVar1 * 0x10000 != (param_1 & 0x3ff0000) || ((piVar1[4] != 0 || (piVar1[0xc] == 1)))))) {
    return 0xffffffff;
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = (uint)*(ushort *)((int)piVar1 + 0x36);
  }
  if (param_3 != (uint *)0x0) {
    *param_3 = (uint)*(ushort *)((int)piVar1 + 0x42);
  }
  if (param_4 != (int *)0x0) {
    *param_4 = piVar1[0xe];
  }
  if (param_5 != (uint *)0x0) {
    *param_5 = (uint)((short)piVar1[0xd] == 3);
  }
  return 0;
}

