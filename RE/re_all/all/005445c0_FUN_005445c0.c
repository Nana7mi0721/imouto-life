
undefined4 FUN_005445c0(undefined1 *param_1)

{
  undefined1 uVar1;
  int iVar2;
  
  param_1[5] = 8;
  param_1[8] = 8;
  param_1[0xd] = 8;
  param_1[9] = 8;
  param_1[10] = 8;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 1;
  *(undefined4 *)(param_1 + 0x24) = 0xff;
  *(undefined4 *)(param_1 + 0x20) = 0xff000000;
  param_1[0xf] = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0x10;
  *(undefined4 *)(param_1 + 0x10) = 0xff0000;
  *(undefined4 *)(param_1 + 0x14) = 0xff00;
  param_1[0xe] = 0;
  *(undefined4 *)(param_1 + 0x18) = 0xff;
  iVar2 = 0;
  param_1 = param_1 + 0x29;
  do {
    uVar1 = (undefined1)iVar2;
    param_1[1] = uVar1;
    *param_1 = uVar1;
    param_1[-1] = uVar1;
    param_1[2] = 0;
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 4;
  } while (iVar2 < 0x100);
  return 0;
}

