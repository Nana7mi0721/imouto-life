
int FUN_00797e20(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_64;
  undefined1 local_60 [96];
  
  iVar1 = param_3;
  iVar4 = 0;
  local_64 = 0;
  if (0 < param_3) {
    iVar3 = param_2;
    do {
      if (iVar3 < 1) {
        return -4;
      }
      iVar2 = FUN_007985c0(param_1,iVar3,iVar4 != iVar1 + -1,&param_3,0,local_60,0,&param_2);
      if (iVar2 < 0) {
        return iVar2;
      }
      iVar2 = FUN_00799ab0(param_1,param_2,param_4);
      if ((iVar4 != 0) && (local_64 != iVar2)) {
        return -4;
      }
      param_1 = param_1 + param_2;
      iVar3 = iVar3 - param_2;
      iVar4 = iVar4 + 1;
      local_64 = iVar2;
    } while (iVar4 < iVar1);
  }
  return local_64;
}

