
undefined4 FUN_00542200(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 0x428);
  if ((((iVar2 <= param_2) || (param_4 < 1)) ||
      (iVar3 = *(int *)(param_1 + 0x42c), iVar3 <= param_3)) || (param_5 < 1)) {
    return 0xffffffff;
  }
  iVar4 = param_4 + param_2;
  if (param_2 < 0) {
    param_2 = 0;
    param_4 = iVar4;
  }
  else if (iVar2 < iVar4) {
    param_4 = iVar2 - param_2;
  }
  if (param_3 < 0) {
    param_5 = param_5 + param_3;
    param_3 = 0;
  }
  else if (iVar3 < param_3 + param_5) {
    param_5 = iVar3 - param_3;
  }
  bVar1 = *(byte *)(param_1 + 4);
  iVar2 = *(int *)(param_1 + 0x430);
  iVar3 = (uint)bVar1 * param_2 + iVar2 * param_3 + *(int *)(param_1 + 0x434);
  for (; 0 < param_5; param_5 = param_5 + -1) {
    FUN_0056d380(iVar3,0,(uint)bVar1 * param_4);
    iVar3 = iVar3 + iVar2;
  }
  return 0;
}

