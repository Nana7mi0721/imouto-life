
undefined4 FUN_0064e540(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_006534a0();
  FUN_006534b0(param_1,uVar1);
  FUN_00650810(param_1 + 0x28,0,0xc0);
  *(undefined2 *)(param_1 + 0x5e) = 1;
  *(undefined2 *)(param_1 + 0x54) = 1;
  *(undefined2 *)(param_1 + 0x5c) = 1;
  *(undefined2 *)(param_1 + 0x60) = 1;
  *(undefined2 *)(param_1 + 0x62) = 1;
  *(undefined4 *)(param_1 + 100) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 1;
  *(undefined4 *)(param_1 + 0xb4) = 1;
  *(undefined2 *)(param_1 + 0x7c) = 2;
  *(undefined2 *)(param_1 + 0x56) = 1;
  *(undefined4 *)(param_1 + 0x40) = 1;
  *(undefined2 *)(param_1 + 0xc0) = 2;
  *(undefined2 *)(param_1 + 0xc2) = 2;
  *(undefined2 *)(param_1 + 0xc4) = 1;
  *(code **)(param_1 + 0x28c) = FUN_0065f670;
  *(undefined4 *)(param_1 + 0x298) = 0;
  *(undefined1 **)(param_1 + 0x29c) = &LAB_0064e620;
  *(code **)(param_1 + 0x2a0) = FUN_0064f730;
  *(undefined4 *)(param_1 + 0x2a4) = 0;
  if (DAT_00f3fa4c != (code *)0x0) {
    (*DAT_00f3fa4c)(param_1);
  }
  FUN_0064e1d0(param_1,0x103,1);
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffbf7;
  return 1;
}

