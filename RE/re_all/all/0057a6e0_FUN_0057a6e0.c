
int FUN_0057a6e0(undefined4 param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte local_200 [512];
  
  iVar4 = 0;
  if (param_2 == 0) {
    iVar4 = FUN_00572ff0(0x30,param_1,param_3);
  }
  else {
    if (param_2 < 0) {
      iVar4 = FUN_00572ff0(0x2d,param_1,param_3);
      param_2 = -param_2;
    }
    iVar2 = 0;
    while (param_2 != 0) {
      local_200[iVar2] = (byte)(param_2 % param_4);
      iVar2 = iVar2 + 1;
      param_2 = param_2 / param_4;
    }
    while (iVar2 = iVar2 + -1, -1 < iVar2) {
      bVar1 = local_200[iVar2];
      if (bVar1 < 10) {
        iVar3 = bVar1 + 0x30;
      }
      else {
        iVar3 = bVar1 + 0x57;
      }
      iVar3 = FUN_00572ff0(iVar3,param_1,iVar4 + param_3);
      iVar4 = iVar4 + iVar3;
    }
  }
  FUN_00572ff0(0,param_1,iVar4 + param_3);
  return param_3;
}

