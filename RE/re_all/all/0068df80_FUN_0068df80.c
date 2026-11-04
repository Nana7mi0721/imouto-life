
void FUN_0068df80(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  short *psVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int local_184;
  byte local_180 [128];
  undefined1 local_100 [256];
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x1c0) + 0x18);
  iVar5 = (param_4 >> 2) * 0x20 + 4;
  iVar8 = (param_3 >> 3) * 0x20 + 2;
  iVar7 = (param_2 >> 2) * 0x20 + 4;
  uVar1 = FUN_0068e0a0(param_1,iVar7,iVar8,iVar5,local_100);
  FUN_0068e290(param_1,iVar7,iVar8,iVar5,uVar1,local_100,local_180);
  pbVar4 = local_180;
  local_184 = 4;
  piVar6 = (int *)(iVar3 + (param_2 >> 2) * 0x10);
  do {
    iVar5 = 8;
    iVar3 = ((param_3 >> 3) * 0x100 + (param_4 >> 2) * 4) * 2;
    do {
      iVar7 = 4;
      psVar2 = (short *)(*piVar6 + iVar3);
      do {
        *psVar2 = *pbVar4 + 1;
        psVar2 = psVar2 + 1;
        pbVar4 = pbVar4 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      iVar3 = iVar3 + 0x40;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    piVar6 = piVar6 + 1;
    local_184 = local_184 + -1;
  } while (local_184 != 0);
  return;
}

