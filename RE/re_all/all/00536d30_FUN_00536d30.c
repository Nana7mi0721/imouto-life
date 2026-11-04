
undefined4
FUN_00536d30(int param_1,uint *param_2,uint *param_3,uint param_4,int *param_5,uint *param_6,
            int *param_7,uint *param_8)

{
  int *piVar1;
  
  if (param_4 == 0xfffffffe) {
    FUN_00530d80();
    param_4 = DAT_00a4bca8;
  }
  if ((((DAT_00cc5c60 == 0) || ((int)param_4 < 0)) || ((param_4 & 0x7c000000) != DAT_00cc5c88)) ||
     (((DAT_00cc5c90 <= (int)(param_4 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc5c64 + (param_4 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      ((*piVar1 * 0x10000 != (param_4 & 0x3ff0000) || (piVar1[4] != 0)))))) {
    return 0xffffffff;
  }
  if (param_1 != 0) {
    FUN_0056cf10(param_1,piVar1 + 0x24bd8);
  }
  if (param_3 != (uint *)0x0) {
    *param_3 = (uint)*(ushort *)(piVar1 + 0x24c58);
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = (uint)*(ushort *)((int)piVar1 + 0x93162);
  }
  if (param_5 != (int *)0x0) {
    *param_5 = piVar1[0x24c61];
  }
  if (param_6 != (uint *)0x0) {
    *param_6 = (uint)*(ushort *)(piVar1 + 0x24c5b);
  }
  if (param_7 != (int *)0x0) {
    *param_7 = piVar1[0x24c62];
  }
  if (param_8 != (uint *)0x0) {
    *param_8 = (uint)*(byte *)(piVar1 + 0x24c5a);
  }
  return 0;
}

