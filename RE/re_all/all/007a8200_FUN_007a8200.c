
void FUN_007a8200(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = param_2;
  if (param_3 <= param_2) {
    iVar5 = param_3;
  }
  iVar4 = param_2;
  if (param_2 <= param_3) {
    iVar4 = param_3;
  }
  iVar1 = param_3 + 1;
  iVar3 = param_2;
  if (iVar1 <= param_2) {
    iVar3 = iVar1;
  }
  if (iVar1 < param_2) {
    iVar1 = param_2;
  }
  uVar2 = FUN_007a21c0(param_4,*(int *)((&PTR_DAT_0083dc68)[iVar3] + iVar1 * 4) +
                               *(int *)((&PTR_DAT_0083dc68)[iVar5] + iVar4 * 4),param_1);
  FUN_007a8270(param_2,param_3,uVar2);
  return;
}

