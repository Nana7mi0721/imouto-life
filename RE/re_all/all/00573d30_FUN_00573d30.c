
void FUN_00573d30(int *param_1,uint *param_2,int *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_2;
  if (uVar1 < 0x110000) {
    if (uVar1 < 0x10000) {
      if (3 < (uint)(param_4 - *param_3)) {
        if ((undefined1 *)*param_1 != (undefined1 *)0x0) {
          *(undefined1 *)*param_1 = (char)*param_2;
          *(char *)(*param_1 + 1) = (char)(*param_2 >> 8);
          *param_1 = *param_1 + 2;
        }
        *param_3 = *param_3 + 2;
        return;
      }
    }
    else if (5 < (uint)(param_4 - *param_3)) {
      if ((undefined1 *)*param_1 != (undefined1 *)0x0) {
        uVar2 = uVar1 - 0x10000 & 0xffc00 | 0x3600000;
        *(undefined1 *)*param_1 = (char)(uVar2 >> 10);
        *(char *)(*param_1 + 1) = (char)(uVar2 >> 0x12);
        *(char *)(*param_1 + 2) = (char)(uVar1 & 0x3ff);
        *(byte *)(*param_1 + 3) = (byte)((uVar1 & 0x3ff) >> 8) | 0xdc;
        *param_1 = *param_1 + 4;
      }
      *param_3 = *param_3 + 4;
    }
  }
  return;
}

