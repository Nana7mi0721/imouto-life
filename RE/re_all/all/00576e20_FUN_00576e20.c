
int FUN_00576e20(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_4;
  
  iVar1 = param_3;
  iVar4 = 0;
  iVar3 = 0;
  local_4 = 0;
  if (param_3 != 0) {
    do {
      iVar2 = FUN_00572c90(iVar3 + param_1,param_2,&param_3,&local_4);
      if (iVar2 == 0) {
        return 0;
      }
      iVar3 = iVar3 + param_3;
      iVar4 = iVar4 + 1;
    } while (iVar4 != iVar1);
  }
  return iVar3 + param_1;
}

