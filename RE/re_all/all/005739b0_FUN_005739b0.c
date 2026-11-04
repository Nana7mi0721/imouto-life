
int FUN_005739b0(int param_1,undefined4 param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 local_4;
  
  uVar1 = param_2;
  iVar4 = param_1;
  iVar5 = 0;
  local_4 = 0;
  iVar2 = FUN_00572c90(param_1,param_2,&param_1,&local_4);
  iVar4 = iVar4 + param_1;
  piVar3 = param_3;
  while (iVar2 != 0) {
    if (piVar3 != (int *)0x0) {
      *piVar3 = iVar2;
      piVar3 = piVar3 + 1;
    }
    iVar5 = iVar5 + 4;
    iVar2 = FUN_00572c90(iVar4,uVar1,&param_1,&local_4);
    iVar4 = iVar4 + param_1;
  }
  if (piVar3 != (int *)0x0) {
    *piVar3 = 0;
  }
  return iVar5 + 4;
}

