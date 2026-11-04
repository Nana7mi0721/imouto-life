
int FUN_00576dc0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_4;
  
  uVar2 = param_2;
  iVar1 = param_1;
  iVar5 = 0;
  local_4 = 0;
  iVar4 = 0;
  iVar3 = FUN_00572c90(param_1,param_2,&param_1,&local_4);
  while (iVar3 != 0) {
    iVar4 = iVar4 + param_1;
    iVar5 = iVar5 + 1;
    iVar3 = FUN_00572c90(iVar4 + iVar1,uVar2,&param_1,&local_4);
  }
  return iVar5;
}

