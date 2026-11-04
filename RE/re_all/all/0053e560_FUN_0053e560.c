
undefined4 FUN_0053e560(short *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = FUN_0052eda0(param_3);
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  iVar4 = 0;
  sVar1 = *param_1;
  while (sVar1 != 0) {
    iVar4 = iVar4 + 1;
    sVar1 = param_1[iVar4];
  }
  if ((param_2 < 0) || (iVar4 < param_2)) {
    param_2 = iVar4;
  }
  uVar3 = FUN_00537710(0,0,0,0,0,1,0,0x3ff0000000000000,0x3ff0000000000000,0,0,0,0,param_1,0,0,0,0,
                       iVar2,0,param_2,param_4,0,0,0,0,0,0);
  return uVar3;
}

