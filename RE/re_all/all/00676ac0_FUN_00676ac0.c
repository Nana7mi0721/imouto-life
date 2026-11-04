
void FUN_00676ac0(int param_1,char *param_2,byte *param_3)

{
  char *pcVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  int iVar9;
  byte *pbVar10;
  
  iVar5 = (int)(*(byte *)(param_1 + 0xb) + 7) >> 3;
  pcVar1 = param_2 + iVar5;
  for (; param_2 < pcVar1; param_2 = param_2 + 1) {
    bVar2 = *param_3;
    param_3 = param_3 + 1;
    *param_2 = *param_2 + bVar2;
  }
  iVar4 = *(int *)(param_1 + 4);
  pbVar10 = param_3;
  for (; param_2 < pcVar1 + (iVar4 - iVar5); param_2 = param_2 + 1) {
    bVar2 = pbVar10[-iVar5];
    bVar3 = *pbVar10;
    iVar6 = (uint)bVar3 - (uint)bVar2;
    pbVar10 = pbVar10 + 1;
    iVar7 = (uint)(byte)param_2[-iVar5] - (uint)bVar2;
    if (iVar6 < 0) {
      param_3 = (byte *)-iVar6;
    }
    else {
      param_3 = (byte *)iVar6;
    }
    iVar9 = iVar7;
    if (iVar7 < 0) {
      iVar9 = -iVar7;
    }
    iVar6 = iVar6 + iVar7;
    if (iVar6 < 0) {
      iVar6 = -iVar6;
    }
    bVar8 = param_2[-iVar5];
    if (iVar9 < (int)param_3) {
      param_3 = (byte *)iVar9;
      bVar8 = bVar3;
    }
    if (iVar6 < (int)param_3) {
      bVar8 = bVar2;
    }
    *param_2 = *param_2 + bVar8;
  }
  return;
}

