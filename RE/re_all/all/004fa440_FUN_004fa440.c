
undefined4 FUN_004fa440(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    uVar1 = 0xffffff9a;
  }
  else if (*(int *)(param_1 + 0x60) == 0 && *(int *)(param_1 + 100) == 0) {
    uVar1 = 0xffffff9c;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x58);
    param_2[1] = *(undefined4 *)(param_1 + 0x5c);
    param_2[2] = *(undefined4 *)(param_1 + 0x50);
    param_2[3] = *(undefined4 *)(param_1 + 0x54);
    uVar1 = 0;
  }
  return uVar1;
}

