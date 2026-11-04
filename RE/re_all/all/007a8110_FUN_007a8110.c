
void FUN_007a8110(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_2;
  if (param_3 <= param_2) {
    iVar4 = param_3;
  }
  iVar3 = param_2;
  if (param_2 <= param_3) {
    iVar3 = param_3;
  }
  param_3 = param_3 + 1;
  iVar2 = param_2;
  if (param_3 <= param_2) {
    iVar2 = param_3;
  }
  if (param_3 < param_2) {
    param_3 = param_2;
  }
  uVar1 = FUN_007a8170(param_2,param_1,
                       *(int *)((&PTR_DAT_0083dc68)[iVar2] + param_3 * 4) +
                       *(int *)((&PTR_DAT_0083dc68)[iVar4] + iVar3 * 4));
  FUN_007a2540(param_4,uVar1);
  return;
}

