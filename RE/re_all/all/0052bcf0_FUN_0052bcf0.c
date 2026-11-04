
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0052bcf0(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x1ec) = _DAT_007d592c;
  uVar1 = _DAT_007d5928;
  *(int *)(param_1 + 0x450) = param_1 + 0x458;
  *(undefined4 *)(param_1 + 500) = uVar1;
  *(undefined4 *)(param_1 + 0x240) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1a8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x120) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x124) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1f0) = 0;
  FUN_005850a0(param_1 + 0x1ac,param_1 + 300,param_1 + 0x16c);
  FUN_0052b680(*(undefined4 *)(param_1 + 4),0,_DAT_007d5340,0);
  return 0;
}

