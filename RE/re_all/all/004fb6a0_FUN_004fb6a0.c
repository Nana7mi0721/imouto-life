
int FUN_004fb6a0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = -0x66;
  }
  else {
    *(undefined4 *)(param_1 + 0x58) = param_2;
    *(undefined4 *)(param_1 + 0x5c) = param_3;
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x38);
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x3c);
    iVar1 = FUN_004f9850(param_1,param_1 + 0x80,param_1 + 0xd8,0,0,0,0,0,0);
    *(uint *)(param_1 + 0x60) = (uint)(iVar1 == 0);
    *(undefined4 *)(param_1 + 100) = 0;
  }
  return iVar1;
}

