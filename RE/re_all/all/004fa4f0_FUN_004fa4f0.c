
int FUN_004fa4f0(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    iVar1 = -0x66;
  }
  else {
    *(undefined4 *)(param_1 + 0x58) = *param_2;
    *(undefined4 *)(param_1 + 0x5c) = param_2[1];
    *(undefined4 *)(param_1 + 0x50) = param_2[2];
    *(undefined4 *)(param_1 + 0x54) = param_2[3];
    iVar1 = FUN_004f9850(param_1,param_1 + 0x80,param_1 + 0xd8,0,0,0,0,0,0);
    *(uint *)(param_1 + 0x60) = (uint)(iVar1 == 0);
    *(undefined4 *)(param_1 + 100) = 0;
  }
  return iVar1;
}

