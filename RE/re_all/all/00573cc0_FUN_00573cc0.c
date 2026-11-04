
void FUN_00573cc0(int *param_1,uint *param_2,int *param_3,int param_4)

{
  ushort uVar1;
  
  if (*param_2 < 0x10000) {
    uVar1 = *(ushort *)(&DAT_00b439c4 + *param_2 * 2);
    if (uVar1 < 0x100) {
      if (1 < (uint)(param_4 - *param_3)) {
        if ((undefined1 *)*param_1 != (undefined1 *)0x0) {
          *(undefined1 *)*param_1 = (char)uVar1;
          *param_1 = *param_1 + 1;
        }
        *param_3 = *param_3 + 1;
        return;
      }
    }
    else if (2 < (uint)(param_4 - *param_3)) {
      if ((undefined1 *)*param_1 != (undefined1 *)0x0) {
        *(undefined1 *)*param_1 = (char)(uVar1 >> 8);
        *(char *)(*param_1 + 1) = (char)uVar1;
        *param_1 = *param_1 + 2;
      }
      *param_3 = *param_3 + 2;
    }
  }
  return;
}

