
void FUN_007a7720(int param_1,undefined4 param_2)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  byte bVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int local_20 [8];
  
  local_20[0] = 1;
  bVar4 = (*(int *)(param_1 + 8) < 1) - 1U & (byte)*(int *)(param_1 + 8);
  piVar5 = local_20;
  psVar3 = (short *)(param_1 + 0xc);
  iVar2 = 0;
  do {
    iVar7 = iVar2;
    piVar5 = piVar5 + 1;
    sVar1 = psVar3[1];
    *piVar5 = piVar5[-1] * (int)*psVar3;
    psVar3 = psVar3 + 2;
    iVar2 = iVar7 + 1;
  } while (sVar1 != 1);
  iVar2 = (int)*(short *)(param_1 + 10 + (iVar7 + 1) * 4);
  for (; -1 < iVar7; iVar7 = iVar7 + -1) {
    if (iVar7 == 0) {
      iVar6 = 1;
    }
    else {
      iVar6 = (int)*(short *)(param_1 + 10 + iVar7 * 4);
    }
    switch(*(undefined2 *)(param_1 + 0xc + iVar7 * 4)) {
    case 2:
      FUN_007a7820(param_2,iVar2,local_20[iVar7]);
      break;
    case 3:
      FUN_007a7ba0(param_2,local_20[iVar7] << (bVar4 & 0x1f),param_1,iVar2,local_20[iVar7],iVar6);
      break;
    case 4:
      FUN_007a7930(param_2,local_20[iVar7] << (bVar4 & 0x1f),param_1,iVar2,local_20[iVar7],iVar6);
      break;
    case 5:
      FUN_007a7d30(param_2,local_20[iVar7] << (bVar4 & 0x1f),param_1,iVar2,local_20[iVar7],iVar6);
    }
    iVar2 = iVar6;
  }
  return;
}

