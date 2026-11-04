
undefined4 FUN_0066bbc0(int param_1,int param_2,undefined4 *param_3,uint *param_4,int *param_5)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((param_1 != 0) && (param_2 != 0)) && ((*(byte *)(param_2 + 8) & 0x10) != 0)) {
    if (*(char *)(param_2 + 0x19) == '\x03') {
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = *(undefined4 *)(param_2 + 0x9c);
        uVar1 = 0x10;
      }
      if (param_5 != (int *)0x0) {
        *param_5 = param_2 + 0xa0;
      }
    }
    else {
      if (param_5 != (int *)0x0) {
        *param_5 = param_2 + 0xa0;
        uVar1 = 0x10;
      }
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = 0;
      }
    }
    if (param_4 != (uint *)0x0) {
      uVar1 = 0x10;
      *param_4 = (uint)*(ushort *)(param_2 + 0x16);
    }
  }
  return uVar1;
}

