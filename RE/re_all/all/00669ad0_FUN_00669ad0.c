
bool FUN_00669ad0(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar6 = param_2[2] + param_2[1] + *param_2;
  iVar3 = FUN_0066b150(param_1,*param_2,100000,iVar6);
  if (iVar3 == 0) {
    return true;
  }
  iVar3 = FUN_0066b150(param_1 + 4,param_2[1],100000,iVar6);
  if (iVar3 == 0) {
    return true;
  }
  iVar3 = param_2[1];
  iVar1 = *param_2;
  iVar7 = param_2[5] + param_2[4] + param_2[3];
  iVar4 = FUN_0066b150(param_1 + 8,param_2[3],100000,iVar7);
  if (iVar4 == 0) {
    return true;
  }
  iVar4 = FUN_0066b150(param_1 + 0xc,param_2[4],100000,iVar7);
  if (iVar4 == 0) {
    return true;
  }
  iVar4 = param_2[3];
  iVar2 = param_2[4];
  iVar8 = param_2[8] + param_2[6] + param_2[7];
  iVar5 = FUN_0066b150(param_1 + 0x10,param_2[6],100000,iVar8);
  if (iVar5 == 0) {
    return true;
  }
  iVar5 = FUN_0066b150(param_1 + 0x14,param_2[7],100000,iVar8);
  if (iVar5 == 0) {
    return true;
  }
  iVar5 = param_2[7];
  iVar8 = iVar6 + iVar7 + iVar8;
  iVar6 = FUN_0066b150(param_1 + 0x18,iVar1 + iVar4 + param_2[6],100000,iVar8);
  if (iVar6 == 0) {
    return true;
  }
  iVar3 = FUN_0066b150(param_1 + 0x1c,iVar3 + iVar2 + iVar5,100000,iVar8);
  return iVar3 == 0;
}

